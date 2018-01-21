#pragma once
#include<dirent.h>
#include<iostream>
#include<fstream>
#ifndef osf_cpp
void listAllFiles(std::string str,void (*fileParse)(std::string))
{
	DIR * dir;
	struct dirent *ent;
	if((dir = opendir(str.c_str()))!= NULL )
	{
		while((ent = readdir(dir)) != NULL)
		{
			std::string r(ent->d_name);
			if(r.size()>0 && r[0] == '.')
				continue;
			listAllFiles(str + "/" + std::string(ent->d_name),fileParse);
		}
		closedir(dir);
	}
	else
	{
		(*fileParse)(str);
	}
}
#endif
/*
usage example
int main()
{
	string str;
	str = "/gitrepo";
	listAllFiles(str,filePrint);
	return 0;
}
*/
