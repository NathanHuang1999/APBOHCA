#pragma once
#include"header_this.h"
#include<vector>

//定义频数表类
class FreqTable {
public:
	FreqTable(wstring input_string);
	vector<record> getAllRecords();
private:
	vector<record> records;
	void buildTableHelp(wstring input_string);
};

//定义频数表中的记录
struct Record {
	int freq = 0;	//字符出现的次数。在排序时是关键字
	wchar_t val;		//字符的值
};
typedef struct Record record;
