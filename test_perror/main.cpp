#include <iostream>
#include <error.h>
using namespace std;

#define sum(x) ((x)+(x))

int main(int argc,char *argv)
{
	cout<<"main go"<<endl;

	int ret = sum(1);
	cout<<"ret: "<<ret<<endl;

	perror("hahahas");
	cout<<"main done"<<endl;
	return 0;
}