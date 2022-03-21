#pragma once
#include <string>
#include <iostream>
#include <fcntl.h>
#include <io.h>

class RimNumber
{
private:
	std::wstring rim = L"N";
	double arabNumb = 0;
	int RimToArab(std::wstring rim);
	static std::wstring FractionToRim(double num);
	static void  Paste(std::wstring& rim, std::wstring ch, int count = 1);
public:
	void SetByArab(double num);
	void CallSetFromConsole(std::wstring const mes);
	std::wstring GetRim();
	double GetArab();
	RimNumber operator+(RimNumber aRim);
	RimNumber operator-(RimNumber aRim);
	RimNumber operator*(RimNumber aRim);
	RimNumber operator/(RimNumber aRim);
};

