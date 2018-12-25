/*
 * DIO.h
 *
 * Author: Engr.Mohammed Hessen
 */

#ifndef DIO_H_
#define DIO_H_

/*
 ----------------------------PORT/PINS Number--------------------------------------
 */
enum PORT_NUM { port_A , port_B , port_C , port_D } ;
enum PINS_NUM { pin_0 , pin_1 , pin_2 , pin_3 , pin_4 , pin_5 , pin_6 , pin_7 } ;
#define INPUT  10		/* Don't Care the Number */
#define OUTPUT 11
#define HIGH   21		/* Don't Care the Number */
#define LOW    20
/*----------------------------------------------------------------------------------*/

void DIO_vidSetPortDirction (u8 port_number , u8 value) ;
void DIO_vidSetPortValue (u8 port_number , u8 value) ;
void DIO_vidSetBitDirction (u8 port_number ,u8 pin_number , u8 value);
void DIO_vidSetBitValue (u8 port_number ,u8 pin_number , u8 value);
u8 DIO_u8ReadPortValue (u8 port_number);
u8 DIO_u8ReadBitValue ( u8 port_number , u8 pin_number );

#endif /* DIO_H_ */
