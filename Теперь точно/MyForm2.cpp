#include "MyForm2.h"
#include "Class.h"
#include "Functions.h"


System::Void �����������::MyForm2::ALL_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridData->Rows->Clear();
	dataGridData->Columns->Clear();
	Object_ obj; obj.item();
	dataGridData->RowCount = obj.GetCount();

	dataGridData->Name = "� �����";

	HeaderA();
	
	Show();
	
	return System::Void();
}

System::Void �����������::MyForm2::Shoes_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridData->Rows->Clear();
	dataGridData->Columns->Clear();
	Shoes_ shoes; 
	dataGridData->RowCount = shoes.GetCount();

	dataGridData->Name = "� �����";

	HeaderA();

	ShowShoes();

	return System::Void();
}

System::Void �����������::MyForm2::Pants_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridData->Rows->Clear();
	dataGridData->Columns->Clear();
	Pants_ pants;
	dataGridData->RowCount = pants.GetCount();

	dataGridData->Name = "� �����";

	HeaderA();

	ShowPants();

	return System::Void();
}

System::Void �����������::MyForm2::Cloth_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridData->Rows->Clear();
	dataGridData->Columns->Clear();
	Cloth_ cloth;
	dataGridData->RowCount = cloth.GetCount();

	dataGridData->Name = "�";

	HeaderA();

	ShowCloth();

	DataCloth();
	return System::Void();
}

System::Void �����������::MyForm2::butbask_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	Basket basket;
	
	if (basket.GetBC() == 1) { MessageBox::Show("���� ������� �����", "���..."); }
	else
	{
		dataGridData->Rows->Clear();
		dataGridData->Columns->Clear();
		dataGridData->Name = "�";
		dataGridData->RowCount = basket.GetBC();
		HeaderA();

		ShowBask();
	}
	return System::Void();
}

System::Void �����������::MyForm2::Bask_Click(System::Object^ sender, System::EventArgs^ e)
{
	Basket basket;
		Object_ object;
		int ask = Convert::ToInt16(numericUpDown1->Text);
		object.Basket(ask);
		dataGridData->Rows->Clear();
		dataGridData->Columns->Clear();
}

void �����������::MyForm2::HeaderA()
{
	DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
	c1->Name = "������";
	c1->HeaderText = "�����";
	c1->Width = 150;
	dataGridData->Columns->Add(c1);

	dataGridData->AutoResizeColumn(0);
}

void �����������::MyForm2::HeaderB()
{
	DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
	c2->Name = "������";
	c2->HeaderText = "�������";
	c2->Width = 150;
	dataGridData->Columns->Add(c2);

	dataGridData->AutoResizeColumn(0);
}

void �����������::MyForm2::ShowCloth()
{
	int temp;
	Cloth_ cloth;
	Object_ object; object.item();
	std::vector<string> v = object.Print();
	dataGridData->ClearSelection();
	temp = cloth.GetBegin();
	for (int i = 0; i < cloth.GetCount(); i++)
	{
		dataGridData->TopLeftHeaderCell->Value = "id";
		dataGridData->Rows[i]->HeaderCell->Value = Convert::ToString(temp + 1);
		dataGridData->Columns[0]->HeaderCell->Value = "####";
		dataGridData->Rows[i]->Cells[0]->Value = "--->";
		dataGridData->Rows[i]->Cells[1]->Value = Convert_string_To_String(v[temp]);
		dataGridData->AutoResizeColumn(0);
		dataGridData->AutoResizeRows();
		temp++;
	}
}

void �����������::MyForm2::ShowBask()
{
	int temp = 0;
	Basket basket;
	std::vector<string> v = basket.GetBK();
	dataGridData->ClearSelection();
	for (int i = 0; i < basket.GetBC(); i++)
	{
		dataGridData->TopLeftHeaderCell->Value = "id";
		dataGridData->Rows[i]->HeaderCell->Value = Convert::ToString(temp +1);
		dataGridData->Columns[0]->HeaderCell->Value = "####";
		dataGridData->Rows[i]->Cells[0]->Value = "--->";
		dataGridData->Rows[i]->Cells[1]->Value = Convert_string_To_String(v[temp]);
		dataGridData->AutoResizeColumn(0);
		dataGridData->AutoResizeRows();
		temp++;
	}
}

void �����������::MyForm2::ShowPants()
{
	int temp;
	Pants_ pants;
	Object_ object; object.item();
	std::vector<string> v = object.Print();
	dataGridData->ClearSelection();
	temp = pants.GetBegin();
	for (int i = 0; i < pants.GetCount(); i++)
	{
		dataGridData->TopLeftHeaderCell->Value = "id";
		dataGridData->Rows[i]->HeaderCell->Value = Convert::ToString(temp + 1);
		dataGridData->Columns[0]->HeaderCell->Value = "####";
		dataGridData->Rows[i]->Cells[0]->Value = "--->";
		dataGridData->Rows[i]->Cells[1]->Value = Convert_string_To_String(v[temp]);
		dataGridData->AutoResizeColumn(0);
		dataGridData->AutoResizeRows();
		temp++;
	}
}

void �����������::MyForm2::ShowShoes()
{
	int temp;
	Shoes_ shoes; 
	Object_ object;
	object.item();
	std::vector<string> v = object.Print();
	dataGridData->ClearSelection();
	temp = shoes.GetBegin();
	for (int i = shoes.GetBegin(); i < dataGridData->RowCount; i++)
	{
		dataGridData->TopLeftHeaderCell->Value = "id";
		dataGridData->Rows[i]->HeaderCell->Value = Convert::ToString(temp + 1);
		dataGridData->Columns[0]->HeaderCell->Value = "####";
		dataGridData->Rows[i]->Cells[0]->Value = "--->";
		dataGridData->Rows[i]->Cells[1]->Value = Convert_string_To_String(v[temp]);
		dataGridData->AutoResizeColumn(0);
		dataGridData->AutoResizeRows();
		temp++;
	}
}

void �����������::MyForm2::Show()
{
	Object_ object; object.item();
	std::vector<string> v = object.Print();
	dataGridData->ClearSelection();
	for (int i = 0; i < dataGridData->RowCount; i++)
	{
		dataGridData->TopLeftHeaderCell->Value = "id";
		dataGridData->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridData->Columns[0]->HeaderCell->Value = "####";
		dataGridData->Rows[i]->Cells[0]->Value = "--->";
		dataGridData->Rows[i]->Cells[1]->Value = Convert_string_To_String(v[i]);
		dataGridData->AutoResizeColumn(0);
		dataGridData->AutoResizeRows();
	}
}
