/*
 * ADconverter.h
 *
 * Created: 3-Avg-20 
 *  Author: Miha Zorman
 */


 // ---------- HARDWARE LEVEL -----------
// libraries
#include <avr/io.h>
#include <avr/eeprom.h>


#define KANAL_1 1
#define X_AXIS 2
#define Y_AXIS 3
int key;



//  function prototypes
void Init_IO();
void ADC_Init();
int ADC_Read();
void ADC_SelectChannel(char channel);
int ADC_ReadChannel(char channel);
int JOY_read_axis(char axis);



