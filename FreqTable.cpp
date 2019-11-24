#include"header_this.h"

/*���캯���������ַ�������Ƶ��������������*/
FreqTable::FreqTable(wstring input_string) {
	buildTableHelp(input_string);
}

/*˽�еĲ��������ַ���Ƶ����ĺ���*/
void FreqTable::buildTableHelp(wstring input_string) {
	int length_str = input_string.length();		//��¼�����ַ����ĳ��ȣ��Թ���������ʹ��
	//���������ַ���������Ƶ����
	for (int iter_str = 0;iter_str < length_str;iter_str++) {
		wchar_t curr = input_string[iter_str];
		int length_vec = records.size();
		bool inTable = false;		//������¼��ǰ�ַ��Ƿ���Ƶ�����У���ʼ��Ϊfalse
		//������ǰ��Ƶ��������ǰ�ַ���Ƶ���������Ӧ��¼��Ƶ��+1
		for (int iter_vec = 0;iter_vec < length_vec;iter_vec++) {
			if (curr == records[iter_vec].val) {
				inTable = true;
				records[iter_vec].freq += 1;
				break;
			}
		}
		//������ȫ��δ�ҵ����򴴽��µļ�¼����ӵ����ĩβ
		if (inTable == false) {
			record new_record;		//�µļ�¼
			new_record.val = curr;
			new_record.freq = 1;
			records.push_back(new_record);
		}
	}
}

/*���ز���������е����м�¼����vector��ʽ��֯������*/
vector<record> FreqTable::getAllRecords() {
	return records;
}