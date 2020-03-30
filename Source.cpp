// Functions
// v0.1 ����˳���֮�󽫲������������Ч��
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

// newһ��
Person * pt = new Person[ArSize];
int nowSize = 0;

void Init()
{
	// �ر���ʾ
	system("@echo off");

	// ���ı���
	system("title ��ϵ��С���� v0.1");

	// �����Ƿ���Data.txt
	ifstream fin("Data.txt");
	bool pd = true;
	if (!fin)	// û�ҵ��ʹ���
	{
		ofstream fout("Data.txt");
		fout << '0';
		pd = false;
	}
	else	// �ҵ��˱�ĳ�1
	{
		system("del Data.txt");
		ofstream fout("Data.txt");
		fout << '1';
	}

	// ��ȡaddressbook.txt
	fin.close();
	fin.open("addressbook.txt");

	int num;
	fin >> num;
	for (register int i = 0; i < num; ++i)	
		fin >> pt[i].m_name >> pt[i].m_phonenumber >> pt[i].m_address;
	
	// �����һ�ν�����������̳�
	if (!pd)
	{
		Guide();
		// ��ǰ����Ϊ0
		nowSize = 0;
	}
	else
	{
		cout << "��ȡ�ɹ���" << endl;
		nowSize = num;
	}
	system("pause");
	system("cls");
}

// �̳̺���
void Guide()
{
	cout << "��ӭ����ͨѶ¼С����" << endl;
	cout << "�������˽̡̳�" << endl;
	system("pause");
	cout << "С���򽫻��ڳ���Ŀ¼�´��������ļ���Addressbook.txt��Data.txt"
		 << endl
		 << "����Data.txt���ڱ���ʹ�����ݣ�0��1��"
		 << endl
		 << "Addressbook.txt���ڱ�����ϵ�����ݣ����Բ鿴��";
	cout << "����ɾ�����������ļ����������Ը���" << endl;
	system("pause");
	cout << "������������밴��Ҫ�����롣" << endl;
	system("pause");
	cout << "�������̳̾͵������ˣ�ʣ�µ������������̽���ɣ�     :-)" << endl;
	system("pause");
}

// ����������
void work()
{
	// ��ʼ��
	Init();
	
	// �����ͱ���Return_Value����showMenu��������ֵ
	bool Return_Value = true;

	// ѭ������
	while (true)
	{
		// ���շ���ֵ��true�ͼ�����false���˳�
		Return_Value = showMenu();

		// ����
		if (Return_Value)
		{
			system("cls");    // ˢ����Ļ
			continue;
		}

		// �˳�
		Quit();
		return;
	}
}

// ��ʾ�˵�����ȡ���뺯��
// ����ֵΪtrue�������Ϊfalse���˳�
bool showMenu()
{
	// ��ʾ�˵�
	cout << "ͨѶ¼����С����  v0.1 by Afordman" << endl;
	cout << "*********************************" << endl;
	cout << "1. �����ϵ��                    " << endl;
	cout << "2. ��ʾ��ϵ��                    " << endl;
	cout << "3. ������ϵ��                    " << endl;
	cout << "4. ɾ����ϵ��                    " << endl;
	cout << "5. �����ϵ��                    "	<< endl;
	cout << "6. ������ϵ����Ϣ                 " << endl;
	cout << "7. �˳�                          " << endl;
	cout << "*********************************" << endl;

	// ����
	cout << "���������֣�1-7����" << endl;
	char InPut;
	cin >> InPut;
	// ������Ҫ�����������
	while (InPut < '1' || InPut > '7')
	{
		cout << endl << "����������������룺" << endl;
		cin >> InPut;
	}

	// ���ֹ���
	switch (InPut)
	{
		// �����ϵ��
		case '1':
			AddPerson();
			break;

		// ��ʾ��ϵ��
		case '2':
			ShowPerson();
			break;
		
		// ������ϵ��
		case '3':
			FindPerson();
			break;

		// ɾ����ϵ��
		case '4':
			DeletePerson();
			break;

		// �����ϵ��
		case '5':
			DeleteAll();
			break;

		// ������ϵ����Ϣ
		case '6':
			ChangePerson();
			break;

		// �˳�
		case '7':
			return false;
	}

	// ����
	return true;
}

// �����ϵ��
void AddPerson()
{
	// ��ʱ������������ͥסַ���绰����
	string name,
		   address,
		   phonenumber;

	// �ж������Ƿ����������˾������ֱ�ӷ���
	if (nowSize + 10 >= ArSize)
	{
		cout << "\n�ռ���������ɾ����ϵ�������\n";
		system("pause");
		system("cls");
		return;
	}
	
	// ����
	cout << "\n�������µ���ϵ����Ϣ������������ո�\n";
	cout << "������";
	cin >> name;
	cout << "�绰���룺";
	cin >> phonenumber;
	cout << "��ͥסַ��";
	cin >> address;
	
	// ��ֵ
	pt[nowSize].m_address = address;
	pt[nowSize].m_name = name;
	pt[nowSize].m_phonenumber = phonenumber;

	// ������1
	++nowSize;

	cout << "\n��ӳɹ���\n";
	system("pause");
	system("cls");
}

