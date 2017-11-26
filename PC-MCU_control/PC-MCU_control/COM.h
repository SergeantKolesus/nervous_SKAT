#ifndef COM_H_INCLUDED
#define COM_H_INCLUDED
#pragma once

#include <Windows.h>

LPCWSTR FindCOM(void);

HANDLE FOpenCOM(void);

#endif //#ifndef COM_H_INCLUDED