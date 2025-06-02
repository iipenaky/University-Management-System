#pragma once
#include "EnterGrades.h"
#include "ViewRoster.h"
#include "ManageProfile.h"
#include "ManageCourseMaterials.h"
#include "VerifyEnrollment.h"
namespace UniversityManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Faculty
	/// </summary>
	public ref class Faculty : public System::Windows::Forms::Form
	{
	public:
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public:
		String^ id;
		Faculty(String^ userid)
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
		~Faculty()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ logout;
	protected:

	private: System::Windows::Forms::Button^ viewRos;
	private: System::Windows::Forms::Button^ manageP;
	protected:


	private: System::Windows::Forms::Button^ eneterG;

	private: System::Windows::Forms::Button^ manageC;


	private: System::Windows::Forms::Label^ label1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Faculty::typeid));
			this->logout = (gcnew System::Windows::Forms::Button());
			this->viewRos = (gcnew System::Windows::Forms::Button());
			this->manageP = (gcnew System::Windows::Forms::Button());
			this->eneterG = (gcnew System::Windows::Forms::Button());
			this->manageC = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// logout
			// 
			this->logout->Location = System::Drawing::Point(512, 290);
			this->logout->Name = L"logout";
			this->logout->Size = System::Drawing::Size(129, 23);
			this->logout->TabIndex = 14;
			this->logout->Text = L"Logout";
			this->logout->UseVisualStyleBackColor = true;
			this->logout->Click += gcnew System::EventHandler(this, &Faculty::logout_Click);
			// 
			// viewRos
			// 
			this->viewRos->Location = System::Drawing::Point(503, 200);
			this->viewRos->Name = L"viewRos";
			this->viewRos->Size = System::Drawing::Size(129, 23);
			this->viewRos->TabIndex = 13;
			this->viewRos->Text = L"View Class Roster";
			this->viewRos->UseVisualStyleBackColor = true;
			this->viewRos->Click += gcnew System::EventHandler(this, &Faculty::button5_Click);
			// 
			// manageP
			// 
			this->manageP->Location = System::Drawing::Point(42, 290);
			this->manageP->Name = L"manageP";
			this->manageP->Size = System::Drawing::Size(158, 23);
			this->manageP->TabIndex = 12;
			this->manageP->Text = L"Manage Profile";
			this->manageP->UseVisualStyleBackColor = true;
			this->manageP->Click += gcnew System::EventHandler(this, &Faculty::button4_Click);
			// 
			// eneterG
			// 
			this->eneterG->Location = System::Drawing::Point(300, 200);
			this->eneterG->Name = L"eneterG";
			this->eneterG->Size = System::Drawing::Size(129, 23);
			this->eneterG->TabIndex = 11;
			this->eneterG->Text = L"Enter Grades";
			this->eneterG->UseVisualStyleBackColor = true;
			this->eneterG->Click += gcnew System::EventHandler(this, &Faculty::button3_Click);
			// 
			// manageC
			// 
			this->manageC->Location = System::Drawing::Point(42, 200);
			this->manageC->Name = L"manageC";
			this->manageC->Size = System::Drawing::Size(158, 23);
			this->manageC->TabIndex = 9;
			this->manageC->Text = L"Add Course Materials";
			this->manageC->UseVisualStyleBackColor = true;
			this->manageC->Click += gcnew System::EventHandler(this, &Faculty::manageC_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(237, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(239, 31);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Faculty Dashboard";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(283, 290);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(158, 23);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Verify Enrollment";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Faculty::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-8, -14);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 177);
			this->pictureBox1->TabIndex = 62;
			this->pictureBox1->TabStop = false;
			// 
			// Faculty
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(682, 409);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->logout);
			this->Controls->Add(this->viewRos);
			this->Controls->Add(this->manageP);
			this->Controls->Add(this->eneterG);
			this->Controls->Add(this->manageC);
			this->Controls->Add(this->label1);
			this->Name = L"Faculty";
			this->Text = L"Faculty";
			this->Load += gcnew System::EventHandler(this, &Faculty::Faculty_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		EnterGrades^ enterg = gcnew EnterGrades(id);
		enterg->Show();
	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	ViewRoster^ registerCourse = gcnew ViewRoster(id);
	registerCourse->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	ManageProfile^ manaP = gcnew ManageProfile(id);
	manaP->Show();
}
private: System::Void Faculty_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void manageC_Click(System::Object^ sender, System::EventArgs^ e) {
	ManageCourseMaterials^ manac = gcnew ManageCourseMaterials(id);
	manac->Show();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	VerifyEnrollment^ manac = gcnew VerifyEnrollment(id);
	manac->Show();
}

private: System::Void logout_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
};
}
