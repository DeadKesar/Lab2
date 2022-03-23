#pragma once
#include <string>
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <math.h>

class RimNumber
{
private:
	std::wstring rim = L"N";
	double arabNumb = 0;
	int RimToArab(std::wstring rim);
	static std::wstring FractionToRim(double num);
	static void  Paste(std::wstring& rim, std::wstring ch, int count = 1);
	RimNumber& TryToGetNumber(std::wstring s);
public:
	void SetByArab(double num);
	void CallSetFromConsole(std::wstring const mes);
	std::wstring GetRim();
	double GetArab();
	RimNumber operator+(RimNumber aRim);
	RimNumber operator-(RimNumber aRim);
	RimNumber operator*(RimNumber aRim);
	RimNumber operator/(RimNumber aRim);
	RimNumber operator+(int num);
	RimNumber operator-(int num);
	RimNumber operator*(int num);
	RimNumber operator/(int num);
	operator int();
	RimNumber& operator=(int num);
	RimNumber& operator=(RimNumber& rim);
	RimNumber& operator+=(RimNumber& aRim);
	RimNumber& operator-=(RimNumber& aRim);
	RimNumber& operator*=(RimNumber& aRim);
	RimNumber& operator/=(RimNumber& aRim);
	RimNumber& operator+=(int num);
	RimNumber& operator-=(int num);
	RimNumber& operator*=(int num);
	RimNumber& operator/=(int num);
	RimNumber& operator++();
	RimNumber operator++(int);
	RimNumber& operator--();
	RimNumber operator--(int);	   
	bool operator>(RimNumber rim);
	bool operator>(int num);
	bool operator<(RimNumber rim);
	bool operator<(int num);
	bool operator>=(RimNumber rim);
	bool operator>=(int num);
	bool operator<=(RimNumber rim);
	bool operator<=(int num);
	bool operator==(RimNumber rim);
	bool operator==(int num);
	bool operator!=(RimNumber rim);
	bool operator!=(int num);
	friend std::wostream& operator<<(std::wostream& os, RimNumber& rim);
	friend std::wistream& operator>>(std::wistream& is, RimNumber& rim);
};

