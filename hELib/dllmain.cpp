// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <cstdio>

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		printf("Welcome to hELib, hez2010 E Language Support Library: Fast, Safe and Convenient\n");
	case DLL_THREAD_ATTACH:
		printf("Welcome to hELib, hez2010 E Language Support Library: Fast, Safe and Convenient\n");
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
