﻿#pragma once
#include "stdafx.h"

EXTERN_C void hELibTest(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf);
EXTERN_C void hELib_Sort_QuickSort(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf);

#ifndef __E_STATIC_LIB

extern ARG_INFO hELibTest__CommandArgs[1];
extern ARG_INFO hELib_Sort_QuickSort__CommandArgs[5];

extern PFN_EXECUTE_CMD ExecuteCommands[];

static CMD_INFO Commands[] =
{
	{
		_WT("test_command"), _WT("test"), _WT("test function"), 1, NULL, SDT_INT, 0, LVL_SIMPLE, 0, 0,
		sizeof hELibTest__CommandArgs / sizeof hELibTest__CommandArgs[0],
		hELibTest__CommandArgs
	},
	{
		_WT("hELib_Sort_QuickSort"), _WT("hELib_Sort_QuickSort"), _WT("Providing quick-sort algorithm to sort array."),
		1, NULL, SDT_BOOL, 0, LVL_HIGH, 0, 0,
		sizeof hELib_Sort_QuickSort__CommandArgs / sizeof hELib_Sort_QuickSort__CommandArgs[0],
		hELib_Sort_QuickSort__CommandArgs
	}
};

static const char* const CommandNames[] =
{
	"hELibTest",
	"hELib_Sort_QuickSort"
};

#endif
