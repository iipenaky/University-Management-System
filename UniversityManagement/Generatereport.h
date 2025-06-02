#pragma once

namespace UniversityManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;
    using namespace System::Drawing::Printing;

    public ref class Generatereport : public System::Windows::Forms::Form
    {
    public:
        MySqlConnection^ sqlConn = gcnew MySqlConnection();
        MySqlCommand^ sqlCmd = gcnew MySqlCommand();
        DataTable^ sqlDt = gcnew DataTable();
        MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
    private: System::Drawing::Printing::PrintDocument^ printDocument1;
    public:
    private: System::Windows::Forms::PrintPreviewDialog^ printPreviewDialog1;
    private: System::Windows::Forms::PictureBox^ pictureBox1;

    public:
        MySqlDataReader^ sqlRd;

        Generatereport(void)
        {
            InitializeComponent();
            sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";

            // Initialize PrintDialog and PrintDocument
            printDialog = gcnew System::Windows::Forms::PrintDialog();
            printDocument = gcnew System::Drawing::Printing::PrintDocument();
            printPreviewDialog = gcnew System::Windows::Forms::PrintPreviewDialog();

            // Subscribe to the PrintPage event of the PrintDocument
            printDocument->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &Generatereport::printDocument_PrintPage);
        }

    protected:
        ~Generatereport()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ print;
        System::Windows::Forms::TextBox^ studentId;
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::RichTextBox^ transcriptBox;  // Changed from DataGridView to RichTextBox
        System::Windows::Forms::Button^ generateR;
        System::Windows::Forms::PrintDialog^ printDialog;
        System::Drawing::Printing::PrintDocument^ printDocument;
        System::Windows::Forms::PrintPreviewDialog^ printPreviewDialog;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Generatereport::typeid));
            this->print = (gcnew System::Windows::Forms::Button());
            this->studentId = (gcnew System::Windows::Forms::TextBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->transcriptBox = (gcnew System::Windows::Forms::RichTextBox());
            this->generateR = (gcnew System::Windows::Forms::Button());
            this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
            this->printPreviewDialog1 = (gcnew System::Windows::Forms::PrintPreviewDialog());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // print
            // 
            this->print->ForeColor = System::Drawing::Color::Black;
            this->print->Location = System::Drawing::Point(681, 100);
            this->print->Name = L"print";
            this->print->Size = System::Drawing::Size(75, 23);
            this->print->TabIndex = 27;
            this->print->Text = L"Print";
            this->print->UseVisualStyleBackColor = true;
            this->print->Click += gcnew System::EventHandler(this, &Generatereport::print_Click);
            // 
            // studentId
            // 
            this->studentId->Location = System::Drawing::Point(305, 100);
            this->studentId->Name = L"studentId";
            this->studentId->Size = System::Drawing::Size(237, 20);
            this->studentId->TabIndex = 26;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->ForeColor = System::Drawing::Color::White;
            this->label5->Location = System::Drawing::Point(189, 102);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(86, 18);
            this->label5->TabIndex = 25;
            this->label5->Text = L"Student ID";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(362, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(326, 31);
            this->label1->TabIndex = 18;
            this->label1->Text = L"Generate Student\'s Report";
            // 
            // transcriptBox
            // 
            this->transcriptBox->Location = System::Drawing::Point(281, 183);
            this->transcriptBox->Name = L"transcriptBox";
            this->transcriptBox->Size = System::Drawing::Size(440, 276);
            this->transcriptBox->TabIndex = 28;
            this->transcriptBox->Text = L"";
            // 
            // generateR
            // 
            this->generateR->ForeColor = System::Drawing::Color::Black;
            this->generateR->Location = System::Drawing::Point(200, 181);
            this->generateR->Name = L"generateR";
            this->generateR->Size = System::Drawing::Size(75, 23);
            this->generateR->TabIndex = 29;
            this->generateR->Text = L"Generate";
            this->generateR->UseVisualStyleBackColor = true;
            this->generateR->Click += gcnew System::EventHandler(this, &Generatereport::generateR_Click);
            // 
            // printDocument1
            // 
            this->printDocument1->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &Generatereport::printDocument1_PrintPage_1);
            // 
            // printPreviewDialog1
            // 
            this->printPreviewDialog1->AutoScrollMargin = System::Drawing::Size(0, 0);
            this->printPreviewDialog1->AutoScrollMinSize = System::Drawing::Size(0, 0);
            this->printPreviewDialog1->ClientSize = System::Drawing::Size(400, 300);
            this->printPreviewDialog1->Document = this->printDocument1;
            this->printPreviewDialog1->Enabled = true;
            this->printPreviewDialog1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"printPreviewDialog1.Icon")));
            this->printPreviewDialog1->Name = L"printPreviewDialog1";
            this->printPreviewDialog1->Visible = false;
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
            // Generatereport
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::IndianRed;
            this->ClientSize = System::Drawing::Size(758, 492);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->generateR);
            this->Controls->Add(this->transcriptBox);
            this->Controls->Add(this->print);
            this->Controls->Add(this->studentId);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label1);
            this->ForeColor = System::Drawing::Color::White;
            this->Name = L"Generatereport";
            this->Text = L"Generatereport";
            this->Load += gcnew System::EventHandler(this, &Generatereport::Generatereport_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        // Event handler for Generate button
    private: System::Void generateR_Click(System::Object^ sender, System::EventArgs^ e) {
        if (studentId->Text->Trim() == "") {
            MessageBox::Show("Please enter a Student ID.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        String^ studentID = studentId->Text->Trim();
        transcriptBox->Clear();  // Clear previous transcript

        try {
            sqlConn->Open();
            sqlCmd->Connection = sqlConn;

            // Query for transcript data
            sqlCmd->CommandText =
                "SELECT users.FirstName, users.LastName, students.Major, "
                "courses.CourseName, courses.Credits, enrollments.Grade "
                "FROM enrollments "
                "JOIN users ON enrollments.StudentID = users.UserID "
                "JOIN students ON enrollments.StudentID = students.StudentID "
                "JOIN courses ON enrollments.CourseID = courses.CourseID "
                "WHERE enrollments.StudentID = @studentID";
            sqlCmd->Parameters->Clear();
            sqlCmd->Parameters->AddWithValue("@studentID", studentID);

            sqlDt->Clear();
            sqlDtA->SelectCommand = sqlCmd;
            sqlDtA->Fill(sqlDt);

            // Fetch student's name and major (for the header)
            String^ studentName = sqlDt->Rows[0]["FirstName"]->ToString() + " " + sqlDt->Rows[0]["LastName"]->ToString();
            String^ studentMajor = sqlDt->Rows[0]["Major"]->ToString();

            // Add GPA, Overall GPA, and CGPA columns to the DataTable
            if (!sqlDt->Columns->Contains("GPA")) {
                sqlDt->Columns->Add("GPA", double::typeid);
            }
            if (!sqlDt->Columns->Contains("OverallGPA")) {
                sqlDt->Columns->Add("OverallGPA", double::typeid);
            }
            if (!sqlDt->Columns->Contains("CGPA")) {
                sqlDt->Columns->Add("CGPA", double::typeid);
            }

            double totalPoints = 0;
            int totalCredits = 0;
            double totalCreditsForCGPA = 0;
            double totalPointsForCGPA = 0;

            transcriptBox->AppendText("Student Name: " + studentName + "\n");
            transcriptBox->AppendText("Major: " + studentMajor + "\n\n");

            // Build transcript layout in RichTextBox
            transcriptBox->AppendText("Course Name\tCredits\tGrade\tGPA\n");
            transcriptBox->AppendText("---------------------------------------------\n");

            // Calculate GPA for each course and CGPA
            for (int i = 0; i < sqlDt->Rows->Count; i++) {
                String^ courseName = sqlDt->Rows[i]["CourseName"]->ToString();
                int credits = Convert::ToInt32(sqlDt->Rows[i]["Credits"]);
                String^ grade = sqlDt->Rows[i]["Grade"]->ToString();

                double gpa = 0;
                if (grade == "A") gpa = 4.0;
                else if (grade == "A+") gpa = 4.0;
                else if (grade == "B+") gpa = 4.0;
                else if (grade == "B") gpa = 3.0;
                else if (grade == "C+") gpa = 2.5;
                else if (grade == "C") gpa = 2.0;
                else if (grade == "D") gpa = 1.0;
                else if (grade == "F") gpa = 0.0;

                totalPoints += gpa * credits;
                totalCredits += credits;

                transcriptBox->AppendText(courseName + "\t" + credits + "\t" + grade + "\t" + gpa + "\n");

                // Calculate CGPA
                totalCreditsForCGPA += credits;
                totalPointsForCGPA += gpa * credits;
            }

            double gpaOverall = totalPoints / totalCredits;
            double cgpa = totalPointsForCGPA / totalCreditsForCGPA;

            transcriptBox->AppendText("---------------------------------------------\n");
            transcriptBox->AppendText("GPA: " + gpaOverall.ToString("F2") + "\n");
            transcriptBox->AppendText("CGPA: " + cgpa.ToString("F2") + "\n");

            sqlConn->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            sqlConn->Close();
        }
    }

           // Event handler for Print button
private: System::Void print_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        // Validate content
        if (String::IsNullOrWhiteSpace(transcriptBox->Text)) {
            MessageBox::Show("No report to print. Generate a report first.", "Print Error",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }
        printPreviewDialog1->Document = printDocument;
        printPreviewDialog1->Width = 800;
        printPreviewDialog->Height = 600;

        // Show print preview
        if (printPreviewDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            try {
                printDocument->Print();
            }
            catch (System::ComponentModel::Win32Exception^ win32Ex) {
                MessageBox::Show("Windows Printing Error: " + win32Ex->Message +
                    "\nError Code: " + win32Ex->ErrorCode,
                    "Printing Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            catch (System::Drawing::Printing::InvalidPrinterException^ printerEx) {
                MessageBox::Show("Invalid Printer: " + printerEx->Message,
                    "Printer Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Unexpected Error during printing: " + ex->Message +
            "\nType: " + ex->GetType()->ToString(),
            "Critical Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

private: System::Void printDocument_PrintPage(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e) {
    try {
        // Validate input parameters
        if (e == nullptr || e->Graphics == nullptr) {
            MessageBox::Show("Invalid print parameters.", "Print Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            e->Cancel = true;
            return;
        }

        // More robust font and layout
        System::Drawing::Font^ printFont = gcnew System::Drawing::Font("Courier New", 10);
        System::Drawing::StringFormat^ stringFormat = gcnew System::Drawing::StringFormat();

        // Use RectangleF for more precise layout
        RectangleF printArea = RectangleF(
            e->MarginBounds.Left,
            e->MarginBounds.Top,
            e->MarginBounds.Width,
            e->MarginBounds.Height
        );

        // Render the entire text
        e->Graphics->DrawString(
            transcriptBox->Text,
            printFont,
            System::Drawing::Brushes::Black,
            printArea,
            stringFormat
        );

        // Indicate no more pages
        e->HasMorePages = false;
    }
    catch (Exception^ ex) {
        MessageBox::Show("Rendering Error: " + ex->Message, "Print Rendering Error",
            MessageBoxButtons::OK, MessageBoxIcon::Error);
        e->Cancel = true;
    }
}



private: System::Void Generatereport_Load(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void printDocument1_PrintPage_1(System::Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e) {
    System::Drawing::Font^ fntString = gcnew System::Drawing::Font("Times New Roman", 18, FontStyle::Regular);
    e->Graphics->DrawString(transcriptBox->Text, fntString, Brushes::Black, 120, 120);
}
};
}
