#pragma once
#include "CourseRegistration.h"
#include "PayFees.h"
#include "ManageProfile.h"
#include "ViewGrades.h"
#include "Transcript.h"
namespace UniversityManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Student
	/// </summary>
	public ref class Student : public System::Windows::Forms::Form
	{
	public:
		String^ id;
		Student(String^ userid)
		{
			InitializeComponent();
			id = userid;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Student()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ enroll;



	private: System::Windows::Forms::Button^ payfees;
	private: System::Windows::Forms::Button^ profile;


	private: System::Windows::Forms::Button^ viewgrades;
	private: System::Windows::Forms::Button^ logout;


	private: System::Windows::Forms::Button^ transcript;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Student::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->enroll = (gcnew System::Windows::Forms::Button());
			this->payfees = (gcnew System::Windows::Forms::Button());
			this->profile = (gcnew System::Windows::Forms::Button());
			this->viewgrades = (gcnew System::Windows::Forms::Button());
			this->logout = (gcnew System::Windows::Forms::Button());
			this->transcript = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(358, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(241, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Student Dashboard";
			// 
			// enroll
			// 
			this->enroll->Location = System::Drawing::Point(228, 170);
			this->enroll->Name = L"enroll";
			this->enroll->Size = System::Drawing::Size(158, 23);
			this->enroll->TabIndex = 1;
			this->enroll->Text = L"Enroll In Course";
			this->enroll->UseVisualStyleBackColor = true;
			this->enroll->Click += gcnew System::EventHandler(this, &Student::button1_Click);
			// 
			// payfees
			// 
			this->payfees->Location = System::Drawing::Point(470, 170);
			this->payfees->Name = L"payfees";
			this->payfees->Size = System::Drawing::Size(129, 23);
			this->payfees->TabIndex = 3;
			this->payfees->Text = L"Pay School Fees";
			this->payfees->UseVisualStyleBackColor = true;
			this->payfees->Click += gcnew System::EventHandler(this, &Student::button3_Click);
			// 
			// profile
			// 
			this->profile->Location = System::Drawing::Point(228, 284);
			this->profile->Name = L"profile";
			this->profile->Size = System::Drawing::Size(129, 23);
			this->profile->TabIndex = 4;
			this->profile->Text = L"Manage Profile";
			this->profile->UseVisualStyleBackColor = true;
			this->profile->Click += gcnew System::EventHandler(this, &Student::button4_Click);
			// 
			// viewgrades
			// 
			this->viewgrades->Location = System::Drawing::Point(657, 170);
			this->viewgrades->Name = L"viewgrades";
			this->viewgrades->Size = System::Drawing::Size(129, 23);
			this->viewgrades->TabIndex = 6;
			this->viewgrades->Text = L"View Grades";
			this->viewgrades->UseVisualStyleBackColor = true;
			this->viewgrades->Click += gcnew System::EventHandler(this, &Student::button5_Click);
			// 
			// logout
			// 
			this->logout->Location = System::Drawing::Point(470, 284);
			this->logout->Name = L"logout";
			this->logout->Size = System::Drawing::Size(129, 23);
			this->logout->TabIndex = 7;
			this->logout->Text = L"Logout";
			this->logout->UseVisualStyleBackColor = true;
			this->logout->Click += gcnew System::EventHandler(this, &Student::button6_Click);
			// 
			// transcript
			// 
			this->transcript->Location = System::Drawing::Point(657, 284);
			this->transcript->Name = L"transcript";
			this->transcript->Size = System::Drawing::Size(129, 23);
			this->transcript->TabIndex = 8;
			this->transcript->Text = L"View Transcript";
			this->transcript->UseVisualStyleBackColor = true;
			this->transcript->Click += gcnew System::EventHandler(this, &Student::transcript_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 177);
			this->pictureBox1->TabIndex = 62;
			this->pictureBox1->TabStop = false;
			// 
			// Student
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(815, 465);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->transcript);
			this->Controls->Add(this->logout);
			this->Controls->Add(this->viewgrades);
			this->Controls->Add(this->profile);
			this->Controls->Add(this->payfees);
			this->Controls->Add(this->enroll);
			this->Controls->Add(this->label1);
			this->Name = L"Student";
			this->Text = L"Student";
			this->Load += gcnew System::EventHandler(this, &Student::Student_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		CourseRegistration^ registerCourse = gcnew CourseRegistration(id);
		registerCourse->Show();
	}
private: System::Void Student_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	PayFees^ pay = gcnew PayFees(id);
	pay->Show();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	ViewGrades^ viewg = gcnew ViewGrades(id);
	viewg->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	ManageProfile^ profile = gcnew ManageProfile(id);
	profile->Show();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void transcript_Click(System::Object^ sender, System::EventArgs^ e) {
	Transcript^ trans = gcnew Transcript(id);
	trans->Show();
}
};
}
