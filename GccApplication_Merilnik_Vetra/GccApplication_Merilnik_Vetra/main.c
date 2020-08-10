/*
 * GccApplication_Merilnik_Vetra.c
 *
 * Created: 4. 08. 2020 10:50:23
 * Author : mihaz
 */ 

// libraries
#include <avr/io.h>
#include <avr/eeprom.h>
#include "systime.h"
#include "LCD_Ili9341.h"
#include "config.h"
#include "config.h"
#include "ugui_config.h"
#include "kbd.h"
#include "ADconverter.h"
#include "Kite_indicators.h"
//-----------------------------------

void Init_IO()
{
	PORTB |= 0x12;
	PORTC |= 0x3F;
	PORTD |= 0xBC;
	PORTE |= 0x00;
	DDRB  |= 0x2D;
	DDRC  |= 0x00;
	DDRD  |= 0xC0;
	DDRE  |= 0x0F;
}

int wind;
#define UNIT_ADDRESS	(uint16_t *)0


//  function prototypes
void UI_show_value_at_XY();
int HandleKeyboard(void);
void start_screen();
void show_wind();
void menu();
void unit();
int NVM_load_word();
void NVM_save_word();
int joystick();
void Kite_Screen();
void Universal_kite();

//-----STATES-------------
#define SHOW_WIND 0

#define MENU      1
#define SETTINGS  2

//------------MAIN FUNCTION------------------------------------------------------------------------
int main(void)
{
	LCD_Init();
	Init_IO();
	ADC_Init();
	KBD_Init();
	Systime_Init();
	sei();
   
 start_screen();
  
   
    while (1) 
    {
		show_wind();
				
    }
}
//--------------------------------------------------------------------------------------------------

void start_screen()
{
	 UG_FontSelect(&RFONT_24X40);     // velikost pisave
	 UG_SetForecolor(C_BLUE);        // barva pisave
	 UG_PutString(80,80,"Zorman");
	  UG_FontSelect(&RFONT_16X26);     // velikost pisave
	 UG_PutString(80,120,"sport");
	 _delay_ms(1000);
	 UG_FillFrame(0,0,400,400,C_BLACK); //ozadje
	 UG_SetForecolor(C_WHITE);        // barva pisave
}


void show_wind()
{
	while (1)
	{
	// time delay to achieve required joystick refresh rate
	_delay_ms(100);
	
	if (NVM_load_word(UNIT_ADDRESS) & (1<<0))
	{
		wind = ADC_ReadChannel(KANAL_1)/31;
		UG_FontSelect(&RFONT_24X40);  // velikost pisave
		UI_show_value_at_XY(60,100,wind); // prikazi vrednost
		
		UG_FontSelect(&RFONT_16X26);
		UG_PutString(0,0,"meni");
		UG_PutString(250,0,"Km/h");
	}
	else
	{
		wind = ADC_ReadChannel(KANAL_1);
		UG_FontSelect(&RFONT_24X40);  // velikost pisave
		UI_show_value_at_XY(60,100,wind); // prikazi vrednost
		
		UG_FontSelect(&RFONT_16X26);
		UG_PutString(0,0,"meni");
		UG_PutString(250,0,"Kn");
	}
	
	
	static int state = 0;
	KBD_Read();
	state = KBD_GetKey();
	
	switch (state)
	{
		case BTN_OK:
		menu();
		break;
				
		case BTN_ESC:	//Welcome - wait for start
		unit();
		break;	
	}
	}
	
}
	
void menu()
{ 
	int key = 0; // tipka
	UG_FillFrame(0,0,400,400,C_BLACK); // crno ozadje
	
	while (1)
	{
		UG_FontSelect(&RFONT_16X26);
		UG_PutString(125,0,"meni");
		UG_PutString(125,60,"kite");
		UG_PutString(125,110,"graf");
		UG_PutString(80,160,"nastavitve");
		
		static int state = 0;
		state = joystick();
		KBD_Read(); // beri tipko
		key =  KBD_GetKey(); // shrani tipko
		
		switch (state)
		{
			
			case 0:  // kite
			UG_DrawRoundFrame (115,102,205,142,10,C_BLACK) ; //izklopi bev okvir 1
			UG_DrawRoundFrame (70,155,260,195,10,C_BLACK) ; //izklopi bev okvir 2
			UG_DrawRoundFrame (115,50,205,95,10,C_WHITE) ; // bev okvir 0
			if(key == BTN_OK && state == 0) Kite_Screen();
			break;
			
					
			case 1:	 // graph
			UG_DrawRoundFrame (115,50,205,95,10,C_BLACK) ; //izklopi bev okvir 0
			UG_DrawRoundFrame (70,155,260,195,10,C_BLACK) ; //izklopi bev okvir 2
			UG_DrawRoundFrame (115,102,205,142,10,C_WHITE) ; // bev okvir 1
			break;
			
			case 2: // settings
			UG_DrawRoundFrame (115,50,205,95,10,C_BLACK) ; //izklopi bev okvir 0
			UG_DrawRoundFrame (115,102,205,142,10,C_BLACK) ; //izklopi bev okvir 1
			UG_DrawRoundFrame (70,155,260,195,10,C_WHITE) ; // bev okvir 2
			break;
		}
	 
	 if(key == BTN_A) break;
	
	}
	 UG_FillFrame(0,0,400,400,C_BLACK); //crno ozadje

}

