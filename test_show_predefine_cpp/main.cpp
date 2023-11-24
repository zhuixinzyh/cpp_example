#include <iostream>

using namespace std;

void example_show_func_name(void)
{
	cout << "__func__: " << __func__ << endl;
	cout << "__PRETTY_FUNCTION__: " << __PRETTY_FUNCTION__ << endl;
	cout << "__FILE__	  : " << __FILE__ << endl;	 // 文件名称
	cout << "__DATE__	  : " << __DATE__ << endl;	 // 编译日期
	cout << "__TIME__	  : " << __TIME__ << endl;	 // 编译时间的字符串
	cout << "__cplusplus : " << __cplusplus << endl; // 编译器的版本号
	cout << "__LINE__	  : " << __LINE__ << endl;	 // 编译的行号
}
int main(int argc, char *argv)
{
	cout << "main go" << endl;
	char ch = '7';
	switch (ch)
	{
	case '0' ... '5':
		cout << "xxx" << endl;
		break;
	case '6' ... '9':
		cout << "yyy" << endl;
		break;
	default:
		cout << "ccc" << endl;
		break;
	}
	cout << "__func__: " << __func__ << endl; // C99标准支持的 变量__func__存储函数的名字
	example_show_func_name();
	cout << "main done" << endl;
	return 0;
}