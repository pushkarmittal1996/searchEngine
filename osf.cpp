#include<dirent.h>
#include<iostream>
#include<fstream>
using namespace std;
static void filePrint(string str)
{	
	ifstream fs(str.c_str());
	if(!fs.is_open())
		return ;
	cout<<"-----file:"<<str<<"\n";
	while(!fs.eof())
	{
		string g;
		getline(fs,g);
		cout<<str<<" "<<g<<endl;
	}
	fs.close();
}
void listAllFiles(string str,void (*fileParse)(string))
{
	DIR * dir;
	struct dirent *ent;
	if((dir = opendir(str.c_str()))!= NULL )
	{
		while((ent = readdir(dir)) != NULL)
		{
			string r(ent->d_name);
			if(r.size()>0 && r[0] == '.')
				continue;
			listAllFiles(str + "/" + string(ent->d_name),fileParse);
		}
		closedir(dir);
	}
	else
	{
		(*fileParse)(str);
	}
}
int main()
{
	string str;
	str = "/gitrepo";
	listAllFiles(str,filePrint);
	return 0;
}
