#include"header_this.h"
#include"header_classes.h"

/*
* @brief 用频数表建立森林的函数
* @param[in] freq_table:vector<record>	频数表
* @return vector<HuffmanTree<wchar_t>>	哈弗曼树组成的森林
* @author Siyuan Huang
* @date 2019/11/25
*/
vector<HuffmanTree<wchar_t>> buildForest(vector<record> freq_table) {
	int size = freq_table.size();			//记录输入的频数表的大小
	vector<HuffmanTree<wchar_t>> forest;
	//遍历频数表，产生森林
	for (int iter = 0;iter < size;iter++) {
		forest.push_back(HuffmanTree<wchar_t>(freq_table[iter].val, freq_table[iter].freq));
	}
	return forest;
}
