#include <iostream>

using namespace std;
//定义状态函数结构体
typedef struct
{	
	int status;
	void (*p_conf)(int a);
} status_config_typedef;
void conf1(int a)
{
	cout<<"conf1"<<a<<endl;
}
void conf2(int a)
{
	cout<<"conf2"<<a<<endl;
}
status_config_typedef sct_tab[]=
{
	{0,conf1},
	{1,conf2}
};
void conf(void)
{
	for(int i=0;i<2;i++)
	{
		if(sct_tab[i].status==i)
		{
			sct_tab[i].p_conf(i);
		}
	}
}
int main(int argc, char *argv)
{
	cout << "main go" << endl;
	conf();
	cout << "main done" << endl;
	return 0;
}