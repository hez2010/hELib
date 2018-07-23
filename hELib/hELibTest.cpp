#include "commands.h"

EXTERN_C void hELibTest(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_int = pArgInf[0].m_int;
	return;
}