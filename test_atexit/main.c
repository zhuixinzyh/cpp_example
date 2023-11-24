#include <iostream>
#include <stdlib.h>

using namespace std;

static void bye(void)
{
	cout<<"good bye"<<endl;
}

int main(int argc,char *argv[])
{
	cout<<"argc : "<<argc<<endl;
	for(int i=0;i<argc;i++)
	{
		cout<<argv[i]<<endl;
	}
	
	cout<<" done "<<endl;
	
	if(atexit(bye))
	{
		cout<<"set exit function failed"<<endl;
		return -1;
	}
	
	
	return 0;
}







