#include <iostream>

using namespace std;
#define A printf("helloworld.\n");
#define B A A A A A A A A A A
#define C B B B B B B B B B B
#define D C C C C C C C C C C

#define ADD1(a,b) ((a)+(b))
#define ADD2(a,b) (a+b)
#define MUL1(a,b) (a*b)
#define MUL2(a,b) ((a)*(b))//define是在编译前的预处理阶段进行字符的替换，因此需要加括号比较好

#define LENGTH(arr_name) sizeof(arr_name)/sizeof(arr_name[0])//可以计算数组长度的宏
int main(int argc,char *argv)
{
	cout<<"main go"<<endl;
	D

	cout<<"ADD1: "<<ADD1(1,2)<<endl;
	cout<<"ADD2: "<<ADD2(1+2,3+4)<<endl;
	cout<<"ADD1: "<<ADD2(1+2,3+4)<<endl;

	cout<<"MUL1: "<<MUL1(1+2,3+4)<<endl;
	cout<<"MUL2: "<<MUL2(1+2,3+4)<<endl;

	int a[10];
	cout<<"length : "<<LENGTH(a)<<endl;
	cout<<"main done"<<endl;
	return 0;
}