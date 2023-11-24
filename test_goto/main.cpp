#include <iostream>

using namespace std;



int main(int argc,char *argv)
{
	cout<<"main go"<<endl;
	int ch = 0;
	while(true)
	{
		ch++;
		if(ch==3)
			break;
		cout<<"ch: "<<ch<<endl;
		if(ch==1)
			goto n1;
		else if(ch==2) 
			goto n2;
		n1:
			cout<<"n1"<<endl;
		n2:
			cout<<"n2"<<endl;
	}
	cout<<"main done"<<endl;
	return 0;
}