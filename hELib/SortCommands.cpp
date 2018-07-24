#include "commands.h"
#include <algorithm>
#include <cstring>

#ifndef __E_STATIC_LIB

ARG_INFO hELib_Sort_QuickSort__CommandArgs[] =
{
	{
		_WT("pArray"), _WT("Array need to be sorted."), 0, 0, _SDT_ALL, NULL, AS_RECEIVE_VAR_ARRAY
	},
	{
		_WT("pBegin"), _WT("Indicate the beginning position the array should be sorted, starting from 1."), 0, 0,
		SDT_INT, 1, AS_HAS_DEFAULT_VALUE
	},
	{
		_WT("pEnd"),
		_WT("Indicate the ending position the array should be sorted, 0 represents sorting the whole array."), 0, 0,
		SDT_INT, 0, AS_HAS_DEFAULT_VALUE
	},
	{
		_WT("pIsDesc"), _WT("Indicate whether array should be sorted by descending."), 0, 0, SDT_BOOL, false,
		AS_HAS_DEFAULT_VALUE
	},
	{
		_WT("pCompFunc"), _WT("Provide the custom comparing function, if this parameter is provided, parameter [pIsDesc] will be ignored."), 0, 0, SDT_SUB_PTR, NULL,
		AS_DEFAULT_VALUE_IS_EMPTY
	}
};

#endif

template <typename T>
constexpr void sortArray(LPBYTE ptr, int begin, int end, bool isDesc, DWORD compFuncAddr = NULL)
{
	if (compFuncAddr == NULL)
		std::sort(reinterpret_cast<T*>(ptr) + begin - 1, reinterpret_cast<T*>(ptr) + end,
		          [isDesc](const T& a, const T& b) -> bool
		          {
			          return isDesc ? (a > b) : (a < b);
		          });
	else
	{
		typedef BOOL (__stdcall *compFunc)(const T&, const T&);
		std::sort(reinterpret_cast<T*>(ptr) + begin - 1, reinterpret_cast<T*>(ptr) + end,
		          reinterpret_cast<compFunc>(compFuncAddr));
	}
};

void hELib_Sort_QuickSort(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_bool = false;
	auto end = pArgInf[2].m_int;

	auto cntAry = 0;
	const auto ptr = GetAryElementInf(*pArgInf[0].m_ppAryData, &cntAry);
	if (end < 0) return;

	if (end == 0) end = cntAry;
	if (end > cntAry) return;
	pRetData->m_bool = true;

	const auto hasCompFunc = pArgInf[4].m_dwSubCodeAdr != NULL;

	switch (pArgInf[0].m_dtDataType & ~DT_IS_ARY)
	{
	case SDT_INT:
		sortArray<INT>(ptr, pArgInf[1].m_int, end, pArgInf[3].m_bool, pArgInf[4].m_dwSubCodeAdr);
		break;
	case SDT_INT64:
		sortArray<INT64>(ptr, pArgInf[1].m_int, end, pArgInf[3].m_bool, pArgInf[4].m_dwSubCodeAdr);
		break;
	case SDT_BOOL:
		sortArray<BOOL>(ptr, pArgInf[1].m_int, end, pArgInf[3].m_bool, pArgInf[4].m_dwSubCodeAdr);
		break;
	case SDT_BYTE:
		sortArray<BYTE>(ptr, pArgInf[1].m_int, end, pArgInf[3].m_bool, pArgInf[4].m_dwSubCodeAdr);
		break;
	case SDT_SHORT:
		sortArray<SHORT>(ptr, pArgInf[1].m_int, end, pArgInf[3].m_bool, pArgInf[4].m_dwSubCodeAdr);
		break;
	case SDT_SUB_PTR:
		sortArray<DWORD>(ptr, pArgInf[1].m_int, end, pArgInf[3].m_bool, pArgInf[4].m_dwSubCodeAdr);
		break;
	case SDT_FLOAT:
		sortArray<FLOAT>(ptr, pArgInf[1].m_int, end, pArgInf[3].m_bool, pArgInf[4].m_dwSubCodeAdr);
		break;
	case SDT_DATE_TIME:
		sortArray<DATE>(ptr, pArgInf[1].m_int, end, pArgInf[3].m_bool, pArgInf[4].m_dwSubCodeAdr);
		break;
	case SDT_DOUBLE:
		sortArray<DOUBLE>(ptr, pArgInf[1].m_int, end, pArgInf[3].m_bool, pArgInf[4].m_dwSubCodeAdr);
		break;
	case SDT_TEXT:
		if (hasCompFunc)
		{
			typedef BOOL(__stdcall *compFunc)(char*, char*);
			std::sort(
				reinterpret_cast<char**>(ptr) + pArgInf[1].m_int - 1,
				reinterpret_cast<char**>(ptr) + end,
				reinterpret_cast<compFunc>(pArgInf[4].m_dwSubCodeAdr)
			);
		}
		else
		{
			std::sort(
				reinterpret_cast<char**>(ptr + (pArgInf[1].m_int - 1) * sizeof(char*)),
				reinterpret_cast<char**>(ptr + end * sizeof(char*)),
				[pArgInf](char* & a, char* & b) -> bool
				{
					if (pArgInf[3].m_bool)
					{
						if (strcmp(b, a) < 0) return true;
					}
					else
					{
						if (strcmp(a, b) < 0) return true;
					}
					return false;
				});
		}
		break;
	case SDT_BIN:
		if (hasCompFunc)
		{
			typedef BOOL(__stdcall *compFunc)(byte*, byte*);
			std::sort(
				reinterpret_cast<byte**>(ptr) + pArgInf[1].m_int - 1,
				reinterpret_cast<byte**>(ptr) + end,
				reinterpret_cast<compFunc>(pArgInf[4].m_dwSubCodeAdr)
			);
		}
		else
		{
			std::sort(
				reinterpret_cast<byte**>(ptr + (pArgInf[1].m_int - 1) * sizeof(byte*)),
				reinterpret_cast<byte**>(ptr + end * sizeof(byte*)),
				[pArgInf](byte* & a, byte* & b) -> bool
				{
					if (pArgInf[3].m_bool)
					{
						if (strcmp(reinterpret_cast<char*>(b), reinterpret_cast<char*>(a)) < 0) return true;
					}
					else
					{
						if (strcmp(reinterpret_cast<char*>(a), reinterpret_cast<char*>(b)) < 0) return true;
					}
					return false;
				});
		}
		break;
	default:
		if (hasCompFunc)
		{
			typedef BOOL(__stdcall *compFunc)(int*, int*);
			std::sort(
				reinterpret_cast<int**>(ptr) + pArgInf[1].m_int - 1,
				reinterpret_cast<int**>(ptr) + end,
				reinterpret_cast<compFunc>(pArgInf[4].m_dwSubCodeAdr)
			);
		}
		else pRetData->m_bool = false;
		break;
	}
}
