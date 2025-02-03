#define _CRT_SECURE_NO_WARNINGS
#define _UNICODE
#include <iostream>
#include <tchar.h>
using namespace std;

void Task1()
{
	_TCHAR buf[15] = _TEXT("abcba");
	_TCHAR bufcopy[15];

	_tcscpy_s(bufcopy, buf);
	_tcsrev(bufcopy);

	bool pal = _tcscmp(buf, bufcopy) == 0;
	string output = pal ? " is a palindrome" : " is not a palindrome";

	wcout << buf;
	cout << output << endl;

}

void main()
{

	Task1();
}