void unit()
{
	int enota;
	int *naslov;
	enota = NVM_load_word(UNIT_ADDRESS);
	enota = enota ^ (1<<0);
	naslov = &enota;
	NVM_save_word (UNIT_ADDRESS, *naslov);
	UG_FillFrame(0,0,400,400,C_BLACK); // crno ozadje
	
}

void Kite_Screen()
{
	UG_FillFrame(0,0,400,400,C_BLACK); // crno ozadje
	while(1)
	{
		wind = ADC_ReadChannel(KANAL_1)/31;
		
		/*
		Kite_Indicator_A1;
		Kite_Indicator_A2;
		Kite_Indicator_A3;
		Kite_Indicator_A4;
		Kite_Indicator_A5;
		Kite_Indicator_A6;
		Kite_Indicator_A7;
		Kite_Indicator_A8;*/
		//------------------------------- 
		Universal_kite(wind);
		 
		 
		 KBD_Read(); // beri tipko
		  if(KBD_GetKey() == BTN_A) break;
	}
	
	
}




void Universal_kite(int wind)
{
	
	if(wind < 6) 
	{
		UG_PutString(70,10,"Premalo vetra"); // manj kot 6 kn
		OFF_All_Kite_Indicator();
	}
	if(wind >= 6 && wind < 8 )
	{
		UG_FillFrame(60,5,400,150,C_BLACK); // izsklop opozorila za premalo vetra
		OFF_All_Kite_Indicator_A();
		OFF_All_Kite_Indicator_B();
		OFF_Kite_Indicator_C8;
		OFF_Kite_Indicator_C7;
		OFF_Kite_Indicator_C6;
		OFF_Kite_Indicator_C5;
		OFF_Kite_Indicator_C4;
		OFF_Kite_Indicator_C3;
		OFF_Kite_Indicator_C2;
		UG_FontSelect(&RFONT_12X20);
		UG_PutString(40,200,"17 m^2 "); // med 6 in 8 kn
		Kite_Indicator_C1;
	}
	if(wind >= 8 && wind < 10 ) // med 8 in 10 kn
	{
		OFF_All_Kite_Indicator_A();
		OFF_All_Kite_Indicator_B_2_8();
		
		OFF_Kite_Indicator_C8;
		OFF_Kite_Indicator_C7;
		OFF_Kite_Indicator_C6;
		OFF_Kite_Indicator_C5;
		OFF_Kite_Indicator_C4;
		OFF_Kite_Indicator_C3;
		
		UG_FontSelect(&RFONT_12X20);
		UG_PutString(40,200,"17 m^2 "); 
		Kite_Indicator_C1;
		Kite_Indicator_C2;
		UG_PutString(40,180,"14 m^2 ");
		Kite_Indicator_B1
	}
	
	if(wind >= 10 && wind < 12 ) // med 10 in 12 kn
	{
		OFF_All_Kite_Indicator_A_2_8();
		
		OFF_All_Kite_Indicator_B_3_8();
		
		OFF_Kite_Indicator_C8;
		OFF_Kite_Indicator_C7;
		OFF_Kite_Indicator_C6;
		OFF_Kite_Indicator_C5;
		OFF_Kite_Indicator_C4;
		
		UG_FontSelect(&RFONT_12X20);
		UG_PutString(40,200,"17 m^2 ");
		Kite_Indicator_C1;
		Kite_Indicator_C2;
		Kite_Indicator_C3;
		UG_PutString(40,180,"14 m^2 ");
		Kite_Indicator_B1;
		Kite_Indicator_B2;
		UG_PutString(40,160,"12 m^2 ");
		Kite_Indicator_A1;
	}
	
	UG_FontSelect(&RFONT_16X26);
	UI_show_value_at_XY(60,100,wind);
}













void UI_show_value_at_XY(int x, int y, int value)
{
	char txt[50];
	if (NVM_load_word(UNIT_ADDRESS) & (1<<0)) sprintf(txt,"%4d Kn", value);
	else sprintf(txt,"%4d Km/h", value);
	UG_PutString(x,y,txt);
}
	


//______EEPROM_________________________

void NVM_save_word(uint16_t* address, int value)
{
	eeprom_write_word (address, value);	// shrani v eeprom
}

int NVM_load_word(const uint16_t* address) // beri z eeproma
{
	return eeprom_read_word(address);
}

//------------------joystick--------------------
int joystick() // funkcija za premikanje po meniju
{ 
	 static int joy_state,joy_old_state,joy_new_state;
	if (JOY_read_axis(X_AXIS) > 700) joy_new_state = 1;
		
	if(JOY_read_axis(X_AXIS) < 600) joy_new_state = 0;
	
	if(JOY_read_axis(X_AXIS) < 400)	joy_new_state = -1;
	if (joy_new_state != joy_old_state)
	{
		if(joy_new_state == 1) joy_state ++;
		if(joy_state == 3 ) joy_state = 0;
		if(joy_new_state == -1) joy_state --;
		if(joy_state == -1 ) joy_state = 2;
		joy_old_state = joy_new_state;
		
	}	
	return joy_state;
}
//---------------------------------------------
