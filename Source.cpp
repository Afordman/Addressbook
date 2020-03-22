// Functions
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

// new一个
Person * pt = new Person[ArSize];
int nowSize = 0;

void Init()
{
	// 关闭提示
	system("@echo off");

	// 查找是否有Data.txt
	ifstream fin("Data.txt");
	bool pd = true;
	if (!fin)	// 没找到就创建
	{
		ofstream fout("Data.txt");
		fout << '0';
		pd = false;
	}
	else	// 找到了便改成1
	{
		system("del Data.txt");
		ofstream fout("Data.txt");
		fout << '1';
	}

	// 读取addressbook.txt
	fin.close();
	fin.open("addressbook.txt");

	int num;
	fin >> num;
	for (register int i = 0; i < num; ++i)	
		fin >> pt[i].m_name >> pt[i].m_phonenumber >> pt[i].m_address;
	
	// 如果第一次进入程序则进入教程
	if (!pd)
		Guide();
	else
		cout << "读取成功！\n";
	system("pause");
	system("cls");
}