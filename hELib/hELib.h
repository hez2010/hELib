#pragma once
#include "stdafx.h"
#include "commands.h"
#include "consts.h"
#include "datatypes.h"

EXTERN_C INT WINAPI hELib_ProcessNotifyLib(INT nMsg, DWORD dwParam1, DWORD dwParam2);

#ifndef __E_STATIC_LIB

#define LIB_MajorVersion 1
#define LIB_MinorVersion 0
#define LIB_BuildNumber 20180723
#define LIB_SysMajorVer 3
#define LIB_SysMinorVer 0
#define LIB_KrnlLibMajorVer 3
#define LIB_KrnlLibMinorVer 0
#define LIB_NAME_STR "hELib"
#define LIB_DESCRIPTION_STR "hez2010 E Language Support Library: Fast, Safe and Convenient"
#define LIB_Author "hez2010"
#define LIB_ZipCode ""
#define LIB_Address ""
#define LIB_Phone ""
#define LIB_Fax ""
#define LIB_Email "hez2010@126.com"
#define LIB_HomePage ""
#define LIB_Other ""
#define LIB_TYPE_COUNT 1
#define LIB_TYPE_STR "0000Basic Command\0""\0"

static LIB_INFO LibInfo =
{
	LIB_FORMAT_VER,
	_T("cb6b2986a76e445fa804d933c451aa2d"),
	LIB_MajorVersion,
	LIB_MinorVersion,
	LIB_BuildNumber,
	LIB_SysMajorVer,
	LIB_SysMinorVer,
	LIB_KrnlLibMajorVer,
	LIB_KrnlLibMinorVer,
	_T(LIB_NAME_STR),
	__ENGLISH_LANG_VER,
	_WT(LIB_DESCRIPTION_STR),
	_LIB_OS(__OS_WIN),
	_WT(LIB_Author),
	_WT(LIB_ZipCode),
	_WT(LIB_Address),
	_WT(LIB_Phone),
	_WT(LIB_Fax),
	_WT(LIB_Email),
	_WT(LIB_HomePage),
	_WT(LIB_Other),
	sizeof DataTypes / sizeof DataTypes[0],
	DataTypes,
	LIB_TYPE_COUNT,
	_WT(LIB_TYPE_STR),
	sizeof Commands / sizeof Commands[0],
	Commands,
	ExecuteCommands,
	nullptr,
	nullptr,
	hELib_ProcessNotifyLib,
	nullptr,
	nullptr,
	sizeof Consts / sizeof Consts[0],
	Consts,
	nullptr
};

#endif
