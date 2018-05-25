#pragma once
#include "..//Tables/Table.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;



namespace TestTables {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		TScanTable<string, int> *scanTable;
		TSortTable<string, int> *sortTable;
		TArrayHash<string, int> *hashTable;
		TTreeTable<string, int> *treeTable;
		char *arr;
		int count;
		int *efficency;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::RadioButton^  radioButton4;
			 
	public:
		MyForm(void)
		{
			 
			InitializeComponent();
			count = 100;
			scanTable = new TScanTable<string, int>(count);
			sortTable = new TSortTable < string, int>(count);
			hashTable = new TArrayHash<string, int>(count);
			treeTable = new TTreeTable<string, int>();
			arr = new char[100];
			efficency = new int[4];

			efficency[0] = scanTable->GetEff();
			efficency[1] = sortTable->GetEff();
			efficency[2] = hashTable->GetEff();
			efficency[3] = treeTable->GetEff();

			dataGridView1->RowCount = count;
			dataGridView1->ColumnCount = 2;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(41, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Сгенерировать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(41, 118);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(207, 400);
			this->dataGridView1->TabIndex = 1;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(311, 118);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(77, 17);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"ScanTable";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(311, 141);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(71, 17);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"SortTable";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(311, 164);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(50, 17);
			this->radioButton3->TabIndex = 4;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Hash";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(311, 187);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(47, 17);
			this->radioButton4->TabIndex = 5;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Tree";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(779, 286);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Найти";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(779, 348);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Добавить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(628, 286);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(628, 350);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 9;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(779, 407);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Удалить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(628, 410);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 11;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(907, 286);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 12;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(907, 353);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(907, 407);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(907, 348);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 15;
			this->label4->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(907, 286);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 16;
			this->label5->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(188, 17);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1046, 608);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: char *GetStr(string str) 
	{
			int len = str.length();
			char *res = new char[len + 1];
			for (int i = 0; i < len; i++) {
				res[i] = str[i];
			}
			res[len] = '\0';
			return res;
		}

	public: String^ StrToStr(string str) 
	{
		return gcnew String(GetStr(str));
	}

	private: void ClrScr()
	{
		for (int i = 0; i < count; i++)
		{
			dataGridView1->Rows[i]->Cells[0]->Value = "";
			dataGridView1->Rows[i]->Cells[1]->Value = "";
		}
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		ifstream ifs("D:\\Vstudio\\Git\\SearchTables\\TablesText.txt");

		if (radioButton1->Checked)
		{
			while (!ifs.eof())
			{
				ifs >> arr;
				string str(arr);
				TRecord<string, int> tmp;
				tmp.value = 1;
				tmp.key = str;

				if (scanTable->Find(tmp.key))
					scanTable->SetCurrentValue(scanTable->GetCurrent().value + 1);
				else
					scanTable->Insert(tmp);
			}

			ClrScr();

			int i = 0;
			TRecord<string, int> tmp;
			for (scanTable->Reset(); !scanTable->IsEnd(); scanTable->GoNext())
			{
				tmp = scanTable->GetCurrent();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.key));
				dataGridView1->Rows[i]->Cells[1]->Value = tmp.value;
				i++;
			}

			label6->Text = Convert::ToString(scanTable->GetEff());
		}

