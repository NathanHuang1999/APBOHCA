#pragma once

#pragma warning(disable : 4996)

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//函数声明
wstring text_input(char* path);
wstring ANSIToUnicode(const std::string & str);
string UnicodeToANSI(const std::wstring & wstr);
