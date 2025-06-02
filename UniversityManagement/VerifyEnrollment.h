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
	/// Summary for VerifyEnrollment
	/// </summary>
	public ref class VerifyEnrollment : public System::Windows::Forms::Form
	{
		String^ userid;
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
	private: System::Windows::Forms::Label^ label1;
		   MySqlDataReader^ sqlRd;

	public:
		VerifyEnrollment(String^ id)
		{
			InitializeComponent();
			userid = id;
		}

	protected:
		~VerifyEnrollment()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		// UI Controls
		System::Windows::Forms::TextBox^ courseIdTextBox;
		System::Windows::Forms::Button^ loadEnrollmentsButton;
		System::Windows::Forms::ListBox^ enrollmentsListBox;
		System::Windows::Forms::Button^ approveButton;
		System::Windows::Forms::Button^ rejectButton;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->courseIdTextBox = (gcnew System::Windows::Forms::TextBox());
			this->loadEnrollmentsButton = (gcnew System::Windows::Forms::Button());
			this->enrollmentsListBox = (gcnew System::Windows::Forms::ListBox());
			this->approveButton = (gcnew System::Windows::Forms::Button());
			this->rejectButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// courseIdTextBox
			// 
			this->courseIdTextBox->Location = System::Drawing::Point(127, 50);
			this->courseIdTextBox->Name = L"courseIdTextBox";
			this->courseIdTextBox->Size = System::Drawing::Size(200, 20);
			this->courseIdTextBox->TabIndex = 0;
			// 
			// loadEnrollmentsButton
			// 
			this->loadEnrollmentsButton->Location = System::Drawing::Point(347, 47);
			this->loadEnrollmentsButton->Name = L"loadEnrollmentsButton";
			this->loadEnrollmentsButton->Size = System::Drawing::Size(75, 23);
			this->loadEnrollmentsButton->TabIndex = 1;
			this->loadEnrollmentsButton->Text = L"Load Enrollments";
			this->loadEnrollmentsButton->UseVisualStyleBackColor = true;
			this->loadEnrollmentsButton->Click += gcnew System::EventHandler(this, &VerifyEnrollment::loadEnrollmentsButton_Click);
			// 
			// enrollmentsListBox
			// 
			this->enrollmentsListBox->FormattingEnabled = true;
			this->enrollmentsListBox->Location = System::Drawing::Point(127, 154);
			this->enrollmentsListBox->Name = L"enrollmentsListBox";
			this->enrollmentsListBox->Size = System::Drawing::Size(295, 160);
			this->enrollmentsListBox->TabIndex = 2;
			// 
			// approveButton
			// 
			this->approveButton->Location = System::Drawing::Point(127, 355);
			this->approveButton->Name = L"approveButton";
			this->approveButton->Size = System::Drawing::Size(75, 23);
			this->approveButton->TabIndex = 3;
			this->approveButton->Text = L"Approve";
			this->approveButton->UseVisualStyleBackColor = true;
			this->approveButton->Click += gcnew System::EventHandler(this, &VerifyEnrollment::approveButton_Click);
			// 
			// rejectButton
			// 
			this->rejectButton->Location = System::Drawing::Point(347, 355);
			this->rejectButton->Name = L"rejectButton";
			this->rejectButton->Size = System::Drawing::Size(75, 23);
			this->rejectButton->TabIndex = 4;
			this->rejectButton->Text = L"Reject";
			this->rejectButton->UseVisualStyleBackColor = true;
			this->rejectButton->Click += gcnew System::EventHandler(this, &VerifyEnrollment::rejectButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(57, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Course ID";
			// 
			// VerifyEnrollment
			// 
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(478, 436);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->rejectButton);
			this->Controls->Add(this->approveButton);
			this->Controls->Add(this->enrollmentsListBox);
			this->Controls->Add(this->loadEnrollmentsButton);
			this->Controls->Add(this->courseIdTextBox);
			this->Name = L"VerifyEnrollment";
			this->Text = L"Verify Enrollment";
			this->Load += gcnew System::EventHandler(this, &VerifyEnrollment::VerifyEnrollment_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Function to load pending enrollments for the specified course
		void loadEnrollmentsButton_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ courseId = courseIdTextBox->Text;
			if (String::IsNullOrEmpty(courseId)) {
				MessageBox::Show("Please enter a valid course ID.");
				return;
			}

			// Query to get enrollments for the course and check if the faculty member is in charge
			sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			// Check if the user is assigned to this course
			sqlCmd->CommandText = "SELECT * FROM CourseFaculty WHERE FacultyID = @facultyId AND CourseID = @course1";
			sqlCmd->Parameters->AddWithValue("@facultyId", Convert::ToInt32(userid));
			sqlCmd->Parameters->AddWithValue("@course1", Convert::ToInt32(courseId));

			sqlRd = sqlCmd->ExecuteReader();
			if (sqlRd->Read()) {
				sqlRd->Close();
				sqlCmd->CommandText = "SELECT EnrollmentID, StudentID, CourseID FROM Enrollments WHERE CourseID = @courseId AND status = 'pending'";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@courseId", Convert::ToInt32(courseId));
				sqlDtA->SelectCommand = sqlCmd;
				sqlDt->Clear();
				sqlDtA->Fill(sqlDt);
				enrollmentsListBox->Items->Clear();

				// Display the pending enrollments
				for (int i = 0; i < sqlDt->Rows->Count; i++) {
					DataRow^ row = sqlDt->Rows[i];
					enrollmentsListBox->Items->Add("Student ID: " + row["StudentID"]);
				}
			}
			else {
				MessageBox::Show("You are not assigned to this course.");
			}
			sqlConn->Close();
		}

		// Approve the selected enrollment
		void approveButton_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ courseId = courseIdTextBox->Text;
			if (String::IsNullOrEmpty(courseId)) {
				MessageBox::Show("Please enter a valid course ID.");
				return;
			}

			if (enrollmentsListBox->SelectedItem == nullptr) {
				MessageBox::Show("Please select an enrollment to approve.");
				return;
			}

			// Get selected enrollment
			String^ selectedEnrollment = enrollmentsListBox->SelectedItem->ToString();
			int studentId = Convert::ToInt32(selectedEnrollment->Substring(12)); // Extract student ID from string

			// Update the enrollment status to approved (e.g., assign a grade or change enrollment status)
			sqlConn->Open();
			sqlCmd->CommandText = "UPDATE Enrollments SET status = 'approved' WHERE StudentID = @studentId and CourseID = @coursei";
			sqlCmd->Parameters->AddWithValue("@studentId", studentId);
			sqlCmd->Parameters->AddWithValue("@coursei", courseId);
			sqlCmd->ExecuteNonQuery();
			sqlConn->Close();

			MessageBox::Show("Enrollment approved.");
			loadEnrollmentsButton_Click(sender, e);  // Refresh the list
		}

		// Reject the selected enrollment
		void rejectButton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (enrollmentsListBox->SelectedItem == nullptr) {
				MessageBox::Show("Please select an enrollment to reject.");
				return;
			}

			// Get selected enrollment
			String^ selectedEnrollment = enrollmentsListBox->SelectedItem->ToString();
			int studentId = Convert::ToInt32(selectedEnrollment->Substring(12)); // Extract student ID from string

			// Delete the enrollment
			sqlConn->Open();
			sqlCmd->CommandText = "DELETE FROM Enrollments WHERE StudentID = @studentId";
			sqlCmd->Parameters->AddWithValue("@studentId", studentId);
			sqlCmd->ExecuteNonQuery();
			sqlConn->Close();

			MessageBox::Show("Enrollment rejected.");
			loadEnrollmentsButton_Click(sender, e);  // Refresh the list
		}
	private: System::Void VerifyEnrollment_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
