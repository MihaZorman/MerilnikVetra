/*
 * ADconverter.c
 *
 * Created: 3-Avg-20 
 *  Author: Miha Zorman
 */

// libraries
#include <avr/io.h>
#include <avr/eeprom.h>
#include "systime.h"
#include "LCD_Ili9341.h"
#include "config.h"
#include "config.h"
#include "ugui_config.h"
#include "ADconverter.h"

//------------------ADC-------------------------

void ADC_Init()
{
	DIDR0 = 14; // izklop vmesnika digitalnega vhoda na kanalih ADC1 , ADC2 in ADC3.
	PORTC &= 0xF1;// izklop pull-up uporov
	DDRC &= 0xF1; // nastavim pine na vhod
	ADMUX = 64;//za referencno napetost AD pretvornika izbrana analogna napajalna napetost VCC,desna poravnava
	ADCSRA |= 0x87; // Prescaler 128 -> 125 KHz,ADC Enable
	ADCSRA &= 0xDF; // samodejno prozenje pretvorbe izklopljeno
}


void ADC_SelectChannel(char channel)
{
	ADMUX &= 0xF0;// bite mux postavim na 0
	switch (channel)
	{
		case 0:
		ADMUX |= 0x0;
		break;
		case 1:
		ADMUX |= 0x1;
		break;
		case 2:
		ADMUX |= 0x2;
		break;
		case 3:
		ADMUX |= 0x3;
		break;
		case 4:
		ADMUX |= 0x4;
		break;
	}
	
}


int ADC_Read()
{
	ADCSRA |= 0x40;
	while(1)
	{
		if ((ADCSRA & 0x40) == 0) break;// preverjanje ali je AD pretvorba se v teku
	}
	return ADC; // vrne rezultat AD pretvorbe
}


int ADC_ReadChannel(char channel)
{
	ADC_SelectChannel(channel);
	_delay_us(10);
	return  ADC_Read();
	
}


// ---------- SYSTEM LEVEL FUNCTIONS -----------

int JOY_read_axis(char axis)
{
	switch ( axis)
	{
		case X_AXIS:
		key = ADC_ReadChannel(X_AXIS); // beri kanal x
		break;
		case Y_AXIS:
		key = ADC_ReadChannel(Y_AXIS);// beri kanal y
		break;
		case KANAL_1:
		key = ADC_ReadChannel(KANAL_1); // beri kanal x
		break;
	}
	
	return key;
}

//test