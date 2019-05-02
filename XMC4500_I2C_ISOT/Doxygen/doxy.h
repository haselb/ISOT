/*! *****************************************************************************
 * @file     	doxy.h
 * @brief    	Main file for Doxygen
 * @version 	V1.0
 * @date     	2018-July-23
 *
 * @note		(C) GNU GPL
 *
 * @profile     Main page file for any project
 * @description If Doxygen is used, this file provides content of Main Page
 *
 * @par
 * CUAS is supplying this software for use with
 * Infineons microcontrollers. This file can be freely distributed within
 * development tools that are supporting such microcontrollers.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * @originator	Matthias Haselberger
 * @author		Matthias Haselberger
 * @bug			none
 * @attention	none
 * @warning		none
 * @todo		-
 ******************************************************************************/

#ifndef _DOXY_H_
#define _DOXY_H_

/*! \mainpage
 *
 * \brief <b>I2C-Bus Scanner</b>\n
 * Seeks I2C-Bus for valid devices.\n
 * \par Project description:
 * If a valid device is found, 8-bit address is displayed on LCD .\n
 *
 * \par Compiler and Switches, Dependencies, Tools
 *
 * Tools for edit, compilation, linking and programming of the sources
 * <ul>
 * <li>DAVE Version 4.4.2</li>
 * <li>Segger Debugger and Programmer</li>
 * <li>Doxygen 1.8.8 and higher</li>
 * <li>Terminal Program PuTTY (is more stable than J-Link RTT Viewer) to watch Segger RTT messaging.</li>
 *
 * </ul>
 *
 * \par Versioning
 *
 * <table>
 * <caption id="multi_row"> Version, History </caption>
 * <tr><th>Nr.   <th> Date		  <th> Comment		</td>
 * <tr><td>0.0.0 <td> 2018-Jun-01 <td> Start of development
 * <tr><td>0.0.1 <td> 2018-Nov-10 <td> add doxygen
 * <tr><td>1.0.0 <td> 2019-May-02 <td> add git versioning
 * <tr><td>0.0.3 <td> 2018- <td>
 * <tr><td>0.0.4 <td> 2018- <td>
 * <tr><td>0.0.5 <td> 2018- <td>
 * <tr><td>0.0.6 <td> 2018- <td>
 * <tr><td>0.0.7 <td> 2018- <td>
 * </table>
 *
 */

#define MAJOR_VERSION 1U
#define MINOR_VERSION 0U
#define PATCH_VERSION 0U

 /*!
 * \defgroup Hardware Hardware
 * @{
 * <b> Microcontroller XMC4500 on Relaxkit</b>
 * <ul>
 * <li>256kB Flash;
 * <li>16kB RAM;
 * <li>PQFP100;
 * <li>I2C-Bus at P5.2 SCL, P5.0:SDA
 * </ul>
 * @}
 */

/*!
 * \defgroup License License
 * @{
 * <b>(C) Copyright</b>
 * The Property Rights are taken from GNU GPL
 *
 * The source code could be used and/or modified and labelled by own author.
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: The Author
 * has no obligation to support this Software. He is
 * providing the Software "AS IS", with no express or implied warranties of any
 * kind, including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement of
 * any proprietary rights of a third party.
 *
 * The Author will not be liable for any consequential,
 * incidental, or special damages, or any other relief, or for any claim by
 * any third party, arising from your use of this Software.
 * @}
 */

#endif /* _DOXY_H_ */

