#pragma once

class String 
{
public:
	static wstring ToWString(const string value);
	static string ToString(const wstring value);
};