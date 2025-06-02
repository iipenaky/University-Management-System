#pragma once
#include "Faculty.h"
#include "Administrator.h"
#include "Student.h"

namespace UniversityManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{

		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;

	public:
		String^ id;
		MainForm(String^ userId)
		{
			InitializeComponent();
			id = userId;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	private: System::Windows::Forms::ToolStripMenuItem^ facultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ administratorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ studentToolStripMenuItem;



















	private: System::ComponentModel::IContainer^ components;




	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->facultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administratorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->studentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->facultyToolStripMenuItem,
					this->administratorToolStripMenuItem, this->studentToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(723, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// facultyToolStripMenuItem
			// 
			this->facultyToolStripMenuItem->Name = L"facultyToolStripMenuItem";
			this->facultyToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->facultyToolStripMenuItem->Text = L"Faculty";
			this->facultyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::facultyToolStripMenuItem_Click);
			// 
			// administratorToolStripMenuItem
			// 
			this->administratorToolStripMenuItem->Name = L"administratorToolStripMenuItem";
			this->administratorToolStripMenuItem->Size = System::Drawing::Size(92, 20);
			this->administratorToolStripMenuItem->Text = L"Administrator";
			this->administratorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::administratorToolStripMenuItem_Click);
			// 
			// studentToolStripMenuItem
			// 
			this->studentToolStripMenuItem->Name = L"studentToolStripMenuItem";
			this->studentToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->studentToolStripMenuItem->Text = L"Student";
			this->studentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::studentToolStripMenuItem_Click_1);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(723, 466);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void studentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void contextMenuStrip1_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
private: System::Void facultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Faculty^ fac = gcnew Faculty(id);
	fac->Show();
}
private: System::Void administratorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Administrator^ admin = gcnew Administrator();

	admin->Show();
}
private: System::Void studentToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Student^ stu = gcnew Student(id);
	stu->Show();
}
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	// Simulate database query to get user role based on id
	String^ userRole = GetUserRoleFromDatabase(id);

	// Set menu visibility based on the user's role
	if (userRole == "admin") {
		facultyToolStripMenuItem->Visible = false;
		studentToolStripMenuItem->Visible = false;
		administratorToolStripMenuItem->Visible = true;
	}
	else if (userRole == "faculty") {
		facultyToolStripMenuItem->Visible = true;
		studentToolStripMenuItem->Visible = false;
		administratorToolStripMenuItem->Visible = false;
	}
	else if (userRole == "student") {
		facultyToolStripMenuItem->Visible = false;
		studentToolStripMenuItem->Visible = true;
		administratorToolStripMenuItem->Visible = false;
	}
	else {
		// Handle unknown roles, e.g., log an error or show a default state
		MessageBox::Show("Unknown role. Access restricted.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		this->Close(); // Close the form if the role is invalid
	}
}

	   // Mock database query function
private: String^ GetUserRoleFromDatabase(String^ userId) {
	// Convert userId (String^) to int
	int userIdInt = Convert::ToInt32(userId);

	// Connection string to your MySQL database
	String^ connectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";

	MySqlConnection^ sqlConn = gcnew MySqlConnection(connectionString);

	try {
		// Open the database connection
		sqlConn->Open();

		// SQL query to fetch the role for the given user ID
		String^ query = "SELECT role FROM Users WHERE UserID = @userId";
		MySqlCommand^ cmd = gcnew MySqlCommand(query, sqlConn);

		// Bind the userIdInt parameter
		cmd->Parameters->AddWithValue("@userId", userIdInt);

		// Execute the query and fetch the result
		MySqlDataReader^ reader = cmd->ExecuteReader();

		if (reader->Read()) {
			// Get the role from the result
			String^ role = reader["role"]->ToString();
			reader->Close();
			return role; // Return the role (e.g., "admin", "faculty", "student")
		}
		else {
			reader->Close();
			return ""; // Return empty string if no role is found
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Database error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return ""; // Return empty string in case of error
	}
	finally {
		// Ensure the connection is closed
		sqlConn->Close();
	}
}


private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
