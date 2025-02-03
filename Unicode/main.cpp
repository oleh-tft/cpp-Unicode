#define _CRT_SECURE_NO_WARNINGS
#define _UNICODE
#include <iostream>
#include <tchar.h>
using namespace std;

void Task1(_TCHAR* text)
{
	_TCHAR textcopy[15];

	_tcscpy_s(textcopy, text);
	_tcsrev(textcopy);

	bool pal = _tcscmp(text, textcopy) == 0;

	wcout << text << (pal ? " is a palindrome" : " is not a palindrome") << endl << endl;

}

void Task2(_TCHAR* text)
{
	int words = 0;
	for (int i = 0; i < _tcslen(text); i++)
	{
		if ((text[i] != ' ' && text[i + 1] == ' ') || (i == _tcslen(text) - 1 && text[i] != ' ')) words++;
	}
	wcout << text << endl << "Words: " << words << endl << endl;
}

void Task3(_TCHAR* text, _TCHAR* find, _TCHAR* replace)
{
	_TCHAR* ind = _tcsstr(text, find);
	if (ind == nullptr) return;

	int position = ind - text;
	ind += _tcslen(find); //text after substring

	_TCHAR newText[50] = _TEXT("");

	for (int i = 0; i < position; i++) 
	{
		newText[i] = text[i];
	}
	_tcscat(newText, replace);
	_tcscat(newText, ind);
	
	_tcscpy(text, newText);

	wcout << text << endl;
}

void main()
{
	_TCHAR pal[15] = _TEXT("abCba");
	Task1(pal);

	_TCHAR str[50] = _TEXT("The quick brown fox jumps over a lazy dog");
	Task2(str);

	_TCHAR find[10] = _TEXT("brown");
	_TCHAR replace[10] = _TEXT("red");
	Task3(str, find, replace);
}