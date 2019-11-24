#include"header_this.h"

/*������*/
void main() {

	//�ɹ����ļ�������룬�Թ�����Ŀ�ο�
	//�ǵ��ڶ��ļ���ʱ����Ҫcatch�쳣"Error 01: File open fail!"
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
* @brief �ı��ļ����뺯��
* @param[in] path:char*	�ļ��ģ���Ի���ԣ�·��
* @return string		�ļ��е������ı�����
* @author Siyuan Huang
* @date 2019/11/24
*/
wstring text_input(char* path) {
	ifstream file_in;
	file_in.open(path, ios::_Nocreate);
	//�쳣����
	//���ļ���ʧ�ܣ����Ȳ²��û�����Ĳ���·����ֻ���ļ�������������¸��ļ�Ӧ���ڳ����ͬһĿ¼�¡�
	//����Ϊ�ļ�����ȫ·�����ٴγ��Դ򿪡�����Ȼ��ʧ�����׳��쳣��"Error 01: File open fail!"
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
	//��ȡ�ļ��Ĵ�С
	file_in.seekg(0, file_in.end);
	int length = file_in.tellg();
	file_in.seekg(0, file_in.beg);
	//���ļ��ж����ı�����
	char* buffer = new char[length];	//���ڴ�Ŵ��ı��ļ��ж��������
	file_in.read(buffer, length);
	string buffer_str;
	wstring buffer_ret;
	//����Ϣ������string�����У��������������Ա��ں����Ĳ���
	buffer_str = buffer;
	buffer_ret = ANSIToUnicode(buffer_str);
	file_in.close();
	delete[] buffer;
	//delete &buffer_str;
	return buffer_ret;
}

/*�˺������ڽ�ANSI��ʽ��stringת����UTF-16��ʽ��wstring
��Ȩ����������ΪCSDN������FlushHip����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/FlushHip/article/details/82836867
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

/*�˺������ڽ�UTF-16��ʽ��wstringת����ANSI��ʽ��string
��Ȩ����������ΪCSDN������FlushHip����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/FlushHip/article/details/82836867
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