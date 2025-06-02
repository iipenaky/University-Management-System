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
	/// Summary for UpdateCourse
	/// </summary>
	public ref class UpdateCourse : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
	private: System::Windows::Forms::ComboBox^ something;
	private: System::Windows::Forms::TextBox^ credits;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   MySqlDataReader^ sqlRd;
	public:
		UpdateCourse(void)
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
		~UpdateCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ update;
	protected:

	private: System::Windows::Forms::TextBox^ CourseID;
	protected:




	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ maxEnrollment;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ semester;
	private: System::Windows::Forms::Label^ label6;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UpdateCourse::typeid));
			this->update = (gcnew System::Windows::Forms::Button());
			this->CourseID = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->maxEnrollment = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->semester = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->something = (gcnew System::Windows::Forms::ComboBox());
			this->credits = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// update
			// 
			this->update->ForeColor = System::Drawing::Color::Black;
			this->update->Location = System::Drawing::Point(359, 501);
			this->update->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->update->Name = L"update";
			this->update->Size = System::Drawing::Size(125, 32);
			this->update->TabIndex = 27;
			this->update->Text = L"Update";
			this->update->UseVisualStyleBackColor = true;
			this->update->Click += gcnew System::EventHandler(this, &UpdateCourse::update_Click);
			// 
			// CourseID
			// 
			this->CourseID->Location = System::Drawing::Point(500, 172);
			this->CourseID->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->CourseID->Name = L"CourseID";
			this->CourseID->Size = System::Drawing::Size(392, 24);
			this->CourseID->TabIndex = 26;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label4->Location = System::Drawing::Point(336, 380);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 18);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Credits";
			// 
			// maxEnrollment
			// 
			this->maxEnrollment->Location = System::Drawing::Point(500, 309);
			this->maxEnrollment->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->maxEnrollment->Name = L"maxEnrollment";
			this->maxEnrollment->Size = System::Drawing::Size(392, 24);
			this->maxEnrollment->TabIndex = 22;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(412, 36);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(190, 31);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Update Course";
			// 
			// semester
			// 
			this->semester->FormattingEnabled = true;
			this->semester->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Spring", L"Fall" });
			this->semester->Location = System::Drawing::Point(500, 239);
			this->semester->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->semester->Name = L"semester";
			this->semester->Size = System::Drawing::Size(392, 26);
			this->semester->TabIndex = 28;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label6->Location = System::Drawing::Point(336, 445);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 18);
			this->label6->TabIndex = 29;
			this->label6->Text = L"Availability";
			// 
			// something
			// 
			this->something->FormattingEnabled = true;
			this->something->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"true", L"false" });
			this->something->Location = System::Drawing::Point(500, 437);
			this->something->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->something->Name = L"something";
			this->something->Size = System::Drawing::Size(392, 26);
			this->something->TabIndex = 32;
			// 
			// credits
			// 
			this->credits->Location = System::Drawing::Point(500, 374);
			this->credits->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->credits->Name = L"credits";
			this->credits->Size = System::Drawing::Size(392, 24);
			this->credits->TabIndex = 33;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label7->Location = System::Drawing::Point(336, 256);
			this->label7->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(80, 18);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Semester";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label8->Location = System::Drawing::Point(332, 315);
			this->label8->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(121, 18);
			this->label8->TabIndex = 20;
			this->label8->Text = L"Max Enrolment";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label9->Location = System::Drawing::Point(332, 178);
			this->label9->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(84, 18);
			this->label9->TabIndex = 25;
			this->label9->Text = L"Course ID";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, -3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 177);
			this->pictureBox1->TabIndex = 62;
			this->pictureBox1->TabStop = false;
			// 
			// UpdateCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(1092, 602);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->credits);
			this->Controls->Add(this->something);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->semester);
			this->Controls->Add(this->update);
			this->Controls->Add(this->CourseID);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->maxEnrollment);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->Name = L"UpdateCourse";
			this->Text = L"UpdateCourse";
			this->Load += gcnew System::EventHandler(this, &UpdateCourse::UpdateCourse_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UpdateCourse_Load(System::Object^ sender, System::EventArgs^ e) {
	}
		   System::Void update_Click(System::Object^ sender, System::EventArgs^ e) {
			   sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";

			   try {
				   sqlConn->Open();

				   // Get values from fields
				   String^ courseId = CourseID->Text;
				   String^ semesterValue = semester->Text;
				   String^ maxEnroll = maxEnrollment->Text;
				   String^ creditsValue = credits->Text;
				   String^ available = something->SelectedItem->ToString();

				   // Validate input
				   if (courseId->Length == 0 || semesterValue->Length == 0 || maxEnroll->Length == 0 || creditsValue->Length == 0 || available->Length == 0) {
					   MessageBox::Show("All fields must be filled out before updating.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					   return;
				   }

				   // Prepare SQL query
				   String^ query = "UPDATE courses SET Semester = @Semester, MaxEnrollment = @MaxEnrollment, Credits = @Credits, Availability = @Availability WHERE CourseID = @CourseID";

				   sqlCmd->Connection = sqlConn;
				   sqlCmd->CommandText = query;
				   sqlCmd->Parameters->AddWithValue("@CourseID", courseId);
				   sqlCmd->Parameters->AddWithValue("@Semester", semesterValue);
				   sqlCmd->Parameters->AddWithValue("@MaxEnrollment", maxEnroll);
				   sqlCmd->Parameters->AddWithValue("@Credits", creditsValue);
				   sqlCmd->Parameters->AddWithValue("@Availability", available);

				   // Execute the command
				   int rowsAffected = sqlCmd->ExecuteNonQuery();
				   if (rowsAffected > 0) {
					   MessageBox::Show("Course updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
					   this->Hide();
				   }
				   else {
					   MessageBox::Show("No course found with the given Course ID.", "Update Failed", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   }

				   // Clear fields
				   CourseID->Clear();
				   semester->SelectedIndex = -1;
				   maxEnrollment->Clear();
				   credits->Clear();
				   something->SelectedIndex = -1;
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Error while updating course details: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
			   finally {
				   sqlConn->Close();
				   sqlCmd->Parameters->Clear();
			   }
		   }
};

}