// ��ʾ��ϵ��
void ShowPerson()
{
	// ����
	cout << endl;

	// forѭ�������ϵ����Ϣ
	for (register int i = 0; i < nowSize; i++)
		cout << "������" << pt[i].m_name
			 << "\t�绰���룺" << pt[i].m_phonenumber
			 << "\t��ͥסַ��" << pt[i].m_address << endl;

	cout << "\n�����ɣ�\n";
	system("pause");
	system("cls"); 
}

// ������ϵ��
void FindPerson()
{
	// ��ʱ����
	string name;
	
	// ����
	cout << "��������Ҫ���ҵ���ϵ��������\n";
	cin >> name;
	
	// �����Ƿ��������
	int Return_Value = IsExist(name);

	// û�ҵ�
	if (Return_Value == -1)
	{
		cout << "\n���޴��ˣ�\n";
		system("pause");
		system("cls");
		return;
	}
	// �ҵ��˾����
	else
	{
		cout << "\n������" << pt[Return_Value].m_name << endl;
		cout << "\t�绰���룺" << pt[Return_Value].m_phonenumber << endl;
		cout << "\t��ͥסַ��" << pt[Return_Value].m_address << endl;

		system("pause");
		system("cls");
	}
}

// �ж���ϵ���Ƿ����
int IsExist(string name)
{

	for (register int i = 0; i < nowSize; i++)
		// �ҵ��˾ͷ���λ��
		if (pt[i].m_name == name)
			return i;

	// û�ҵ�����-1����Ϊ�����±��0��ʼ�
	return -1;
}

// ������ϵ����Ϣ
void ChangePerson()
{
	// ��ȡ����ı���
	string name,
		   phonenumber,
		   address;
	
	// ����
	cout << "\n������������ĵ���ϵ��������\n";
	cin >> name;

	// �����Ƿ��������
	int Return_Value = IsExist(name);

	// û�ҵ�
	if (Return_Value == -1)
	{
		cout << "\n���޴��ˣ�\n";
		system("pause");
		system("cls");
		return;
	}
	// �ҵ��˾����벢�洢
	else
	{
		cout << "\n������" << endl;
		cin >> name;
		cout << "�绰���룺" << endl;
		cin >> phonenumber;
		cout << "��ͥסַ��" << endl;
		cin >> address;

		// �洢������֮ǰ��Ϣ��
		pt[Return_Value].m_name = name;
		pt[Return_Value].m_address = address;
		pt[Return_Value].m_phonenumber = phonenumber;

		system("pause");
		system("cls");
	}
}

// ɾ��ָ����ϵ��
void DeletePerson()
{
	// ��ȡ������ϵ�������ı���
	string name;

	// ����
	cin >> name;

	// �����Ƿ��������
	int Return_Value = IsExist(name);

	// û�ҵ�
	if (Return_Value == -1)
	{
		cout << "\n���޴��ˣ�\n";
		system("pause");
		system("cls");
		return;
	}
	// �ҵ��˾�ɾ��������Ԫ��ǰ�ƣ�����֮ǰ����Ϣ��
	else
	{
		for (register int i = nowSize-1; i >= Return_Value; i--)
			pt[i-1] = pt[i];	// ���帳ֵ

		cout << "\nɾ���ɹ���\n";

		system("pause");
		system("cls");
	}
}

// �����ϵ��
void DeleteAll()
{
	// ch���ڶ�ȡ�ַ�����
	char ch;

	cout << "\n�������Ҫ�����ϵ���𣿣��˲��������棩[Y/N]\n";
	cin >> ch;

	// �û�ȡ������
	if (ch != 'Y' && ch != 'y')
	{
		cout << "������ȡ��\n";
		system("pause");
		system("cls");
		return;
	}

	// ȷ�ϲ���
	cout << "������ա�����\n";
	
	// ���
	for (register int i = 0; i < ArSize; i++)
	{
		pt[i].m_address = "";
		pt[i].m_name = "";
		pt[i].m_phonenumber	= "";
	}
	nowSize = 0;

	cout << "\nͨѶ¼����գ�\n";

	system("pause");
	system("cls");
}

// ���沢�Ƴ�
void Quit()
{
	// ch���ڶ�ȡ����
	char ch;

	cout << "���뱣�������[Y/N]\n";
	cin >> ch;

	if (ch == 'Y' || ch == 'y')
	{
		cout << "\n�����С�����\n";

		// �ļ����
		ofstream fout("Addressbook.txt");
		fout << nowSize << endl;
		for (register int i = 0; i < nowSize; i++)
			fout << pt[i].m_name << ' '
				 << pt[i].m_address << ' '
				 << pt[i].m_phonenumber;

		cout << "\n������ϣ�\n";
		system("pause");
		system("cls");
	}

	cout << "�����˳�������\n";
	system("pause");
	system("cls");
}

// ���������ã���������￪ʼ�����������
int main(void)
{
	work();
	delete [] pt;	// �ͷŶѿռ�

	return 0;
}

// By Afordman Cai
// Դ�������ϴ�Github����ַΪ��https://github.com/Afordman/Addressbook