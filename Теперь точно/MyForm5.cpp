#include "MyForm5.h"
#include "Functions.h"
#include "Class.h"

System::Void �����������::MyForm5::Aadd_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	String^ str = "Pants ";
	str += comboBox1->Text->ToString() + " "
		+ Gender->Text->ToString() + " "
		+ textBox1->Text->ToString() + " "
		+ textBox2->Text->ToString() + " "
		+ numericUpDown1->Text->ToString() + " "
		+ numericUpDown2->Text->ToString() + " "
		+ Color->Text->ToString() + " "
		+ numericCount->Text->ToString();
	std::string temp = Stos(str);
	std::ofstream File(FILE_MAIN_NAME, std::ios::app);
	File << "\n" << temp;
	MessageBox::Show("�������", "���������");
	File.close();
}