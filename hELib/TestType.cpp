#include "datatypes.h"
#ifndef __E_STATIC_LIB

LIB_DATA_TYPE_ELEMENT testType[] =
{
	{SDT_INT, nullptr,_T("next_in"), _T("next_in"), _T("next_in"), NULL, 0,},
	{SDT_INT, nullptr,_T("avail_in"), _T("avail_in"), _T("avail_in"), NULL, 0,},
	{SDT_INT, nullptr,_T("total_in"), _T("total_in"), _T("total_in"), NULL, 0,},
	{SDT_INT, nullptr,_T("next_out"), _T("next_out"), _T("next_out"), NULL, 0,},
	{SDT_INT, nullptr,_T("avail_out"), _T("avail_out"), _T("avail_out"), NULL, 0,},
	{SDT_INT, nullptr,_T("total_out"), _T("total_out"), _T("total_out"), NULL, 0,},
	{SDT_INT, nullptr,_T("msg"), _T("msg"), _T("msg"), NULL, 0,},
	{SDT_INT, nullptr,_T("state"), _T("state"), _T("state"), NULL, 0,},
	{SDT_INT, nullptr,_T("zalloc"), _T("zalloc"), _T("zalloc"), NULL, 0,},
	{SDT_INT, nullptr,_T("zfree"), _T("zfree"), _T("zfree"), NULL, 0,},
	{SDT_INT, nullptr,_T("opaque"), _T("opaque"), _T("opaque"), NULL, 0,},
	{SDT_INT, nullptr,_T("data_type"), _T("data_type"), _T("data_type"), NULL, 0,},
	{SDT_INT, nullptr,_T("adler"), _T("adler"), _T("adler"), NULL, 0,},
	{SDT_INT, nullptr,_T("reserved"), _T("reserved"), _T("reserved"), NULL, 0,}
};

#endif
