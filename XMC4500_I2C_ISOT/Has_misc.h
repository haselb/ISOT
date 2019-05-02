/*
 * Has_misc.h
 *
 *  Created on: Oct 13, 2015
 *      Author: haselb
 */

#ifndef HAS_MISC_H_
#define HAS_MISC_H_

#define ON 	1
#define OFF 0

extern uint32_t timer_1_of_8;  	//I2C SW_IRQ1
extern volatile uint8_t mainloop_ticks;
//extern XMC_RTC_TIME_t timeval;

extern void RTC_init(void);
extern void delay100us(uint32_t dwUs);


#endif /* HAS_MISC_H_ */
