#include "osf.cpp"
void filePrint(std::string str)
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
	listAllFiles(str,filePrint);
	return 0;
}

