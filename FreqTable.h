#pragma once
#include"header_this.h"
#include<vector>

//����Ƶ������
class FreqTable {
public:
	FreqTable(wstring input_string);
	vector<record> getAllRecords();
private:
	vector<record> records;
	void buildTableHelp(wstring input_string);
};

//����Ƶ�����еļ�¼
struct Record {
	int freq = 0;	//�ַ����ֵĴ�����������ʱ�ǹؼ���
	wchar_t val;		//�ַ���ֵ
};
typedef struct Record record;
