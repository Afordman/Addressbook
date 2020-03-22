#pragma once

#ifndef STDFILEHEADER_H_
#define STDFILEHEADER_H_

#include <string>

void Init();
void Guide();
void work();
bool showMenu();
void AddPerson();
void ShowPerson();
void FindPerson();
void ChangePerson();
void DeletePerson();
void DeleteAll();
void Quit();
bool IsExist();

struct Person{
	std::string m_name,
		m_address,
		m_phonenumber;
};

const int ArSize = 1000 + 10;

#endif // !STDFILEHEADER_H_