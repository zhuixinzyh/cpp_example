#include <iostream>

using namespace std;
int foo1(int a,int b)
{

	cout<<"foo1: "<<"a is "<<a<<" , b is "<<b<<endl;
	return a+b;
}
int main(int argc,char *argv)
{
	cout<<"main go"<<endl;
	//////////////////////////简单的函数指针使用
	int (*p)(int,int);
	p=foo1;//p=&foo1;//因为函数名就是地址，所以这两种方式都对
	cout<<p(1,2)<<endl;//cout<<(*p)(1,2)<<endl;//为函数名就是地址，所以这两种方式都对
	

	cout<<"main done"<<endl;
	return 0;
}