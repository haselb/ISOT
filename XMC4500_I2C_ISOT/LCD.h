/*
 * LCD.h
 *
 *  Created on: 06.12.2014
 *      Author: haselb
 */

#ifndef LCD_H_
#define LCD_H_


/*
 * To connect LCD on XMC-MMC Board, following options have to be asserted:
 * Use the BUS_IO in Dave Apps: Number of Pins: 7; Pin Direction: Input/Output
 * Dont forget to assign with 'manual pin allocator' following Pads to Ports:
 * Pad_Bus_0 <--> P2.14
 * Pad_Bus_1 <--> P2.1
 * Pad_Bus_2 <--> P2.10
 * Pad_Bus_3 <--> P2.15
 * Pad_Bus_4 <--> P0.9
 * Pad_Bus_5 <--> P3.2
 * Pad_Bus_6 <--> P3.1
 */


#define LCD_local_display_width 40		//xx colums-display

#define LCD_EN_Clr  0xEF
#define LCD_EN_Set  0x10

#define LCD_RS_Clr 0xDF
#define LCD_RS_Set 0x20

#define LCD_RW_Clr 0xBF
#define LCD_RW_Set  0x40

//enumerate bit condition of sent character
//bitposition in a Byte
//| 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |

enum{
   bit0      = 0x01U,
   bit1      = 0x02U,
   bit2      = 0x04U,
   bit3      = 0x08U,
   bit4      = 0x10U,
   bit5      = 0x20U,
   bit6      = 0x40U,
   bit7      = 0x80U
};



//prototypes for local LCD display with nibble-drive mode (4bit)
//	------------------------------------------
//  | |	LCDLine 0			               | |
//	|  ------------------------------------  |
//  |  ^Char 0					   Char 16^	 |
//	|  ------------------------------------  |
//	------------------------------------------


extern void LCD_init(void);

//****************************************************************************
// @Function      void LCD_local_display_clearlines (void)
//----------------------------------------------------------------------------
// @Description   This is the clear whole display function of LCD-Local_Displ.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    void
//
//----------------------------------------------------------------------------
// @Date          06.01.2008
//
//****************************************************************************
extern void LCD_clearlines (void);

//****************************************************************************
// @Function      void LCD_text(
//						 unsigned char LCDLine,
//			 			 unsigned char LCDColumn,
//						 char *LCDInfo);
//----------------------------------------------------------------------------
// @Description   This is the text write function of LCD-Local_Displ.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters
//	 			  LCDLine :  0 for upper line, 1 for lower line
//				  LCDColumn: 0 till LCD_local_display_width (40 Char)
//				  *LCDInfo :  text written to display
//----------------------------------------------------------------------------
// @Date          06.01.2008
//
//****************************************************************************
extern void LCD_text
			( unsigned char LCDLine, uint16_t LCDColumn, char *LCDInfo);


extern void LCD_clearlines (void);

extern void update_LCD(void);

#endif /* LCD_H_ */
