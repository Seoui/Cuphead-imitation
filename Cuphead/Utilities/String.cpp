#include "stdafx.h"
#include "String.h"

wstring String::ToWString(const string value)
{
	wstring temp = L"";
	temp.assign(value.cbegin(), value.cend());

	return temp;
}

string String::ToString(const wstring value)
{
	string temp = "";
	temp.assign(value.cbegin(), value.cend());

	return temp;
}
