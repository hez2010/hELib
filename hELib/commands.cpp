#include "commands.h"

#ifndef __E_STATIC_LIB

ARG_INFO hELibTest__CommandArgs[] =
{
	{ _WT("value"), _WT("test"), NULL, NULL, SDT_INT, 123, AS_HAS_DEFAULT_VALUE }
};

PFN_EXECUTE_CMD ExecuteCommands[] =
{
	hELibTest
};

#endif