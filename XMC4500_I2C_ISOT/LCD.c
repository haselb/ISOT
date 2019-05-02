/*
 * LCD.c
 *
 *  Created on: 06.12.2014
 *      Author: haselb
 */
#include <DAVE.h>			//Declarations from DAVE Code Generation (includes SFR declaration)
#include <stdio.h>			//requested by sprintf
#include "LCD.h"
#include "has_Misc.h"


/*!
 * @brief 	   Function for initializing LC-Display, 4-bit parallel mode
 * @param[in]  None
 * @param[out] None
 * @retval     void
 * @pre        requires BUS_IO-App
 * @post       None
 * @attention  None
 * @note       This routine initializes a HD44780 compatible LCD.
 * It needs a delay function @ref delay_100us().
 */
 void LCD_init(void)
 {
 	//Step 1: wait for power stabilization 500ms
	 delay100us(5000);   //wait after Power on device

	LCD_RS_Clr;
	LCD_RW_Clr;
	// 0000 five times
	for(int i=0;i<10;i++)
	{
		BUS_IO_Write(&BUS_IO_0,0x0|LCD_EN_Set);
		BUS_IO_Write(&BUS_IO_0,0x0&LCD_EN_Clr);
		delay100us(100);
	}

	delay100us(5000);   //wait after Power on device
// Step 2: Function set

 	BUS_IO_Write(&BUS_IO_0,0x2|LCD_EN_Set);
 	BUS_IO_Write(&BUS_IO_0,0x2&LCD_EN_Clr);
 	BUS_IO_Write(&BUS_IO_0,0x2|LCD_EN_Set);
 	BUS_IO_Write(&BUS_IO_0,0x2&LCD_EN_Clr);
 	BUS_IO_Write(&BUS_IO_0,0xB|LCD_EN_Set);
 	BUS_IO_Write(&BUS_IO_0,0xB&LCD_EN_Clr);
 	 delay100us(100);
 	//BussyFlag();


//Step 3: Display ON/OFF Control

 	BUS_IO_Write(&BUS_IO_0,0x0|LCD_EN_Set);
 	BUS_IO_Write(&BUS_IO_0,0x0&LCD_EN_Clr);
 	BUS_IO_Write(&BUS_IO_0,0xC|LCD_EN_Set);
 	BUS_IO_Write(&BUS_IO_0,0xC&LCD_EN_Clr);
 	delay100us(5);


// 	Step 4: Display Clear

 	BUS_IO_Write(&BUS_IO_0,0x0|LCD_EN_Set);
 	BUS_IO_Write(&BUS_IO_0,0x0&LCD_EN_Clr);
 	BUS_IO_Write(&BUS_IO_0,0x1|LCD_EN_Set);
 	BUS_IO_Write(&BUS_IO_0,0x1&LCD_EN_Clr);
 	delay100us(500);
 	//BussyFlag();

// 	Step 5: Return Home

 	BUS_IO_Write(&BUS_IO_0,0x0|LCD_EN_Set);
 	BUS_IO_Write(&BUS_IO_0,0x0&LCD_EN_Clr);
 	BUS_IO_Write(&BUS_IO_0,0x2|LCD_EN_Set);
 	BUS_IO_Write(&BUS_IO_0,0x2&LCD_EN_Clr);
 	delay100us(500);


// 	Step 6: Entry Mode Set

 	BUS_IO_Write(&BUS_IO_0,0x0|LCD_EN_Set);
 	BUS_IO_Write(&BUS_IO_0,0x0&LCD_EN_Clr);
 	BUS_IO_Write(&BUS_IO_0,0x6|LCD_EN_Set);
 	BUS_IO_Write(&BUS_IO_0,0x6&LCD_EN_Clr);
 	delay100us(1000);

	// 0000 five times
	for(int i=0;i<6;i++)
	{
		BUS_IO_Write(&BUS_IO_0,0x0|LCD_EN_Set);
		BUS_IO_Write(&BUS_IO_0,0x0&LCD_EN_Clr);
		delay100us(100);
	}


 }

