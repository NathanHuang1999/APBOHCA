#pragma once

#pragma warning( disable : 4996)

#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

//函数声明
wstring text_input(char* path);
wstring ANSIToUnicode(const std::string & str);
string UnicodeToANSI(const std::wstring & wstr);

//定义频数表中的记录
struct Record {
	int freq = 0;	//字符出现的次数。在排序时是关键字
	wchar_t val;		//字符的值
};
typedef struct Record record;

//定义频数表类
class FreqTable {
public:
	FreqTable(wstring input_string);
	vector<record> getAllRecords();
private:
	vector<record> records;
	void buildTableHelp(wstring input_string);
};
