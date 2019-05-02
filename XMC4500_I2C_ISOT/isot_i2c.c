/*
 * isot_i2c.c
 *
 *  Created on: Jan 27, 2018
 *      Author: haselb
 *      Is Somewhat Out There on I2C Bus?
 */

#include <Dave.h>
#include <stdio.h>			//requested by sprintf
#include "hal_i2c.h"
#include "isot_i2c.h"
#include "Has_Misc.h"
#include "LCD.h"


uint8_t I2C_devices_on_bus[10]= {0}; // I think, that bus responses less than 10 devices
uint8_t I2C_device_found=0;
uint8_t j=0;

/*!
 * @brief 	   Function to write I2C-Adresses to I2C-bus.
 * @param[in]  I2C_Address in 8-bit Mode
 * @param[out] I2C_device_found in 8-bit Mode
 * @retval     0 if no device is found\par
 * 			   1 if device is found
 * @pre        None
 * @post       None
 * @attention  None
 * @note
 */
uint8_t I2C_bus_scanner(uint8_t I2C_address, uint8_t *I2C_device_found)
{
	 uint8_t mem_address=0;

	 //Write - transmit data to DEVICE by
	 //1.) Start Condition
	 //2.) Write Address of Slave Device
	 //3.) Write Register Address of Slave device, here a dummy 0x00
	 //4.) and close bus by sending stop
	 //5.) if no device is on I2C_address, bus would wait infty for ACKnowledge,
	 // therefore the bus has to be aborted and reinitialized by Soft_WDG

	 Soft_WDG_1(ON);	// if no acknowledge occurs, program would waits infintiy in while loop
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,I2C_address,&mem_address,1,false); //call by referenced value (mem_address)
	 while((tx_completion_0 == 0) && (flag_I2C_NACK == 0) && (flag_eject_at_I2C_NACK == 0));
	 tx_completion_0 = 0;
	 Soft_WDG_1(OFF);  // if after xxms of no response, IRQ set flag_eject_at_I2C_NACK=1 to leave while loop
	 if(flag_I2C_NACK || flag_eject_at_I2C_NACK) {
		flag_I2C_NACK=0;
		flag_eject_at_I2C_NACK=0;
		*I2C_device_found=0; // if no device is available on bus
		return 0;
	 }
	 else {
		 *I2C_device_found=I2C_address;
		 return 1; // if device is available on bus
	 }
}


/*!
 * @brief 	   Function to scan I2C-bus from address 0 to 256.
 * @param[in]  None
 * @param[out] None
 * @retval     void
 * @pre        None
 * @post       None
 * @attention  8-bit Address syntax is utilized
 * @note       This routine checks the I2C-Acknowledge-Bit(ACK). If a valid I2C-Adress is responded,\n
 *  the Adress is displayed for 5 seconds.
 */
void find_I2C_device(void)
{
	char buffer[41];

	for (uint8_t i = 0; i < 255; ++i) {
		sprintf(buffer,"Seek at Addr: 0x%02X",i);
		LCD_text(0,0,buffer);
		delay100us(1000);
		if(I2C_bus_scanner(i,&I2C_device_found))
		{
			I2C_devices_on_bus[j]=I2C_device_found; //write only found I2C_device address to array
			j++;  // increment array for next found device
			sprintf(buffer,"Device found at 0x%02X",i);
			LCD_text(1,0,buffer);
			delay100us(20000);
		}
		i++; // take only even adresses in 8 bit Address syntax
	}
}
