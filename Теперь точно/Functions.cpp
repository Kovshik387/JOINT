#include "Functions.h"
#include "Class.h"
//�������� �������

using namespace System;

void DataAll()
{
	int ask = 0; // ���� ��
	Object_ object;
	object.item(); object.Print();
}

void DataShoes()
{
	int ask = 0;
	Object_ object;
	Shoes_ shoes; shoes.Print();
}

void DataPants()
{
	int ask = 0;
	Object_ object;
	Pants_ pants; pants.Print();
}

void DataCloth()
{
	int ask = 0;
	Object_ object;
	Cloth_ cloth; cloth.Print();
}

void SetData()	// ������� ����������� ������ � �������� ���
{
	ifstream File_Default(FILE_MAIN_NAME);
	vector<string> temp_data; string temp;
	if (!File_Default.is_open()) throw exception("File read error");
	while (!File_Default.eof()) {
		getline(File_Default, temp);
		temp_data.push_back(temp);
	}
	File_Default.close();
	ofstream File_Data(FILE_NAME, ios_base::trunc);
	if (!File_Data.is_open()) throw exception("File read error");
	for (int i = 0; i < temp_data.size(); i++) {
		if (i == temp_data.size() - 1) File_Data << temp_data[i];
		else File_Data << temp_data[i] << endl;
	}

	File_Data.close();
}

void ReGroupData()
{
	std::vector<std::string> regroup;
	Object_ obj;
	obj.item();
	regroup = obj.Print();
	ofstream File_New(FILE_NAME, ios_base::trunc); // �������� ����� � ������ "������ � �����"
	if (!File_New.is_open()) throw exception("File read error"); // ������ �������� �����
	for (int i = 0; i < regroup.size(); i++) {  // ������ ������������ �������� � ����� "�������"
		if (i == regroup.size() - 1) File_New << regroup[i]; // �������
		else File_New << regroup[i] << endl;			   //
	}
}

std::string Stos(System::String^ s) // �� String � std::string
{
	using namespace System::Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	std::string os(chars);
	return os;
}

//void travel()
//{
//	srand(time(NULL));
//	User user;
//	int temp_day;
//	temp_day = 1 + rand() % 15;
//	user.Purchase();
//}

System::String^ Convert_string_To_String(std::string& os) // �� std::string � String
{
	System::String^ s;
	s = gcnew System::String(os.c_str());
	return s;
}

vector<Ones> ReturnCell(vector<string> s, int count)
{
	Ones ones;
	vector <Ones> ones_v;
	regex reg(BITSTRING); // ���������
	smatch cat; // ���������
	for (int i = 0; i < count; i++)
	{
		ones_v.push_back(ones);
		int iterator = 0;

		// �������
		while (regex_search(s[i], cat, reg))
		{
			switch (iterator)
			{
			case 0:
				ones_v[i].Category = cat.str();
				break;
			case 1:
				ones_v[i].Type = cat.str();
				break;
			case 2:
				ones_v[i].Gender = cat.str();
				break;
			case 3:
				ones_v[i].Brand = cat.str();
				break;
			case 4:
				ones_v[i].Model = cat.str();
				break;
			case 5:
				ones_v[i].Size = cat.str();
				break;
			case 6:
				ones_v[i].Price = cat.str();
				break;
			case 7:
				ones_v[i].Color = cat.str();
				break;
			case 8:
				ones_v[i].Count = cat.str();
				break;
			default:
				break;
			}
			s[i] = cat.suffix();
			iterator++;
		}
	}
	return ones_v;
}
