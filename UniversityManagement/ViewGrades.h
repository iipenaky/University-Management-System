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
	/// Summary for ViewGrades
	/// </summary>
	public ref class ViewGrades : public System::Windows::Forms::Form
	{
	public:
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
		String^ userid;
		ViewGrades(String^ id)
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
		~ViewGrades()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ viewG;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ courseId;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label3;

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
			this->viewG = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->courseId = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// viewG
			// 
			this->viewG->Location = System::Drawing::Point(155, 95);
			this->viewG->Name = L"viewG";
			this->viewG->Size = System::Drawing::Size(80, 23);
			this->viewG->TabIndex = 15;
			this->viewG->Text = L"View Grades";
			this->viewG->UseVisualStyleBackColor = true;
			this->viewG->Click += gcnew System::EventHandler(this, &ViewGrades::viewG_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(12, 96);
			this->label2->Name = L"label2";
			this->label2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label2->Size = System::Drawing::Size(73, 19);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Course ID";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(277, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 31);
			this->label1->TabIndex = 12;
			this->label1->Text = L"View Grades";
			// 
			// courseId
			// 
			this->courseId->Location = System::Drawing::Point(103, 95);
			this->courseId->Name = L"courseId";
			this->courseId->Size = System::Drawing::Size(46, 20);
			this->courseId->TabIndex = 16;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(253, 120);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(472, 286);
			this->dataGridView1->TabIndex = 17;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(457, 83);
			this->label3->Name = L"label3";
			this->label3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label3->Size = System::Drawing::Size(53, 19);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Grades";
			// 
			// ViewGrades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(737, 461);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->courseId);
			this->Controls->Add(this->viewG);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ViewGrades";
			this->Text = L"ViewGrades";
			this->Load += gcnew System::EventHandler(this, &ViewGrades::ViewGrades_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ViewGrades_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void viewG_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Database connection string (update with your credentials)
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
		sqlConn->Open();

		// Query to fetch grades for the logged-in student
		String^ query = "SELECT c.CourseName, e.Grade, e.Semester, e.EnrollmentDate " +
			"FROM Enrollments e " +
			"JOIN Courses c ON e.CourseID = c.CourseID " +
			"WHERE e.StudentID = @StudentID";

		// Prepare the SQL command
		sqlCmd->Connection = sqlConn;
		sqlCmd->CommandText = query;
		sqlCmd->Parameters->AddWithValue("@StudentID", userid);

		// Execute the query and fill the DataGridView
		sqlDtA->SelectCommand = sqlCmd;
		sqlDt->Clear();
		sqlDtA->Fill(sqlDt);
		dataGridView1->DataSource = sqlDt;

		// Inform the user
		MessageBox::Show("Grades loaded successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		sqlConn->Close();
	}
}

};
}
