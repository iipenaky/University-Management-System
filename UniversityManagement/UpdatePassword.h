#pragma once
#using <System.dll>
#using <System.Security.dll>
namespace UniversityManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace System::Text;
	using namespace System::Security::Cryptography;


	/// <summary>
	/// Summary for UpdatePassword
	/// </summary>
	public ref class UpdatePassword : public System::Windows::Forms::Form
	{
	public:
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
		String^ userid;
		UpdatePassword(String^ id)
		{
			InitializeComponent();
			userid = id;
			//
			//TODO: Add the constructor code here
			//
		}
		String^ HashPassword(String^ password) {
			array<Byte>^ passwordBytes = Encoding::UTF8->GetBytes(password);
			SHA256^ sha256 = SHA256::Create();
			array<Byte>^ hashBytes = sha256->ComputeHash(passwordBytes);
			return BitConverter::ToString(hashBytes)->Replace("-", "");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UpdatePassword()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ newpass;
	private: System::Windows::Forms::TextBox^ conPass;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ update;

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
			this->newpass = (gcnew System::Windows::Forms::TextBox());
			this->conPass = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->update = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(21, 141);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"New Password";
			// 
			// newpass
			// 
			this->newpass->Location = System::Drawing::Point(179, 139);
			this->newpass->Name = L"newpass";
			this->newpass->Size = System::Drawing::Size(233, 20);
			this->newpass->TabIndex = 1;
			// 
			// conPass
			// 
			this->conPass->Location = System::Drawing::Point(175, 228);
			this->conPass->Name = L"conPass";
			this->conPass->Size = System::Drawing::Size(233, 20);
			this->conPass->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(12, 230);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(148, 18);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Confirm Password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::IndianRed;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(105, 33);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(198, 31);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Reset Password";
			// 
			// update
			// 
			this->update->Location = System::Drawing::Point(121, 273);
			this->update->Name = L"update";
			this->update->Size = System::Drawing::Size(75, 23);
			this->update->TabIndex = 5;
			this->update->Text = L"Update";
			this->update->UseVisualStyleBackColor = true;
			this->update->Click += gcnew System::EventHandler(this, &UpdatePassword::update_Click);
			// 
			// UpdatePassword
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(445, 370);
			this->Controls->Add(this->update);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->conPass);
			this->Controls->Add(this->newpass);
			this->Controls->Add(this->label1);
			this->Name = L"UpdatePassword";
			this->Text = L"UpdatePassword";
			this->Load += gcnew System::EventHandler(this, &UpdatePassword::UpdatePassword_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UpdatePassword_Load(System::Object^ sender, System::EventArgs^ e) {
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
	}
private: System::Void update_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ passwordA = newpass->Text->Trim();
	String^ confirmPassW = conPass->Text->Trim();
	bool isValid = true;
	if (passwordA->Length == 0) {
		MessageBox::Show("Please enter the password");
		isValid = false;
	}
	if (confirmPassW->Length == 0) {
		MessageBox::Show("Please confirm Password");
		isValid = false;
	}
	if (confirmPassW != passwordA) {
		MessageBox::Show("Passwords do not match, please check.");
		isValid = false;
	}
	if (isValid) {
		try {
			String^ hashedPassword = HashPassword(passwordA);
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "UPDATE users SET password = @pass WHERE UserID = @user";
			sqlCmd->Parameters->AddWithValue("@user", userid);
			sqlCmd->Parameters->AddWithValue("@pass", hashedPassword);
			sqlCmd->ExecuteNonQuery();
			sqlConn->Close();
			MessageBox::Show("Password Changed!! reload the page again to sign in!");
			Application::Exit();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Updating Password Failed: " + ex->Message);
		}
		finally {
			sqlConn->Close();  
		}
	}
	
}
};
}
