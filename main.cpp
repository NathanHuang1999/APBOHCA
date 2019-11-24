#include"header_this.h"

/*主函数*/
void main() {

	//成功的文件读入代码，以供本项目参考
	//记得在读文件的时候需要catch异常"Error 01: File open fail!"
	/*string path;
	cout << "Please enter the name of the file you want to open:" << endl;
	cin >> path;
	wstring inputed_string = text_input((char*)path.c_str());
	wcout << inputed_string << endl;
	FreqTable table_toolman(inputed_string);
	vector<record> table = table_toolman.getAllRecords();
	*/
}

/*
* @brief 文本文件读入函数
* @param[in] path:char*	文件的（相对或绝对）路径
* @return string		文件中的所有文本内容
* @author Siyuan Huang
* @date 2019/11/24
*/
wstring text_input(char* path) {
	ifstream file_in;
	file_in.open(path, ios::_Nocreate);
	//异常处理
	//若文件打开失败，则先猜测用户输入的不是路径而只有文件名，这种情况下该文件应处于程序的同一目录下。
	//所以为文件名补全路径并再次尝试打开。若仍然打开失败则抛出异常："Error 01: File open fail!"
	if (!file_in.is_open()) {
		string path_sub;
		string filename = path;
		path_sub = "./" + filename;
		file_in.open(path_sub, ios::_Nocreate);
		if (!file_in.is_open()) {
			throw "Error 01: File open fail!";
			return NULL;
		}
	}
	//获取文件的大小
	file_in.seekg(0, file_in.end);
	int length = file_in.tellg();
	file_in.seekg(0, file_in.beg);
	//从文件中读入文本数据
	char* buffer = new char[length];	//用于存放从文本文件中读入的内容
	file_in.read(buffer, length);
	string buffer_str;
	wstring buffer_ret;
	//将信息储存在string对象中，利用其良好特性便于后续的操作
	buffer_str = buffer;
	buffer_ret = ANSIToUnicode(buffer_str);
	file_in.close();
	delete[] buffer;
	//delete &buffer_str;
	return buffer_ret;
}

/*此函数用于将ANSI格式的string转换成UTF-16格式的wstring
版权声明：本文为CSDN博主「FlushHip」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/FlushHip/article/details/82836867
*/
wstring ANSIToUnicode(const std::string & str) {
	setlocale(LC_CTYPE, "");
	wstring ret;
	mbstate_t state = {};
	const char *src = str.data();
	size_t len = mbsrtowcs(nullptr, &src, 0, &state);
	if (static_cast<size_t>(-1) != len) {
		unique_ptr< wchar_t[] > buff(new wchar_t[len + 1]);
		len = mbsrtowcs(buff.get(), &src, len, &state);
		if (static_cast<size_t>(-1) != len) {
			ret.assign(buff.get(), len);
		}
	}
	return ret;
}

/*此函数用于将UTF-16格式的wstring转换成ANSI格式的string
版权声明：本文为CSDN博主「FlushHip」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/FlushHip/article/details/82836867
*/
string UnicodeToANSI(const std::wstring & wstr) {
	setlocale(LC_CTYPE, "");
	string ret;
	mbstate_t state = {};
	const wchar_t *src = wstr.data();
	size_t len = wcsrtombs(nullptr, &src, 0, &state);
	if (static_cast<size_t>(-1) != len) {
		unique_ptr< char[] > buff(new char[len + 1]);
		len = wcsrtombs(buff.get(), &src, len, &state);
		if (static_cast<size_t>(-1) != len) {
			ret.assign(buff.get(), len);
		}
	}
	return ret;
}