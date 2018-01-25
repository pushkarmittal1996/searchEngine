#include "osf.cpp"
#include<iostream>
#include<fstream>
void filePrint(std::string& str)
{	
	std::ifstream fs(str.c_str());
	if(!fs.is_open())
		return ;
	std::cout<<"-----file:"<<str<<"\n";
	while(!fs.eof())
	{
		std::string g;
		getline(fs,g);
		std::cout<<str<<" "<<g<<"\n";
	}
	fs.close();
}
using namespace std;
int main()
{
	string str;
	str = "/gitrepo";
	//listAllFiles(str,filePrint);
	string g = "my*name$%^&is<>?,./gaurav";
	replaceString(g,"!@#$%^&*()_+-={}|[]\\:\"';:<>?,./",'_');
	cout<<"\n\n"<<g<<"\n\n";
	string a1 = "demonetization";
	string a2 = "relaxing";
	string a3 = "king";
	cout<<StemEnglish(a1)<<"\n";
	cout<<StemEnglish(a2)<<"\n";
	cout<<StemEnglish(a3)<<"\n";
	return 0;
}

