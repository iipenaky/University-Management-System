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
	/// Summary for AddCourse
	/// </summary>
	public ref class AddCourse : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ availability;
	private: System::Windows::Forms::ListBox^ prerequisites;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

		   MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
	public:
		AddCourse(void)
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
		~AddCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ semester;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ submit;

	private: System::Windows::Forms::TextBox^ facID;

	private: System::Windows::Forms::TextBox^ totalCredits;

	private: System::Windows::Forms::TextBox^ courseName;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ maxEnrollment;
	private: System::Windows::Forms::ListBox^ selectedPrerequisites;
	private: System::Windows::Forms::Button^ addPrerequisiteButton;
	private: System::Windows::Forms::Button^ removePrerequisiteButton;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddCourse::typeid));
			this->semester = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->submit = (gcnew System::Windows::Forms::Button());
			this->facID = (gcnew System::Windows::Forms::TextBox());
			this->totalCredits = (gcnew System::Windows::Forms::TextBox());
			this->courseName = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->maxEnrollment = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->availability = (gcnew System::Windows::Forms::ComboBox());
			this->prerequisites = (gcnew System::Windows::Forms::ListBox());
			this->selectedPrerequisites = (gcnew System::Windows::Forms::ListBox());
			this->addPrerequisiteButton = (gcnew System::Windows::Forms::Button());
			this->removePrerequisiteButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// semester
			// 
			this->semester->FormattingEnabled = true;
			this->semester->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Spring", L"Fall" });
			this->semester->Location = System::Drawing::Point(462, 168);
			this->semester->Name = L"semester";
			this->semester->Size = System::Drawing::Size(237, 21);
			this->semester->TabIndex = 52;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(228, 171);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(80, 18);
			this->label9->TabIndex = 51;
			this->label9->Text = L"Semester";
			// 
			// submit
			// 
			this->submit->Location = System::Drawing::Point(421, 507);
			this->submit->Name = L"submit";
			this->submit->Size = System::Drawing::Size(75, 23);
			this->submit->TabIndex = 45;
			this->submit->Text = L"Submit";
			this->submit->UseVisualStyleBackColor = true;
			this->submit->Click += gcnew System::EventHandler(this, &AddCourse::submit_Click);
			// 
			// facID
			// 
			this->facID->Location = System::Drawing::Point(462, 218);
			this->facID->Name = L"facID";
			this->facID->Size = System::Drawing::Size(237, 20);
			this->facID->TabIndex = 43;
			// 
			// totalCredits
			// 
			this->totalCredits->Location = System::Drawing::Point(462, 127);
			this->totalCredits->Name = L"totalCredits";
			this->totalCredits->Size = System::Drawing::Size(237, 20);
			this->totalCredits->TabIndex = 41;
			// 
			// courseName
			// 
			this->courseName->Location = System::Drawing::Point(462, 95);
			this->courseName->Name = L"courseName";
			this->courseName->Size = System::Drawing::Size(237, 20);
			this->courseName->TabIndex = 40;
			this->courseName->TextChanged += gcnew System::EventHandler(this, &AddCourse::courseName_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(225, 262);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(166, 18);
			this->label5->TabIndex = 38;
			this->label5->Text = L"Maximum Enrollment";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(225, 129);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 18);
			this->label3->TabIndex = 36;
			this->label3->Text = L"Credits";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(228, 95);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 18);
			this->label2->TabIndex = 35;
			this->label2->Text = L"Course Name";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(342, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 31);
			this->label1->TabIndex = 34;
			this->label1->Text = L"Add Course";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(228, 220);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(83, 18);
			this->label4->TabIndex = 53;
			this->label4->Text = L"Faculty ID";
			// 
			// maxEnrollment
			// 
			this->maxEnrollment->Location = System::Drawing::Point(462, 262);
			this->maxEnrollment->Name = L"maxEnrollment";
			this->maxEnrollment->Size = System::Drawing::Size(237, 20);
			this->maxEnrollment->TabIndex = 54;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(228, 305);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 18);
			this->label6->TabIndex = 55;
			this->label6->Text = L"Availability";
			// 
			// availability
			// 
			this->availability->FormattingEnabled = true;
			this->availability->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"true", L"false" });
			this->availability->Location = System::Drawing::Point(462, 302);
			this->availability->Name = L"availability";
			this->availability->Size = System::Drawing::Size(237, 21);
			this->availability->TabIndex = 56;
			// 
			// prerequisites
			// 
			this->prerequisites->FormattingEnabled = true;
			this->prerequisites->Location = System::Drawing::Point(228, 354);
			this->prerequisites->Name = L"prerequisites";
			this->prerequisites->Size = System::Drawing::Size(120, 95);
			this->prerequisites->TabIndex = 57;
			// 
			// selectedPrerequisites
			// 
			this->selectedPrerequisites->Location = System::Drawing::Point(579, 354);
			this->selectedPrerequisites->Name = L"selectedPrerequisites";
			this->selectedPrerequisites->Size = System::Drawing::Size(120, 95);
			this->selectedPrerequisites->TabIndex = 58;
			// 
			// addPrerequisiteButton
			// 
			this->addPrerequisiteButton->ForeColor = System::Drawing::Color::White;
			this->addPrerequisiteButton->Location = System::Drawing::Point(411, 354);
			this->addPrerequisiteButton->Name = L"addPrerequisiteButton";
			this->addPrerequisiteButton->Size = System::Drawing::Size(126, 23);
			this->addPrerequisiteButton->TabIndex = 59;
			this->addPrerequisiteButton->Text = L"Add Prerequisite";
			this->addPrerequisiteButton->Click += gcnew System::EventHandler(this, &AddCourse::addPrerequisiteButton_Click);
			// 
			// removePrerequisiteButton
			// 
			this->removePrerequisiteButton->ForeColor = System::Drawing::Color::White;
			this->removePrerequisiteButton->Location = System::Drawing::Point(411, 426);
			this->removePrerequisiteButton->Name = L"removePrerequisiteButton";
			this->removePrerequisiteButton->Size = System::Drawing::Size(126, 23);
			this->removePrerequisiteButton->TabIndex = 60;
			this->removePrerequisiteButton->Text = L"Remove Prerequisite";
			this->removePrerequisiteButton->Click += gcnew System::EventHandler(this, &AddCourse::removePrerequisiteButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 177);
			this->pictureBox1->TabIndex = 61;
			this->pictureBox1->TabStop = false;
			// 
			// AddCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(818, 555);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->prerequisites);
			this->Controls->Add(this->availability);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->maxEnrollment);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->semester);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->submit);
			this->Controls->Add(this->facID);
			this->Controls->Add(this->totalCredits);
			this->Controls->Add(this->courseName);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->selectedPrerequisites);
			this->Controls->Add(this->addPrerequisiteButton);
			this->Controls->Add(this->removePrerequisiteButton);
			this->Name = L"AddCourse";
			this->Text = L"AddCourse";
			this->Load += gcnew System::EventHandler(this, &AddCourse::AddCourse_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddCourse_Load(System::Object^ sender, System::EventArgs^ e) {
		try {
			sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
			sqlConn->Open();

			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT CourseID, CourseName FROM Courses";

			sqlDt->Clear();
			sqlDtA->SelectCommand = sqlCmd;
			sqlDtA->Fill(sqlDt);

			prerequisites->Items->Clear();
			for each (DataRow ^ row in sqlDt->Rows) {
				prerequisites->Items->Add(row["CourseID"]->ToString() + " - " + row["CourseName"]->ToString());
			}

			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error loading prerequisites: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		// Optional: Initialize any additional components or logic when the form loads
	}
	private: System::Void addPrerequisiteButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (prerequisites->SelectedItem != nullptr) {
			selectedPrerequisites->Items->Add(prerequisites->SelectedItem);
			prerequisites->Items->Remove(prerequisites->SelectedItem);
		}
	}

	private: System::Void removePrerequisiteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (selectedPrerequisites->SelectedItem != nullptr) {
		prerequisites->Items->Add(selectedPrerequisites->SelectedItem);
		selectedPrerequisites->Items->Remove(selectedPrerequisites->SelectedItem);
	}
}

