#pragma once
#include "CourseManagement.h"
#include "FacultyManagement.h"
#include "StudentManagement.h"
#include "ManageFinances.h"
#include "Generatereport.h"

namespace UniversityManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Administrator
	/// </summary>
	public ref class Administrator : public System::Windows::Forms::Form
	{
	public:
		Administrator(void)
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
		~Administrator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button6;
	protected:
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Administrator::typeid));
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(572, 309);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(129, 23);
			this->button6->TabIndex = 14;
			this->button6->Text = L"Logout";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Administrator::button6_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(572, 219);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(129, 23);
			this->button5->TabIndex = 13;
			this->button5->Text = L"Manage Students";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Administrator::button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(331, 309);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(158, 23);
			this->button4->TabIndex = 12;
			this->button4->Text = L"Generate Reports";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Administrator::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(131, 219);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(129, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Manage Faculty";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Administrator::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(131, 309);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(129, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Manage Finances";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Administrator::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(331, 219);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(158, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Manage Courses";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Administrator::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(255, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(296, 31);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Admistrator Dashboard";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1, 1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(163, 183);
			this->pictureBox1->TabIndex = 62;
			this->pictureBox1->TabStop = false;
			// 
			// Administrator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(828, 468);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Administrator";
			this->Text = L"Administrator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		CourseManagement^ manageC = gcnew CourseManagement();
		manageC->Show();
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	FacultyManagement^ facMan = gcnew FacultyManagement();
	facMan->Show();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	StudentManagement^ stuman = gcnew StudentManagement();
	stuman->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	ManageFinances^ stuman = gcnew ManageFinances();
	stuman->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Generatereport^ genR = gcnew Generatereport();
	genR->Show();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
};
}
