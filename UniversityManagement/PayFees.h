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
	/// Summary for PayFees
	/// </summary>
	public ref class PayFees : public System::Windows::Forms::Form
	{
	public:
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public:
		String^ userid;
		PayFees(String^ id)
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
		~PayFees()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ pay;
	protected:


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ amountToPay;

	private: System::Windows::Forms::DataGridView^ arrears;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PayFees::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pay = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->amountToPay = (gcnew System::Windows::Forms::TextBox());
			this->arrears = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arrears))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(486, 335);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PayFees::button2_Click);
			// 
			// pay
			// 
			this->pay->Location = System::Drawing::Point(295, 335);
			this->pay->Name = L"pay";
			this->pay->Size = System::Drawing::Size(75, 23);
			this->pay->TabIndex = 8;
			this->pay->Text = L"Pay";
			this->pay->UseVisualStyleBackColor = true;
			this->pay->Click += gcnew System::EventHandler(this, &PayFees::pay_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(248, 148);
			this->label2->Name = L"label2";
			this->label2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label2->Size = System::Drawing::Size(61, 19);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Arrears";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(331, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(202, 31);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Pay School Fees";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(248, 260);
			this->label3->Name = L"label3";
			this->label3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label3->Size = System::Drawing::Size(107, 19);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Amount to Pay";
			// 
			// amountToPay
			// 
			this->amountToPay->AllowDrop = true;
			this->amountToPay->Location = System::Drawing::Point(389, 259);
			this->amountToPay->Name = L"amountToPay";
			this->amountToPay->Size = System::Drawing::Size(293, 20);
			this->amountToPay->TabIndex = 11;
			// 
			// arrears
			// 
			this->arrears->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->arrears->Location = System::Drawing::Point(389, 139);
			this->arrears->Name = L"arrears";
			this->arrears->Size = System::Drawing::Size(293, 90);
			this->arrears->TabIndex = 13;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-2, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 177);
			this->pictureBox1->TabIndex = 62;
			this->pictureBox1->TabStop = false;
			// 
			// PayFees
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::IndianRed;
			this->ClientSize = System::Drawing::Size(859, 452);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->arrears);
			this->Controls->Add(this->amountToPay);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pay);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"PayFees";
			this->Text = L"PayFees";
			this->Load += gcnew System::EventHandler(this, &PayFees::PayFees_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arrears))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void PayFees_Load(System::Object^ sender, System::EventArgs^ e) {
	try {
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
		sqlConn->Open();
		sqlCmd->Connection = sqlConn;

		// Query to get payment information for the student
		sqlCmd->CommandText = "SELECT TotalAmount, PaidAmount FROM Payments WHERE StudentID = @StudentID AND Semester = 'Spring';";
		sqlCmd->Parameters->Clear(); // Clear parameters from previous usage
		sqlCmd->Parameters->AddWithValue("@StudentID", userid);
		sqlRd = sqlCmd->ExecuteReader();

		if (sqlRd->Read()) {
			double totalAmount = Convert::ToDouble(sqlRd["TotalAmount"]);
			double paidAmount = Convert::ToDouble(sqlRd["PaidAmount"]);

			arrears->Rows->Clear();
			arrears->Columns->Clear();
			arrears->Columns->Add("Total Amount", "Total Amount");
			arrears->Columns->Add("Paid Amount", "Paid Amount");
			arrears->Columns->Add("Remaining Amount", "Remaining Amount");

			DataGridViewRow^ row = gcnew DataGridViewRow();
			row->CreateCells(arrears);
			row->Cells[0]->Value = totalAmount;
			row->Cells[1]->Value = paidAmount;
			row->Cells[2]->Value = totalAmount - paidAmount;
			arrears->Rows->Add(row);
		}
		else {
			MessageBox::Show("No payment record found for the current semester.", "No Payment Record", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		sqlRd->Close();
		sqlConn->Close();
		sqlCmd->Parameters->Clear();
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}


private: System::Void pay_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ amountText = amountToPay->Text;
		double amountToPayDouble;

		if (!double::TryParse(amountText, amountToPayDouble) || amountToPayDouble <= 0) {
			MessageBox::Show("Please enter a valid amount to pay.", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		sqlConn->Open();
		sqlCmd->Connection = sqlConn;

		// Fetch current total and paid amounts
		sqlCmd->CommandText = "SELECT TotalAmount, PaidAmount FROM Payments WHERE StudentID = @StudentID AND Semester = 'Spring';";
		sqlCmd->Parameters->Clear(); // Clear parameters
		sqlCmd->Parameters->AddWithValue("@StudentID", userid);

		sqlRd = sqlCmd->ExecuteReader();

		if (sqlRd->Read()) {
			double totalAmount = Convert::ToDouble(sqlRd["TotalAmount"]);
			double paidAmount = Convert::ToDouble(sqlRd["PaidAmount"]);
			sqlRd->Close(); // Close reader before executing an update

			if (paidAmount + amountToPayDouble > totalAmount) {
				MessageBox::Show("Payment exceeds the remaining amount due.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			sqlCmd->CommandText = "UPDATE Payments SET PaidAmount = PaidAmount + @Amount WHERE StudentID = @StudentID AND Semester = 'Spring';";
			sqlCmd->Parameters->AddWithValue("@Amount", amountToPayDouble);
			sqlCmd->ExecuteNonQuery();

			MessageBox::Show("Payment successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
		else {
			MessageBox::Show("No payment record found for this semester.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		if (sqlConn->State == ConnectionState::Open) {
			sqlConn->Close();
		}
		sqlCmd->Parameters->Clear(); // Clear parameters
	}
}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}
};
}