private: System::Void submit_Click(System::Object^ sender, System::EventArgs^ e) {
	// Collect user input values
	String^ courseNameValue = courseName->Text;
	double totalCreditsValue = Convert::ToInt32(totalCredits->Text);
	String^ semesterValue = semester->Text;
	String^ availabilityValue = availability->Text;
	int facIDValue = Convert::ToInt32(facID->Text);
	int maxEnrollmentValue = Convert::ToInt32(maxEnrollment->Text);

	// Check if the course name already exists
	try {
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
		sqlConn->Open();

		sqlCmd->Connection = sqlConn;
		sqlCmd->CommandText = "SELECT COUNT(*) FROM Courses WHERE CourseName = @courseName";
		sqlCmd->Parameters->AddWithValue("@courseName", courseNameValue);

		int courseCount = Convert::ToInt32(sqlCmd->ExecuteScalar());

		if (courseCount > 0) {
			MessageBox::Show("Course name already exists. Please choose a different name.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return; // Exit the method if the course already exists
		}

		// Insert course data into the Courses table
		String^ query = "INSERT INTO Courses (CourseName, Credits, Semester, MaxEnrollment, Availability) "
			"VALUES (@coursename, @totalCredits, @semester, @maxEnrollment, @availability)";
		sqlCmd->CommandText = query;

		// Bind parameters
		sqlCmd->Parameters->Clear();
		sqlCmd->Parameters->AddWithValue("@coursename", courseNameValue);
		sqlCmd->Parameters->AddWithValue("@totalCredits", totalCreditsValue);
		sqlCmd->Parameters->AddWithValue("@semester", semesterValue);
		sqlCmd->Parameters->AddWithValue("@maxEnrollment", maxEnrollmentValue);
		sqlCmd->Parameters->AddWithValue("@availability", availabilityValue);

		// Execute the insert statement
		sqlCmd->ExecuteNonQuery();

		// Get the last inserted CourseID
		int courseID = (int)sqlCmd->LastInsertedId;

		// Link the course to the faculty in the CourseFaculty table
		String^ facultyQuery = "INSERT INTO CourseFaculty (FacultyID, CourseID) VALUES (@facID, @courseID)";
		sqlCmd->CommandText = facultyQuery;

		// Bind faculty ID and course ID
		sqlCmd->Parameters->Clear();
		sqlCmd->Parameters->AddWithValue("@facID", facIDValue);
		sqlCmd->Parameters->AddWithValue("@courseID", courseID);

		// Execute the command to link the faculty to the course
		sqlCmd->ExecuteNonQuery();

		// Add prerequisites if any
		for each(String ^ prerequisite in selectedPrerequisites->Items) {
			int prerequisiteID = Convert::ToInt32(prerequisite->Split('-')[0]->Trim());

			String^ prerequisiteQuery = "INSERT INTO Prerequisites (CourseID, PrerequisiteID) VALUES (@courseID, @prerequisiteID)";
			sqlCmd->CommandText = prerequisiteQuery;
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@courseID", courseID);
			sqlCmd->Parameters->AddWithValue("@prerequisiteID", prerequisiteID);

			sqlCmd->ExecuteNonQuery();
		}

		MessageBox::Show("Course and prerequisites added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Hide();
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error adding course: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		sqlConn->Close();
	}
}


private: System::Void courseName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
