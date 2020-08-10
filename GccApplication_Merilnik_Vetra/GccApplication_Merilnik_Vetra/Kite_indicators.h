#include "ugui.h"
//-----------------------Functions prototypes---------------------------------

void OFF_All_Kite_Indicator();
void OFF_All_Kite_Indicator_A();
void OFF_All_Kite_Indicator_B();
void OFF_All_Kite_Indicator_C();

void OFF_Kite_Indicator_C_2_8(); // IZKLOPI INDIKATORJE OD 2 D0 8
void OFF_Kite_Indicator_C_3_8(); // IZKLOPI INDIKATORJE OD 3 D0 8
void OFF_Kite_Indicator_C_4_8(); // IZKLOPI INDIKATORJE OD 4 D0 8

void OFF_Kite_Indicator_B_2_8(); // IZKLOPI INDIKATORJE OD 2 D0 8
void OFF_Kite_Indicator_B_3_8(); // IZKLOPI INDIKATORJE OD 3 D0 8
void OFF_Kite_Indicator_B_4_8(); // IZKLOPI INDIKATORJE OD 4 D0 8

void OFF_Kite_Indicator_A_2_8(); // IZKLOPI INDIKATORJE OD 2 D0 8
void OFF_Kite_Indicator_A_3_8(); // IZKLOPI INDIKATORJE OD 3 D0 8
void OFF_Kite_Indicator_A_4_8(); // IZKLOPI INDIKATORJE OD 4 D0 8

// -----------------------Kite_Indicators-------------------------------------

// ------------Kite_Indicator_Frame-----------------
#define Kite_Indicator_Frame_A1   UG_DrawFrame(149,139,160,160,C_WHITE); //  X start position,Y start position,X end position,Y end position
#define Kite_Indicator_Frame_A2   UG_DrawFrame(169,139,180,160,C_WHITE);
#define Kite_Indicator_Frame_A3   UG_DrawFrame(189,139,200,160,C_WHITE);
#define Kite_Indicator_Frame_A4   UG_DrawFrame(209,139,220,160,C_WHITE);
#define Kite_Indicator_Frame_A5   UG_DrawFrame(229,139,240,160,C_WHITE);
#define Kite_Indicator_Frame_A6   UG_DrawFrame(249,139,260,160,C_WHITE);
#define Kite_Indicator_Frame_A7   UG_DrawFrame(269,139,280,160,C_WHITE);
#define Kite_Indicator_Frame_A8   UG_DrawFrame(289,139,300,160,C_WHITE);

#define Kite_Indicator_Frame_B1   UG_DrawFrame(150,170,160,190,C_WHITE);
#define Kite_Indicator_Frame_B2   UG_DrawFrame(170,170,180,190,C_WHITE);
#define Kite_Indicator_Frame_B3   UG_DrawFrame(190,170,200,190,C_WHITE);

#define Kite_Indicator_Frame_B4   UG_DrawFrame(210,170,220,190,C_WHITE);
#define Kite_Indicator_Frame_B5   UG_DrawFrame(230,170,240,190,C_WHITE);
#define Kite_Indicator_Frame_B6   UG_DrawFrame(250,170,260,190,C_WHITE);
#define Kite_Indicator_Frame_B7   UG_DrawFrame(270,170,280,190,C_WHITE);
#define Kite_Indicator_Frame_B8   UG_DrawFrame(290,170,300,190,C_WHITE);

#define Kite_Indicator_Frame_C1   UG_DrawFrame(150,200,160,220,C_WHITE);
#define Kite_Indicator_Frame_C2   UG_DrawFrame(170,200,180,220,C_WHITE);
#define Kite_Indicator_Frame_C3   UG_DrawFrame(190,200,200,220,C_WHITE);
#define Kite_Indicator_Frame_C4   UG_DrawFrame(210,200,220,220,C_WHITE);
#define Kite_Indicator_Frame_C5   UG_DrawFrame(230,200,240,220,C_WHITE);
#define Kite_Indicator_Frame_C6   UG_DrawFrame(250,200,260,220,C_WHITE);
#define Kite_Indicator_Frame_C7   UG_DrawFrame(270,200,280,220,C_WHITE);
#define Kite_Indicator_Frame_C8   UG_DrawFrame(290,200,300,220,C_WHITE);
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
#define Kite_Indicator_A1   UG_FillFrame(150,140,160,160,C_BLUE_VIOLET);
#define Kite_Indicator_A2   UG_FillFrame(170,140,180,160,C_DODGER_BLUE);
#define Kite_Indicator_A3   UG_FillFrame(190,140,200,160,C_AQUA);
#define Kite_Indicator_A4   UG_FillFrame(210,140,220,160,C_LIME_GREEN);
#define Kite_Indicator_A5   UG_FillFrame(230,140,240,160,C_SPRING_GREEN);
#define Kite_Indicator_A6   UG_FillFrame(250,140,260,160,C_GREEN);
#define Kite_Indicator_A7   UG_FillFrame(270,140,280,160,C_DARK_ORANGE);
#define Kite_Indicator_A8   UG_FillFrame(290,140,300,160,C_RED);

