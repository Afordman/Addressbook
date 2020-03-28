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

	// 更改标题
	system("title 联系人小程序 v0.1");

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
	{
		Guide();
		// 当前人数为0
		nowSize = 0;
	}
	else
		cout << "读取成功！\n";
	system("pause");
	system("cls");
}

// 教程函数
void Guide()
{
	cout << "欢迎来到通讯录小程序！" << endl;
	cout << "您进入了教程。" << endl;
	system("pause");
	cout << "小程序将会在程序目录下创建两个文件：Addressbook.txt和Data.txt"
		 << endl
		 << "其中Data.txt用于保存使用数据（0或1）"
		 << endl
		 << "Addressbook.txt用于保存联系人数据，可以查看。";
	cout << "请勿删除以上两个文件，否则后果自负。" << endl;
	system("pause");
	cout << "进入主程序后请按照要求输入。" << endl;
	system("pause");
	cout << "好啦，教程就到这里了，剩下的请进入主程序探索吧！     :-)" << endl;
	system("pause");
}

// 主工作函数
void work()
{
	// 初始化
	Init();
	
	// 布尔型变量Return_Value接收showMenu函数返回值
	bool Return_Value = true;

	// 循环部分
	while (true)
	{
		// 接收返回值，true就继续，false就退出
		Return_Value = showMenu();

		// 继续
		if (Return_Value)
		{
			system("cls");    // 刷新屏幕
			continue;
		}

		// 退出
		Quit();
		return;
	}
}

// 显示菜单并读取输入函数
// 返回值为true则继续，为false则退出
bool showMenu()
{
	// 显示菜单
	cout << "通讯录管理小程序  v0.1 by Afordman" << endl;
	cout << "*********************************" << endl;
	cout << "1. 添加联系人                    " << endl;
	cout << "2. 显示联系人                    " << endl;
	cout << "3. 查找联系人                    " << endl;
	cout << "4. 删除联系人                    " << endl;
	cout << "5. 清空联系人                    "	<< endl;
	cout << "6. 更改联系人信息                 " << endl;
	cout << "7. 退出                          " << endl;
	cout << "*********************************" << endl;

	// 输入
	cout << "请输入数字（1-7）：" << endl;
	char InPut;
	cin >> InPut;
	// 不符合要求就重新输入
	while (InPut < '1' || InPut > '7')
	{
		cout << endl << "输入错误，请重新输入：" << endl;
		cin >> InPut;
	}

	// 各种功能
	switch (InPut)
	{
		// 添加联系人
		case '1':
			AddPerson();
			break;

		// 显示联系人
		case '2':
			ShowPerson();
			break;
		
		// 查找联系人
		case '3':
			FindPerson();
			break;

		// 删除联系人
		case '4':
			DeletePerson();
			break;

		// 清空联系人
		case '5':
			DeleteAll();
			break;

		// 更改联系人信息
		case '6':
			ChangePerson();
			break;

		// 退出
		case '7':
			return false;
	}

	// 继续
	return true;
}