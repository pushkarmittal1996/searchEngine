#include "stemming/english_stem.h"
#include <string>
#include <iostream>
#include "../osf.cpp"
int main()
    {
    /*if you are using std::string (ANSI strings) then convert it to a temporary
    wchar_t buffer, assign that to a std::wstring, and then stem that.*/
	std::wstring word;
	stemming::english_stem<> StemEnglish;
	std::string ANSIWord("documentation");
	word = StringToWString(ANSIWord);
	StemEnglish(word);
	ANSIWord = WStringToString(word);
	std::cout<<ANSIWord<<"\n";
    return 0;
    }
