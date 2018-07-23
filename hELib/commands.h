#pragma once
#include "stdafx.h"

EXTERN_C void hELibTest(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf);

#ifndef __E_STATIC_LIB

extern ARG_INFO hELibTest__CommandArgs[];
extern PFN_EXECUTE_CMD ExecuteCommands[];


static CMD_INFO Commands[] =
{
	{ _WT("test_command"), _WT("test"), _WT("test function"), 1, NULL, SDT_INT, 0, LVL_SIMPLE, 0, 0, 1, hELibTest__CommandArgs }
};

static const char* const CommandNames[] =
{
	"hELibTest"
};

#endif