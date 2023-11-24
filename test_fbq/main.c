#include <iostream>
#include <stdlib.h>
#include <stdio.h>
//#include "spdlog/spdlog.h"



using std::endl;
using std::cout;
int main(void)
{
	std::string s1;
	s1 = "ss1";
	cout<<s1<<endl;

	std::string home_path;
	home_path = getenv("HOME");
	cout<<home_path<<endl;
	
	std::string log_path;
	log_path = home_path+"/work";
	cout<<log_path<<endl;	
	if(system("echo ${HOME}")==-1)
	{
		perror("system error\n");
	}	

	cout<<"main done"<<endl;
	return 0;
}








