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
	/// Summary for ManageFinances
	/// </summary>
	public ref class ManageFinances : public System::Windows::Forms::Form
	{
	public:
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;

		ManageFinances(void)
		{
			InitializeComponent();
		}

	protected:
		~ManageFinances()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		// UI controls
		System::Windows::Forms::TextBox^ txtStudentID;
		System::Windows::Forms::TextBox^ txtPaidAmount;
		System::Windows::Forms::Button^ btnUpdatePayment;
		System::Windows::Forms::DataGridView^ dgvPayments;
		System::Windows::Forms::Label^ lblStudentID;
		System::Windows::Forms::Label^ lblPaidAmount;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
			this->txtPaidAmount = (gcnew System::Windows::Forms::TextBox());
			this->btnUpdatePayment = (gcnew System::Windows::Forms::Button());
			this->dgvPayments = (gcnew System::Windows::Forms::DataGridView());
			this->lblStudentID = (gcnew System::Windows::Forms::Label());
			this->lblPaidAmount = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPayments))->BeginInit();
			this->SuspendLayout();
			// 
			// txtStudentID
			// 
			this->txtStudentID->Location = System::Drawing::Point(180, 38);
			this->txtStudentID->Name = L"txtStudentID";
			this->txtStudentID->Size = System::Drawing::Size(100, 20);
			this->txtStudentID->TabIndex = 0;
			// 
			// txtPaidAmount
			// 
			this->txtPaidAmount->Location = System::Drawing::Point(180, 78);
			this->txtPaidAmount->Name = L"txtPaidAmount";
			this->txtPaidAmount->Size = System::Drawing::Size(100, 20);
			this->txtPaidAmount->TabIndex = 1;
			// 
			// btnUpdatePayment
			// 
			this->btnUpdatePayment->Location = System::Drawing::Point(483, 60);
			this->btnUpdatePayment->Name = L"btnUpdatePayment";
			this->btnUpdatePayment->Size = System::Drawing::Size(100, 23);
			this->btnUpdatePayment->TabIndex = 2;
			this->btnUpdatePayment->Text = L"Update Payment";
			this->btnUpdatePayment->UseVisualStyleBackColor = true;
			this->btnUpdatePayment->Click += gcnew System::EventHandler(this, &ManageFinances::btnUpdatePayment_Click);
			// 
			// dgvPayments
			// 
			this->dgvPayments->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvPayments->Location = System::Drawing::Point(12, 160);
			this->dgvPayments->Name = L"dgvPayments";
			this->dgvPayments->Size = System::Drawing::Size(688, 200);
			this->dgvPayments->TabIndex = 3;
			// 
			// lblStudentID
			// 
			this->lblStudentID->AutoSize = true;
			this->lblStudentID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStudentID->ForeColor = System::Drawing::Color::White;
			this->lblStudentID->Location = System::Drawing::Point(30, 40);
			this->lblStudentID->Name = L"lblStudentID";
			this->lblStudentID->Size = System::Drawing::Size(86, 18);
			this->lblStudentID->TabIndex = 4;
			this->lblStudentID->Text = L"Student ID";
			// 
			// lblPaidAmount
			// 
			this->lblPaidAmount->AutoSize = true;
			this->lblPaidAmount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPaidAmount->ForeColor = System::Drawing::Color::White;
			this->lblPaidAmount->Location = System::Drawing::Point(30, 80);
			this->lblPaidAmount->Name = L"lblPaidAmount";
			this->lblPaidAmount->Size = System::Drawing::Size(103, 18);
			this->lblPaidAmount->TabIndex = 5;
			this->lblPaidAmount->Text = L"Paid Amount";
			// 
			// ManageFinances
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(712, 408);
			this->Controls->Add(this->lblPaidAmount);
			this->Controls->Add(this->lblStudentID);
			this->Controls->Add(this->dgvPayments);
			this->Controls->Add(this->btnUpdatePayment);
			this->Controls->Add(this->txtPaidAmount);
			this->Controls->Add(this->txtStudentID);
			this->Name = L"ManageFinances";
			this->Text = L"Manage Finances";
			this->Load += gcnew System::EventHandler(this, &ManageFinances::ManageFinances_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPayments))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ManageFinances_Load(System::Object^ sender, System::EventArgs^ e) {
		// Load payment data when the form loads
		LoadPayments();
	}

		   // Load all payments into the DataGridView
	private: System::Void LoadPayments() {
		String^ query = "SELECT u.FirstName, u.LastName, p.TotalAmount, p.PaidAmount, (p.TotalAmount - p.PaidAmount) AS OutstandingAmount "
			"FROM Users u "
			"JOIN Students s ON u.UserID = s.StudentID "
			"JOIN Payments p ON s.StudentID = p.StudentID "
			"WHERE u.Role = 'student'";

		try {
			sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
			sqlConn->Open();

			sqlCmd->CommandText = query;
			sqlCmd->Connection = sqlConn;

			sqlDtA->SelectCommand = sqlCmd;
			sqlDt->Clear();
			sqlDtA->Fill(sqlDt);

			// Bind the result to DataGridView
			dgvPayments->DataSource = sqlDt;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
		finally {
			sqlConn->Close();
		}
	}

		   // Update the paid amount for a student
private: System::Void btnUpdatePayment_Click(System::Object^ sender, System::EventArgs^ e) {
	int studentID = Convert::ToInt32(txtStudentID->Text);
	double paidAmount = Convert::ToDouble(txtPaidAmount->Text);  // Changed to double

	// Step 1: Check if the student ID exists in the Students table
	String^ checkStudentQuery = "SELECT COUNT(*) FROM Students WHERE StudentID = @studentID";
	int studentExists = 0;

	try {
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
		sqlConn->Open();

		sqlCmd->CommandText = checkStudentQuery;
		sqlCmd->Parameters->Clear();
		sqlCmd->Parameters->AddWithValue("@studentID", studentID);

		studentExists = Convert::ToInt32(sqlCmd->ExecuteScalar());

		if (studentExists == 0) {
			MessageBox::Show("Student ID does not exist.");
			return;
		}

		// Step 2: Get the total amount and paid amount for the student
		String^ getTotalAmountQuery = "SELECT TotalAmount, PaidAmount FROM Payments WHERE StudentID = @studentID";
		sqlCmd->CommandText = getTotalAmountQuery;
		sqlCmd->Parameters->Clear();
		sqlCmd->Parameters->AddWithValue("@studentID", studentID);

		sqlRd = sqlCmd->ExecuteReader();

		if (sqlRd->Read()) {
			double totalAmount = sqlRd->GetDouble(0);  // Changed to double
			double currentPaidAmount = sqlRd->GetDouble(1);  // Changed to double

			// Check if the new payment exceeds the total amount
			if (currentPaidAmount + paidAmount > totalAmount) {
				MessageBox::Show("Payment exceeds the total amount due.");
				return;
			}
		}
		else {
			MessageBox::Show("No payment record found for this student.");
			return;
		}
		sqlRd->Close();

		// Step 3: Update the paid amount for the student
		String^ updateQuery = "UPDATE Payments SET PaidAmount = PaidAmount + @paidAmount WHERE StudentID = @studentID";
		sqlCmd->CommandText = updateQuery;
		sqlCmd->Parameters->Clear();
		sqlCmd->Parameters->AddWithValue("@paidAmount", paidAmount);  // Changed to double
		sqlCmd->Parameters->AddWithValue("@studentID", studentID);

		sqlCmd->ExecuteNonQuery();
		MessageBox::Show("Payment updated successfully.");
		sqlConn->Close();
		// Reload the payment data
		LoadPayments();
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}
	finally {
		sqlConn->Close();
	}
}

};
}