/*!
 * @brief 	   Function to clear LCD.
 * @param[in]  None
 * @param[out] None
 * @retval     void
 * @pre        requires BUS_IO-App
 * @post       None
 * @attention  None
 * @note       This routine clears all lines of LCD.
 */
 void LCD_clearlines (void)
 {
// Write command CLS(0x01) to LCD-Display


	 	BUS_IO_Write(&BUS_IO_0,0x0|LCD_EN_Set);
	 	BUS_IO_Write(&BUS_IO_0,0x0&LCD_EN_Clr);
	 	BUS_IO_Write(&BUS_IO_0,0x1|LCD_EN_Set);
	 	BUS_IO_Write(&BUS_IO_0,0x1&LCD_EN_Clr);
	 	BUS_IO_Write(&BUS_IO_0,0x0|LCD_EN_Set);
	 	BUS_IO_Write(&BUS_IO_0,0x0&LCD_EN_Clr);
	 	BUS_IO_Write(&BUS_IO_0,0x2|LCD_EN_Set);
	 	BUS_IO_Write(&BUS_IO_0,0x2&LCD_EN_Clr);
 }

/*!
 * @brief 	   Function writes a ASCII string to LCD.
 * @param[in]  char LCDLine;   upper or lower display line (range 0 and 1)
 * @param[in]  char LCDColumn; where text starts (range 0 to LCD_local_display_width-1)
 * @param[in]  char* LCDInfo; text string in ASCII notation @par
 * @param[out] None
 * @retval     void
 * @pre        requires BUS_IO-App
 * @post       None
 * @attention  A  buffer
 * @note       This routine writes ASCII text to LCD.
 */
 void LCD_text (unsigned char LCDLine, uint16_t LCDColumn, char *LCDInfo)
 {
  uint16_t i = 0;
//  uint16_t LCD_local_Character = 0;
  uint16_t LCD_Data=0x0;

  if(LCDLine != 1) {LCDLine=0;}


   	LCD_Data|=0x8;		//LCD_D7_Set;

 	if(LCDLine == 0){
 		LCD_Data&=0xB;	//LCD_D6_Clr;first line
 	}
 	else{
 		LCD_Data|=0x4;	//LCD_D6_Set;second line
 	}


 	if (LCDColumn > LCD_local_display_width)
 		LCD_Data|=0x0; //beyond LCD_local_display_width start at beginning of line
 	else

    LCD_Data|=LCDColumn >>4;
 	BUS_IO_Write(&BUS_IO_0,LCD_Data|LCD_EN_Set);
 	BUS_IO_Write(&BUS_IO_0,LCD_Data&LCD_EN_Clr);
 	LCD_Data = 0x0F&LCDColumn ;

 	BUS_IO_Write(&BUS_IO_0,LCD_Data|LCD_EN_Set);
 	BUS_IO_Write(&BUS_IO_0,LCD_Data&LCD_EN_Clr);
 	i = 0;
 	while((LCDInfo[i] != '\0') && (i < LCD_local_display_width))
 	{
 		LCD_Data=0x0F&LCDInfo[i]>>4; // assign character
 		BUS_IO_Write(&BUS_IO_0,LCD_Data|LCD_RS_Set);
 		BUS_IO_Write(&BUS_IO_0,LCD_Data|LCD_EN_Set);
 		BUS_IO_Write(&BUS_IO_0,LCD_Data&LCD_EN_Clr);
 		LCD_Data=0x0F&LCDInfo[i]; // assign character
 		BUS_IO_Write(&BUS_IO_0,LCD_Data|LCD_RS_Set);
 		BUS_IO_Write(&BUS_IO_0,LCD_Data|LCD_EN_Set);
 		BUS_IO_Write(&BUS_IO_0,LCD_Data&LCD_EN_Clr);

 		i++;
 	}
 	//LCD_RS_Clr;
 	BUS_IO_Write(&BUS_IO_0,0x0);
 }




