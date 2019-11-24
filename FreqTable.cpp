#include"header_this.h"

/*构造函数：输入字符串产生频数表并储存在类内*/
FreqTable::FreqTable(wstring input_string) {
	buildTableHelp(input_string);
}

/*私有的产生根据字符串频数表的函数*/
void FreqTable::buildTableHelp(wstring input_string) {
	int length_str = input_string.length();		//记录输入字符串的长度，以供后续遍历使用
	//遍历整个字符串，构建频数表
	for (int iter_str = 0;iter_str < length_str;iter_str++) {
		wchar_t curr = input_string[iter_str];
		int length_vec = records.size();
		bool inTable = false;		//用来记录当前字符是否在频数表中，初始化为false
		//遍历当前的频数表，若当前字符在频数表中则对应记录的频数+1
		for (int iter_vec = 0;iter_vec < length_vec;iter_vec++) {
			if (curr == records[iter_vec].val) {
				inTable = true;
				records[iter_vec].freq += 1;
				break;
			}
		}
		//若遍历全表都未找到，则创建新的纪录并添加到表的末尾
		if (inTable == false) {
			record new_record;		//新的记录
			new_record.val = curr;
			new_record.freq = 1;
			records.push_back(new_record);
		}
	}
}

/*返回产生的码表中的所有记录（以vector形式组织起来）*/
vector<record> FreqTable::getAllRecords() {
	return records;
}