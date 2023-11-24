#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc,char *argv[])
{
	cout<<"argc is :"<<argc<<endl;
		
	int cnt=0;
	
	for(;;)
	{
		cout<<"cnt: "<<cnt<<endl;
		cnt++;
		sleep(1);
	}
	
	
	
	exit(0);
}






