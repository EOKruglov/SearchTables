#pragma once
#include "..//Tables/Table.h"
#include <fstream>
#include <String>
#include <iostream>
#include <cstdio>

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
		FILE *f;
		TScanTable<string, int> *scanTable;
		TSortTable<string, int> *sortTable;
		TArrayHash<string, int> *hashTable;
		TTreeTable<string, int> *treeTable;
		TRecord<string, int> *r;
		char *arr;
		int count;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton4;
			 int *efficency;
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
			r = new TRecord<string, int>;

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(41, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"—генерировать";
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1046, 608);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
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

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		ifstream ifs("D:\\Vstudio\\Git\\SearchTables\\TablesText.txt");
		while (!ifs.eof())
		{
			ifs >> arr;
			string str(arr);
			TRecord<string, int> *tmp; 
			tmp = new TRecord<string, int>;
			tmp->value = 1;
			tmp->key = str;

			if (scanTable->Find(tmp->key))
				scanTable->SetCurrentValue(scanTable->GetCurrent().value + 1);
			else
				scanTable->Insert(*tmp);

			if (sortTable->Find(tmp->key))
				sortTable->SetCurrentValue(sortTable->GetCurrent().value + 1);
			else
				sortTable->Insert(*tmp);

			if (hashTable->Find(tmp->key))
				hashTable->SetCurrentValue(hashTable->GetCurrent().value + 1);
			else
				hashTable->Insert(*tmp);

			if (treeTable->Find(tmp->key))
				treeTable->SetCurrentValue(treeTable->GetCurrent().value + 1);
			else
				treeTable->Insert(*tmp);
			}

		if (radioButton1->Checked)
		{
			int i = 0;
			TRecord<string, int> *tmp = new TRecord<string, int>;
			for (scanTable->Reset(); !scanTable->IsEnd(); scanTable->GoNext())
			{
				*tmp = scanTable->GetCurrent();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp->key));
				dataGridView1->Rows[i]->Cells[1]->Value = tmp->value;
				i++;
			}
		}

		if (radioButton2->Checked)
		{
			int i = 0;
			TRecord<string, int> *tmp = new TRecord<string, int>;
			for (sortTable->Reset(); !sortTable->IsEnd(); sortTable->GoNext())
			{
				*tmp = sortTable->GetCurrent();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp->key));
				dataGridView1->Rows[i]->Cells[1]->Value = tmp->value;
				i++;
			}
		}

		if (radioButton3->Checked)
		{
			int i = 0;
			TRecord<string, int> *tmp = new TRecord<string, int>;
			for (hashTable->Reset(); !hashTable->IsEnd(); hashTable->GoNext())
			{
				*tmp = hashTable->GetCurrent();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp->key));
				dataGridView1->Rows[i]->Cells[1]->Value = tmp->value;
				i++;
			}
		}

		if (radioButton4->Checked)
		{
			int i = 0;
			TRecord<string, int> *tmp = new TRecord<string, int>;
			for (treeTable->Reset(); !treeTable->IsEnd(); treeTable->GoNext())
			{
				*tmp = treeTable->GetCurrent();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp->key));
				dataGridView1->Rows[i]->Cells[1]->Value = tmp->value;
				i++;
			}
		}
	}
	};
}
