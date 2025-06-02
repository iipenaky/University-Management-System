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
	/// Summary for CourseRegistration
	/// </summary>
	public ref class CourseRegistration : public System::Windows::Forms::Form
	{
		String^ userId;
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   MySqlDataReader^ sqlRd;
	public:
		CourseRegistration(String^ id)
		{
			InitializeComponent();
			userId = id;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CourseRegistration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ availablecourses;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ courseid;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CourseRegistration::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->availablecourses = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->courseid = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->availablecourses))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(387, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(212, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enroll In Course";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(189, 117);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(122, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Past Enrollments";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(656, 338);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Enroll";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CourseRegistration::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(457, 338);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &CourseRegistration::button2_Click);
			// 
			// availablecourses
			// 
			this->availablecourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->availablecourses->Location = System::Drawing::Point(130, 151);
			this->availablecourses->Name = L"availablecourses";
			this->availablecourses->Size = System::Drawing::Size(261, 297);
			this->availablecourses->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(453, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 19);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Course ID";
			// 
			// courseid
			// 
			this->courseid->Location = System::Drawing::Point(553, 132);
			this->courseid->Name = L"courseid";
			this->courseid->Size = System::Drawing::Size(178, 20);
			this->courseid->TabIndex = 7;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-9, -11);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(150, 137);
			this->pictureBox1->TabIndex = 62;
			this->pictureBox1->TabStop = false;
			// 
			// CourseRegistration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(743, 446);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->courseid);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->availablecourses);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"CourseRegistration";
			this->Text = L"CourseRegistration";
			this->Load += gcnew System::EventHandler(this, &CourseRegistration::CourseRegistration_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->availablecourses))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CourseRegistration_Load(System::Object^ sender, System::EventArgs^ e) {
		sqlConn->ConnectionString = "datasource=localhost;port=3306;"
			"username=root;password=;database=universityrecords";
		sqlConn->Open();
		sqlCmd->Connection = sqlConn;

		// Query to fetch only the courses the current student is enrolled in
		sqlCmd->CommandText = "SELECT Courses.CourseID, Courses.CourseName, Courses.Semester, Enrollments.EnrollmentDate "
			"FROM Enrollments "
			"INNER JOIN Courses ON Enrollments.CourseID = Courses.CourseID "
			"WHERE Enrollments.StudentID = @StudentID";

		sqlCmd->Parameters->AddWithValue("@StudentID", userId);

		sqlRd = sqlCmd->ExecuteReader();
		sqlDt->Load(sqlRd);
		sqlRd->Close();
		sqlConn->Close();

		availablecourses->DataSource = sqlDt;
		sqlCmd->Parameters->Clear();
	}

	private: System::Void courseid_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ searchText = courseid->Text->Trim();

			// Open database connection
			sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
			sqlConn->Open();

			// Update the course list based on search criteria
			sqlCmd->Connection = sqlConn;

			if (String::IsNullOrWhiteSpace(searchText)) {
				// No search term: Load all available courses
				sqlCmd->CommandText = "SELECT * FROM Courses WHERE Availability = 'true';";
			}
			else {
				// Search term present: Filter results
				sqlCmd->CommandText = "SELECT * FROM Courses WHERE Availability = 'true' AND (CourseName LIKE @Search OR CourseID LIKE @Search);";
				sqlCmd->Parameters->AddWithValue("@Search", "%" + searchText + "%");
			}

			sqlRd = sqlCmd->ExecuteReader();
			sqlDt->Clear();
			sqlDt->Load(sqlRd);
			sqlRd->Close();
			sqlConn->Close();

			// Bind the results to the DataGridView
			availablecourses->DataSource = sqlDt;
			sqlCmd->Parameters->Clear();
		}
		catch (MySqlException^ ex) {
			MessageBox::Show("Database error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			sqlCmd->Parameters->Clear();
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
		}
	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ selectedCourseID = courseid->Text;

	if (String::IsNullOrWhiteSpace(selectedCourseID)) {
		MessageBox::Show("Please enter a valid course ID.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	try {
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
		sqlConn->Open();
		sqlCmd->Connection = sqlConn;

		// Validate if the course exists and is available 
		sqlCmd->CommandText = "SELECT COUNT(*) FROM Courses WHERE CourseID = @CourseID AND availability = 'true';";
		sqlCmd->Parameters->AddWithValue("@CourseID", Convert::ToInt32(selectedCourseID));
		int isOfferedThisSemester = Convert::ToInt32(sqlCmd->ExecuteScalar());
		sqlCmd->Parameters->Clear();

		if (isOfferedThisSemester == 0) {
			MessageBox::Show("This course is not available.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		sqlCmd->CommandText = "SELECT COUNT(*) FROM Prerequisites WHERE CourseID = @CourseID;";
		sqlCmd->Parameters->AddWithValue("@CourseID", selectedCourseID);
		int totalPrerequisites = Convert::ToInt32(sqlCmd->ExecuteScalar());
		sqlCmd->Parameters->Clear();

		sqlCmd->CommandText = "SELECT COUNT(*) FROM Prerequisites P "
			"INNER JOIN Enrollments E ON P.PrerequisiteID = E.CourseID "
			"WHERE P.CourseID = @CourseID AND E.StudentID = @StudentID;";
		sqlCmd->Parameters->AddWithValue("@CourseID", selectedCourseID);
		sqlCmd->Parameters->AddWithValue("@StudentID", userId);
		int completedPrerequisites = Convert::ToInt32(sqlCmd->ExecuteScalar());
		sqlCmd->Parameters->Clear();

		if (completedPrerequisites < totalPrerequisites) {
			MessageBox::Show("You have not completed all prerequisites for this course.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Check if the student is already enrolled in this course
		sqlCmd->CommandText = "SELECT COUNT(*) FROM Enrollments WHERE StudentID = @StudentID AND CourseID = @CourseID;";
		sqlCmd->Parameters->AddWithValue("@StudentID", userId);
		sqlCmd->Parameters->AddWithValue("@CourseID", Convert::ToInt32(selectedCourseID));
		int isAlreadyEnrolled = Convert::ToInt32(sqlCmd->ExecuteScalar());
		sqlCmd->Parameters->Clear();

		if (isAlreadyEnrolled > 0) {
			MessageBox::Show("You are already enrolled in this course.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Enroll the student in the course
		sqlCmd->CommandText = "INSERT INTO Enrollments (StudentID, CourseID, EnrollmentDate, status) VALUES (@StudentID, @CourseID, NOW(), 'pending');";
		sqlCmd->Parameters->AddWithValue("@StudentID", userId);
		sqlCmd->Parameters->AddWithValue("@CourseID", Convert::ToInt32(selectedCourseID));
		sqlCmd->ExecuteNonQuery();
		sqlCmd->Parameters->Clear();

		MessageBox::Show("Successfully enrolled in the course!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
	catch (Exception^ ex) {
		MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		sqlConn->Close();
	}
}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}
};
}
