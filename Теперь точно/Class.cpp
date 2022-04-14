#include "Class.h"
using namespace System;

Admin::Admin()
{
	ifstream File(FILE_MAIN_NAME);	// ����������� ������ ��������� ������
	if (!File.is_open()) throw exception("File read error");
	count = 0;
	while (!File.eof()) {
		string temp;	// ��������� ���������� ��������� ����
		getline(File, temp);
		this->admin_data.push_back(temp);
		count++;
	}
	File.close();
}

std::vector<std::string> Admin::Print_Admin_data()
{
	return admin_data;
}

//string Admin::GetPassword()
//{
//	return Password;
//}

//void User::Purchase()
//{
//	int it = day;
//	fstream File(FILE_BASKET_NAME, ios::out);
//	thread thr(travel, it);
//	thr.detach();
//}

//void travel()
//{
//	srand(time(NULL));
//	User user;
//	int temp_day;
//	temp_day = 1 + rand() % 15;
//	user.SetDay(temp_day);
//	this_thread::sleep_for(chrono::seconds(2));
//	user.Purchase();
//	this_thread::sleep_for(chrono::seconds(1));
//}

void User::SetDay(int day)
{
	this->day = day;
}

Basket::Basket()
{
	ifstream File(FILE_BASKET_NAME);
	if (!File.is_open()) throw exception("File read error");
	while (!File.eof()) {
		bc++; string temp;	// 
		getline(File, temp);
		this->bk.push_back(temp);
	}
	File.close();
}

vector <string> Basket::GetBK()
{
	return bk;
}

Builder::Builder()
{
	ifstream File(FILE_NAME);
	if (!File.is_open()) throw exception("File read error");
	while (!File.eof()) {
		id++; string temp;	// 
		getline(File, temp);
		this->data.push_back(temp);
	}
	File.close();
}

void Object_::item()
{
	regex regular(SEARCH_EXP_NEW);	// ���������� ���������
	smatch find_word;
	vector<string>::iterator it = data.begin();// �������� ������
	int i = 0; // ��������� ����������, �� ��� ����������
	count = id;
	while (i < id) {
		if (!regex_match(data[i], find_word, regular)) {// ��������
			data.erase(data.begin() + i);
			id--; i--;									// ����� ��������� 
		}
		i++;
	}
}

void Object_::Basket (int id_)
{
	fstream File(FILE_NAME); fstream File_Basket(FILE_BASKET_NAME, ios_base::app); // �������� ������
	id_--; // �������� ���������� � ����� ������ Object
	string temp; string buff; // ��������� ����������
	temp = (data[id_].c_str()[data[id_].size() - 1]);
	buff = data[id_];
	int count = stoi(temp); // �������������� �� ��������� ���� � �������������
	if (count == 1) {									// ��������, ���� ����� � ����� ����������,
		buff.replace(buff.size() - 1, buff.size(), "1");// �� ������� ��� �� ������ ������ �������
		File_Basket << buff << endl;
		data.erase(data.begin() + id_);
	}
	else {
		buff.replace(buff.size() - 1, buff.size(), "1");
		File_Basket << buff << endl; // ������ ������ � ���� "�������"
		count--; string temp2 = to_string(count); // �������������� ������������ �������� � �������� ���
		this->data[id_].replace(data[id_].size() - 1, data[id_].size(), temp2); // ������ � ������� ���������� ������
	}
	File.close(); File_Basket.close(); // �������� ������������ ������
	ofstream File_New(FILE_NAME, ios_base::trunc); // �������� ����� � ������ "������ � �����"
	if (!File_New.is_open()) throw exception("File read error"); // ������ �������� �����
	for (int i = 0; i < data.size(); i++) {  // ������ ������������ �������� � ����� "�������"
		if (i == data.size() - 1) File_New << data[i]; // �������
		else File_New << data[i] << endl;			   //
	}
	File_New.close();
}

std::vector<string> Object_::Print()
{
	return data;
}

//std::vector<string> Object_::PrintBasket()
//{
//	ifstream File_Basket(FILE_BASKET_NAME); // ������ �� ����� Basket.txt
//	if (!File_Basket.is_open()) throw exception("File read error");
//	int i = 0; string temp;
//	while (!File_Basket.eof()) {
//		getline(File_Basket, temp);
//		basket_.push_back(temp);
//		cout << basket_[i] << endl; i++;
//	}
//}

//int Object::GetCount()
//{
//	return count;
//}

Shoes_::Shoes_()
{
	smatch find_world;
	regex regular(SEARCH_SHOES);	// ���������� ���������
	for (int i = 0; i < id; i++)
	{
		if (regex_search(data[i], find_world, regular)) {
			if (count < 1) begin = i;
			count++;
			Shoes_Data.push_back(data[i]);
			end = i;
		}
	}
}

std::vector<std::string> Shoes_::Print()
{
	return Shoes_Data;
}

Pants_::Pants_()
{
	smatch find_world;
	regex regular(SEARCH_PANTS);	// ���������� ���������
	for (int i = 0; i < id; i++)
	{
		if (regex_search(data[i], find_world, regular)) {
			if (count < 1) begin = i;
			count++;
			Pants_Data.push_back(data[i]);
			end = i;
		}
	}
}

std::vector<std::string> Pants_::Print()
{
	return Pants_Data;
}

Cloth_::Cloth_()
{
	smatch find_world;
	regex regular(SEARCH_CLOTH);	// ���������� ���������
	for (int i = 0; i < id; i++)
	{
		if (regex_search(data[i], find_world, regular)) {
			if (count < 1) begin = i;
			count++;
			Cloth_Data.push_back(data[i]);
			end = i;
		}
	}
}

std::vector<std::string> Cloth_::Print()
{
	return Cloth_Data;
}
