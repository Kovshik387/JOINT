#include "MyForm1.h"
#include "MyForm3.h"

System::Void �����������::MyForm1::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    /*return System::Void();*/
}

System::Void �����������::MyForm1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (textBox1->Text == "OOP1337")
    {
        MyForm3^ form3 = gcnew MyForm3();
        MyForm1::Close();
        form3->Show();
    }
    else
    {
        MessageBox::Show("�������� ������");
    }
    return System::Void();
}
