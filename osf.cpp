#pragma once
#include<dirent.h>
#include<string>
#include<omp.h>
#include"./stemLib/stemming/english_stem.h"
#ifndef osf_cpp
stemming::english_stem<> __stemEng;
std::wstring StringToWString(const std::string& s)
{
	std::wstring temp(s.length(),L' ');
	std::copy(s.begin(), s.end(), temp.begin());
	return temp; 
}
std::string WStringToString(const std::wstring& s)
{
	std::string temp(s.length(), ' ');
	std::copy(s.begin(), s.end(), temp.begin());
	return temp; 
}
std::string StemEnglish(const std::string& s)
{
	std::wstring w(StringToWString(s));
	__stemEng(w);
	return WStringToString(w);
}
void listAllFiles(std::string str,void (*fileParse)(std::string&))
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
void replaceString(std::string &g,const std::string &S,const char C)
{
	register char c = C;
	register char * G = (char*)g.c_str();
	unsigned register long long i,r,B1=0,B2=0,sl=S.size(),gl=g.size();
	for(i = 0;i<sl;i++)
	{
		r = (int)S[i];
		B1 |= r < 64? 1<<r : 0;
		B2 |= r > 63? 1<<(r-64) : 0;
	}
	#pragma omp parallel for private(i,r) firstprivate(gl,c,B1,B2) shared(G)
	for(i = 0;i<gl;i++)
	{
		r = (int)G[i];
		G[i] = r < 64 ?
			(B1 & 1<<r ? c : r):
			(B2 & 1<<(r-64) ? c : r);
	}
}
#endif
