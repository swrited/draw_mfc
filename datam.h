#pragma once
#include "pch.h"


template <class TYPE>
class CDatManage
{
public:
	TYPE m_num1;
	TYPE m_num2;
public:
	TYPE Add()
	{
		return m_num1 + m_num2;
	}
	void setvalue(TYPE x1, TYPE x2)
	{
		m_num1 = x1;
		m_num2 = x2;
	}
};

