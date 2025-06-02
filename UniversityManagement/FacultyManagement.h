#pragma once
#include "AddFaculty1.h"
#include "DeleteFaculty.h"
#include "UpdateUser.h"

namespace UniversityManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for FacultyManagement
	/// </summary>
	public ref class FacultyManagement : public System::Windows::Forms::Form
	{
	public:
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
		FacultyManagement(void)
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
		~FacultyManagement()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FacultyManagement::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(633, 516);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(129, 23);
			this->button2->TabIndex = 23;
			this->button2->Text = L"Update Faculty";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FacultyManagement::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(437, 516);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(129, 23);
			this->button3->TabIndex = 22;
			this->button3->Text = L"Delete Faculty";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FacultyManagement::button3_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(220, 516);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(158, 23);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Add Faculty";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FacultyManagement::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(306, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(260, 31);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Faculty Management";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-1, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 177);
			this->pictureBox1->TabIndex = 62;
			this->pictureBox1->TabStop = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(169, 96);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(633, 400);
			this->dataGridView1->TabIndex = 64;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FacultyManagement::dataGridView1_CellContentClick);
			// 
			// FacultyManagement
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(849, 551);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"FacultyManagement";
			this->Text = L"FacultyManagement";
			this->Load += gcnew System::EventHandler(this, &FacultyManagement::FacultyManagement_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		AddFaculty1^ addF = gcnew AddFaculty1();
		addF->Show();
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteFaculty^ delU = gcnew DeleteFaculty();
	delU->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	UpdateUser^ updateF = gcnew UpdateUser();
	updateF->Show();
}
private: System::Void FacultyManagement_Load(System::Object^ sender, System::EventArgs^ e) {
	LoadFaculty();

}

	   private: System::Void LoadFaculty() {
		   String^ query = "SELECT u.FirstName, u.LastName, u.DateOfBirth, u.Email, u.Role, "
			   "f.Department, f.AppointmentDate "
			   "FROM Users u "
			   "JOIN Faculty f ON u.UserID = f.FacultyID";


		   try {
			   sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
			   sqlConn->Open();

			   sqlCmd->CommandText = query;
			   sqlCmd->Connection = sqlConn;

			   sqlDtA->SelectCommand = sqlCmd;
			   sqlDt->Clear();
			   sqlDtA->Fill(sqlDt);

			   // Bind the result to DataGridView
			   dataGridView1->DataSource = sqlDt;
		   }
		   catch (Exception^ ex) {
			   MessageBox::Show("Error: " + ex->Message);
		   }
		   finally {
			   sqlConn->Close();
		   }
	   }
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
