#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#pragma once

#include "Debug.h"

/*
*Enum is used if it is neccesary to create more than one menu
*/

typedef enum
{
	Debug,
	Reliase
} menu_mode_t; 

#define MENU_ARGUMENT menu_mode_t mode

void Menu(MENU_ARGUMENT);

#endif //#ifndef MENU_H_INCLUDED