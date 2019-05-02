/*
 * Has_Misc.c
 *
 *  Created on: Oct 13, 2015
 *      Author: haselb
 */

#include <Dave.h>
#include "Has_Misc.h"


volatile uint32_t timetick_count=0;	// global variable for time tick count
volatile uint8_t mainloop_ticks=0;
uint32_t timer_1_of_8 = 0;


/*!
 * @brief 	   IRQ Handler is invoked after TIMER_0 period match.
 * @param[in]  None
 * @param[out] None
 * @retval     void
 * @pre        requires TIMER_0 initiated by DAVE associated to this IRQ.
 * @post       Function increments global variable @ref timetick_count
 * @attention  None
 * @note       This routine is invoked by the ISR generated from TIMER_0 perod match.
 * It is responsible to assert a timer interrupt.
 */
 void UserIRQHandler_0(void)
 {

 	/* Acknowledge the period match interrupt*/
	 TIMER_ClearEvent(&TIMER_0);

 	/* Increment time tick count */
 	timetick_count++;

 }

 /*!
  * @brief 	   Function to wait for n 100µs.
  * @param[in]  uint32_t dwUs
  * @param[out] None
  * @retval     void
  * @pre        manages TIMER_0-IRQ
  * @post       None
  * @attention  In TIMER_0 the Time Interval is set to 100µs.
  * @note       This routine serves the TIMER_0.
  */
 void delay100us(uint32_t dwUs)
 {
	 timetick_count=0;
	 TIMER_Start(&TIMER_0);
	 while(timetick_count < dwUs);
	  {
	    while(TIMER_GetInterruptStatus(&TIMER_0));
	    TIMER_Stop(&TIMER_0);
	  }

 }


/*!
* @brief 	   IRQ_Handler initiated by DAVE IRQ-Service and is invoked after RTC0 event.
* @param[in]  None
* @param[out] None
* @retval     void
* @pre        requires IRQ, initiated by DAVE
* @post       Function increments global variables @ref mainloop_ticks
* @attention  None
* @note       This routine is the callback function of DAVE. It is invoked by the ISR generated from DAVE.
*/
//void RTC_Time_Handler(void) //RTC_IRQ_Handler
//{
//
//	mainloop_ticks++;
//}

/*!
 * @brief 	   Function sanitizes @ref timeval struct and is invoked in init cycle.
 * @param[in]  None
 * @param[out] None
 * @retval     void
 * @pre        invoked in init cycle
 * @post       Function updates global variable @ref timeval
 * @attention  None
 * @note       This routine initializes @ref timeval values in RTC_0 App.
 */
//void RTC_init(void)
//{
//	timeval.seconds=0;
//	timeval.minutes=0;
//	timeval.hours=16;
//	timeval.days=4;
//	timeval.month=11;
//	timeval.year=2018;
//	RTC_Stop();
//	RTC_SetTime(&timeval);
//	RTC_Start();
//}
