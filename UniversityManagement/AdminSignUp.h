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
	using namespace System::IO;
	using namespace MySql::Data::MySqlClient;
	using namespace System::Text;
	using namespace System::Security::Cryptography;

	/// <summary>
	/// Summary for AdminSignUp
	/// </summary>
	public ref class AdminSignUp : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public:
		static int userId;
		AdminSignUp(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void clearBoxes() {
			email->Text = "";
			txtFirstName->Text = "";
			txtLastName->Text = "";
			password->Text = "";
			confirmPass->Text = "";

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
		~AdminSignUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label8;
	protected:
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DateTimePicker^ dtpDateofBirth;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ confirmPass;

	private: System::Windows::Forms::TextBox^ password;

	private: System::Windows::Forms::TextBox^ email;

	private: System::Windows::Forms::TextBox^ txtLastName;

	private: System::Windows::Forms::TextBox^ txtFirstName;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminSignUp::typeid));
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dtpDateofBirth = (gcnew System::Windows::Forms::DateTimePicker());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->confirmPass = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->email = (gcnew System::Windows::Forms::TextBox());
			this->txtLastName = (gcnew System::Windows::Forms::TextBox());
			this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(204, 204);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 13);
			this->label8->TabIndex = 51;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(204, 162);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(103, 18);
			this->label7->TabIndex = 50;
			this->label7->Text = L"Date of Birth";
			// 
			// dtpDateofBirth
			// 
			this->dtpDateofBirth->Location = System::Drawing::Point(365, 160);
			this->dtpDateofBirth->Name = L"dtpDateofBirth";
			this->dtpDateofBirth->Size = System::Drawing::Size(237, 20);
			this->dtpDateofBirth->TabIndex = 49;
			// 
			// button2
			// 
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(307, 380);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 48;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminSignUp::button2_Click);
			// 
			// button1
			// 
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(527, 380);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 47;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminSignUp::button1_Click);
			// 
			// confirmPass
			// 
			this->confirmPass->Location = System::Drawing::Point(365, 284);
			this->confirmPass->Name = L"confirmPass";
			this->confirmPass->Size = System::Drawing::Size(237, 20);
			this->confirmPass->TabIndex = 46;
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(365, 238);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(237, 20);
			this->password->TabIndex = 45;
			// 
			// email
			// 
			this->email->Location = System::Drawing::Point(365, 197);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(237, 20);
			this->email->TabIndex = 44;
			// 
			// txtLastName
			// 
			this->txtLastName->Location = System::Drawing::Point(365, 117);
			this->txtLastName->Name = L"txtLastName";
			this->txtLastName->Size = System::Drawing::Size(237, 20);
			this->txtLastName->TabIndex = 43;
			// 
			// txtFirstName
			// 
			this->txtFirstName->Location = System::Drawing::Point(365, 85);
			this->txtFirstName->Name = L"txtFirstName";
			this->txtFirstName->Size = System::Drawing::Size(237, 20);
			this->txtFirstName->TabIndex = 42;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(204, 284);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(148, 18);
			this->label6->TabIndex = 41;
			this->label6->Text = L"Confirm Password";
			this->label6->Click += gcnew System::EventHandler(this, &AdminSignUp::label6_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(204, 240);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(83, 18);
			this->label5->TabIndex = 40;
			this->label5->Text = L"Password";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(204, 199);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 18);
			this->label4->TabIndex = 39;
			this->label4->Text = L"Email";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(204, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 18);
			this->label3->TabIndex = 38;
			this->label3->Text = L"Last Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::IndianRed;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(196, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 18);
			this->label2->TabIndex = 37;
			this->label2->Text = L"First Name";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::IndianRed;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(291, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(188, 33);
			this->label1->TabIndex = 36;
			this->label1->Text = L"Admin SignUp";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1, -6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 177);
			this->pictureBox1->TabIndex = 62;
			this->pictureBox1->TabStop = false;
			// 
			// AdminSignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(802, 455);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->dtpDateofBirth);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->confirmPass);
			this->Controls->Add(this->password);
			this->Controls->Add(this->email);
			this->Controls->Add(this->txtLastName);
			this->Controls->Add(this->txtFirstName);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::White;
			this->Name = L"AdminSignUp";
			this->Text = L"AdminSignUp";
			this->Load += gcnew System::EventHandler(this, &AdminSignUp::AdminSignUp_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			sqlConn->ConnectionString = "datasource = localhost; port=3306;"
				"username=root; password=""; database=universityrecords";
			String^ firstName = txtFirstName->Text->Trim();
			String^ lastName = txtLastName->Text->Trim();
			DateTime dateOfBirth = dtpDateofBirth->Value;
			String^ emailA = email->Text->Trim();
			String^ passwordA = password->Text->Trim();
			String^ confirmPassW = confirmPass->Text->Trim();
			bool isValid = true;

			if (firstName->Length == 0) {
				MessageBox::Show("Please enter the first name");
				isValid = false;
			}
			if (lastName->Length == 0) {
				MessageBox::Show("Please enter the last name");
				isValid = false;
			}
			if (emailA->Length == 0) {
				MessageBox::Show("Please enter the email");
				isValid = false;
			}
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
					// Open connection first
					sqlConn->Open();

					// Insert into users table
					sqlCmd->Connection = sqlConn;
					sqlCmd->CommandText = "INSERT INTO users (FirstName, LastName, DateOfBirth, Email, Password, role) "
						"VALUES (@firstName, @lastName, @dateOfBirth, @emailA, @passwordA, 'admin');"
						"SELECT LAST_INSERT_ID();";  // Get the last inserted UserID

					// Add parameters for users table
					sqlCmd->Parameters->AddWithValue("@firstName", firstName);
					sqlCmd->Parameters->AddWithValue("@lastName", lastName);
					sqlCmd->Parameters->AddWithValue("@dateOfBirth", dateOfBirth);
					sqlCmd->Parameters->AddWithValue("@emailA", emailA);
					sqlCmd->Parameters->AddWithValue("@passwordA", hashedPassword);

					// Execute the query and get the last inserted ID (UserID)
					userId = Convert::ToInt32(sqlCmd->ExecuteScalar());  // ExecuteScalar returns the value of the first column in the first row

					// Insert into admin table using the UserID
					sqlCmd->CommandText = "INSERT INTO admin (AdminID) VALUES (@userId)";
					sqlCmd->Parameters->Clear();  // Clear previous parameters
					sqlCmd->Parameters->AddWithValue("@userId", userId);  // Add the UserID parameter

					// Execute the insert for admin table
					sqlCmd->ExecuteNonQuery();

					// Clear input fields after successful insert
					clearBoxes();
					MessageBox::Show("Admin added successfully! Login");
					Application::Exit();
				}
				catch (Exception^ ex) {
					MessageBox::Show("Inserting Data Failed: " + ex->Message);
				}
				finally {
					sqlConn->Close();  // Ensure the connection is closed even if an exception occurs
				}
			}
		}

private: System::Void AdminSignUp_Load(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}