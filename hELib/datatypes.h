#pragma once
#include "stdafx.h"

#ifndef __E_STATIC_LIB

extern LIB_DATA_TYPE_ELEMENT testType[14];

static LIB_DATA_TYPE_INFO DataTypes[] =
{
	{
		_WT("testDataType"), _WT("testDataType"), _WT("test data type"), 0, nullptr, NULL, 0, 0, nullptr, 0, nullptr,
		nullptr, sizeof testType / sizeof testType[0], testType
	}
};

#endif