		if (radioButton2->Checked)
		{
			while (!ifs.eof())
			{
				ifs >> arr;
				string str(arr);
				TRecord<string, int> tmp;
				tmp.value = 1;
				tmp.key = str;
				if (sortTable->Find(tmp.key))
					sortTable->SetCurrentValue(sortTable->GetCurrent().value + 1);
				else
					sortTable->Insert(tmp);
			}

			ClrScr();


			int i = 0;
			TRecord<string, int> tmp;
			for (sortTable->Reset(); !sortTable->IsEnd(); sortTable->GoNext())
			{
				tmp = sortTable->GetCurrent();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.key));
				dataGridView1->Rows[i]->Cells[1]->Value = tmp.value;
				i++;
			}

			label6->Text = Convert::ToString(sortTable->GetEff());
		}

		if (radioButton3->Checked)
		{
			while (!ifs.eof())
			{
				ifs >> arr;
				string str(arr);
				TRecord<string, int> tmp;
				tmp.value = 1;
				tmp.key = str;
				if (hashTable->Find(tmp.key))
					hashTable->SetCurrentValue(hashTable->GetCurrent().value + 1);
				else
					hashTable->Insert(tmp);
			}

			ClrScr();

			int i = 0;
			TRecord<string, int> tmp;
			for (hashTable->Reset(); !hashTable->IsEnd(); hashTable->GoNext())
			{
				tmp = hashTable->GetCurrent();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.key));
				dataGridView1->Rows[i]->Cells[1]->Value = tmp.value;
				i++;
			}

			label6->Text = Convert::ToString(hashTable->GetEff());
		}

		if (radioButton4->Checked)
		{
			while (!ifs.eof())
			{
				ifs >> arr;
				string str(arr);
				TRecord<string, int> tmp;
				tmp.value = 1;
				tmp.key = str;
				if (treeTable->Find(tmp.key))
					treeTable->SetCurrentValue(treeTable->GetCurrent().value + 1);
				else
					treeTable->Insert(tmp);
			}

			ClrScr();

			int i = 0;
			TRecord<string, int> tmp;
			for (treeTable->Reset(); !treeTable->IsEnd(); treeTable->GoNext())
			{
				tmp = treeTable->GetCurrent();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.key));
				dataGridView1->Rows[i]->Cells[1]->Value = tmp.value;
				i++;
			}

			label6->Text = Convert::ToString(treeTable->GetEff());
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (radioButton1->Checked)
		{
			String^ str = textBox1->Text;
			string tmp;
			for (int i = 0; i < str->Length; i++)
				tmp += str[i];

			scanTable->ClrEff();

			if (scanTable->Find(tmp))
				label5->Text = Convert::ToString(scanTable->GetEff());
			else
				label5->Text = "NONE";
		}

		if (radioButton2->Checked)
		{
			String^ str = textBox1->Text;
			string tmp;
			for (int i = 0; i < str->Length; i++)
				tmp += str[i];

			sortTable->ClrEff();

			if (sortTable->Find(tmp))
				label5->Text = Convert::ToString(sortTable->GetEff());
			else
				label5->Text = "NONE";
		}

		if (radioButton3->Checked)
		{
			String^ str = textBox1->Text;
			string tmp;
			for (int i = 0; i < str->Length; i++)
				tmp += str[i];

			hashTable->ClrEff();

			if (hashTable->Find(tmp))
				label5->Text = Convert::ToString(hashTable->GetEff());
			else
				label5->Text = "NONE";
		}

		if (radioButton4->Checked)
		{
			String^ str = textBox1->Text;
			string tmp;
			for (int i = 0; i < str->Length; i++)
				tmp += str[i];

			treeTable->ClrEff();
			
			if (treeTable->Find(tmp))
				label5->Text = Convert::ToString(treeTable->GetEff());
			else
				label5->Text = "NONE";
		}

	}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	TRecord<string, int> tmp;
	String^ str = textBox2->Text;
	string buf;
	for (int i = 0; i < str->Length; i++)
		buf += str[i];

	tmp.key = buf;
	tmp.value = 1;

	if (radioButton1->Checked)
	{
		scanTable->ClrEff();
		if (scanTable->Find(tmp.key))
		{
			scanTable->SetCurrentValue(scanTable->GetCurrent().value + 1);
		}
		else
		{
			scanTable->Insert(tmp);
		}

		ClrScr();

		int i = 0;
		for (scanTable->Reset(); !scanTable->IsEnd(); scanTable->GoNext())
		{
			tmp = scanTable->GetCurrent();
			dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.key));
			dataGridView1->Rows[i]->Cells[1]->Value = tmp.value;
			i++;
		}


		label4->Text = Convert::ToString(scanTable->GetEff());
		
	}

	if (radioButton2->Checked)
	{
		sortTable->ClrEff();
		if (sortTable->Find(tmp.key))
		{
			sortTable->SetCurrentValue(sortTable->GetCurrent().value + 1);
		}
		else
		{
			sortTable->Insert(tmp);
		}
		ClrScr();

		int i = 0;
		for (sortTable->Reset(); !sortTable->IsEnd(); sortTable->GoNext())
		{
			tmp = sortTable->GetCurrent();
			dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.key));
			dataGridView1->Rows[i]->Cells[1]->Value = tmp.value;
			i++;
		}

		label4->Text = Convert::ToString(sortTable->GetEff());
	}

	if (radioButton3->Checked)
	{
		hashTable->ClrEff();
		if (hashTable->Find(tmp.key))
		{
			hashTable->SetCurrentValue(hashTable->GetCurrent().value + 1);
		}
		else
		{
			hashTable->Insert(tmp);
		}

		ClrScr();

		int i = 0;
		for (hashTable->Reset(); !hashTable->IsEnd(); hashTable->GoNext())
		{
			tmp = hashTable->GetCurrent();
			dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.key));
			dataGridView1->Rows[i]->Cells[1]->Value = tmp.value;
			i++;
		}

		label4->Text = Convert::ToString(hashTable->GetEff());
	}

	if (radioButton4->Checked)
	{
		treeTable->ClrEff();
		if (treeTable->Find(tmp.key))
		{
			treeTable->SetCurrentValue(treeTable->GetCurrent().value + 1);
		}
		else
		{
			treeTable->Insert(tmp);
		}

		ClrScr();

		int i = 0;
		for (treeTable->Reset(); !treeTable->IsEnd(); treeTable->GoNext())
		{
			tmp = treeTable->GetCurrent();
			dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.key));
			dataGridView1->Rows[i]->Cells[1]->Value = tmp.value;
			i++;
		}

		label4->Text = Convert::ToString(treeTable->GetEff());
	}
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ str = textBox3->Text;
	string tkey;
	for (int i = 0; i < str->Length; i++)
		tkey += str[i];

	if (radioButton1->Checked)
	{
		scanTable->ClrEff();
		scanTable->Delete(tkey);

		ClrScr();

		if (!scanTable->IsEmpty())
		{
			int i = 0;
			TRecord<string, int> tmp;
			for (scanTable->Reset(); !scanTable->IsEnd(); scanTable->GoNext())
			{
				tmp = scanTable->GetCurrent();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.key));
				dataGridView1->Rows[i]->Cells[1]->Value = tmp.value;
				i++;
			}
			label3->Text = Convert::ToString(scanTable->GetEff());
		}
		else
			label3->Text = "NONE";

	}

	if (radioButton2->Checked)
	{
		sortTable->ClrEff();
		sortTable->Delete(tkey);

		ClrScr();

		int i = 0;
		TRecord<string, int> tmp;
		if (!sortTable->IsEmpty())
		{
			for (sortTable->Reset(); !sortTable->IsEnd(); sortTable->GoNext())
			{
				tmp = sortTable->GetCurrent();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.key));
				dataGridView1->Rows[i]->Cells[1]->Value = tmp.value;
				i++;
			}
			label3->Text = Convert::ToString(sortTable->GetEff());
		}
		else
			label3->Text = "NONE";
	}

	if (radioButton3->Checked)
	{
		hashTable->ClrEff();
		hashTable->Delete(tkey);

		ClrScr();

		if (!hashTable->IsEmpty())
		{
			int i = 0;
			TRecord<string, int> tmp;
			for (hashTable->Reset(); !hashTable->IsEnd(); hashTable->GoNext())
			{
				tmp = hashTable->GetCurrent();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.key));
				dataGridView1->Rows[i]->Cells[1]->Value = tmp.value;
				i++;
			}
			label3->Text = Convert::ToString(hashTable->GetEff());
		}
		else
			label3->Text = "NONE";
	}

	if (radioButton4->Checked)
	{
		treeTable->ClrEff();
		treeTable->Delete(tkey);

		ClrScr();

		if (!treeTable->IsEmpty())
		{
			int i = 0;
			TRecord<string, int> tmp;
			for (treeTable->Reset(); !treeTable->IsEnd(); treeTable->GoNext())
			{
				tmp = treeTable->GetCurrent();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.key));
				dataGridView1->Rows[i]->Cells[1]->Value = tmp.value;
				i++;
			}
			label3->Text = Convert::ToString(treeTable->GetEff());
		}
		else
			label3->Text = "NONE";
	}
}
};
}
