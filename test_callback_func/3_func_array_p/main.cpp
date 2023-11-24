#include <iostream>

using namespace std;
//定义一个数组，数组元素为函数指针
//方式1：采用typedef
typedef void (*p_func_array)(int,int);
p_func_array fa[5];
//方式2：直接定义
void (*pfa[5])(int,int);

typedef int (*func_type)(int,int);
//使用typedef定义一个函数指针类型，而不是函数指针变量
int add(int a,int b)
{
	return a+b;
}
int mult(int a,int b)
{
	return a*b;
}
void (* func5(int, int, float ))(int, int)
{//返回类型为函数指针的函数

}
void callback(func_type f,int a,int b)
{
	cout<<"callback: "<<f(a,b)<<endl;
}
int main(int argc,char *argv)
{
	cout<<"main go"<<endl;
	callback(add,1,2);
	callback(mult,2,3);

	cout<<"main done"<<endl;
	return 0;
}