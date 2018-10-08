#pragma once

#include <iostream>
#include <iomanip>
#include <stdexcept>
namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			//TODO: Make this a nice funtion.
			this->comPortSelector->Items->Clear();
			array<String^>^ serialPorts = nullptr;
			serialPorts = this->serialPortToDevice->GetPortNames();
			for each(String^ port in serialPorts)
			{
				this->comPortSelector->Items->Add(port);
			}


		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (this->serialPortToDevice->IsOpen){
				this->serialPortToDevice->Close();
			}
			
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comPortSelector;
	protected:

	protected:

	private: System::IO::Ports::SerialPort^  serialPortToDevice;
	private: System::Windows::Forms::Button^  connectButton;
	protected:


	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::CheckBox^  LockingCheckBox;
	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
	public: bool LockingEnalbed = false;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->comPortSelector = (gcnew System::Windows::Forms::ComboBox());
			this->serialPortToDevice = (gcnew System::IO::Ports::SerialPort(this->components));
			this->connectButton = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->LockingCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// comPortSelector
			// 
			this->comPortSelector->FormattingEnabled = true;
			this->comPortSelector->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Select COM Port" });
			this->comPortSelector->Location = System::Drawing::Point(12, 29);
			this->comPortSelector->Name = L"comPortSelector";
			this->comPortSelector->Size = System::Drawing::Size(179, 21);
			this->comPortSelector->TabIndex = 0;
			this->comPortSelector->Text = L"Select COM Port";
			this->comPortSelector->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comPortSelector_SelectedIndexChanged);
			// 
			// serialPortToDevice
			// 
			this->serialPortToDevice->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::serialPortToDevice_DataReceived);
			// 
			// connectButton
			// 
			this->connectButton->Location = System::Drawing::Point(108, 109);
			this->connectButton->Name = L"connectButton";
			this->connectButton->Size = System::Drawing::Size(90, 29);
			this->connectButton->TabIndex = 1;
			this->connectButton->Text = L"Connect";
			this->connectButton->UseVisualStyleBackColor = true;
			this->connectButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(206, 24);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 29);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Refresh";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::refreshButton_Click);
			// 
			// LockingCheckBox
			// 
			this->LockingCheckBox->AutoSize = true;
			//this->LockingCheckBox->Checked = true; //Not nessecary since state is defined below
			this->LockingCheckBox->CheckState = System::Windows::Forms::CheckState::Unchecked;
			this->LockingCheckBox->Location = System::Drawing::Point(12, 73);
			this->LockingCheckBox->Name = L"LockingCheckBox";
			this->LockingCheckBox->Size = System::Drawing::Size(169, 17);
			this->LockingCheckBox->TabIndex = 3;
			this->LockingCheckBox->Text = L"Standard Double Tap Locking";
			this->LockingCheckBox->UseVisualStyleBackColor = true;
			this->LockingCheckBox->CheckStateChanged += gcnew System::EventHandler(this, &MyForm::LockingCheckBox_CheckStateChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(312, 144);
			this->Controls->Add(this->LockingCheckBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->connectButton);
			this->Controls->Add(this->comPortSelector);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Connect To Serial Device";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		try
		{ 
			this->serialPortToDevice->BaudRate = 9600;
			this->serialPortToDevice->Open();
		}
		catch (UnauthorizedAccessException^ e)
		{
			MessageBox::Show("Problem Opening Serial Port", "Error");
			Application::Exit();
			this->Close();
		}
		catch (System::IO::IOException^ ie)
		{
			MessageBox::Show("Problem Opening Serial Port", "Error");
			Application::Exit();
			this->Close();
		}
		//Stupid Threading, need to leave this call here for now
		this->Hide();
	}

		private: System::Void serialPortToDevice_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
			//std::cout << "" << std::endl;
		}

		private: System::Void comPortSelector_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			this->serialPortToDevice->PortName = this->comPortSelector->SelectedItem->ToString();
		}
		public: void sendDataOverComm(System::String^ dataToSend){
			try
			{
				if (this->serialPortToDevice->IsOpen)
				{
					this->serialPortToDevice->WriteLine(dataToSend);
				}
			
			}
			catch(int e)
			{
			}
		}
		//Sends Integer over serail communication
		public: void sendIntOverComm(System::String^ intDataToSend) {
			try
			{
				if (this->serialPortToDevice->IsOpen)
				{
					this->serialPortToDevice->WriteLine(intDataToSend);
				}

			}
			catch (int e)
			{
			}
		}

		private: System::Void refreshButton_Click(System::Object^  sender, System::EventArgs^  e) {
			this->comPortSelector->Items->Clear();
			array<String^>^ serialPorts = nullptr;
			serialPorts = this->serialPortToDevice->GetPortNames();
			for each(String^ port in serialPorts)
			{
				this->comPortSelector->Items->Add(port);
			}
		}

		private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void LockingCheckBox_CheckStateChanged(System::Object^  sender, System::EventArgs^  e) {
			this->LockingEnalbed = this->LockingCheckBox->Checked;
		}
	};
}
