#include "commands.h"

#ifndef __E_STATIC_LIB

ARG_INFO hELibTest__CommandArgs[] =
{
	{_WT("value"), _WT("test"), NULL, NULL, SDT_INT, 123, AS_HAS_DEFAULT_VALUE}
};

#endif

EXTERN_C void hELibTest(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = pArgInf[0].m_int;
}
