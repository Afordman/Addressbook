// Functions
// v0.1 采用顺序表，之后将采用链表以提高效率
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
	{
		cout << "读取成功！" << endl;
		nowSize = num;
	}
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

// 添加联系人
void AddPerson()
{
	// 临时输入姓名、家庭住址、电话号码
	string name,
		   address,
		   phonenumber;

	// 判断数组是否已满，满了就输出并直接返回
	if (nowSize + 10 >= ArSize)
	{
		cout << "\n空间已满，请删除联系人以添加\n";
		system("pause");
		system("cls");
		return;
  }
	
	// 输入
	cout << "\n请输入新的联系人信息：（请勿包含空格）\n";
	cout << "姓名：";
	cin >> name;
	cout << "电话号码：";
	cin >> phonenumber;
	cout << "家庭住址：";
	cin >> address;
	
	// 赋值
	pt[nowSize].m_address = address;
	pt[nowSize].m_name = name;
	pt[nowSize].m_phonenumber = phonenumber;

	// 人数加1
	++nowSize;

	cout << "\n添加成功！\n";
	system("pause");
	system("cls");
}

// 显示联系人
void ShowPerson()
{
	// 换行
	cout << endl;

	// for循环输出联系人信息
	for (register int i = 0; i < nowSize; i++)
		cout << "姓名：" << pt[i].m_name
			 << "\t电话号码：" << pt[i].m_phonenumber
			 << "\t家庭住址：" << pt[i].m_address << endl;

	cout << "\n输出完成！\n";
	system("pause");
	system("cls"); 
}

// 查找联系人
void FindPerson()
{
	// 临时输入
	string name;
	
	// 输入
	cout << "请输入想要查找的联系人姓名：\n";
	cin >> name;
	
	// 查找是否有这个人
	int Return_Value = IsExist(name);

	// 没找到
	if (Return_Value == -1)
	{
		cout << "\n查无此人！\n";
		system("pause");
		system("cls");
		return;
	}
	// 找到了就输出
	else
	{
		cout << "\n姓名：" << pt[Return_Value].m_name << endl;
		cout << "\t电话号码：" << pt[Return_Value].m_phonenumber << endl;
		cout << "\t家庭住址：" << pt[Return_Value].m_address << endl;

		system("pause");
		system("cls");
	}

}

// 判断联系人是否存在
int IsExist(string name)
{

	for (register int i = 0; i < nowSize; i++)
		// 找到了就返回位置
		if (pt[i].m_name == name)
			return i;

	// 没找到返回-1（因为数组下标从0开始嘛）
	return -1;
}

// 更改联系人信息
void ChangePerson()
{
	// 读取输入的变量
	string name,
		   phonenumber,
		   address;
	
	// 输入
	cout << "\n请输入您想更改的联系人姓名：\n";
	cin >> name;

	// 查找是否有这个人
	int Return_Value = IsExist(name);

	// 没找到
	if (Return_Value == -1)
	{
		cout << "\n查无此人！\n";
		system("pause");
		system("cls");
		return;
	}
	// 找到了就输入并存储
	else
	{
		cout << "\n姓名：" << endl;
		cin >> name;
		cout << "电话号码：" << endl;
		cin >> phonenumber;
		cout << "家庭住址：" << endl;
		cin >> address;

		// 存储（覆盖之前信息）
		pt[Return_Value].m_name = name;
		pt[Return_Value].m_address = address;
		pt[Return_Value].m_phonenumber = phonenumber;

		system("pause");
		system("cls");
	}
}

// 删除指定联系人
void DeletePerson()
{
	// 读取输入联系人姓名的变量
	string name;

	cout << "请输入需要删除的联系人姓名：\n";

	// 输入
	cin >> name;

	// 查找是否有这个人
	int Return_Value = IsExist(name);

	// 没找到
	if (Return_Value == -1)
	{
		cout << "\n查无此人！\n";
		system("pause");
		system("cls");
		return;
	}
	// 找到了就删除（数组元素前移，覆盖之前的信息）
	else
	{
		for (register int i = nowSize-1; i >= Return_Value; i--)
			pt[i-1] = pt[i];	// 整体赋值

		cout << "\n删除成功！\n";

		system("pause");
		system("cls");
	}
}

// 清空联系人
void DeleteAll()
{
	// ch用于读取字符输入
	char ch;

	cout << "\n您真的想要清空联系人吗？（此操作不可逆）[Y/N]\n";
	cin >> ch;

	// 用户取消操作
	if (ch != 'Y' && ch != 'y')
	{
		cout << "操作已取消\n";
		system("pause");
		system("cls");
		return;
	}

	// 确认操作
	cout << "正在清空。。。\n";
	
	// 清空
	for (register int i = 0; i < ArSize; i++)
	{
		pt[i].m_address = "";
		pt[i].m_name = "";
		pt[i].m_phonenumber	= "";
	}
	nowSize = 0;

	cout << "\n通讯录已清空！\n";

	system("pause");
	system("cls");
}

// 保存并推出
void Quit()
{
	// ch用于读取输入
	char ch;

	cout << "您想保存更改吗？[Y/N]\n";
	cin >> ch;

	if (ch == 'Y' || ch == 'y')
	{
		cout << "\n保存中。。。\n";

		// 文件输出
		ofstream fout("Addressbook.txt");
		fout << nowSize << endl;
		for (register int i = 0; i < nowSize; i++)
			fout << pt[i].m_name << ' '
				 << pt[i].m_address << ' '
				 << pt[i].m_phonenumber;

		cout << "\n保存完毕！\n";
		system("pause");
		system("cls");
	}

	cout << "正在退出。。。\n";
	system("pause");
	system("cls");
}

// 主函数调用，程序从这里开始，从这里结束
int main(void)
{
	work();
	delete [] pt;	// 释放堆空间

	return 0;
}

// By Afordman Cai
// 源代码已上传Github，网址为：https://github.com/Afordman/Addressbook