#define Kite_Indicator_B1   UG_FillFrame(150,170,160,190,C_BLUE_VIOLET);
#define Kite_Indicator_B2   UG_FillFrame(170,170,180,190,C_DODGER_BLUE);
#define Kite_Indicator_B3   UG_FillFrame(190,170,200,190,C_AQUA);
#define Kite_Indicator_B4   UG_FillFrame(210,170,220,190,C_LIME_GREEN);
#define Kite_Indicator_B5   UG_FillFrame(230,170,240,190,C_SPRING_GREEN);
#define Kite_Indicator_B6   UG_FillFrame(250,170,260,190,C_GREEN);
#define Kite_Indicator_B7   UG_FillFrame(270,170,280,190,C_DARK_ORANGE);
#define Kite_Indicator_B8   UG_FillFrame(290,170,300,190,C_RED);

#define Kite_Indicator_C1   UG_FillFrame(150,200,160,220,C_BLUE_VIOLET);
#define Kite_Indicator_C2   UG_FillFrame(170,200,180,220,C_DODGER_BLUE);
#define Kite_Indicator_C3   UG_FillFrame(190,200,200,220,C_AQUA);
#define Kite_Indicator_C4   UG_FillFrame(210,200,220,220,C_LIME_GREEN);
#define Kite_Indicator_C5   UG_FillFrame(230,200,240,220,C_SPRING_GREEN);
#define Kite_Indicator_C6   UG_FillFrame(250,200,260,220,C_GREEN);
#define Kite_Indicator_C7   UG_FillFrame(270,200,280,220,C_DARK_ORANGE);
#define Kite_Indicator_C8   UG_FillFrame(290,200,300,220,C_RED);

//----------------------------------------------------------------------------
#define OFF_Kite_Indicator_A1   UG_FillFrame(150,140,160,160,C_BLACK);
#define OFF_Kite_Indicator_A2   UG_FillFrame(170,140,180,160,C_BLACK);
#define OFF_Kite_Indicator_A3   UG_FillFrame(190,140,200,160,C_BLACK);
#define OFF_Kite_Indicator_A4   UG_FillFrame(210,140,220,160,C_BLACK);
#define OFF_Kite_Indicator_A5   UG_FillFrame(230,140,240,160,C_BLACK);
#define OFF_Kite_Indicator_A6   UG_FillFrame(250,140,260,160,C_BLACK);
#define OFF_Kite_Indicator_A7   UG_FillFrame(270,140,280,160,C_BLACK);
#define OFF_Kite_Indicator_A8   UG_FillFrame(290,140,300,160,C_BLACK);

#define OFF_Kite_Indicator_B1   UG_FillFrame(150,170,160,190,C_BLACK);
#define OFF_Kite_Indicator_B2   UG_FillFrame(170,170,180,190,C_BLACK);
#define OFF_Kite_Indicator_B3   UG_FillFrame(190,170,200,190,C_BLACK);
#define OFF_Kite_Indicator_B4   UG_FillFrame(210,170,220,190,C_BLACK);
#define OFF_Kite_Indicator_B5   UG_FillFrame(230,170,240,190,C_BLACK);
#define OFF_Kite_Indicator_B6   UG_FillFrame(250,170,260,190,C_BLACK);
#define OFF_Kite_Indicator_B7   UG_FillFrame(270,170,280,190,C_BLACK);
#define OFF_Kite_Indicator_B8   UG_FillFrame(290,170,300,190,C_BLACK);

#define OFF_Kite_Indicator_C1   UG_FillFrame(150,200,160,220,C_BLACK);
#define OFF_Kite_Indicator_C2   UG_FillFrame(170,200,180,220,C_BLACK);
#define OFF_Kite_Indicator_C3   UG_FillFrame(190,200,200,220,C_BLACK);
#define OFF_Kite_Indicator_C4   UG_FillFrame(210,200,220,220,C_BLACK);
#define OFF_Kite_Indicator_C5   UG_FillFrame(230,200,240,220,C_BLACK);
#define OFF_Kite_Indicator_C6   UG_FillFrame(250,200,260,220,C_BLACK);
#define OFF_Kite_Indicator_C7   UG_FillFrame(270,200,280,220,C_BLACK);
#define OFF_Kite_Indicator_C8   UG_FillFrame(290,200,300,220,C_BLACK);
//---------------------------------------------------------------------------------------------------
