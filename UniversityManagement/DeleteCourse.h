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
	/// Summary for DeleteCourse
	/// </summary>
	public ref class DeleteCourse : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   MySqlDataReader^ sqlRd;
	public:
		DeleteCourse(void)
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
		~DeleteCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ del;
	protected:

	private: System::Windows::Forms::TextBox^ courseID;
	protected:

	private: System::Windows::Forms::Label^ label2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DeleteCourse::typeid));
			this->del = (gcnew System::Windows::Forms::Button());
			this->courseID = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// del
			// 
			this->del->Location = System::Drawing::Point(297, 236);
			this->del->Name = L"del";
			this->del->Size = System::Drawing::Size(75, 23);
			this->del->TabIndex = 7;
			this->del->Text = L"Delete";
			this->del->UseVisualStyleBackColor = true;
			this->del->Click += gcnew System::EventHandler(this, &DeleteCourse::del_Click);
			// 
			// courseID
			// 
			this->courseID->Location = System::Drawing::Point(297, 166);
			this->courseID->Name = L"courseID";
			this->courseID->Size = System::Drawing::Size(204, 20);
			this->courseID->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(197, 166);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 18);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Course ID";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(240, 92);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 31);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Delete Course";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-1, -3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 177);
			this->pictureBox1->TabIndex = 62;
			this->pictureBox1->TabStop = false;
			// 
			// DeleteCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(709, 440);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->del);
			this->Controls->Add(this->courseID);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"DeleteCourse";
			this->Text = L"DeleteCourse";
			this->Load += gcnew System::EventHandler(this, &DeleteCourse::DeleteCourse_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DeleteCourse_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void del_Click(System::Object ^ sender, System::EventArgs ^ e) {
	// Step 1: Get User ID from the TextBox
	String^ courseId = courseID->Text;

	if (String::IsNullOrEmpty(courseId)) {
		MessageBox::Show("Please enter a User ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	try {
		// Step 2: Establish a database connection
		sqlConn->ConnectionString = "datasource = localhost; port=3306;"
			"username=root; password=""; database=universityrecords";
		sqlConn->Open();

		// Step 3: Check if User ID exists in the database
		String^ query = "SELECT COUNT(*) FROM courses WHERE CourseID = @courseid";
		sqlCmd = gcnew MySqlCommand(query, sqlConn);
		sqlCmd->Parameters->AddWithValue("@courseid", courseId);

		int courseCount = Convert::ToInt32(sqlCmd->ExecuteScalar());

		if (courseCount == 0) {
			MessageBox::Show("Course ID not found.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
			sqlConn->Close();
			return;
		}

		// Step 4: Prompt the user for confirmation
		//DialogResult result = MessageBox::Show("Are you sure you want to delete this user?", "Confirm Deletion", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

		System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show(
			"Are you sure you want to delete this course?",
			"Confirm Deletion",
			System::Windows::Forms::MessageBoxButtons::YesNo,
			System::Windows::Forms::MessageBoxIcon::Warning
		);

		if (result == System::Windows::Forms::DialogResult::Yes) {
			// Step 5: Delete the user from the database
			query = "DELETE FROM courses WHERE CourseID = @courseid";
			sqlCmd = gcnew MySqlCommand(query, sqlConn);
			sqlCmd->Parameters->AddWithValue("@courseid", courseId);
			sqlCmd->ExecuteNonQuery();

			MessageBox::Show("Course deleted successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Hide();
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
