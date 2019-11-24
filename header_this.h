#pragma once

#pragma warning( disable : 4996)

#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

//��������
wstring text_input(char* path);
wstring ANSIToUnicode(const std::string & str);
string UnicodeToANSI(const std::wstring & wstr);

//����Ƶ�����еļ�¼
struct Record {
	int freq = 0;	//�ַ����ֵĴ�����������ʱ�ǹؼ���
	wchar_t val;		//�ַ���ֵ
};
typedef struct Record record;

//����Ƶ������
class FreqTable {
public:
	FreqTable(wstring input_string);
	vector<record> getAllRecords();
private:
	vector<record> records;
	void buildTableHelp(wstring input_string);
};
