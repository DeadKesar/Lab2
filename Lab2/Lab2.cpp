//
//+//Усовершенствовать программу для автоматизации вычислений с использованием римских чисел.Реализовать:
//+//функции потокового ввода и вывода числа для консоли(операции << и >> );     
//+//перегруженные операции присваивания : присваивание для операнда типа римское число и присваивание для операнда типа int;
//+//функции простейших арифметических операций, используя перегрузку операций(+, -, *, +=, -=, *=).Операции должны также работать с типом int;      
//+//перегруженные функции инкремента : постфиксный и префиксный;  
//+//перегруженные операции сравнения другим числом и int.
//+//Усложнение №1(+1 балл).Перегрузить операцию приведения к int.      
//+//Усложнение №2(+2 балла).Обеспечить корректную работоспособность следующего выражения :
//+//Number a, b, c;                            
//+//Number d = a += (b + 10) + ++c;                                                                           
//+//Усложнение №3(+3 балла).Перегрузить функции потокового ввода и вывода числа для консоли(операции << и >> ) таким образом, чтобы они считывали и возвращали число в римском виде.  



#pragma once
#include "RimNumber.h"


double GetNumber(std::wstring s);
wchar_t GetOperator(std::wstring mes);
wchar_t GetChar(std::wstring mes);
RimNumber Calculate(RimNumber rim1, RimNumber rim2, wchar_t const operation);

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << L"Лабораторная работа №2. \nПо теме: \"Операционный полиморфизм. Перегрузка функций и операций.\"\n" <<
                    L"Вариант №1 \nВыполнил: Порядин В.С." << std::endl;
    RimNumber rim1, rim2;
    std::wcout << L"для римских цифр: работает с римскими целыми числами числами +-4000" << std::endl;
    std::wcout << L"для арабских цифр: ограничтесь +-10млн. значения больше просто заполняют экран максимальным символом." << std::endl;
    rim1.CallSetFromConsole(L"введите римское число 1: ");
    std::wcout << std::endl;
    rim2.CallSetFromConsole(L"введите римское число 2: ");
    std::wcout << std::endl;
    wchar_t operation = GetOperator(L"Выберите операцию + - * / :\n");
    RimNumber answer;
    answer.SetByArab(Calculate(rim1, rim2, operation).GetArab());
    std::wcout << rim1.GetArab() << L" " << operation << L" " << rim2.GetArab() << L" = " << answer.GetArab() << std::endl;
    std::wcout << rim1 << L" " << operation << L" " << rim2 << L" = " << answer << std::endl;
    RimNumber a, b, c;
    std::wcout << "Тестовый пример: \"d = a += (b + 10) + ++c\"" << std::endl;
    a.CallSetFromConsole(L"Введите число a= ");
    std::wcout << std::endl;
    b.CallSetFromConsole(L"Введите число b= ");
    std::wcout << std::endl;
    c.CallSetFromConsole(L"Введите число c= ");
    std::wcout << std::endl;
    RimNumber d = a += (b + 10) + ++c;
    std::wcout << L"d= " << d.GetArab() << L", a = " << a.GetArab() << L", b= " << b.GetArab() << L", c= " << c.GetArab() << std::endl;
    std::wcout << L"d= " << d << L", a = " << a << L", b= " << b << L", c= " << c << std::endl;
}
RimNumber Calculate(RimNumber rim1, RimNumber rim2, wchar_t const operation)
{
    if (operation == L'+')
    {
        return rim1 + rim2;
    }
    if (operation == L'-')
    {
        return rim1 - rim2;
    }
    if (operation == L'*')
    {
        return rim1 * rim2;
    }
    if (operation == L'/')
    {
        return rim1 / rim2;
    }
    return rim1;
}
wchar_t GetChar(std::wstring mes)
{
    wchar_t ch = L' ';
    while (true)
    {
        std::wcout << mes << std::endl;
        std::wcin >> ch;
        if (std::wcin.fail())
        {
            std::wcin.clear();
            std::wcin.ignore(32767, '\n');
            std::wcout << L"некоректное значение, попробуйте снова." << std::endl;
        }
        else
        {
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return ch;
    }
}
wchar_t GetOperator(std::wstring mes)
{
    wchar_t operation = L' ';
    while (operation != L'+' && operation != L'-' && operation != L'*' && operation != L'/')
    {
        operation = GetChar(mes);
        if (operation != L'+' && operation != L'-' && operation != L'*' && operation != L'/')
        {
            std::wcout << L"Операция не найдена, попробуйте снова.\n";
        }
    }
    return operation;
}
double GetNumber(std::wstring s)
{
    double num;
    while (true)
    {
        std::wcout << s;
        std::wcin >> num;
        if (std::wcin.fail()) //проверяем, не заблокирован ли буфер ввода, если да, значит значения ввода юыло некоректным.
        {
            std::wcin.clear(); //возвращаем буфер в обычный режим
            std::wcin.ignore(32767, '\n'); // очищаем буфер ввода
            std::wcout << L"некоректное значение, попробуйте снова" << std::endl; //просим повторный ввод
        }
        else
        {
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищаем буфер ввода от лишних символов, если таковые есть
            return num; // выходим из функции.
        }
    }
}