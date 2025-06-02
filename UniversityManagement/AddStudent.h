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
	/// Summary for AddStudent
	/// </summary>
	public ref class AddStudent : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   MySqlDataReader^ sqlRd;
	public:
		AddStudent(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void clearBoxes() {
			email->Text = "";
			firstname->Text = "";
			lastname->Text = "";
			password->Text = "";
			comfirmpassW->Text = "";
			major->Text = "";

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
		~AddStudent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^ enrollmendate;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DateTimePicker^ dob;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ submit;

	private: System::Windows::Forms::TextBox^ comfirmpassW;


	private: System::Windows::Forms::TextBox^ password;

	private: System::Windows::Forms::TextBox^ email;

	private: System::Windows::Forms::TextBox^ lastname;

	private: System::Windows::Forms::TextBox^ firstname;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ major;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddStudent::typeid));
			this->enrollmendate = (gcnew System::Windows::Forms::DateTimePicker());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dob = (gcnew System::Windows::Forms::DateTimePicker());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->submit = (gcnew System::Windows::Forms::Button());
			this->comfirmpassW = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->email = (gcnew System::Windows::Forms::TextBox());
			this->lastname = (gcnew System::Windows::Forms::TextBox());
			this->firstname = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->major = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// enrollmendate
			// 
			this->enrollmendate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->enrollmendate->Location = System::Drawing::Point(410, 255);
			this->enrollmendate->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->enrollmendate->Name = L"enrollmendate";
			this->enrollmendate->Size = System::Drawing::Size(276, 20);
			this->enrollmendate->TabIndex = 33;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(222, 257);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(129, 18);
			this->label8->TabIndex = 32;
			this->label8->Text = L"Enrollment Date";
			this->label8->Click += gcnew System::EventHandler(this, &AddStudent::label8_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(222, 219);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(103, 18);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Date of Birth";
			this->label7->Click += gcnew System::EventHandler(this, &AddStudent::label7_Click);
			// 
			// dob
			// 
			this->dob->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dob->Location = System::Drawing::Point(410, 217);
			this->dob->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->dob->Name = L"dob";
			this->dob->Size = System::Drawing::Size(276, 20);
			this->dob->TabIndex = 30;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(243, 444);
			this->button2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(88, 23);
			this->button2->TabIndex = 29;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AddStudent::button2_Click);
			// 
			// submit
			// 
			this->submit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->submit->Location = System::Drawing::Point(465, 444);
			this->submit->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->submit->Name = L"submit";
			this->submit->Size = System::Drawing::Size(88, 23);
			this->submit->TabIndex = 28;
			this->submit->Text = L"Submit";
			this->submit->UseVisualStyleBackColor = true;
			this->submit->Click += gcnew System::EventHandler(this, &AddStudent::button1_Click);
			// 
			// comfirmpassW
			// 
			this->comfirmpassW->Location = System::Drawing::Point(410, 403);
			this->comfirmpassW->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->comfirmpassW->Name = L"comfirmpassW";
			this->comfirmpassW->Size = System::Drawing::Size(276, 20);
			this->comfirmpassW->TabIndex = 27;
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(410, 366);
			this->password->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(276, 20);
			this->password->TabIndex = 26;
			// 
			// email
			// 
			this->email->Location = System::Drawing::Point(410, 293);
			this->email->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(276, 20);
			this->email->TabIndex = 25;
			// 
			// lastname
			// 
			this->lastname->Location = System::Drawing::Point(410, 174);
			this->lastname->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->lastname->Name = L"lastname";
			this->lastname->Size = System::Drawing::Size(276, 20);
			this->lastname->TabIndex = 24;
			// 
			// firstname
			// 
			this->firstname->Location = System::Drawing::Point(410, 142);
			this->firstname->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->firstname->Name = L"firstname";
			this->firstname->Size = System::Drawing::Size(276, 20);
			this->firstname->TabIndex = 23;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(222, 405);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(153, 18);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Comfirm Password";
			this->label6->Click += gcnew System::EventHandler(this, &AddStudent::label6_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(222, 368);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(83, 18);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Password";
			this->label5->Click += gcnew System::EventHandler(this, &AddStudent::label5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(222, 295);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 18);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Email";
			this->label4->Click += gcnew System::EventHandler(this, &AddStudent::label4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(222, 176);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 18);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Last Name";
			this->label3->Click += gcnew System::EventHandler(this, &AddStudent::label3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(220, 144);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 18);
			this->label2->TabIndex = 18;
			this->label2->Text = L"First Name";
			this->label2->Click += gcnew System::EventHandler(this, &AddStudent::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(345, 71);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 31);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Add Student";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(222, 338);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(51, 18);
			this->label9->TabIndex = 34;
			this->label9->Text = L"Major";
			this->label9->Click += gcnew System::EventHandler(this, &AddStudent::label9_Click);
			// 
			// major
			// 
			this->major->FormattingEnabled = true;
			this->major->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Computer Science", L"Business Administration", L"Computer Engineering",
					L"Mechanical Engineering", L"Electrical Engineering ", L"Mechatronics"
			});
			this->major->Location = System::Drawing::Point(412, 335);
			this->major->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->major->Name = L"major";
			this->major->Size = System::Drawing::Size(274, 21);
			this->major->TabIndex = 35;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-1, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 177);
			this->pictureBox1->TabIndex = 62;
			this->pictureBox1->TabStop = false;
			// 
			// AddStudent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(904, 530);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->major);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->enrollmendate);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->dob);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->submit);
			this->Controls->Add(this->comfirmpassW);
			this->Controls->Add(this->password);
			this->Controls->Add(this->email);
			this->Controls->Add(this->lastname);
			this->Controls->Add(this->firstname);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"AddStudent";
			this->Text = L"AddStudent";
			this->Load += gcnew System::EventHandler(this, &AddStudent::AddStudent_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	sqlConn->ConnectionString = "datasource = localhost; port=3306;"
		"username=root; password=""; database=universityrecords";
	String^ firstNameF = firstname->Text->Trim();
	String^ lastNameF = lastname->Text->Trim();
	DateTime dateOfBirth = dob->Value;
	DateTime enrollmentDate = enrollmendate->Value;
	String^ emailF = email->Text->Trim();
	String^ passwordF = password->Text->Trim();
	String^ confirmPassW = comfirmpassW->Text->Trim();
	String^ majorS = major->SelectedItem->ToString();
	bool isValid = true;

	if (firstNameF->Length == 0) {
		MessageBox::Show("Please enter the first name");
		isValid = false;
	}
	if (lastNameF->Length == 0) {
		MessageBox::Show("Please enter the last name");
		isValid = false;
	}
	if (emailF->Length == 0) {
		MessageBox::Show("Please enter the email");
		isValid = false;
	}
	if (passwordF->Length == 0) {
		MessageBox::Show("Please enter the password");
		isValid = false;
	}
	if (confirmPassW->Length == 0) {
		MessageBox::Show("Please confirm Password");
		isValid = false;
	}
	if (!passwordF->Equals(confirmPassW)) {
		MessageBox::Show("Passwords do not match, please check.");
		isValid = false;
	}
	if (major->SelectedItem == nullptr) {
		MessageBox::Show("Please select a major.");
		isValid = false;
	}
	if (!emailF->Contains("@") || !emailF->Contains(".")) {
		MessageBox::Show("Please enter a valid email address.");
		isValid = false;
	}

	if (isValid) {
		try {
			String^ hashedPassword = HashPassword(passwordF);
			sqlConn->Open();

			// Insert into users table
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "INSERT INTO users (FirstName, LastName, DateOfBirth, Email, Password, role) "
				"VALUES (@firstName, @lastName, @dateOfBirth, @emailA, @passwordA, 'student');";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@firstName", firstNameF);
			sqlCmd->Parameters->AddWithValue("@lastName", lastNameF);
			sqlCmd->Parameters->AddWithValue("@dateOfBirth", dateOfBirth);
			sqlCmd->Parameters->AddWithValue("@emailA", emailF);
			sqlCmd->Parameters->AddWithValue("@passwordA", hashedPassword);

			sqlCmd->ExecuteNonQuery();

			// Get the last inserted UserID
			sqlCmd->CommandText = "SELECT LAST_INSERT_ID();";
			int userId = Convert::ToInt32(sqlCmd->ExecuteScalar());

			// Insert into students table
			sqlCmd->CommandText = "INSERT INTO students (StudentID, Major, EnrollmentDate) "
				"VALUES (@userId, @major, @enrollmentDate);";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@userId", userId);
			sqlCmd->Parameters->AddWithValue("@major", majorS);
			sqlCmd->Parameters->AddWithValue("@enrollmentDate", enrollmentDate);

			sqlCmd->ExecuteNonQuery();

			// Insert into payments table
			sqlCmd->CommandText = "INSERT INTO payments (StudentID, Semester, TotalAmount, PaidAmount) "
				"VALUES (@userId, 'Spring', 70000, 0.0);";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@userId", userId);

			sqlCmd->ExecuteNonQuery();

			clearBoxes();
			MessageBox::Show("Student added successfully!");
			this->Hide();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
		finally {
			sqlConn->Close();
		}
	}
}
private: System::Void major_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void AddStudent_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
