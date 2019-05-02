/*
 * HAL_i2c.c
 *
 *  Created on: Dec 26, 2017
 *      Author: haselb
 */

#include <Dave.h>
#include "Has_Misc.h"

// define global variables
volatile uint8_t tx_completion_0 = 0;
volatile uint8_t rx_completion_0 = 0;
volatile bool flag_I2C_NACK=0;
volatile bool flag_eject_at_I2C_NACK=0;


//define functions

/*!
 * @brief 	   Callback function restarts I2C-Bus.
 * @param[in]  *args == NULL
 * @param[out] None
 * @retval     void
 * @pre        requires SYSTIMER_0 init: SYSTIMER_CreateTimer(50000, SYSTIMER_MODE_ONE_SHOT,...
 * @post       Function restarts USIC-Module I2C-Bus
 * @attention  checkout Infineon Application Note SYSTIMER_XMC45.PDF
 * @note       This routine is asserted by @ref Soft_WDG_1. If timeout occurs after 50000µs, this Handler\n
 * restarts I2C-Bus.
 */
void SW_IRQ_1 (void *args)
{
		flag_eject_at_I2C_NACK=1;

		I2C_MASTER_AbortTransmit(&I2C_MASTER_0);
		I2C_MASTER_AbortReceive(&I2C_MASTER_0);
//		I2C_MASTER_SendStop(&I2C_MASTER_0);
		I2C_MASTER_Init(&I2C_MASTER_0);
}


/*!
 * @brief 	   Function prevents from stucking in a while loop.
 * @param[in]  ON
 * 			   OFF
 * @param[out] None
 * @retval     void
 * @pre        requires SYSTIMER_0, initiated by DAVE
 * @post       Function starts o stops timer
 * @attention  None
 * @note       Before a while-loop, Soft_WDG_1(ON) starts SYSTIMER_0 timer 1 of 8.\n
 * after while loop, Soft_WDG_1(OFF) stops SYSTIMER_0 timer 1 of 8. If not,\n
 * after 50ms @ref SW_IRQ_1 is called.
 */
void Soft_WDG_1 (bool on_or_off)
{
	if(on_or_off)
	{
		SYSTIMER_StartTimer(timer_1_of_8);
	}
	else
	{
		SYSTIMER_StopTimer(timer_1_of_8);
	}
}

/*!
 * @brief 	   IRQ-Handler callback initiated by DAVE I2C-Bus.
 * @param[in]  None
 * @param[out] None
 * @retval     void
 * @pre        requires I2C, initiated by DAVE, end of transmit
 * @post       Function sets @ref tx_completion_0
 * @attention  activate end of transmit interrupt in I2C_MASTER_0 App
 * @note       This routine is the callback function of DAVE. It is invoked by the ISR generated from DAVE.
 */
void tx_callback_0(void)
{
       tx_completion_0 = 1;
}

/*!
 * @brief 	   IRQ-Handler callback initiated by DAVE I2C-Bus.
 * @param[in]  None
 * @param[out] None
 * @retval     void
 * @pre        requires I2C, initiated by DAVE, end of receive
 * @post       Function sets @ref rx_completion_0
 * @attention  activate end of receive interrupt in I2C_MASTER_0 App
 * @note       This routine is the callback function of DAVE. It is invoked by the ISR generated from DAVE.
 */
void rx_callback_0(void)
{
       rx_completion_0 = 1;
}

/*!
 * @brief 	   IRQ-Handler callback initiated by DAVE I2C-Bus.
 * @param[in]  None
 * @param[out] None
 * @retval     void
 * @pre        requires I2C, initiated by DAVE, detecting missing/not responding slave
 * @post       Function sets @ref flag_I2C_NACK
 * @attention  activate NACK interrupt in I2C_MASTER_0 App
 * @note       This routine is the callback function of DAVE. It is invoked by the ISR generated from DAVE.
 */
void I2C_NACK_IRQ_Handler_0(void)
{
	flag_I2C_NACK=1;
	I2C_MASTER_AbortTransmit(&I2C_MASTER_0) ;// before init, abort transmit has to be executed
	I2C_MASTER_AbortReceive(&I2C_MASTER_0);
//	I2C_MASTER_SendStop(&I2C_MASTER_0);
//	I2C_MASTER_Init(&I2C_MASTER_0); // init I2C bus again to respond
}

/*!
 * @brief 	   IRQ-Handler callback initiated by DAVE I2C-Bus.
 * @param[in]  None
 * @param[out] None
 * @retval     void
 * @pre        requires I2C, initiated by DAVE, detecting arbitration lost
 * @post       Function sets @ref flag_I2C_NACK
 * @attention  activate ARB Lost interrupt in I2C_MASTER_0 App
 * @note       This routine is the callback function of DAVE. It is invoked by the ISR generated from DAVE.
 */
void I2C_ARB_Lost_IRQ_Handler_0 (void)
{
	flag_I2C_NACK=1;
}

/*!
 * @brief 	   IRQ-Handler callback initiated by DAVE I2C-Bus.
 * @param[in]  None
 * @param[out] None
 * @retval     void
 * @pre        requires I2C, initiated by DAVE, detecting errors
 * @post       Function sets @ref flag_I2C_NACK
 * @attention  activate ERR interrupt in I2C_MASTER_0 App
 * @note       This routine is the callback function of DAVE. It is invoked by the ISR generated from DAVE.
 */
void I2C_ERR_IRQ_Handler_0 (void)
{
	flag_I2C_NACK=1;
}




