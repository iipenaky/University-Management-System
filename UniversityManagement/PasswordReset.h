#pragma once
#include "UpdatePassword.h"

namespace UniversityManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for PasswordReset
	/// </summary>
	public ref class PasswordReset : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();

	private: System::Windows::Forms::Button^ update;

		   MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
	public:
		PasswordReset()
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
		~PasswordReset()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ userid;
	private: System::Windows::Forms::TextBox^ email;

	protected:

	protected:


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;



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
			this->userid = (gcnew System::Windows::Forms::TextBox());
			this->email = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->update = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// userid
			// 
			this->userid->Location = System::Drawing::Point(343, 116);
			this->userid->Name = L"userid";
			this->userid->Size = System::Drawing::Size(233, 20);
			this->userid->TabIndex = 0;
			// 
			// email
			// 
			this->email->Location = System::Drawing::Point(343, 179);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(233, 20);
			this->email->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(142, 118);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 18);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Identification Number";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(142, 181);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(116, 18);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Email Address";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(142, 252);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Date of Birth";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(213, 49);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(233, 31);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Retrieve Password";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(343, 252);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(233, 20);
			this->dateTimePicker1->TabIndex = 7;
			// 
			// update
			// 
			this->update->Location = System::Drawing::Point(277, 323);
			this->update->Name = L"update";
			this->update->Size = System::Drawing::Size(75, 23);
			this->update->TabIndex = 10;
			this->update->Text = L"Update";
			this->update->UseVisualStyleBackColor = true;
			this->update->Click += gcnew System::EventHandler(this, &PasswordReset::update_Click);
			// 
			// PasswordReset
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(679, 475);
			this->Controls->Add(this->update);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->email);
			this->Controls->Add(this->userid);
			this->Name = L"PasswordReset";
			this->Text = L"PasswordReset";
			this->Load += gcnew System::EventHandler(this, &PasswordReset::PasswordReset_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PasswordReset_Load(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void update_Click(System::Object^ sender, System::EventArgs^ e) {
	// Set the connection string
	sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
	sqlConn->Open();
	String^ userEmail = email->Text;
	String^ userDOB = dateTimePicker1->Value.ToString("yyyy-MM-dd");
	String^ userID = userid->Text;
	String^ query = "SELECT Password FROM users WHERE UserID = @UserID AND Email = @Email AND DateOfBirth = @DOB";

	// Prepare the command
	sqlCmd->Connection = sqlConn;
	sqlCmd->CommandText = query;
	sqlCmd->Parameters->Clear();
	sqlCmd->Parameters->AddWithValue("@UserID", userID);
	sqlCmd->Parameters->AddWithValue("@Email", userEmail);
	sqlCmd->Parameters->AddWithValue("@DOB", userDOB);

	UpdatePassword^ upd = gcnew UpdatePassword(userID);
	this->Hide();
	upd->Show();

}
};
}
