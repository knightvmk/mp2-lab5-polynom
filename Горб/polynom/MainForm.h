#pragma once

//#include "tlist.h"
//#include "tpolinom.h"

namespace polynom {

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
	public:
		MyForm(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Constanta;
	private: System::Windows::Forms::Label^  label_x;

	protected:


	private: System::Windows::Forms::TextBox^  deg_1;
	private: System::Windows::Forms::Label^  label_y;


	private: System::Windows::Forms::TextBox^  deg_2;
	private: System::Windows::Forms::Label^  label_z;


	private: System::Windows::Forms::TextBox^  deg_3;
	private: System::Windows::Forms::Button^  Add_monom;


	private: System::Windows::Forms::RichTextBox^  polinom_field;
	private: System::Windows::Forms::Button^  del_polynom;
	private: System::Windows::Forms::Button^  create_polinom;
	private: System::Windows::Forms::ListBox^  list_pol;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Constanta = (gcnew System::Windows::Forms::TextBox());
			this->label_x = (gcnew System::Windows::Forms::Label());
			this->deg_1 = (gcnew System::Windows::Forms::TextBox());
			this->label_y = (gcnew System::Windows::Forms::Label());
			this->deg_2 = (gcnew System::Windows::Forms::TextBox());
			this->label_z = (gcnew System::Windows::Forms::Label());
			this->deg_3 = (gcnew System::Windows::Forms::TextBox());
			this->Add_monom = (gcnew System::Windows::Forms::Button());
			this->polinom_field = (gcnew System::Windows::Forms::RichTextBox());
			this->del_polynom = (gcnew System::Windows::Forms::Button());
			this->create_polinom = (gcnew System::Windows::Forms::Button());
			this->list_pol = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ввод полинома";
			// 
			// Constanta
			// 
			this->Constanta->Location = System::Drawing::Point(15, 54);
			this->Constanta->MaxLength = 999;
			this->Constanta->Name = L"Constanta";
			this->Constanta->Size = System::Drawing::Size(54, 20);
			this->Constanta->TabIndex = 1;
			this->Constanta->TextChanged += gcnew System::EventHandler(this, &MyForm::Add_monom_EnabledChanged);
			// 
			// label_x
			// 
			this->label_x->AutoSize = true;
			this->label_x->Location = System::Drawing::Point(76, 60);
			this->label_x->Name = L"label_x";
			this->label_x->Size = System::Drawing::Size(12, 13);
			this->label_x->TabIndex = 2;
			this->label_x->Text = L"x";
			// 
			// deg_1
			// 
			this->deg_1->Location = System::Drawing::Point(97, 44);
			this->deg_1->MaxLength = 9;
			this->deg_1->Name = L"deg_1";
			this->deg_1->Size = System::Drawing::Size(25, 20);
			this->deg_1->TabIndex = 3;
			this->deg_1->TextChanged += gcnew System::EventHandler(this, &MyForm::Add_monom_EnabledChanged);
			// 
			// label_y
			// 
			this->label_y->AutoSize = true;
			this->label_y->Location = System::Drawing::Point(129, 60);
			this->label_y->Name = L"label_y";
			this->label_y->Size = System::Drawing::Size(12, 13);
			this->label_y->TabIndex = 4;
			this->label_y->Text = L"y";
			// 
			// deg_2
			// 
			this->deg_2->Location = System::Drawing::Point(149, 44);
			this->deg_2->MaxLength = 9;
			this->deg_2->Name = L"deg_2";
			this->deg_2->Size = System::Drawing::Size(25, 20);
			this->deg_2->TabIndex = 5;
			this->deg_2->TextChanged += gcnew System::EventHandler(this, &MyForm::Add_monom_EnabledChanged);
			// 
			// label_z
			// 
			this->label_z->AutoSize = true;
			this->label_z->Location = System::Drawing::Point(181, 59);
			this->label_z->Name = L"label_z";
			this->label_z->Size = System::Drawing::Size(12, 13);
			this->label_z->TabIndex = 6;
			this->label_z->Text = L"z";
			// 
			// deg_3
			// 
			this->deg_3->Location = System::Drawing::Point(201, 44);
			this->deg_3->MaxLength = 9;
			this->deg_3->Name = L"deg_3";
			this->deg_3->Size = System::Drawing::Size(28, 20);
			this->deg_3->TabIndex = 7;
			this->deg_3->TextChanged += gcnew System::EventHandler(this, &MyForm::Add_monom_EnabledChanged);
			// 
			// Add_monom
			// 
			this->Add_monom->Enabled = false;
			this->Add_monom->Location = System::Drawing::Point(247, 52);
			this->Add_monom->Name = L"Add_monom";
			this->Add_monom->Size = System::Drawing::Size(75, 23);
			this->Add_monom->TabIndex = 8;
			this->Add_monom->Text = L"В строку";
			this->Add_monom->UseVisualStyleBackColor = true;
			this->Add_monom->EnabledChanged += gcnew System::EventHandler(this, &MyForm::Add_monom_EnabledChanged);
			this->Add_monom->Click += gcnew System::EventHandler(this, &MyForm::Add_monom_Click);
			// 
			// polinom_field
			// 
			this->polinom_field->Location = System::Drawing::Point(15, 101);
			this->polinom_field->Name = L"polinom_field";
			this->polinom_field->Size = System::Drawing::Size(307, 31);
			this->polinom_field->TabIndex = 9;
			this->polinom_field->Text = L"";
			this->polinom_field->TextChanged += gcnew System::EventHandler(this, &MyForm::create_polinom_EnabledChanged);
			// 
			// del_polynom
			// 
			this->del_polynom->Location = System::Drawing::Point(329, 101);
			this->del_polynom->Name = L"del_polynom";
			this->del_polynom->Size = System::Drawing::Size(32, 30);
			this->del_polynom->TabIndex = 10;
			this->del_polynom->Text = L"C";
			this->del_polynom->UseVisualStyleBackColor = true;
			this->del_polynom->Click += gcnew System::EventHandler(this, &MyForm::del_polynom_Click);
			// 
			// create_polinom
			// 
			this->create_polinom->Enabled = false;
			this->create_polinom->Location = System::Drawing::Point(15, 139);
			this->create_polinom->Name = L"create_polinom";
			this->create_polinom->Size = System::Drawing::Size(75, 23);
			this->create_polinom->TabIndex = 11;
			this->create_polinom->Text = L"Добавить";
			this->create_polinom->UseVisualStyleBackColor = true;
			this->create_polinom->EnabledChanged += gcnew System::EventHandler(this, &MyForm::create_polinom_EnabledChanged);
			this->create_polinom->Click += gcnew System::EventHandler(this, &MyForm::create_polinom_Click);
			// 
			// list_pol
			// 
			this->list_pol->FormattingEnabled = true;
			this->list_pol->Location = System::Drawing::Point(367, 27);
			this->list_pol->Name = L"list_pol";
			this->list_pol->Size = System::Drawing::Size(362, 134);
			this->list_pol->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(754, 298);
			this->Controls->Add(this->list_pol);
			this->Controls->Add(this->create_polinom);
			this->Controls->Add(this->del_polynom);
			this->Controls->Add(this->polinom_field);
			this->Controls->Add(this->Add_monom);
			this->Controls->Add(this->deg_3);
			this->Controls->Add(this->label_z);
			this->Controls->Add(this->deg_2);
			this->Controls->Add(this->label_y);
			this->Controls->Add(this->deg_1);
			this->Controls->Add(this->label_x);
			this->Controls->Add(this->Constanta);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Программа работы с полиномами трёх переменных";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Add_monom_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (polinom_field->Text != "" && Convert::ToInt32(Constanta->Text) >= 0) polinom_field->Text += "+";
		polinom_field->Text += (Constanta->Text) + (label_x->Text) + (deg_1->Text) + (label_y->Text) + (deg_2->Text) + (label_z->Text) + (deg_3->Text);

	}

private: System::Void Add_monom_EnabledChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (Constanta->Text != "" && deg_1->Text != "" && deg_2->Text != "" && deg_3->Text != "")
	{
		Add_monom->Enabled = true;
	}
	else Add_monom->Enabled = false;
}
		
private: System::Void del_polynom_Click(System::Object^  sender, System::EventArgs^  e) 
{
	polinom_field->Text = "";
}

private: System::Void create_polinom_EnabledChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (polinom_field->Text != "") create_polinom->Enabled = true;
	else create_polinom->Enabled = false;
}

private: System::Void create_polinom_Click(System::Object^  sender, System::EventArgs^  e) 
{
	list_pol->Items->Add(polinom_field->Text);
}
};


}
