#include "MyForm1.h"


System::Void �����������::MyForm1::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    /*return System::Void();*/
}

System::Void �����������::MyForm1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (textBox1->Text == "OOP1337")
    {
        MyForm1::Hide();
        MessageBox::Show("�� �����");
        Form::Hide();
    }
    else
    {
        MessageBox::Show("�� �� �����\n���� �����");
        Application::Exit();
    }
    return System::Void();
}
