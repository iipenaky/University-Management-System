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
	/// Summary for Transcript
	/// </summary>
	public ref class Transcript : public System::Windows::Forms::Form
	{
	public:
		String^ userid;  // User ID to fetch the transcript for
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
	private: System::Windows::Forms::Button^ button1;
	public:
		MySqlDataReader^ sqlRd;
		Transcript(String^ id)
		{
			InitializeComponent();
			userid = id;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Transcript()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RichTextBox^ transcriptBox;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->transcriptBox = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(274, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(202, 31);
			this->label1->TabIndex = 18;
			this->label1->Text = L"View Transcript";
			// 
			// transcriptBox
			// 
			this->transcriptBox->Location = System::Drawing::Point(124, 95);
			this->transcriptBox->Name = L"transcriptBox";
			this->transcriptBox->Size = System::Drawing::Size(509, 381);
			this->transcriptBox->TabIndex = 26;
			this->transcriptBox->Text = L"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(65, 511);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 27;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Transcript::button1_Click);
			// 
			// Transcript
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(771, 546);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->transcriptBox);
			this->Controls->Add(this->label1);
			this->Name = L"Transcript";
			this->Text = L"Transcript";
			this->Load += gcnew System::EventHandler(this, &Transcript::Transcript_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Transcript_Load(System::Object^ sender, System::EventArgs^ e) {
		try {
			sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;

			// Query to fetch student's name, major, and transcript data
			sqlCmd->CommandText =
				"SELECT users.FirstName, users.LastName, students.Major, "
				"courses.CourseName, courses.Credits, enrollments.Grade "
				"FROM enrollments "
				"JOIN users ON enrollments.StudentID = users.UserID "
				"JOIN students ON enrollments.StudentID = students.StudentID "
				"JOIN courses ON enrollments.CourseID = courses.CourseID "
				"WHERE enrollments.StudentID = @StudentID";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@StudentID", userid);

			// Fetching the data into a DataTable
			sqlDt->Clear();
			sqlDtA->SelectCommand = sqlCmd;
			sqlDtA->Fill(sqlDt);

			// Check if any rows were returned
			if (sqlDt->Rows->Count > 0) {
				// Fetching student name and major for the header
				String^ studentName = sqlDt->Rows[0]["FirstName"]->ToString() + " " + sqlDt->Rows[0]["LastName"]->ToString();
				String^ studentMajor = sqlDt->Rows[0]["Major"]->ToString();

				// Clear the RichTextBox before displaying the new data
				transcriptBox->Clear();
				transcriptBox->AppendText("Student Name: " + studentName + "\n");
				transcriptBox->AppendText("Major: " + studentMajor + "\n\n");

				// Add table header for the transcript data
				transcriptBox->AppendText("Course Name\tCredits\tGrade\tGPA\n");
				transcriptBox->AppendText("---------------------------------------------\n");

				// Loop through each row and display course details
				double totalPoints = 0;
				int totalCredits = 0;
				double totalCreditsForCGPA = 0;
				double totalPointsForCGPA = 0;

				for (int i = 0; i < sqlDt->Rows->Count; i++) {
					String^ courseName = sqlDt->Rows[i]["CourseName"]->ToString();
					int credits = Convert::ToInt32(sqlDt->Rows[i]["Credits"]);
					String^ grade = sqlDt->Rows[i]["Grade"]->ToString();

					// Calculate GPA based on the grade
					double gpa = 0;
					if (grade == "A") gpa = 4.0;
					else if (grade == "A+") gpa = 4.0;
					else if (grade == "B+") gpa = 3.5;
					else if (grade == "B") gpa = 3.0;
					else if (grade == "C+") gpa = 2.5;
					else if (grade == "C") gpa = 2.0;
					else if (grade == "D+") gpa = 1.5;
					else if (grade == "D") gpa = 1.0;
					else if (grade == "F") gpa = 0.0;

					totalPoints += gpa * credits;
					totalCredits += credits;
					totalCreditsForCGPA += credits;
					totalPointsForCGPA += gpa * credits;

					// Append course details to RichTextBox
					transcriptBox->AppendText(courseName + "\t" + credits + "\t" + grade + "\t" + gpa + "\n");
				}

				// Calculate GPA and CGPA
				double gpaOverall = totalPoints / totalCredits;
				double cgpa = totalPointsForCGPA / totalCreditsForCGPA;

				// Append GPA and CGPA to RichTextBox
				transcriptBox->AppendText("---------------------------------------------\n");
				transcriptBox->AppendText("GPA: " + gpaOverall.ToString("F2") + "\n");
				transcriptBox->AppendText("CGPA: " + cgpa.ToString("F2") + "\n");
			}
			else {
				// Handle the case where no transcript data is found
				transcriptBox->Clear();
				transcriptBox->AppendText("No transcript data found for the given student ID.");
			}

			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
};
}