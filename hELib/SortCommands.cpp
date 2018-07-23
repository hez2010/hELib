#include "commands.h"
#include <algorithm>
#include <cstring>

#ifndef __E_STATIC_LIB

ARG_INFO hELib_Sort_QuickSort__CommandArgs[] =
{
	{ _WT("pArray"), _WT("Array need to be sorted."), 0, 0, _SDT_ALL, NULL, AS_RECEIVE_VAR_ARRAY },
	{ _WT("pBegin"), _WT("Indicate the beginning position the array should be sorted, starting from 1."), 0, 0, SDT_INT, 1, AS_HAS_DEFAULT_VALUE },
	{ _WT("pEnd"), _WT("Indicate the ending position the array should be sorted, 0 represents sorting the whole array."), 0, 0, SDT_INT, 0, AS_HAS_DEFAULT_VALUE },
	{ _WT("pIsDesc"), _WT("Indicate whether array should be sorted by descending."), 0, 0, SDT_BOOL, false, AS_HAS_DEFAULT_VALUE }
};

#endif

template<typename T, bool desc>
bool sort_template(const T& a, const T& b)
{
	bool v = a > b;
	return desc ? v : !v;
}

template<typename T, bool desc>
bool sort_string_template(const T a, const T b)
{
	if (desc)
	{
		if (strcmp((char*)b, (char*)a) < 0) return true;
	}
	else
	{
		if (strcmp((char*)a, (char*)b) < 0) return true;
	}
	return false;
}

#define quick_sort(type, begin, end, ptr, desc) std::sort(\
	reinterpret_cast<type*>(ptr + (begin - 1) * sizeof(type)), \
	reinterpret_cast<type*>(ptr + end * sizeof(type)), \
	desc ? sort_template<type, true> : sort_template<type, false>)

void hELib_Sort_QuickSort(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_bool = false;
	auto end = pArgInf[2].m_int;

	auto cntAry = 0;
	auto ptr = GetAryElementInf(*pArgInf->m_ppAryData, &cntAry);
	if (end < 0) return;

	if (end == 0) end = cntAry;
	if (end > cntAry) return;
	pRetData->m_bool = true;

	switch (pArgInf[0].m_dtDataType & (~DT_IS_ARY))
	{
	case SDT_INT:
		quick_sort(int, pArgInf[1].m_int, end, ptr, pArgInf[3].m_bool);
		break;
	case SDT_INT64:
		quick_sort(long long, pArgInf[1].m_int, end, ptr, pArgInf[3].m_bool);
		break;
	case SDT_BOOL:
		quick_sort(bool, pArgInf[1].m_int, end, ptr, pArgInf[3].m_bool);
		break;
	case SDT_BYTE:
		quick_sort(byte, pArgInf[1].m_int, end, ptr, pArgInf[3].m_bool);
		break;
	case SDT_SHORT:
		quick_sort(short, pArgInf[1].m_int, end, ptr, pArgInf[3].m_bool);
		break;
	case SDT_SUB_PTR:
		quick_sort(int, pArgInf[1].m_int, end, ptr, pArgInf[3].m_bool);
		break;
	case SDT_FLOAT:
		quick_sort(float, pArgInf[1].m_int, end, ptr, pArgInf[3].m_bool);
		break;
	case SDT_DATE_TIME:
	case SDT_DOUBLE:
		quick_sort(double, pArgInf[1].m_int, end, ptr, pArgInf[3].m_bool);
		break;
	case SDT_TEXT:
		std::sort(
			reinterpret_cast<char**>(ptr + (pArgInf[1].m_int - 1) * sizeof(char*)),
			reinterpret_cast<char**>(ptr + end * sizeof(char*)),
			pArgInf[3].m_bool ? sort_string_template<char*, true> : sort_string_template<char*, false>);
		break;
	case SDT_BIN:
		std::sort(
			reinterpret_cast<byte**>(ptr + (pArgInf[1].m_int - 1) * sizeof(byte*)),
			reinterpret_cast<byte**>(ptr + end * sizeof(byte*)),
			pArgInf[3].m_bool ? sort_string_template<byte*, true> : sort_string_template<byte*, false>);
		break;
	default:
		pRetData->m_bool = false;
		break;
	}
	return;
}