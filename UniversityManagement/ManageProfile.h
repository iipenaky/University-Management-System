#pragma once

namespace UniversityManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for ManageProfile
	/// </summary>
	public ref class ManageProfile : public System::Windows::Forms::Form
	{
	public:
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public:
		   String^ userid;
		ManageProfile(String^ id)
		{
			InitializeComponent();
			userid = id;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ManageProfile()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ update;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ firstname;
	private: System::Windows::Forms::TextBox^ lastname;
	private: System::Windows::Forms::TextBox^ email;
	private: System::Windows::Forms::Button^ del;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ManageProfile::typeid));
			this->update = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->firstname = (gcnew System::Windows::Forms::TextBox());
			this->lastname = (gcnew System::Windows::Forms::TextBox());
			this->email = (gcnew System::Windows::Forms::TextBox());
			this->del = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// update
			// 
			this->update->Location = System::Drawing::Point(223, 303);
			this->update->Name = L"update";
			this->update->Size = System::Drawing::Size(115, 23);
			this->update->TabIndex = 19;
			this->update->Text = L"Update Profile";
			this->update->UseVisualStyleBackColor = true;
			this->update->Click += gcnew System::EventHandler(this, &ManageProfile::update_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(268, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 31);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Manage Profile";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(293, 201);
			this->label3->Name = L"label3";
			this->label3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label3->Size = System::Drawing::Size(79, 17);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Last Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(293, 248);
			this->label4->Name = L"label4";
			this->label4->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label4->Size = System::Drawing::Size(45, 17);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Email";
			// 
			// firstname
			// 
			this->firstname->Location = System::Drawing::Point(394, 143);
			this->firstname->Name = L"firstname";
			this->firstname->Size = System::Drawing::Size(196, 20);
			this->firstname->TabIndex = 22;
			// 
			// lastname
			// 
			this->lastname->Location = System::Drawing::Point(394, 191);
			this->lastname->Name = L"lastname";
			this->lastname->Size = System::Drawing::Size(196, 20);
			this->lastname->TabIndex = 23;
			// 
			// email
			// 
			this->email->Location = System::Drawing::Point(394, 238);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(196, 20);
			this->email->TabIndex = 24;
			// 
			// del
			// 
			this->del->Location = System::Drawing::Point(454, 303);
			this->del->Name = L"del";
			this->del->Size = System::Drawing::Size(136, 23);
			this->del->TabIndex = 25;
			this->del->Text = L"Delete Account";
			this->del->UseVisualStyleBackColor = true;
			this->del->Click += gcnew System::EventHandler(this, &ManageProfile::del_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(292, 144);
			this->label5->Name = L"label5";
			this->label5->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label5->Size = System::Drawing::Size(81, 17);
			this->label5->TabIndex = 17;
			this->label5->Text = L"First Name";
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
			// ManageProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(665, 445);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->del);
			this->Controls->Add(this->email);
			this->Controls->Add(this->lastname);
			this->Controls->Add(this->firstname);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->update);
			this->Controls->Add(this->label1);
			this->Name = L"ManageProfile";
			this->Text = L"ManageProfile";
			this->Load += gcnew System::EventHandler(this, &ManageProfile::ManageProfile_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ManageProfile_Load(System::Object^ sender, System::EventArgs^ e) {
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
	}
private: System::Void update_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Open the connection
		sqlConn->Open();

		// SQL query to update the user details based on the User ID
		String^ mail = email->Text;
		String^ firstName = firstname->Text;
		String^ lastName = lastname->Text;

		if (mail == "" || firstName == "" || lastName == "") {
			MessageBox::Show("All fields must be filled out before updating.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ query = "UPDATE users SET FirstName = @FirstName, LastName = @LastName, Email = @mail WHERE UserID = @UserId";

		// Prepare the command with parameters
		sqlCmd->Connection = sqlConn;
		sqlCmd->CommandText = query;
		sqlCmd->Parameters->AddWithValue("@UserId", userid);
		sqlCmd->Parameters->AddWithValue("@FirstName", firstName);
		sqlCmd->Parameters->AddWithValue("@LastName", lastName);
		sqlCmd->Parameters->AddWithValue("@mail", mail);

		// Execute the update command
		int rowsAffected = sqlCmd->ExecuteNonQuery();

		if (rowsAffected > 0) {
			MessageBox::Show("User details updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("No user found with the given User ID.", "Update Failed", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		// Clear input fields
		email->Clear();
		firstname->Clear();
		lastname->Clear();
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error while updating user details: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		// Ensure the connection is closed
		sqlConn->Close();
		sqlCmd->Parameters->Clear(); // Clear parameters to avoid reuse issues
	}
}
private: System::Void del_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Step 2: Establish a database connection
		sqlConn->ConnectionString = "datasource = localhost; port=3306;"
			"username=root; password=""; database=universityrecords";
		sqlConn->Open();

		// Step 3: Check if User ID exists in the database
		String^ query = "SELECT COUNT(*) FROM users WHERE UserID = @userId";
		sqlCmd = gcnew MySqlCommand(query, sqlConn);
		sqlCmd->Parameters->AddWithValue("@userId", userid);

		System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show(
			"Are you sure you want to delete your account?",
			"Confirm Deletion",
			System::Windows::Forms::MessageBoxButtons::YesNo,
			System::Windows::Forms::MessageBoxIcon::Warning
		);

		if (result == System::Windows::Forms::DialogResult::Yes) {
			// Step 5: Delete the user from the database
			query = "DELETE FROM users WHERE UserID = @userId";
			sqlCmd = gcnew MySqlCommand(query, sqlConn);
			sqlCmd->Parameters->AddWithValue("@userId", userid);
			sqlCmd->ExecuteNonQuery();

			MessageBox::Show("Account deleted successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			Application::Exit();
		}

		sqlConn->Close();
	}
	catch (Exception^ ex) {
		MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		if (sqlConn->State == ConnectionState::Open) {
			sqlConn->Close();
		}
	}
}
};
}
