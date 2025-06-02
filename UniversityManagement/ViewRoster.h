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
	/// Summary for ViewRoster
	/// </summary>
	public ref class ViewRoster : public System::Windows::Forms::Form
	{
	public:
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
		String^ userid;

		ViewRoster(String^ id)
		{
			InitializeComponent();
			userid = id;
		}

	protected:
		~ViewRoster()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::DataGridView^ dataGridView1;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(169, 102);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(189, 20);
			this->textBox1->TabIndex = 16;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(446, 96);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ViewRoster::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(34, 101);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 18);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Course";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(267, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(227, 31);
			this->label1->TabIndex = 10;
			this->label1->Text = L"View Class Roster";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(37, 161);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(639, 299);
			this->dataGridView1->TabIndex = 17;
			// 
			// ViewRoster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(745, 472);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Name = L"ViewRoster";
			this->Text = L"ViewRoster";
			this->Load += gcnew System::EventHandler(this, &ViewRoster::ViewRoster_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Form Load event to populate initial information if needed
	private: System::Void ViewRoster_Load(System::Object^ sender, System::EventArgs^ e) {
		// No need to load courses since we're now using a TextBox for input
	}

		   // Submit button click event to fetch and display enrolled students
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Get the course ID entered by the faculty
	String^ courseID = textBox1->Text;

	// Check if the input is valid (non-empty)
	if (String::IsNullOrEmpty(courseID)) {
		MessageBox::Show("Please enter a valid course ID.");
		return;
	}

	// SQL query to fetch students enrolled in the course and check if the faculty is assigned to the course
	String^ query = "SELECT e.StudentID, u.FirstName, u.LastName, e.Grade "
		"FROM Enrollments e "
		"JOIN Users u ON e.StudentID = u.UserID "
		"WHERE e.CourseID = @courseID";

	// Check if the faculty is assigned to this course
	String^ facultyQuery = "SELECT COUNT(*) "
		"FROM CourseFaculty cf "
		"WHERE cf.CourseID = @courseID AND cf.FacultyID = @facultyID";

	try {
		// Set up the connection string
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
		sqlConn->Open();
		sqlCmd->Connection = sqlConn;

		// Check if the faculty is assigned to this course
		sqlCmd->CommandText = facultyQuery;
		sqlCmd->Parameters->Clear();
		sqlCmd->Parameters->AddWithValue("@courseID", courseID);
		sqlCmd->Parameters->AddWithValue("@facultyID", userid); // Use the logged-in faculty's user ID

		int facultyCount = Convert::ToInt32(sqlCmd->ExecuteScalar());

		if (facultyCount == 0) {
			MessageBox::Show("You are not assigned to this course.");
			return;
		}

		// Now fetch the students enrolled in the course
		sqlCmd->CommandText = query;
		sqlCmd->Parameters->Clear();
		sqlCmd->Parameters->AddWithValue("@courseID", courseID);

		sqlDtA->SelectCommand = sqlCmd;
		sqlDt->Clear();
		sqlDtA->Fill(sqlDt);

		// Bind the result to DataGridView
		dataGridView1->DataSource = sqlDt;

		// If there are no students enrolled, inform the faculty
		if (sqlDt->Rows->Count == 0) {
			MessageBox::Show("No students are enrolled in this course.");
		}

	}
	catch (MySqlException^ ex) {
		MessageBox::Show("MySQL Error: " + ex->Message);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}
	finally {
		// Always close the connection
		if (sqlConn->State == System::Data::ConnectionState::Open) {
			sqlConn->Close();
		}
	}
}


	};
}
