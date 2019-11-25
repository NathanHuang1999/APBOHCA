#include"header_this.h"
#include"header_classes.h"

/*
* @brief 用哈弗曼树的根节点填充空码表的函数
* @param[in] root:HuffmanNode<wchar_t>*	哈弗曼树的根节点
			code:string	编码字符串。使用时应输入空字符串""
			codeTable:vector<record_CodeTable>*	指向码表的指针
* @return void
* @author Siyuan Huang
* @date 2019/11/26
*/
void coding(HuffmanNode<wchar_t>* root, string code, vector<record_CodeTable>* codeTable) {
	if (root->isLeaf()) {
		wchar_t ch = root->val();
		record_CodeTable new_record;
		new_record.val = ch;
		new_record.code = code;
		codeTable->push_back(new_record);
		return;
	}
	else {
		coding(root->left(), code + "0", codeTable);
		coding(root->right(), code + "1", codeTable);
	}
}
