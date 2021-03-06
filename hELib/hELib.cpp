#include "hELib.h"
#include "elib/fnshare.cpp"

EXTERN_C INT WINAPI hELib_ProcessNotifyLib(INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if (nMsg == NL_GET_CMD_FUNC_NAMES)
		return reinterpret_cast<INT>(CommandNames);
	if (nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME)
		return reinterpret_cast<INT>("hELib_ProcessNotifyLib");
	if (nMsg == NL_GET_DEPENDENT_LIBS) return NULL;
#endif
	return ProcessNotifyLib(nMsg, dwParam1, dwParam2);
};

#ifndef __E_STATIC_LIB

PLIB_INFO WINAPI GetNewInf()
{
	return &LibInfo;
};

#endif
