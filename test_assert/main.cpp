#include <iostream>


#define NDEBUG //定义这个宏可以失能assert,放开就是失能断言，打开就是使能断言
//断言只用在调试阶段，用于捕捉想要的情况下的错误。在发行版本的软件中，不能使用断言
//如果在发行版本中还是想检查错误并推出，那应该用return  exit 等方法
#include <assert.h>
using namespace std;

void diva(int a,int b)
{
	assert(a!=0);
	//cout<<"div: "<<b/a<<endl;
}


int main(int argc,char *argv)
{
	cout<<"main go"<<endl;
	diva(1,2);
	diva(0,2);
	cout<<"main done"<<endl;
	return 0;
}