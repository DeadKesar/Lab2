#pragma once
#include "RimNumber.h"

void RimNumber::Paste(std::wstring& rim, std::wstring ch, int count)
{
    for (int i = 0; i < count; i++)
    {
        rim += ch;
    }
}
int RimNumber::RimToArab(std::wstring rim)
{
    if (rim.length() == 1 && std::toupper(rim[0]) == L'N')
    {
        return 0;
    }
    int num = 0, countI = 0, countV = 0, countX = 0, countL = 0, countC = 0, countD = 0, countM = 0, countIV = 0,
        countIX = 0, countXL = 0, countXC = 0, countCD = 0, countCM = 0;
    for (int i = 0, length = rim.length(); i < length; i++)
    {

        switch (std::toupper(rim[i]))
        {
        case (L'-'):
        {
            break;
        }
        case (L'I'):
        {
            if (i + 1 < length && std::toupper(rim[i + 1]) == L'V')
            {
                num -= 2;
                countI--;
                countIV++;
            }
            if (i + 1 < length && std::toupper(rim[i + 1]) == L'X')
            {
                num -= 2;
                countI--;
                countIX++;
            }
            if (i + 1 < length && (std::toupper(rim[i + 1]) == L'L' || std::toupper(rim[i + 1]) == L'C' || std::toupper(rim[i + 1]) == L'D' || std::toupper(rim[i + 1]) == L'M'))
            {
                return -1;
            }
            num += 1;
            countI++;
            break;
        }
        case (L'V'):
        {
            if (i + 1 < length && (std::toupper(rim[i + 1]) == 'X' || std::toupper(rim[i + 1]) == 'L' || std::toupper(rim[i + 1]) == 'C' || std::toupper(rim[i + 1]) == 'D' || std::toupper(rim[i + 1]) == 'M'))
            {
                return -1;
            }
            num += 5;
            countV++;
            break;
        }
        case (L'X'):
        {
            if (i + 1 < length && std::toupper(rim[i + 1]) == L'L')
            {
                num -= 20;
                countX--;
                countXL++;
            }
            if (i + 1 < length && std::toupper(rim[i + 1]) == L'C')
            {
                num -= 20;
                countX--;
                countXC++;
            }
            if (i + 1 < length && (std::toupper(rim[i + 1]) == L'D' || std::toupper(rim[i + 1]) == L'M'))
            {
                return -1;
            }
            num += 10;
            countX++;
            break;
        }
        case (L'L'):
        {
            if (i + 1 < length && (std::toupper(rim[i + 1]) == L'C' || std::toupper(rim[i + 1]) == L'D' || std::toupper(rim[i + 1]) == L'M'))
            {
                return -1;
            }
            num += 50;
            countL++;
            break;
        }
        case (L'C'):
        {
            if (i + 1 < length && std::toupper(rim[i + 1]) == L'D')
            {
                num -= 200;
                countC--;
                countCD++;
            }
            if (i + 1 < length && std::toupper(rim[i + 1]) == L'M')
            {
                num -= 200;
                countC--;
                countCM++;
            }
            num += 100;
            countC++;
            break;
        }
        case (L'D'):
        {
            num += 500;
            countD++;
            break;
        }
        case (L'M'):
        {
            num += 1000;
            countM++;
            break;
        }
        default:
            return -1;
            break;
        }
    }
    //�������� ������ ���������� �������� �����: ������� ����� �� ����� ����� �������� ����� ������� ������ ����� ����� ����������� �������
    // ����������, ��� �������� ����� �� ����� ������� ����� �������, � ����� ��������.
    //
    if (countI > 3 || countV > 1 || countX > 3 || countL > 1 || countC > 3 || countD > 1 || countM > 3 ||
        countIV > 1 || countIX > 1 || countXL > 1 || countXC > 1 || countCD > 1 || countCM > 1 ||
        (countIV == 1 && countIX == 1) || (countIV == 0 && countIX == 1 && countV > 0) ||
        (countXL == 1 && countXC == 1) || (countXL == 0 && countXC == 1 && countL > 0) ||
        (countCD == 1 && countCM == 1) || (countCD == 0 && countCM == 1 && countD > 0) ||
        (countIX == 1 && countI > 0) || (countIV == 1 && countI > 0) ||
        (countXC == 1 && countX > 0) || (countXL == 1 && countXC > 0) ||
        (countCM == 1 && countC > 0) || (countCD == 1 && countC > 0))
    {
        return -1;
    }
    return num;
}
std::wstring RimNumber::FractionToRim(double num)
{
    std::wstring answer = L"";
    while (num >= 1.0 / 1728)
    {
        if ((num - 1.0 / 2) >= 0)
        {
            Paste(answer, L"S");
            num -= 1.0 / 2;
        }
        else if ((num - 1.0 / 6) >= 0)
        {
            Paste(answer, L"\u2022");
            num -= 1.0 / 6;
        }
        else if ((num - 1.0 / 8) >= 0)
        {
            Paste(answer, L"f");
            num -= 1.0 / 8;
        }
        else if ((num - 1.0 / 24) >= 0)
        {
            Paste(answer, L"\u03A3");
            num -= 1.0 / 24;
        }
        else if ((num - 1.0 / 36) >= 0)
        {
            Paste(answer, L"\u01A7");
            num -= 1.0 / 36;
        }
        else if ((num - 1.0 / 48) >= 0)
        {
            Paste(answer, L"\u0186");
            num -= 1.0 / 48;
        }
        else if ((num - 1.0 / 72) >= 0)
        {
            Paste(answer, L"\u01A7\u01A7");
            num -= 1.0 / 72;
        }
        else if ((num - 1.0 / 144) >= 0)
        {
            Paste(answer, L"$");
            num -= 1.0 / 144;
        }
        else if ((num - 1.0 / 288) >= 0)
        {
            Paste(answer, L"\u2108");
            num -= 1.0 / 288;
        }
        else if ((num - 1.0 / 1728) >= 0)
        {
            Paste(answer, L"\u00BB");
            num -= 1.0 / 1728;
        }
    }
    return answer;
}
void RimNumber::SetByArab(double numb)
{
    arabNumb = numb;
    std::wstring answer = L"";
    bool isMinus = false;
    if (numb == 0)
    {
        answer = L"N";
    }
    if (numb < 0)
    {
        isMinus = true;
        Paste(answer, L"-");
        numb *= (-1);
    }
    int num = (int)numb;
    if (num / 100000 > 0)
    {
        Paste(answer, L"\u2188 ", num / 100000);
        num %= 100000;
    }
    if (num / 90000 > 0)
    {
        Paste(answer, L"\u2182 \u2188", num / 90000);
        num %= 90000;
    }
    if (num / 50000 > 0)
    {
        Paste(answer, L"\u2187 ", num / 50000);
        num %= 50000;
    }
    if (num / 40000 > 0)
    {
        Paste(answer, L"\u2182 \u2187 ", num / 40000);
        num %= 40000;
    }
    if (num / 10000 > 0)
    {
        Paste(answer, L"\u2182 ", num / 10000);
        num %= 10000;
    }
    if (num / 9000 > 0)
    {
        Paste(answer, L"\u2180 \u2182 ", num / 9000);
        num %= 9000;
    }
    if (num / 5000 > 0)
    {
        Paste(answer, L"\u2181 ", num / 5000);
        num %= 5000;
    }
    if (num / 4000 > 0)
    {
        Paste(answer, L"\u2180 \u2181 ", num / 4000);
        num %= 4000;
    }
    if (num / 1000 > 0)
    {
        Paste(answer, L"M", num / 1000);
        num %= 1000;
    }
    if (num / 900 > 0)
    {
        Paste(answer, L"CM", num / 900);
        num %= 900;
    }
    if (num / 500 > 0)
    {
        Paste(answer, L"D", num / 500);
        num %= 500;
    }
    if (num / 400 > 0)
    {
        Paste(answer, L"CD", num / 400);
        num %= 400;
    }
    if (num / 100 > 0)
    {
        Paste(answer, L"C", num / 100);
        num %= 100;
    }
    if (num / 90 > 0)
    {
        Paste(answer, L"XC", num / 90);
        num %= 90;
    }
    if (num / 50 > 0)
    {
        Paste(answer, L"L", num / 50);
        num %= 50;
    }
    if (num / 40 > 0)
    {
        Paste(answer, L"XL", num / 40);
        num %= 40;
    }

    if (num / 10 > 0)
    {
        Paste(answer, L"X", num / 10);
        num %= 10;
    }
    if (num / 9 > 0)
    {
        Paste(answer, L"IX", num / 9);
        num %= 9;
    }
    if (num / 5 > 0)
    {
        Paste(answer, L"V", num / 5);
        num %= 5;
    }
    else if (num / 4 > 0)
    {
        Paste(answer, L"IV", num / 4);
        num %= 4;
    }
    if (num >= 1)
    {
        Paste(answer, L"I", num / 1);
        num--;
    }
    if (numb - (int)numb > 0)
    {
        answer += FractionToRim(numb - (int)numb);
    }
    rim = answer;
}
void RimNumber::CallSetFromConsole(std::wstring const mes)
{
    arabNumb = -1;
    while (arabNumb == -1)
    {
        std::wcout << (mes);
        std::getline(std::wcin, rim);
        arabNumb = RimToArab(rim);
        if (arabNumb == -1)
        {
            std::wcout << (L"\n �������� ����� - ����������, ���������� �����. \n");
        }
    }
    if (rim[0] == '-')
    {
        arabNumb *= -1;
    }
}
std::wstring RimNumber::GetRim()
{
    return this->rim;
}
double RimNumber::GetArab()
{
    return this->arabNumb;
}
RimNumber RimNumber::operator+(RimNumber aRim)
{
    RimNumber temp;
    temp.SetByArab(this->arabNumb + aRim.arabNumb);
    return temp;
}
RimNumber RimNumber::operator-(RimNumber aRim)
{
    RimNumber temp;
    temp.SetByArab(this->arabNumb - aRim.arabNumb);
    return temp;
}
RimNumber RimNumber::operator*(RimNumber aRim)
{
    RimNumber temp;
    temp.SetByArab(this->arabNumb * aRim.arabNumb);
    return temp;
}
RimNumber RimNumber::operator/(RimNumber aRim)
{
    RimNumber temp;
    if (aRim.arabNumb == 0)
    {
        std::wcout << L"������ �� 0 ������." << std::endl;
        temp.SetByArab(0);
        return temp;
    }
    temp.SetByArab(this->arabNumb + aRim.arabNumb);
    return temp;
}