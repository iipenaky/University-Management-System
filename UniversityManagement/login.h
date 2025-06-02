#pragma once
#include "MainForm.h"
#include "AdminSignUp.h"
#include "PasswordReset.h"
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
	/// Summary for login
	/// </summary>
	public ref class login : public System::Windows::Forms::Form
	{
	public: String^ userId; 
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public:

	public:
		MySqlDataReader^ sqlRd;
		login(void)
		{
			InitializeComponent();
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
		~login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ loginUser;
	private: System::Windows::Forms::Label^ emailAdd;
	private: System::Windows::Forms::Label^ pass;
	protected:


	private: System::Windows::Forms::LinkLabel^ passReset;
	private: System::Windows::Forms::TextBox^ email;
	private: System::Windows::Forms::TextBox^ passkey;



	private: System::Windows::Forms::Button^ submit;
	private: System::Windows::Forms::Button^ cancel;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(login::typeid));
			this->loginUser = (gcnew System::Windows::Forms::Label());
			this->emailAdd = (gcnew System::Windows::Forms::Label());
			this->pass = (gcnew System::Windows::Forms::Label());
			this->passReset = (gcnew System::Windows::Forms::LinkLabel());
			this->email = (gcnew System::Windows::Forms::TextBox());
			this->passkey = (gcnew System::Windows::Forms::TextBox());
			this->submit = (gcnew System::Windows::Forms::Button());
			this->cancel = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// loginUser
			// 
			this->loginUser->AutoSize = true;
			this->loginUser->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginUser->ForeColor = System::Drawing::Color::White;
			this->loginUser->Location = System::Drawing::Point(398, 36);
			this->loginUser->Name = L"loginUser";
			this->loginUser->Size = System::Drawing::Size(91, 31);
			this->loginUser->TabIndex = 0;
			this->loginUser->Text = L"Log In";
			// 
			// emailAdd
			// 
			this->emailAdd->AutoSize = true;
			this->emailAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->emailAdd->ForeColor = System::Drawing::Color::White;
			this->emailAdd->Location = System::Drawing::Point(217, 114);
			this->emailAdd->Name = L"emailAdd";
			this->emailAdd->Size = System::Drawing::Size(116, 18);
			this->emailAdd->TabIndex = 1;
			this->emailAdd->Text = L"Email Address";
			// 
			// pass
			// 
			this->pass->AutoSize = true;
			this->pass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pass->ForeColor = System::Drawing::Color::White;
			this->pass->Location = System::Drawing::Point(217, 188);
			this->pass->Name = L"pass";
			this->pass->Size = System::Drawing::Size(83, 18);
			this->pass->TabIndex = 2;
			this->pass->Text = L"Password";
			// 
			// passReset
			// 
			this->passReset->AutoSize = true;
			this->passReset->Location = System::Drawing::Point(364, 240);
			this->passReset->Name = L"passReset";
			this->passReset->Size = System::Drawing::Size(117, 13);
			this->passReset->TabIndex = 3;
			this->passReset->TabStop = true;
			this->passReset->Text = L"Forgot Your Password\?";
			this->passReset->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &login::passReset_LinkClicked);
			// 
			// email
			// 
			this->email->Location = System::Drawing::Point(367, 111);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(236, 20);
			this->email->TabIndex = 4;
			// 
			// passkey
			// 
			this->passkey->Location = System::Drawing::Point(367, 181);
			this->passkey->Name = L"passkey";
			this->passkey->Size = System::Drawing::Size(236, 20);
			this->passkey->TabIndex = 5;
			// 
			// submit
			// 
			this->submit->Location = System::Drawing::Point(508, 262);
			this->submit->Name = L"submit";
			this->submit->Size = System::Drawing::Size(75, 23);
			this->submit->TabIndex = 6;
			this->submit->Text = L"Login";
			this->submit->UseVisualStyleBackColor = true;
			this->submit->Click += gcnew System::EventHandler(this, &login::submit_Click);
			// 
			// cancel
			// 
			this->cancel->Location = System::Drawing::Point(258, 262);
			this->cancel->Name = L"cancel";
			this->cancel->Size = System::Drawing::Size(75, 23);
			this->cancel->TabIndex = 7;
			this->cancel->Text = L"Cancel";
			this->cancel->UseVisualStyleBackColor = true;
			this->cancel->Click += gcnew System::EventHandler(this, &login::cancel_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 177);
			this->pictureBox1->TabIndex = 62;
			this->pictureBox1->TabStop = false;
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(865, 556);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->cancel);
			this->Controls->Add(this->submit);
			this->Controls->Add(this->passkey);
			this->Controls->Add(this->email);
			this->Controls->Add(this->passReset);
			this->Controls->Add(this->pass);
			this->Controls->Add(this->emailAdd);
			this->Controls->Add(this->loginUser);
			this->Name = L"login";
			this->Text = L"login";
			this->Load += gcnew System::EventHandler(this, &login::login_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void submit_Click(System::Object^ sender, System::EventArgs^ e) {
		// Check if email or password fields are empty
		if (email->Text->Trim() == "" || passkey->Text->Trim() == "") {
			MessageBox::Show("Please fill in both email and password fields.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Connect to the database
		sqlConn->ConnectionString = "datasource = localhost; port=3306; username=root; password=; database=universityrecords";

		// SQL query to check if the email exists
		String^ query = "SELECT * FROM users WHERE email = @Email";
		sqlCmd->CommandText = query;
		sqlCmd->Connection = sqlConn;
		sqlCmd->Parameters->Clear();
		sqlCmd->Parameters->AddWithValue("@Email", email->Text);

		try {
			sqlConn->Open();
			sqlRd = sqlCmd->ExecuteReader();

			if (sqlRd->Read()) {
				// Check if the entered password matches the one in the database
				String^ storedPassword = sqlRd["password"]->ToString();
				if (storedPassword == HashPassword(passkey->Text)) {
					userId = sqlRd["UserId"]->ToString();
					// If the password matches, navigate to the main form
					MainForm^ MDIParent = gcnew MainForm(userId);
					MDIParent->Show();
					this->Hide();
				}
				else {
					// Password doesn't match
					MessageBox::Show("Incorrect password.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else {
				// Email not found
				MessageBox::Show("Email not found. Please check your email address.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			// Close the connection
			sqlConn->Close();
		}
	}

public: String^ getUserId() { return userId; } // Public getter

private: System::Void login_Load(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
}
private: System::Void passReset_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	PasswordReset^ passreset = gcnew PasswordReset();
	passreset->Show();
}
private: System::Void cancel_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
};
}
