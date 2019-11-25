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

vector<HuffmanTree<wchar_t>> buildForest(vector<record> freq_table);

void coding(HuffmanNode<wchar_t>* root, string code, vector<record_CodeTable>* codeTable);
