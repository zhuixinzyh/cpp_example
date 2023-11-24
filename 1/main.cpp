#include <iostream>

using namespace std;


void example_show_func_name(void)
{
	cout<<"__func__: "<<__func__<<endl;
	cout<<"__PRETTY_FUNCTION__: "<<__PRETTY_FUNCTION__<<endl;
}
int main(int argc,char *argv)
{
	cout<<"main go"<<endl;
	char ch = '7';
	switch(ch){
		case '0'...'5':cout<<"xxx"<<endl;
			break;
		case '6'...'9':cout<<"yyy"<<endl;
			break;
		default:cout<<"ccc"<<endl;
			break;
	}
	cout<<"__func__: "<<__func__<<endl;//C99标准支持的 变量__func__存储函数的名字
	example_show_func_name();
	cout<<"main done"<<endl;
	return 0;
}