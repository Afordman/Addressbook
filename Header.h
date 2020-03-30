#pragma once

#ifndef HEADER_H_
#define HEADER_H_

#include <string>

void Init();					// 初始化
void Guide();					// 教程
void work();					// 主工作函数
bool showMenu();				// 显示菜单并读取输入
void AddPerson();				// 添加联系人
void ShowPerson();				// 显示联系人
void FindPerson();				// 查找联系人
void ChangePerson();			// 更改联系人
void DeletePerson();			// 删除指定联系人
void DeleteAll();				// 删除全部联系人
void Quit();					// 退出并询问是否保存更改
int IsExist(std::string name);	// 判断联系人是否存在

// 联系人结构体
struct Person{
	std::string m_name,
		m_address,
		m_phonenumber;
};

// 数组大小常量
const int ArSize = 1000 + 10;

#endif // !HEADER_H_