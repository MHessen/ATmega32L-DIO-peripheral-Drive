/*
 * DIO.c
 *
 *Author: Engr.Mohammed Hessen
 */

#include "Types.h"
#include "Registers.h"
#include "DIO.h"
#define SetBit(Register,Pin) Register|=(1<<Pin)
#define ClrBit(Register,Pin) Register&=(~(1<<Pin))


/*
------------------------------DIO DDR Registers--------------------------------
 */

void DIO_vidSetPortDirction (u8 port_number , u8 value)
{
	switch (port_number)
	{
	case port_A :
		DDRA = value ;
		break ;
	case port_B :
		DDRB = value ;
		break ;
	case port_C :
		DDRC = value ;
		break ;
	case port_D :
		DDRD = value ;
		break ;
	}

}

void DIO_vidSetBitDirction (u8 port_number ,u8 pin_number , u8 value)
{
	switch (port_number)
	{

	case port_A :
		{
			if (OUTPUT==value)
				SetBit (DDRA,pin_number) ;
			else if (INPUT==value)
				ClrBit (DDRA,pin_number);
		}
		break ;

	case port_B :
		{
			if (OUTPUT==value)
				SetBit (DDRB,pin_number) ;
			else if (INPUT==value)
				ClrBit (DDRB,pin_number);
		}
		break ;

	case port_C :
		{
			if (OUTPUT==value)
				SetBit (DDRC,pin_number) ;
			else if (INPUT==value)
				ClrBit (DDRC,pin_number);
		}
		break ;

	case port_D :
		{
			if (OUTPUT==value)
				SetBit (DDRD,pin_number) ;
			else if (INPUT==value)
				ClrBit (DDRD,pin_number);
		}
		break ;
	}
}

/*
------------------------------DIO PORT Registers-------------------------------
 */
void DIO_vidSetPortValue (u8 port_number , u8 value)
{
	switch (port_number)
	{
	case port_A:
		PORTA = value ;
		break ;
	case port_B :
		PORTB = value ;
		break ;
	case port_C:
		PORTC = value ;
		break ;
	case port_D:
		PORTD = value ;
		break ;
	}
}


void DIO_vidSetBitValue (u8 port_number ,u8 pin_number , u8 value)
{
	switch (port_number)
	{
	case port_A :
		{
			if (HIGH==value)
				SetBit (PORTA,pin_number) ;
			else if (LOW==value)
				ClrBit (PORTA,pin_number);
		}
		break ;

	case port_B :
		{
			if (HIGH==value)
				SetBit (PORTB,pin_number) ;
			else if (LOW==value)
				ClrBit (PORTB,pin_number);
		}
		break ;

	case port_C :
		{
			if (HIGH==value)
				SetBit (PORTC,pin_number) ;
			else if (LOW==value)
				ClrBit (PORTC,pin_number);
		}
		break ;

	case port_D :
		{
			if (HIGH==value)
				SetBit (PORTD,pin_number) ;
			else if (LOW==value)
				ClrBit (PORTD,pin_number);
		}
		break ;
	}

}


/*
 -------------------------------DIO PIN Registers-------------------------------------
 */

u8 DIO_u8ReadPortValue (u8 port_number)
{
	u8 value ;

	switch(port_number)
	{

	case port_A:
		value = PINA ;
		break ;
	case port_B:
		value = PINB ;
		break ;
	case port_C:
		value = PINC ;
		break ;
	case port_D:
		value = PIND ;
		break ;
	}

	return value ;
}

// Read a specified Pin value

u8 DIO_u8ReadBitValue ( u8 port_number , u8 pin_number )
{
	u8 x , res ;

	switch (port_number)
	{
	case port_A :
		{
			x = PINA & (1<<pin_number) ;
			res  = (x>>pin_number) ;
		}
		break ;

	case port_B :
		{
			x = PINB & (1<<pin_number) ;
			res  = (x>>pin_number) ;
		}
		break;

	case port_C :
		{
			x = PINC & (1<<pin_number) ;
			res  = (x>>pin_number) ;
		}
		break ;

	case port_D :
		{
			x = PIND & (1<<pin_number) ;
			res  = (x>>pin_number) ;
		}
		break ;
	}

	return res ;

}
