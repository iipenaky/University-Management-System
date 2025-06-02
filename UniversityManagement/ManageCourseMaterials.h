#pragma once

namespace UniversityManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;
    using namespace System::IO;

    public ref class ManageCourseMaterials : public System::Windows::Forms::Form
    {
        MySqlConnection^ sqlConn = gcnew MySqlConnection();
        MySqlCommand^ sqlCmd = gcnew MySqlCommand();
        DataTable^ sqlDt = gcnew DataTable();
        MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
        MySqlDataReader^ sqlRd;
    private: System::Windows::Forms::Label^ label5;
           String^ userid;

    public:
        ManageCourseMaterials(String^ id)
        {
            InitializeComponent();
            userid = id;
            sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=universityrecords";
        }

    protected:
        ~ManageCourseMaterials()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::TextBox^ courseId;
        System::Windows::Forms::TextBox^ materialName;
        System::Windows::Forms::ComboBox^ materialType;
        System::Windows::Forms::TextBox^ materialSource;
        System::Windows::Forms::TextBox^ materialDescription;
        System::Windows::Forms::Button^ browseButton;
        System::Windows::Forms::Button^ uploadButton;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->courseId = (gcnew System::Windows::Forms::TextBox());
            this->materialName = (gcnew System::Windows::Forms::TextBox());
            this->materialType = (gcnew System::Windows::Forms::ComboBox());
            this->materialSource = (gcnew System::Windows::Forms::TextBox());
            this->materialDescription = (gcnew System::Windows::Forms::TextBox());
            this->browseButton = (gcnew System::Windows::Forms::Button());
            this->uploadButton = (gcnew System::Windows::Forms::Button());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.25F, System::Drawing::FontStyle::Bold));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(180, 20);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(255, 25);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Manage Course Materials";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->ForeColor = System::Drawing::Color::White;
            this->label2->Location = System::Drawing::Point(63, 80);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(89, 18);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Course ID:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->ForeColor = System::Drawing::Color::White;
            this->label3->Location = System::Drawing::Point(63, 123);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(122, 18);
            this->label3->TabIndex = 3;
            this->label3->Text = L"Material Name:";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->ForeColor = System::Drawing::Color::White;
            this->label4->Location = System::Drawing::Point(63, 163);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(114, 18);
            this->label4->TabIndex = 5;
            this->label4->Text = L"Material Type:";
            // 
            // courseId
            // 
            this->courseId->Location = System::Drawing::Point(210, 78);
            this->courseId->Name = L"courseId";
            this->courseId->Size = System::Drawing::Size(200, 20);
            this->courseId->TabIndex = 2;
            // 
            // materialName
            // 
            this->materialName->Location = System::Drawing::Point(210, 121);
            this->materialName->Name = L"materialName";
            this->materialName->Size = System::Drawing::Size(200, 20);
            this->materialName->TabIndex = 4;
            // 
            // materialType
            // 
            this->materialType->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"File", L"Link", L"Video", L"Book" });
            this->materialType->Location = System::Drawing::Point(210, 160);
            this->materialType->Name = L"materialType";
            this->materialType->Size = System::Drawing::Size(200, 21);
            this->materialType->TabIndex = 6;
            this->materialType->SelectedIndexChanged += gcnew System::EventHandler(this, &ManageCourseMaterials::MaterialType_Changed);
            // 
            // materialSource
            // 
            this->materialSource->Location = System::Drawing::Point(210, 207);
            this->materialSource->Name = L"materialSource";
            this->materialSource->Size = System::Drawing::Size(200, 20);
            this->materialSource->TabIndex = 7;
            this->materialSource->TextChanged += gcnew System::EventHandler(this, &ManageCourseMaterials::materialSource_TextChanged);
            // 
            // materialDescription
            // 
            this->materialDescription->Location = System::Drawing::Point(210, 254);
            this->materialDescription->Multiline = true;
            this->materialDescription->Name = L"materialDescription";
            this->materialDescription->Size = System::Drawing::Size(200, 60);
            this->materialDescription->TabIndex = 8;
            // 
            // browseButton
            // 
            this->browseButton->ForeColor = System::Drawing::Color::White;
            this->browseButton->Location = System::Drawing::Point(479, 279);
            this->browseButton->Name = L"browseButton";
            this->browseButton->Size = System::Drawing::Size(75, 23);
            this->browseButton->TabIndex = 9;
            this->browseButton->Text = L"Browse";
            this->browseButton->Click += gcnew System::EventHandler(this, &ManageCourseMaterials::BrowseFile);
            // 
            // uploadButton
            // 
            this->uploadButton->ForeColor = System::Drawing::Color::White;
            this->uploadButton->Location = System::Drawing::Point(110, 279);
            this->uploadButton->Name = L"uploadButton";
            this->uploadButton->Size = System::Drawing::Size(75, 23);
            this->uploadButton->TabIndex = 10;
            this->uploadButton->Text = L"Upload";
            this->uploadButton->Click += gcnew System::EventHandler(this, &ManageCourseMaterials::UploadMaterial);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->ForeColor = System::Drawing::Color::White;
            this->label5->Location = System::Drawing::Point(40, 207);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(164, 18);
            this->label5->TabIndex = 11;
            this->label5->Text = L"Material Description:";
            // 
            // ManageCourseMaterials
            // 
            this->BackColor = System::Drawing::Color::IndianRed;
            this->ClientSize = System::Drawing::Size(600, 400);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->courseId);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->materialName);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->materialType);
            this->Controls->Add(this->materialSource);
            this->Controls->Add(this->materialDescription);
            this->Controls->Add(this->browseButton);
            this->Controls->Add(this->uploadButton);
            this->ForeColor = System::Drawing::Color::White;
            this->Name = L"ManageCourseMaterials";
            this->Text = L"Manage Course Materials";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        void MaterialType_Changed(System::Object^ sender, System::EventArgs^ e) {
            String^ selectedType = this->materialType->SelectedItem->ToString();
            if (selectedType == "File") {
                this->browseButton->Visible = true;
                this->materialSource->Enabled = false;
            }
            else {
                this->browseButton->Visible = false;
                this->materialSource->Enabled = true;
            }
        }

        void BrowseFile(System::Object^ sender, System::EventArgs^ e) {
            OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
            openFileDialog->Filter = "All Files (*.*)|*.*";
            if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                this->materialSource->Text = openFileDialog->FileName;
            }
        }

        void UploadMaterial(System::Object^ sender, System::EventArgs^ e) {
            try {
                // Collect data from the form
                String^ courseId = this->courseId->Text;
                String^ materialName = this->materialName->Text;
                String^ materialType = this->materialType->SelectedItem->ToString();
                String^ materialSource = this->materialSource->Text;
                String^ materialDescription = this->materialDescription->Text;

                // Validate inputs
                if (String::IsNullOrWhiteSpace(courseId) || String::IsNullOrWhiteSpace(materialName) ||
                    String::IsNullOrWhiteSpace(materialSource) || this->materialType->SelectedIndex == -1) {
                    MessageBox::Show("All fields except description are required.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                // Database connection and insertion
                sqlConn->Open();
                sqlCmd->Connection = sqlConn;

                sqlCmd->CommandText = "INSERT INTO CourseMaterials (CourseID, MaterialName, MaterialType, MaterialSource, MaterialDescription, UploadedBy) "
                    "VALUES (@courseId, @materialName, @materialType, @materialSource, @materialDescription, @uploadedBy)";

                sqlCmd->Parameters->AddWithValue("@courseId", courseId);
                sqlCmd->Parameters->AddWithValue("@materialName", materialName);
                sqlCmd->Parameters->AddWithValue("@materialType", materialType);
                sqlCmd->Parameters->AddWithValue("@materialSource", materialSource);
                sqlCmd->Parameters->AddWithValue("@materialDescription", materialDescription);
                sqlCmd->Parameters->AddWithValue("@uploadedBy", userid);

                int result = sqlCmd->ExecuteNonQuery();

                if (result > 0) {
                    MessageBox::Show("Course material uploaded successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    this->Hide();
                }
                else {
                    MessageBox::Show("Failed to upload course material.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            catch (Exception^ ex) {
                MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally {
                // Clean up
                sqlConn->Close();
                sqlCmd->Parameters->Clear();
            }
        }

    private: System::Void materialSource_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
