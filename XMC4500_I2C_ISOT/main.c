/*
 * main.c
 *
 *  Created on: 2018 Nov 09 16:41:16
 *  Author: haselb
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include "LCD.h"
#include "isot_i2c.h"
#include "has_misc.h"
#include "hal_i2c.h"
/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }
  timer_1_of_8 = SYSTIMER_CreateTimer(50000, SYSTIMER_MODE_ONE_SHOT, SW_IRQ_1, NULL); //SW-WDG for I2C
  LCD_init(),
  LCD_text(0, 0, "Find I2C-Device(s) on P5.2:SCL, P5.0:SDA");
  LCD_text(1, 0, "hm,2019; Version 1.0.0");
  delay100us(50000); // 5 second
  LCD_clearlines();

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	  	  find_I2C_device();	// seek I2C-bus for devices and respond available addresses

	  	  delay100us(10000); // 1 second main loop

	  	  DIGITAL_IO_ToggleOutput(&DIGITAL_O_HB_LED); //toggles : 0 -> 1
  }
}
