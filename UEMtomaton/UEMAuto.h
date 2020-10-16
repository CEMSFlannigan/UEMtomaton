#pragma once
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "kernel32.lib")
#pragma comment (lib, "user32.lib")
#pragma comment (lib, "SoloistC.lib")
#pragma comment (lib, "SoloistC64.lib")

#include <sys/stat.h>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <process.h> 
#include <iostream>
#include <ctime>
#include <time.h>
#include <sstream>
#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <algorithm>
#include <Windows.h>
#include <WinUser.h>
#include <filesystem>
#include "WriteULG.h"
#include "WriteDMComm.h"
#include "Soloist.h"

/* -------------------------------GLOBAL VARIABLE DECLARATIONS-------------------------------------- */

WSADATA WSAData;

// Double socket setup for delay value communication to the camera and run-status communication to the camera
SOCKET dc_server, cc_server;

// Camera side. Two addresses for delay position and camera
SOCKADDR_IN dc_addr, cc_addr;

// Delay stage side. Two clients for delay position communication and camera communication
SOCKET delaycomm_client, camcomm_client;

// Four seperate addresses. Each side of the program will only use two.
SOCKADDR_IN dc_serverAddr, cc_serverAddr, dc_clientAddr, cc_clientAddr;

// variables for passing data between delay stage computer and camera computer. If we need more than 1024 alphanumerical characters, change 1024 to MAX_VAL or integer MAX
char dc_buffer[1024], cc_buffer[1024];

// Indicates the size of the addresses for each communication client and server. Used to open a port
int cc_clientAddrSize, dc_clientAddrSize, servAddrSize;

double* timeTable; // the table of time points generated from the Make Timepoints program
double* timeptArr; // the array of time points generated from the time-point table
double* expArr; // the array of experimental time points to be measured by the instruments (accounts for randomization)
int includeLast; // indicates whether or not to include the last point in the time-point table
int randomized; // indicates a randomized set of timepoints or not
int totPoints; // the total number of points in the experimental time points array

int designation; // used to designate whether camera or delay stage after pressing the initialize buttons on either side
int runStat; // indicates the status of a currently running scan. 0 indicates not running. 1 indicates running. 2 indicates a pause. 3 indicates a stop command which will switch to 0.
int butPressMeantime; // indicates whether a button has been pressed while a run is occuring (pause, play, or stop)
double timeLeft; // keeps track of the time left in a run. This is an estimated

double spdlght; // m/s
double curZero; // As of August 16th, 2019 position 293.527 mm on the delay stage corresponds to 0 ps
double curTimeEnd;
double mm_to_fs;
double curdelTime; // current delay position in terms of time relative to some fixed position on the delay stage

char units[2]; // the units used to designate the file names and .ULG data

// Tracks the time
time_t my_time;

// Handles to all the connected Soloists
SoloistHandle* handles;
// Handle to give access to Soloist
SoloistHandle handle = NULL;
DWORD handleCount = 0;
DOUBLE positionFeedback;

// Declaring a namespace and all constructor methods
namespace UEMtamaton {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class UEMAuto : public System::Windows::Forms::Form
	{
	public:
		UEMAuto(void) // constructor for all values that need to be initialized
		{
			InitializeComponent();

			spdlght = 299792458;
			mm_to_fs = 1e12 / spdlght / 1000;
			curZero = 293.527;
			curTimeEnd = -1 * curZero * mm_to_fs;
			units[0] = 'p'; // initialize with ps
			units[1] = 's';
			designation = -1; // to tell either side that no designation has been assigned yet.
			runStat = 0; // set default value of runstat
			timeLeft = 0; // set the estimated time left to zero
		}

	protected:
		/// Clean up any resources being used.
		~UEMAuto()
		{
			if (components)
			{
				delete components;
			}
		}

	// Declare all Form objects
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::ToolStripPanel^ BottomToolStripPanel;
	private: System::Windows::Forms::ToolStripPanel^ TopToolStripPanel;
	private: System::Windows::Forms::ToolStripPanel^ RightToolStripPanel;
	private: System::Windows::Forms::ToolStripPanel^ LeftToolStripPanel;
	private: System::Windows::Forms::ToolStripContentPanel^ ContentPanel;
	private: System::Windows::Forms::TabControl^ cameraTab;

	private: System::Windows::Forms::TabPage^ delayTab;


	private: System::Windows::Forms::Button^ ServInitButton;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Button^ ServConnButton;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ delayPosTime;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ delaySpd;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ delayMovFor;

	private: System::Windows::Forms::Button^ delayMovBack;
	private: System::Windows::Forms::Label^ delayPosDist;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;




	private: System::Windows::Forms::TextBox^ statusWindow;









	private: System::Windows::Forms::Button^ disconServ;
	private: System::ComponentModel::BackgroundWorker^ trackTime;

	private: System::Windows::Forms::Label^ curTime;


	private: System::ComponentModel::BackgroundWorker^ delayComm;
	private: System::Windows::Forms::Button^ disconCam;
	private: System::Windows::Forms::TextBox^ servIP;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ browseFilePath;
	private: System::Windows::Forms::TextBox^ fileSavePath;

	private: System::Windows::Forms::TextBox^ camStat;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ fileNameBase;
	private: System::Windows::Forms::Label^ label10;












	private: System::ComponentModel::BackgroundWorker^ scanRunner;
	private: System::ComponentModel::BackgroundWorker^ cameraRunner;
	private: System::Windows::Forms::Label^ camDelPosPS;
	private: System::Windows::Forms::Label^ camDelPosMM;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::RadioButton^ nsIndicator;

	private: System::Windows::Forms::RadioButton^ psIndicator;
	private: System::ComponentModel::BackgroundWorker^ delayValueUpdater;
	private: System::Windows::Forms::Button^ stopButton;
	private: System::Windows::Forms::Button^ pauseButton;
	private: System::Windows::Forms::Button^ runScan;
	private: System::Windows::Forms::Button^ playRun;
	private: System::Windows::Forms::CheckBox^ randomPoints;
	private: System::Windows::Forms::Button^ MakeTimeButton;
	private: System::Windows::Forms::Label^ timeRemLab;
	private: System::Windows::Forms::DataGridView^ TimePoints;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TimepointList;
	private: System::Windows::Forms::Label^ tRT;
	private: System::Windows::Forms::ProgressBar^ runProg;
	private: System::Windows::Forms::DataGridView^ DataReadouts;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Step;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Timepoint;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DelayPos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ delayStatus;





	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// Required designer variable.


#pragma region Windows Form Designer generated code
		/// Required method for Designer support
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UEMAuto::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->BottomToolStripPanel = (gcnew System::Windows::Forms::ToolStripPanel());
			this->TopToolStripPanel = (gcnew System::Windows::Forms::ToolStripPanel());
			this->RightToolStripPanel = (gcnew System::Windows::Forms::ToolStripPanel());
			this->LeftToolStripPanel = (gcnew System::Windows::Forms::ToolStripPanel());
			this->ContentPanel = (gcnew System::Windows::Forms::ToolStripContentPanel());
			this->cameraTab = (gcnew System::Windows::Forms::TabControl());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->DataReadouts = (gcnew System::Windows::Forms::DataGridView());
			this->Step = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Timepoint = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DelayPos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->delayStatus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->stopButton = (gcnew System::Windows::Forms::Button());
			this->pauseButton = (gcnew System::Windows::Forms::Button());
			this->runScan = (gcnew System::Windows::Forms::Button());
			this->playRun = (gcnew System::Windows::Forms::Button());
			this->randomPoints = (gcnew System::Windows::Forms::CheckBox());
			this->MakeTimeButton = (gcnew System::Windows::Forms::Button());
			this->timeRemLab = (gcnew System::Windows::Forms::Label());
			this->TimePoints = (gcnew System::Windows::Forms::DataGridView());
			this->TimepointList = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tRT = (gcnew System::Windows::Forms::Label());
			this->nsIndicator = (gcnew System::Windows::Forms::RadioButton());
			this->runProg = (gcnew System::Windows::Forms::ProgressBar());
			this->psIndicator = (gcnew System::Windows::Forms::RadioButton());
			this->camDelPosPS = (gcnew System::Windows::Forms::Label());
			this->camDelPosMM = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->fileNameBase = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->browseFilePath = (gcnew System::Windows::Forms::Button());
			this->fileSavePath = (gcnew System::Windows::Forms::TextBox());
			this->camStat = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->servIP = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->disconCam = (gcnew System::Windows::Forms::Button());
			this->ServConnButton = (gcnew System::Windows::Forms::Button());
			this->delayTab = (gcnew System::Windows::Forms::TabPage());
			this->disconServ = (gcnew System::Windows::Forms::Button());
			this->statusWindow = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->delayPosDist = (gcnew System::Windows::Forms::Label());
			this->delayPosTime = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->delaySpd = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->delayMovFor = (gcnew System::Windows::Forms::Button());
			this->delayMovBack = (gcnew System::Windows::Forms::Button());
			this->ServInitButton = (gcnew System::Windows::Forms::Button());
			this->trackTime = (gcnew System::ComponentModel::BackgroundWorker());
			this->curTime = (gcnew System::Windows::Forms::Label());
			this->delayComm = (gcnew System::ComponentModel::BackgroundWorker());
			this->scanRunner = (gcnew System::ComponentModel::BackgroundWorker());
			this->cameraRunner = (gcnew System::ComponentModel::BackgroundWorker());
			this->delayValueUpdater = (gcnew System::ComponentModel::BackgroundWorker());
			this->cameraTab->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataReadouts))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimePoints))->BeginInit();
			this->delayTab->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"UEM Automation";
			// 
			// BottomToolStripPanel
			// 
			this->BottomToolStripPanel->Location = System::Drawing::Point(0, 0);
			this->BottomToolStripPanel->Name = L"BottomToolStripPanel";
			this->BottomToolStripPanel->Orientation = System::Windows::Forms::Orientation::Horizontal;
			this->BottomToolStripPanel->RowMargin = System::Windows::Forms::Padding(3, 0, 0, 0);
			this->BottomToolStripPanel->Size = System::Drawing::Size(0, 0);
			// 
			// TopToolStripPanel
			// 
			this->TopToolStripPanel->Location = System::Drawing::Point(0, 0);
			this->TopToolStripPanel->Name = L"TopToolStripPanel";
			this->TopToolStripPanel->Orientation = System::Windows::Forms::Orientation::Horizontal;
			this->TopToolStripPanel->RowMargin = System::Windows::Forms::Padding(3, 0, 0, 0);
			this->TopToolStripPanel->Size = System::Drawing::Size(0, 0);
			// 
			// RightToolStripPanel
			// 
			this->RightToolStripPanel->Location = System::Drawing::Point(0, 0);
			this->RightToolStripPanel->Name = L"RightToolStripPanel";
			this->RightToolStripPanel->Orientation = System::Windows::Forms::Orientation::Horizontal;
			this->RightToolStripPanel->RowMargin = System::Windows::Forms::Padding(3, 0, 0, 0);
			this->RightToolStripPanel->Size = System::Drawing::Size(0, 0);
			// 
			// LeftToolStripPanel
			// 
			this->LeftToolStripPanel->Location = System::Drawing::Point(0, 0);
			this->LeftToolStripPanel->Name = L"LeftToolStripPanel";
			this->LeftToolStripPanel->Orientation = System::Windows::Forms::Orientation::Horizontal;
			this->LeftToolStripPanel->RowMargin = System::Windows::Forms::Padding(3, 0, 0, 0);
			this->LeftToolStripPanel->Size = System::Drawing::Size(0, 0);
			// 
			// ContentPanel
			// 
			this->ContentPanel->Size = System::Drawing::Size(1019, 592);
			// 
			// cameraTab
			// 
			this->cameraTab->Controls->Add(this->tabPage2);
			this->cameraTab->Controls->Add(this->delayTab);
			this->cameraTab->Location = System::Drawing::Point(16, 53);
			this->cameraTab->Name = L"cameraTab";
			this->cameraTab->SelectedIndex = 0;
			this->cameraTab->Size = System::Drawing::Size(796, 610);
			this->cameraTab->TabIndex = 1;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->DataReadouts);
			this->tabPage2->Controls->Add(this->stopButton);
			this->tabPage2->Controls->Add(this->pauseButton);
			this->tabPage2->Controls->Add(this->runScan);
			this->tabPage2->Controls->Add(this->playRun);
			this->tabPage2->Controls->Add(this->randomPoints);
			this->tabPage2->Controls->Add(this->MakeTimeButton);
			this->tabPage2->Controls->Add(this->timeRemLab);
			this->tabPage2->Controls->Add(this->TimePoints);
			this->tabPage2->Controls->Add(this->tRT);
			this->tabPage2->Controls->Add(this->nsIndicator);
			this->tabPage2->Controls->Add(this->runProg);
			this->tabPage2->Controls->Add(this->psIndicator);
			this->tabPage2->Controls->Add(this->camDelPosPS);
			this->tabPage2->Controls->Add(this->camDelPosMM);
			this->tabPage2->Controls->Add(this->label12);
			this->tabPage2->Controls->Add(this->label11);
			this->tabPage2->Controls->Add(this->fileNameBase);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Controls->Add(this->browseFilePath);
			this->tabPage2->Controls->Add(this->fileSavePath);
			this->tabPage2->Controls->Add(this->camStat);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->servIP);
			this->tabPage2->Controls->Add(this->label6);
			this->tabPage2->Controls->Add(this->disconCam);
			this->tabPage2->Controls->Add(this->ServConnButton);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(788, 584);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Camera Side";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// DataReadouts
			// 
			this->DataReadouts->AllowUserToAddRows = false;
			this->DataReadouts->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->DataReadouts->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->DataReadouts->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DataReadouts->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Step, this->Timepoint,
					this->DelayPos, this->delayStatus
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->DataReadouts->DefaultCellStyle = dataGridViewCellStyle2;
			this->DataReadouts->Location = System::Drawing::Point(194, 211);
			this->DataReadouts->Name = L"DataReadouts";
			this->DataReadouts->ReadOnly = true;
			this->DataReadouts->Size = System::Drawing::Size(575, 223);
			this->DataReadouts->TabIndex = 8;
			// 
			// Step
			// 
			this->Step->HeaderText = L"Step";
			this->Step->Name = L"Step";
			this->Step->ReadOnly = true;
			// 
			// Timepoint
			// 
			this->Timepoint->HeaderText = L"Timepoint (ps)";
			this->Timepoint->Name = L"Timepoint";
			this->Timepoint->ReadOnly = true;
			// 
			// DelayPos
			// 
			this->DelayPos->HeaderText = L"Delay Stage Position (mm)";
			this->DelayPos->Name = L"DelayPos";
			this->DelayPos->ReadOnly = true;
			// 
			// delayStatus
			// 
			this->delayStatus->HeaderText = L"Status";
			this->delayStatus->Name = L"delayStatus";
			this->delayStatus->ReadOnly = true;
			this->delayStatus->Width = 230;
			// 
			// stopButton
			// 
			this->stopButton->Location = System::Drawing::Point(18, 534);
			this->stopButton->Name = L"stopButton";
			this->stopButton->Size = System::Drawing::Size(69, 31);
			this->stopButton->TabIndex = 22;
			this->stopButton->Text = L"Stop Run";
			this->stopButton->UseVisualStyleBackColor = true;
			this->stopButton->Click += gcnew System::EventHandler(this, &UEMAuto::StopButton_Click);
			// 
			// pauseButton
			// 
			this->pauseButton->ForeColor = System::Drawing::Color::Black;
			this->pauseButton->Location = System::Drawing::Point(698, 150);
			this->pauseButton->Name = L"pauseButton";
			this->pauseButton->Size = System::Drawing::Size(32, 23);
			this->pauseButton->TabIndex = 21;
			this->pauseButton->Text = L"| |";
			this->pauseButton->UseVisualStyleBackColor = true;
			this->pauseButton->Click += gcnew System::EventHandler(this, &UEMAuto::PauseButton_Click);
			// 
			// runScan
			// 
			this->runScan->Location = System::Drawing::Point(663, 87);
			this->runScan->Name = L"runScan";
			this->runScan->Size = System::Drawing::Size(106, 51);
			this->runScan->TabIndex = 6;
			this->runScan->Text = L"4. Run Scan";
			this->runScan->UseVisualStyleBackColor = true;
			this->runScan->Click += gcnew System::EventHandler(this, &UEMAuto::RunScan_Click);
			// 
			// playRun
			// 
			this->playRun->Location = System::Drawing::Point(737, 150);
			this->playRun->Name = L"playRun";
			this->playRun->Size = System::Drawing::Size(32, 23);
			this->playRun->TabIndex = 20;
			this->playRun->Text = L">";
			this->playRun->UseVisualStyleBackColor = true;
			this->playRun->Click += gcnew System::EventHandler(this, &UEMAuto::PlayRun_Click);
			// 
			// randomPoints
			// 
			this->randomPoints->AutoSize = true;
			this->randomPoints->Location = System::Drawing::Point(524, 105);
			this->randomPoints->Name = L"randomPoints";
			this->randomPoints->Size = System::Drawing::Size(133, 17);
			this->randomPoints->TabIndex = 5;
			this->randomPoints->Text = L"Randomize Timepoints";
			this->randomPoints->UseVisualStyleBackColor = true;
			this->randomPoints->CheckedChanged += gcnew System::EventHandler(this, &UEMAuto::RandomPoints_CheckedChanged);
			// 
			// MakeTimeButton
			// 
			this->MakeTimeButton->Location = System::Drawing::Point(394, 87);
			this->MakeTimeButton->Name = L"MakeTimeButton";
			this->MakeTimeButton->Size = System::Drawing::Size(124, 51);
			this->MakeTimeButton->TabIndex = 3;
			this->MakeTimeButton->Text = L"3. Make Timepoints";
			this->MakeTimeButton->UseVisualStyleBackColor = true;
			this->MakeTimeButton->Click += gcnew System::EventHandler(this, &UEMAuto::MakeTimeButton_Click);
			// 
			// timeRemLab
			// 
			this->timeRemLab->AutoSize = true;
			this->timeRemLab->Location = System::Drawing::Point(161, 156);
			this->timeRemLab->Name = L"timeRemLab";
			this->timeRemLab->Size = System::Drawing::Size(38, 13);
			this->timeRemLab->TabIndex = 19;
			this->timeRemLab->Text = L"0 secs";
			// 
			// TimePoints
			// 
			this->TimePoints->AllowUserToAddRows = false;
			this->TimePoints->AllowUserToDeleteRows = false;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->TimePoints->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->TimePoints->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->TimePoints->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->TimepointList });
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->TimePoints->DefaultCellStyle = dataGridViewCellStyle4;
			this->TimePoints->Location = System::Drawing::Point(18, 211);
			this->TimePoints->Name = L"TimePoints";
			this->TimePoints->ReadOnly = true;
			this->TimePoints->Size = System::Drawing::Size(170, 223);
			this->TimePoints->TabIndex = 4;
			// 
			// TimepointList
			// 
			this->TimepointList->HeaderText = L"Timepoints (ps)";
			this->TimepointList->Name = L"TimepointList";
			this->TimepointList->ReadOnly = true;
			this->TimepointList->Width = 125;
			// 
			// tRT
			// 
			this->tRT->AutoSize = true;
			this->tRT->Location = System::Drawing::Point(25, 156);
			this->tRT->Name = L"tRT";
			this->tRT->Size = System::Drawing::Size(140, 13);
			this->tRT->TabIndex = 18;
			this->tRT->Text = L"Estiimated Time Remaining: ";
			// 
			// nsIndicator
			// 
			this->nsIndicator->AutoSize = true;
			this->nsIndicator->Location = System::Drawing::Point(351, 121);
			this->nsIndicator->Name = L"nsIndicator";
			this->nsIndicator->Size = System::Drawing::Size(36, 17);
			this->nsIndicator->TabIndex = 16;
			this->nsIndicator->Text = L"ns";
			this->nsIndicator->UseVisualStyleBackColor = true;
			this->nsIndicator->CheckedChanged += gcnew System::EventHandler(this, &UEMAuto::NsIndicator_CheckedChanged);
			// 
			// runProg
			// 
			this->runProg->Location = System::Drawing::Point(19, 179);
			this->runProg->Name = L"runProg";
			this->runProg->Size = System::Drawing::Size(750, 23);
			this->runProg->TabIndex = 17;
			// 
			// psIndicator
			// 
			this->psIndicator->AutoSize = true;
			this->psIndicator->Checked = true;
			this->psIndicator->Location = System::Drawing::Point(310, 121);
			this->psIndicator->Name = L"psIndicator";
			this->psIndicator->Size = System::Drawing::Size(36, 17);
			this->psIndicator->TabIndex = 15;
			this->psIndicator->TabStop = true;
			this->psIndicator->Text = L"ps";
			this->psIndicator->UseVisualStyleBackColor = true;
			this->psIndicator->CheckedChanged += gcnew System::EventHandler(this, &UEMAuto::PsIndicator_CheckedChanged);
			// 
			// camDelPosPS
			// 
			this->camDelPosPS->AutoSize = true;
			this->camDelPosPS->Location = System::Drawing::Point(569, 47);
			this->camDelPosPS->Name = L"camDelPosPS";
			this->camDelPosPS->Size = System::Drawing::Size(25, 13);
			this->camDelPosPS->TabIndex = 14;
			this->camDelPosPS->Text = L"000";
			// 
			// camDelPosMM
			// 
			this->camDelPosMM->AutoSize = true;
			this->camDelPosMM->Location = System::Drawing::Point(569, 22);
			this->camDelPosMM->Name = L"camDelPosMM";
			this->camDelPosMM->Size = System::Drawing::Size(25, 13);
			this->camDelPosMM->TabIndex = 13;
			this->camDelPosMM->Text = L"000";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(429, 47);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(131, 13);
			this->label12->TabIndex = 12;
			this->label12->Text = L"Delay Stage Position (ps): ";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(429, 22);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(134, 13);
			this->label11->TabIndex = 11;
			this->label11->Text = L"Delay Stage Position (nm): ";
			// 
			// fileNameBase
			// 
			this->fileNameBase->Location = System::Drawing::Point(110, 120);
			this->fileNameBase->Name = L"fileNameBase";
			this->fileNameBase->Size = System::Drawing::Size(189, 20);
			this->fileNameBase->TabIndex = 9;
			this->fileNameBase->Text = L"Test_01";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(25, 123);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(79, 13);
			this->label10->TabIndex = 8;
			this->label10->Text = L"Filename Base:";
			// 
			// browseFilePath
			// 
			this->browseFilePath->Location = System::Drawing::Point(310, 83);
			this->browseFilePath->Name = L"browseFilePath";
			this->browseFilePath->Size = System::Drawing::Size(75, 23);
			this->browseFilePath->TabIndex = 7;
			this->browseFilePath->Text = L"Browse";
			this->browseFilePath->UseVisualStyleBackColor = true;
			this->browseFilePath->Click += gcnew System::EventHandler(this, &UEMAuto::BrowseFilePath_Click);
			// 
			// fileSavePath
			// 
			this->fileSavePath->Location = System::Drawing::Point(78, 85);
			this->fileSavePath->Name = L"fileSavePath";
			this->fileSavePath->Size = System::Drawing::Size(221, 20);
			this->fileSavePath->TabIndex = 6;
			this->fileSavePath->Text = L"C:\\";
			// 
			// camStat
			// 
			this->camStat->Location = System::Drawing::Point(18, 443);
			this->camStat->Multiline = true;
			this->camStat->Name = L"camStat";
			this->camStat->Size = System::Drawing::Size(751, 85);
			this->camStat->TabIndex = 5;
			this->camStat->Text = L"Status Bar:\r\n";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(25, 88);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(47, 13);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Filepath:";
			// 
			// servIP
			// 
			this->servIP->Location = System::Drawing::Point(301, 32);
			this->servIP->Name = L"servIP";
			this->servIP->Size = System::Drawing::Size(100, 20);
			this->servIP->TabIndex = 3;
			this->servIP->Text = L"192.168.0.3";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(167, 35);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(132, 13);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Delay Stage Computer IP: ";
			// 
			// disconCam
			// 
			this->disconCam->Location = System::Drawing::Point(685, 534);
			this->disconCam->Name = L"disconCam";
			this->disconCam->Size = System::Drawing::Size(84, 31);
			this->disconCam->TabIndex = 1;
			this->disconCam->Text = L"Disconnect";
			this->disconCam->UseVisualStyleBackColor = true;
			this->disconCam->Click += gcnew System::EventHandler(this, &UEMAuto::DisconCam_Click);
			// 
			// ServConnButton
			// 
			this->ServConnButton->Location = System::Drawing::Point(18, 16);
			this->ServConnButton->Name = L"ServConnButton";
			this->ServConnButton->Size = System::Drawing::Size(136, 51);
			this->ServConnButton->TabIndex = 0;
			this->ServConnButton->Text = L"2. Connect to Server";
			this->ServConnButton->UseVisualStyleBackColor = true;
			this->ServConnButton->Click += gcnew System::EventHandler(this, &UEMAuto::ServConnButton_Click);
			// 
			// delayTab
			// 
			this->delayTab->Controls->Add(this->disconServ);
			this->delayTab->Controls->Add(this->statusWindow);
			this->delayTab->Controls->Add(this->groupBox1);
			this->delayTab->Controls->Add(this->ServInitButton);
			this->delayTab->Location = System::Drawing::Point(4, 22);
			this->delayTab->Name = L"delayTab";
			this->delayTab->Padding = System::Windows::Forms::Padding(3);
			this->delayTab->Size = System::Drawing::Size(788, 584);
			this->delayTab->TabIndex = 0;
			this->delayTab->Text = L"Delay Stage";
			this->delayTab->UseVisualStyleBackColor = true;
			// 
			// disconServ
			// 
			this->disconServ->Location = System::Drawing::Point(641, 16);
			this->disconServ->Name = L"disconServ";
			this->disconServ->Size = System::Drawing::Size(136, 51);
			this->disconServ->TabIndex = 11;
			this->disconServ->Text = L"Disconnect";
			this->disconServ->UseVisualStyleBackColor = true;
			this->disconServ->Click += gcnew System::EventHandler(this, &UEMAuto::DisconServ_Click);
			// 
			// statusWindow
			// 
			this->statusWindow->Location = System::Drawing::Point(18, 406);
			this->statusWindow->Multiline = true;
			this->statusWindow->Name = L"statusWindow";
			this->statusWindow->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->statusWindow->Size = System::Drawing::Size(759, 159);
			this->statusWindow->TabIndex = 6;
			this->statusWindow->Text = L"Status Updates:\r\n";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->delayPosDist);
			this->groupBox1->Controls->Add(this->delayPosTime);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->delaySpd);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->delayMovFor);
			this->groupBox1->Controls->Add(this->delayMovBack);
			this->groupBox1->Location = System::Drawing::Point(264, 99);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(261, 217);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Manual Delay Stage Control";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(118, 27);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(73, 13);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Disconnected";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(15, 27);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(97, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Connection Status:";
			// 
			// delayPosDist
			// 
			this->delayPosDist->AutoSize = true;
			this->delayPosDist->Location = System::Drawing::Point(97, 189);
			this->delayPosDist->Name = L"delayPosDist";
			this->delayPosDist->Size = System::Drawing::Size(25, 13);
			this->delayPosDist->TabIndex = 9;
			this->delayPosDist->Text = L"000";
			// 
			// delayPosTime
			// 
			this->delayPosTime->AutoSize = true;
			this->delayPosTime->Location = System::Drawing::Point(97, 163);
			this->delayPosTime->Name = L"delayPosTime";
			this->delayPosTime->Size = System::Drawing::Size(25, 13);
			this->delayPosTime->TabIndex = 8;
			this->delayPosTime->Text = L"000";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 137);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Speed:";
			// 
			// delaySpd
			// 
			this->delaySpd->Location = System::Drawing::Point(66, 133);
			this->delaySpd->Name = L"delaySpd";
			this->delaySpd->Size = System::Drawing::Size(36, 20);
			this->delaySpd->TabIndex = 6;
			this->delaySpd->Text = L"50";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 189);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Position (mm):";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 163);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Position (ps):";
			// 
			// delayMovFor
			// 
			this->delayMovFor->Location = System::Drawing::Point(135, 51);
			this->delayMovFor->Name = L"delayMovFor";
			this->delayMovFor->Size = System::Drawing::Size(108, 73);
			this->delayMovFor->TabIndex = 1;
			this->delayMovFor->Text = L">";
			this->delayMovFor->UseVisualStyleBackColor = true;
			this->delayMovFor->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UEMAuto::DelayMovFor_Click);
			this->delayMovFor->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UEMAuto::DelayMovFor_Unclick);
			// 
			// delayMovBack
			// 
			this->delayMovBack->Location = System::Drawing::Point(21, 51);
			this->delayMovBack->Name = L"delayMovBack";
			this->delayMovBack->Size = System::Drawing::Size(108, 73);
			this->delayMovBack->TabIndex = 0;
			this->delayMovBack->Text = L"<";
			this->delayMovBack->UseVisualStyleBackColor = true;
			this->delayMovBack->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UEMAuto::DelayMovBack_Click);
			this->delayMovBack->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UEMAuto::DelayMovBack_Unclick);
			// 
			// ServInitButton
			// 
			this->ServInitButton->Location = System::Drawing::Point(18, 16);
			this->ServInitButton->Name = L"ServInitButton";
			this->ServInitButton->Size = System::Drawing::Size(136, 51);
			this->ServInitButton->TabIndex = 0;
			this->ServInitButton->Text = L"1. Initialize Server";
			this->ServInitButton->UseVisualStyleBackColor = true;
			this->ServInitButton->Click += gcnew System::EventHandler(this, &UEMAuto::ServInitButton_Click);
			// 
			// trackTime
			// 
			this->trackTime->WorkerSupportsCancellation = true;
			this->trackTime->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &UEMAuto::timeTracker_DoWork);
			// 
			// curTime
			// 
			this->curTime->AutoSize = true;
			this->curTime->Location = System::Drawing::Point(17, 667);
			this->curTime->Name = L"curTime";
			this->curTime->Size = System::Drawing::Size(49, 13);
			this->curTime->TabIndex = 2;
			this->curTime->Text = L"00:00:00";
			// 
			// delayComm
			// 
			this->delayComm->WorkerSupportsCancellation = true;
			this->delayComm->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &UEMAuto::DelayComm_DoWork);
			// 
			// scanRunner
			// 
			this->scanRunner->WorkerSupportsCancellation = true;
			this->scanRunner->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &UEMAuto::ScanRunner_DoWork);
			// 
			// cameraRunner
			// 
			this->cameraRunner->WorkerSupportsCancellation = true;
			this->cameraRunner->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &UEMAuto::CameraRunner_DoWork);
			// 
			// delayValueUpdater
			// 
			this->delayValueUpdater->WorkerSupportsCancellation = true;
			this->delayValueUpdater->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &UEMAuto::DelayValueUpdater_DoWork);
			// 
			// UEMAuto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(823, 689);
			this->Controls->Add(this->curTime);
			this->Controls->Add(this->cameraTab);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"UEMAuto";
			this->Text = L"UEMtamaton";
			this->cameraTab->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataReadouts))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimePoints))->EndInit();
			this->delayTab->ResumeLayout(false);
			this->delayTab->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		/* ServInitButton_Click
			Function that will initialize the server. Intended for delay-stage side.

			Uses port 6666 for the delay value communication to the camera computer
			Uses port 6667 for the camera run-status communication to the camera computer 
		*/
		private: System::Void ServInitButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{

			// Update the user on beginning initialization
			String^ upStat = gcnew String("Initializing server...\n");
			this->statusWindow->AppendText(upStat);

			// standard server startup code --> search Berkeley sockets or c++ sockets for more information
			WSAStartup(MAKEWORD(2, 0), &WSAData);
			dc_server = socket(AF_INET, SOCK_STREAM, 0);
			cc_server = socket(AF_INET, SOCK_STREAM, 0);

			dc_serverAddr.sin_addr.s_addr = INADDR_ANY;
			dc_serverAddr.sin_family = AF_INET;
			dc_serverAddr.sin_port = htons(6666);

			cc_serverAddr.sin_addr.s_addr = INADDR_ANY;
			cc_serverAddr.sin_family = AF_INET;
			cc_serverAddr.sin_port = htons(6667);

			bind(dc_server, (SOCKADDR*)& dc_serverAddr, sizeof(dc_serverAddr));
			listen(dc_server, 0);

			bind(cc_server, (SOCKADDR*)& cc_serverAddr, sizeof(cc_serverAddr));
			listen(cc_server, 0);

			// Update the user on listening for the connection to the delay value client and run client
			upStat = gcnew String("Listening for incoming connections on ports 6666 and 6667...\n");
			this->statusWindow->AppendText(upStat);

			dc_clientAddrSize = sizeof(dc_clientAddr);
			cc_clientAddrSize = sizeof(cc_clientAddr);

			// Connect to the delay value client
			if ((delaycomm_client = accept(dc_server, (SOCKADDR*)& dc_clientAddr, &dc_clientAddrSize)) != INVALID_SOCKET)
			{
				upStat = gcnew String("Delay data transferring.\n");
				this->statusWindow->AppendText(upStat);
			}

			// Connect to the camera run status client
			if ((camcomm_client = accept(cc_server, (SOCKADDR*)& cc_clientAddr, &cc_clientAddrSize)) != INVALID_SOCKET)
			{
				upStat = gcnew String("Camera data communicating.\n");
				this->statusWindow->AppendText(upStat);
			}

			this->trackTime->RunWorkerAsync();

			if (!SoloistConnect(&handles, &handleCount))
			{
				this->statusWindow->AppendText("No controllers found.\n");
				cleanupSoloist();
				return;
			}

			if (handleCount != 1)
			{
				this->statusWindow->AppendText("Too many controllers.\n");
				cleanupSoloist();
				return;
			}
			handle = handles[0];

			if (!SoloistMotionEnable(handle))
			{
				cleanupSoloist();
				return;
			}

			this->scanRunner->RunWorkerAsync(); // run the scan-thread
			this->delayValueUpdater->RunWorkerAsync();
	
		}

		/* RunScan_Click
			Begins a scan containing the experimental time point array. Sends a signal to the camera computer that a scan has begun as well.
		*/
		private: System::Void RunScan_Click(System::Object^ sender, System::EventArgs^ e) 
		{

			runStat = 1; // set state of run to running

			this->pauseButton->ForeColor.Black; // set the pause button to black
			this->pauseButton->Refresh();
			this->playRun->ForeColor.AliceBlue; // set the play button to blue
			this->playRun->Refresh();
			this->cameraRunner->RunWorkerAsync();

		}
		 
		/* MakeTimeButton_Click
			Opens the MakeTimepoints.exe program and loads the results into the main program. Uses that data to make the timepoint table, timepoint array, and experimental array.
		*/
		private: System::Void MakeTimeButton_Click(System::Object^ sender, System::EventArgs^ e)
		{

			// Update the user on making timepoints sub-program.
			String^ upStat = gcnew String("Started MakeTimepoints.exe.\n");
			this->statusWindow->AppendText(upStat);

			// Spawns the .exe
			spawnl(P_WAIT, "MakeTimepoints.exe", "MakeTimepoints.exe", NULL);

			// Grabs the time points from the program.
			upStat = gcnew String("Grabbing timepoints.\n");
			this->statusWindow->AppendText(upStat);

			std::ifstream OpenFile;
			double startIn, endIn, sepIn;
			int pointIn;

			int curRow = 0;
			int lastQu, throwaway1, throwaway2;
			int numLines = 0;
			totPoints = 0;
			std::string line;

			OpenFile.open("TimeInputs.txt");

			do
			{

				getline(OpenFile, line);
				numLines++;

			} while (!OpenFile.eof());

			const int numRows = numLines-2;

			timeTable = new double[4*numRows];

			OpenFile.clear();
			OpenFile.seekg(0, std::ios::beg);

			// Begin assembling the timetable

			getline(OpenFile, line);

			std::istringstream ss(line);

			ss >> lastQu >> throwaway1 >> throwaway2;
			includeLast = lastQu;

			while (getline(OpenFile, line))
			{
				std::istringstream ss(line);

				ss >> startIn >> endIn >> sepIn;

				pointIn = (int)floor(abs(endIn-startIn)/sepIn);

				timeTable[curRow*4] = startIn;
				timeTable[curRow*4+1] = endIn;
				timeTable[curRow*4+2] = sepIn;
				timeTable[curRow*4+3] = pointIn;

				totPoints = totPoints + pointIn;

				curRow++;
			}

			OpenFile.close();

			if (includeLast == 1)
			{
				totPoints++;
			}

			const int tpV = totPoints;

			// Begin assembling the time point array

			timeptArr = new double[tpV];
			int curLinePt = 0;

			for (int a = 0; a < numRows; a++)
			{
				for (int b = 0; b < timeTable[a*4+3]; b++)
				{
					timeptArr[curLinePt + b] = timeTable[a*4] + timeTable[a*4+2] * b;
				}
				curLinePt = curLinePt + timeTable[a*4+3];
			}

			if (includeLast == 1)
			{
				timeptArr[tpV - 1] = timeTable[(numRows - 1)*4 + 1];
			}

			// Begin assembling the experimental array
			expArr = new double[tpV];

			for (int a = 0; a < tpV; a++)
			{
				expArr[a] = timeptArr[a];
			}

			this->TimePoints->Rows->Clear();
			this->TimePoints->Refresh();

			if (randomized == 1)
			{
				std::random_shuffle(&expArr[0], &expArr[tpV]);

				for (int a = 0; a < tpV; a++)
				{
					String^ timeAdd = gcnew String(std::to_string(expArr[a]).c_str());
				
					this->TimePoints->Rows->Add(timeAdd);
				}
			}
			else
			{
				for (int a = 0; a < tpV; a++)
				{
					String^ timeAdd = gcnew String(std::to_string(expArr[a]).c_str());

					this->TimePoints->Rows->Add(timeAdd);
				}
			}

		}

		/* RandomPoints_CheckedChanged
			Checks if the timepoints should be randomized or not. Adjusts the time array accordingly.
		*/
		private: System::Void RandomPoints_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
		{

			const int tpV = totPoints;
			expArr = new double[tpV];

			this->TimePoints->Rows->Clear();
			this->TimePoints->Refresh();

			for (int a = 0; a < tpV; a++)
			{
				expArr[a] = timeptArr[a];
			}

			if (this->randomPoints->Checked)
			{
				randomized = 1;

				std::random_shuffle(&expArr[0], &expArr[tpV]);

				for (int a = 0; a < tpV; a++)
				{
					String^ timeAdd = gcnew String(std::to_string(expArr[a]).c_str());

					this->TimePoints->Rows->Add(timeAdd);
				}

				String^ upStat = gcnew String("Randomized timepoints.\n");
				this->statusWindow->AppendText(upStat);

			}
			else
			{
				randomized = 0;

				for (int a = 0; a < tpV; a++)
				{
					String^ timeAdd = gcnew String(std::to_string(expArr[a]).c_str());

					this->TimePoints->Rows->Add(timeAdd);
				}

				String^ upStat = gcnew String("Unandomized timepoints.\n");
				this->statusWindow->AppendText(upStat);
			}

		}

		/* DisconServ_Click
			Close all sockets and execute WSACleanup. Cancel the delay-value communication thread.
		*/
		private: System::Void DisconServ_Click(System::Object^ sender, System::EventArgs^ e)
		{
	
			closesocket(delaycomm_client);
			closesocket(camcomm_client);

			WSACleanup();

			if (!SoloistDisconnect(handles))
			{
				printSoloistError();
			}

			String^ upStat = gcnew String("Server shutdown.\n");
			this->statusWindow->AppendText(upStat);

			this->trackTime->CancelAsync();
	
		}

		/* timeTracker_DoWork and associated delegate functions. Intended for delay-stage computer.
			Named as such because it tracks the amount of time delay data has been passing between the two computers, but also passes the delay values.

			UpdateTime-TimeUpdater delegate pair: Used to update the time in the bottom left corner.
			delStopComm-stopDelComm delegate pair: Used to cancel timeTracker_DoWork in the event of a disconnect from the delay stage.
		*/
		delegate System::Void UpdateTime(String^ TimeUp);
		System::Void TimeUpdater(String^ TimeUp) 
		{
			this->curTime->Text = TimeUp;
			this->curTime->Update();
		}
		delegate System::Void delStopComm();
		System::Void stopDelComm()
		{
			this->delayComm->CancelAsync();
		}
		delegate System::Void delPosDisUp(double curPos);
		private: System::Void timeTracker_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e)
		{

			System::Threading::Thread::Sleep(1000);

			// ADD DELAY VALUE PASSING
			DateTime initTime = DateTime::Now;
			DateTime curTime;
			TimeSpan connectTime;
			int cumulTime;
			std::string conTime;
			int a;
			std::string curdelPosStr;
			std::string curdelTimStr;

			while (true)
			{

				System::Threading::Thread::Sleep(100);

				curTime = DateTime::Now;
				connectTime = curTime - initTime;
				my_time = time(NULL);
				cumulTime = (int)round((double)connectTime.TotalSeconds);

				conTime = std::to_string(cumulTime);

				dc_buffer[0] = '0';

				for (a = 1; a < conTime.length() + 1; a++)
				{
					dc_buffer[a] = (char)conTime[a - 1];

					if (a == conTime.length() + 1)
					{
						dc_buffer[a + 1] = '|';
						dc_buffer[a + 2] = '\0';
					}
				}

				send(delaycomm_client, dc_buffer, sizeof(dc_buffer), 0);

				memset(dc_buffer, 0, sizeof(dc_buffer));

				this->BeginInvoke(gcnew UpdateTime(this, &UEMAuto::TimeUpdater), gcnew String(ctime(&my_time)));

				curdelPosStr = msclr::interop::marshal_as<std::string>(this->delayPosDist->Text);
				curdelTimStr = msclr::interop::marshal_as<std::string>(this->delayPosTime->Text);

				dc_buffer[0] = '1';

				for (a = 1; a < curdelPosStr.length() + 1; a++)
				{
					dc_buffer[a] = curdelPosStr[a - 1];
				}
				dc_buffer[curdelPosStr.length() + 1] = '|';
				for (a = curdelPosStr.length() + 2; a < curdelPosStr.length() + curdelTimStr.length() + 2; a++)
				{
					dc_buffer[a] = curdelTimStr[a - curdelPosStr.length() - 2];
				}
				dc_buffer[curdelPosStr.length() + curdelTimStr.length() + 2] = '|';
				dc_buffer[curdelPosStr.length() + curdelTimStr.length() + 3] = '\0';

				send(delaycomm_client, dc_buffer, sizeof(dc_buffer), 0);

				memset(dc_buffer, 0, sizeof(dc_buffer));

			}

			this->BeginInvoke(gcnew delStopComm(this, &UEMAuto::stopDelComm));

		}

		/* DelayComm_DoWork and associated delegate functions. Intended for camera computer
			Will receive the amount of time connected as well as the delay stage readouts.

			Borrows timeTracker_DoWork's delegate UpdateTime-TimeUpdater.
		*/
		delegate System::Void camPosDisUp(String^ curPos);
		System::Void camDisPosUp(String^ curPos)
		{
			this->camDelPosMM->Text = curPos;
		}
		delegate System::Void camPosTimUp(String^ curTim);
		System::Void camDisTimUp(String^ curTim)
		{
			this->camDelPosPS->Text = curTim;
		}
		private: System::Void DelayComm_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) 
		{

			char curChar;
			int sizeData;
			int tracker = 0;
			char* data;
			int sizeDelayPos;
			int sizeDelayTime;
			char* posdata;
			char* timdata;
			int a;

			do
			{
				recv(dc_server, dc_buffer, sizeof(dc_buffer), 0);

				if (dc_buffer[0] == '0')
				{
					curChar = dc_buffer[1];
					sizeData = 0;
					tracker = 1;

					while (curChar != '|')
					{
						sizeData++;
						tracker++;
						curChar = dc_buffer[tracker];
					}

					data = new char[sizeData + 1];

					for (a = 1; a < sizeData + 1; a++)
					{
						data[a - 1] = dc_buffer[a];
					}

					data[sizeData] = '\0';

					this->BeginInvoke(gcnew UpdateTime(this, &UEMAuto::TimeUpdater), gcnew String(data));
				}
				else if (dc_buffer[0] == '1')
				{
					curChar = dc_buffer[1];
					sizeDelayPos = 0;
					sizeDelayTime = 0;
					tracker = 1;

					while (curChar != '|')
					{
						sizeDelayPos++;
						tracker++;
						curChar = dc_buffer[tracker];
					}

					tracker++;
					curChar = dc_buffer[tracker];

					while (curChar != '|')
					{
						sizeDelayTime++;
						tracker++;
						curChar = dc_buffer[tracker];
					}

					posdata = new char[sizeDelayPos + 1];
					timdata = new char[sizeDelayTime + 1];

					for (a = 1; a < sizeDelayPos + 1; a++)
					{
						posdata[a - 1] = dc_buffer[a];
					}

					for (a = sizeDelayPos + 2; a < sizeDelayPos + sizeDelayTime + 2; a++)
					{
						timdata[a - sizeDelayPos - 2] = dc_buffer[a];
					}

					posdata[sizeDelayPos] = '\0';
					timdata[sizeDelayTime] = '\0';

					this->BeginInvoke(gcnew camPosDisUp(this, &UEMAuto::camDisPosUp), gcnew String(posdata));
					this->BeginInvoke(gcnew camPosTimUp(this, &UEMAuto::camDisTimUp), gcnew String(timdata));
				}

				memset(dc_buffer, 0, sizeof(dc_buffer));

			} while (true);

		}

		/* ServConnButton_Click
			Connects the camera computer to the delay stage server and initiates two background threads
		*/
		private: System::Void ServConnButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{

			WSAStartup(MAKEWORD(2, 0), &WSAData);
			dc_server = socket(AF_INET, SOCK_STREAM, 0);
			cc_server = socket(AF_INET, SOCK_STREAM, 0);

			inet_pton(AF_INET, msclr::interop::marshal_as<std::string>(this->servIP->Text).c_str(), &dc_addr.sin_addr.s_addr);
			dc_addr.sin_family = AF_INET;
			dc_addr.sin_port = htons(6666);

			inet_pton(AF_INET, msclr::interop::marshal_as<std::string>(this->servIP->Text).c_str(), &cc_addr.sin_addr.s_addr);
			cc_addr.sin_family = AF_INET;
			cc_addr.sin_port = htons(6667);

			servAddrSize = sizeof(dc_addr);
			connect(dc_server, (SOCKADDR*)& dc_addr, sizeof(dc_addr));

			servAddrSize = sizeof(cc_addr);
			connect(cc_server, (SOCKADDR*)& cc_addr, sizeof(cc_addr));

			String^ upStat = gcnew String("Connected to server!\n");
			this->camStat->AppendText(upStat);

			this->delayComm->RunWorkerAsync();

		}

		/* DisconCam_Click
			Disconnects the camera computer from the delay stage and stops the background threads
		*/
		private: System::Void DisconCam_Click(System::Object^ sender, System::EventArgs^ e) 
		{
	
			closesocket(dc_server);
			closesocket(cc_server);
			WSACleanup();
			String^ upStat = gcnew String("Socket closed.\n");
			this->camStat->AppendText(upStat);
			this->cameraRunner->CancelAsync();
			this->delayComm->CancelAsync();

		}

		/* CameraRunner_DoWork and associated delegate functions. Intended for the camera computer.
			This function is the one that handles all initiated scans.

			AddDelRunGridRow-DelGridRowAdd delegate pair: Updates the run log with the current step
			DelRunGridRowUp-DelGridRowUp delegate pair: Updates the status of the current step
			DelRunGridClear-DelGridRunClear delegate pair: Clears the log
			delStopRun-stopDelRun delegate pair: Stops the main method
			upDelRunProg-upDelProgRun delegate pair: Updates the progress bar for the run
			upEstTime-upTimeEst delegate pair: Updates the estimated time for the scan to run
			SetForegroundWindowInternal: function intended to set DM to the foreground
			PressKey: Presses a key in the computer.
			PressEnter: Presses the enter key in the computer.
		*/
		delegate System::Void AddDelRunGridRow(String^ step, String^ TimePoint, String^ DelPos, String^ status);
		System::Void DelGridRowAdd(String^ step, String^ TimePoint, String^ DelPos, String^ status)
		{
			this->DataReadouts->Rows->Add(step, TimePoint, DelPos, status);
		}
		delegate System::Void DelRunGridRowUp(String^ status);
		System::Void DelGridRowUp(String^ status)
		{
			this->DataReadouts->Rows[this->DataReadouts->RowCount - 1]->Cells[3]->Value = status;
		}
		delegate System::Void DelRunGridClear();
		System::Void DelGridRunClear()
		{
			this->DataReadouts->Rows->Clear();
			this->DataReadouts->Update();
		}
		delegate System::Void delStopRun();
		System::Void stopDelRun()
		{
			this->scanRunner->CancelAsync();
		}
		delegate System::Void upDelRunProg(int stepVal);
		System::Void upDelProgRun(int stepVal)
		{
			this->runProg->Minimum = 0;
			this->runProg->Maximum = totPoints;
			this->runProg->Value = stepVal + 1;
			this->runProg->Update();
		}
		delegate System::Void upEstTime(double timePer, int curStep);
		System::Void upTimeEst(double timePer, int curStep)
		{
			timeLeft = round(timePer * (totPoints - curStep));
			this->timeRemLab->Text = gcnew String(std::to_string((int)timeLeft).c_str()) + " sec";
		}
		void SetForegroundWindowInternal(HWND hWnd)
		{
			if (!::IsWindow(hWnd)) return;

			BYTE keyState[256] = { 0 };
			//to unlock SetForegroundWindow we need to imitate Alt pressing
			if (::GetKeyboardState((LPBYTE)& keyState))
			{
				if (!(keyState[VK_MENU] & 0x80))
				{
					::keybd_event(VK_MENU, 0, KEYEVENTF_EXTENDEDKEY | 0, 0);
				}
			}

			::SetForegroundWindow(hWnd);

			if (::GetKeyboardState((LPBYTE)& keyState))
			{
				if (!(keyState[VK_MENU] & 0x80))
				{
					::keybd_event(VK_MENU, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
				}
			}
		}
		void PressKey(WORD keypress)
		{
			INPUT input;
			WORD vkey = keypress; // see link below
			input.type = INPUT_KEYBOARD;
			input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
			input.ki.time = 0;
			input.ki.dwExtraInfo = 0;
			input.ki.wVk = vkey;
			input.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
			SendInput(1, &input, sizeof(INPUT));

			System::Threading::Thread::Sleep(30);
			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(INPUT));
		}
		void PressEnter()
		{
			INPUT ip;
			ip.type = INPUT_KEYBOARD;
			ip.ki.time = 0;
			ip.ki.dwFlags = KEYEVENTF_UNICODE;
			ip.ki.wScan = VK_RETURN; //VK_RETURN is the code of Return key
			ip.ki.wVk = 0;

			ip.ki.dwExtraInfo = 0;
			SendInput(1, &ip, sizeof(INPUT));

		}
		delegate System::Void UpdateCamStatus(String^ appStat);
		System::Void CamStatUpdater(String^ appStat)
		{
			this->camStat->AppendText(appStat);
		}
		private: System::Void CameraRunner_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) 
		{

			int firstPass = 0;
			int recvSignal = 0;
			int firstPause = 1;
			int curStep = 0;
			int a;

			DateTime timeInit;
			DateTime timeTrack;

			TimeSpan addTime;
			TimeSpan cumulTime;
			double timeSpent;
			double timePer;
			double curTimePoint;
			double curDistPoint;

			String^ upStat;
			String^ stepString;
			String^ timeString;
			String^ posString;
			String^ statString;

			//struct stat buffer;

			FILE* filechecker;
			int fileFound;

			double curDelay = 0;
			WriteULG ulgWriter;
			WriteDMComm dmCommWriter;
			String^ curFileName;
			String^ curFileTot;
			String^ ulgFileName;
			String^ delayText;
			int toCounter = 0;

			std::string timeVal;

			HWND hWnd;
			int timeout = 3600 * 4;

			this->BeginInvoke(gcnew DelRunGridClear(this, &UEMAuto::DelGridRunClear));

			hWnd = FindWindow(NULL, L"DigitalMicrograph");
			if (hWnd) {
				// move to foreground
				this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
				this->WindowState = System::Windows::Forms::FormWindowState::Normal; // this is the dumbest hack I've tried and I'm almost ashamed it works. Almost.
				//SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
				SetForegroundWindowInternal(hWnd);
				//SetActiveWindow(hWnd);

				this->PressKey(VK_F10);
				this->PressKey(VK_RIGHT);
				this->PressKey(VK_RIGHT);
				this->PressKey(VK_RIGHT);
				this->PressKey(VK_RIGHT);
				this->PressKey(VK_RIGHT);
				this->PressKey(VK_RIGHT);
				this->PressKey(VK_RIGHT);
				this->PressKey(VK_RIGHT);
				this->PressKey(VK_DOWN);
				this->PressKey(VK_DOWN);
				this->PressKey(VK_RETURN);

				System::Threading::Thread::Sleep(30);

				this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
				this->WindowState = System::Windows::Forms::FormWindowState::Normal; // facepalm

			}
			else
			{
				upStat = gcnew String("DM was not found.\n");
				this->BeginInvoke(gcnew UpdateCamStatus(this, &UEMAuto::CamStatUpdater), upStat);
			}

			do
			{

				if (WSAGetLastError() == 10054)
				{
					upStat = gcnew String("Network error.\n");

					this->BeginInvoke(gcnew UpdateCamStatus(this, &UEMAuto::CamStatUpdater), upStat);

					runStat = 3;
				}

				butPressMeantime = 0;

				if (runStat == 1)
				{

					timeInit = DateTime::Now;

					if (firstPause == 0)
					{
						firstPause = 1;

						upStat = "Resumed on step " + gcnew String(std::to_string(curStep + 1).c_str()) + ".\n";
						this->BeginInvoke(gcnew UpdateCamStatus(this, &UEMAuto::CamStatUpdater), upStat);
					}

					if (totPoints <= 0 || totPoints.Equals(NULL))
						runStat = 3;
					else
					{

						curTimePoint = expArr[curStep];
						curDistPoint = curTimePoint / mm_to_fs + curZero;

						stepString = gcnew String(std::to_string(curStep + 1).c_str());
						timeString = gcnew String(std::to_string(curTimePoint).c_str());
						posString = gcnew String(std::to_string(curDistPoint).c_str());
						statString = "Moving delay stage...";

						this->BeginInvoke(gcnew AddDelRunGridRow(this, &UEMAuto::DelGridRowAdd), stepString, timeString, posString, statString);

						timeVal = std::to_string(expArr[curStep]);

						cc_buffer[0] = '1';

						for (a = 1; a <= timeVal.length(); a++)
						{
							cc_buffer[a] = timeVal[a - 1];
						}

						cc_buffer[timeVal.length() + 1] = '|';
						cc_buffer[timeVal.length() + 2] = '\0';

						send(cc_server, cc_buffer, sizeof(cc_buffer), 0);

						memset(cc_buffer, 0, sizeof(cc_buffer));

						recv(cc_server, cc_buffer, sizeof(cc_buffer), 0);

						memset(cc_buffer, 0, sizeof(cc_buffer));

						statString = "Acquiring...";
						this->BeginInvoke(gcnew DelRunGridRowUp(this, &UEMAuto::DelGridRowUp), statString);

						recvSignal = 0;

						if (butPressMeantime == 0)
						{
							runStat = 4;
						}
					}

					timeTrack = DateTime::Now;

					addTime = timeTrack - timeInit;
					cumulTime = cumulTime.Add(addTime);

				}
				else if (runStat == 2)
				{
					// Pause signal, to wait for resume button. Allows current step to complete. Blocking only occurs once here.
					if (recvSignal == 0)
					{

						timeInit = DateTime::Now;

						// ADJUST FOR DECIMAL DELAYS, WITH LIMITER TO A SINGLE DECIMAL PLACE
						curDelay = curTimePoint;
						if (fmod(curDelay, 1) != 0)
						{
							curDelay = round(curDelay * 10);
							delayText = gcnew String(std::to_string((int)curDelay).c_str()) + "x10";
						}
						else
						{
							delayText = gcnew String(std::to_string((int)curDelay).c_str());
						}

						curFileName = this->fileNameBase->Text + "_0_" + gcnew String(std::to_string(curStep + 1).c_str()) + "_" + delayText + gcnew String(units) + ".dm4";
						curFileTot = this->fileSavePath->Text + "\\" + curFileName;
						ulgFileName = this->fileNameBase->Text + ".ulg";

						upStat = "Updating DM communication for step " + gcnew String(std::to_string(curStep + 1).c_str());
						this->BeginInvoke(gcnew UpdateCamStatus(this, &UEMAuto::CamStatUpdater), upStat);
						// UPDATE CAMERA COMMUNICATION DOCUMENT
						dmCommWriter.WriteData("X:\\TestFile\\InputFileTest.txt", msclr::interop::marshal_as<std::string>(this->fileSavePath->Text), msclr::interop::marshal_as<std::string>(this->fileNameBase->Text), std::string(units), std::to_string(curStep + 1), msclr::interop::marshal_as<std::string>(delayText));

						upStat = "Updating ULG file for step " + gcnew String(std::to_string(curStep + 1).c_str());
						this->BeginInvoke(gcnew UpdateCamStatus(this, &UEMAuto::CamStatUpdater), upStat);

						// UPDATE ULG
						ulgWriter.WriteData(msclr::interop::marshal_as<std::string>(ulgFileName), msclr::interop::marshal_as<std::string>(this->fileSavePath->Text), msclr::interop::marshal_as<std::string>(this->fileNameBase->Text), std::to_string(totPoints), std::to_string(curStep + 1), std::to_string(curDelay), msclr::interop::marshal_as<std::string>(curFileName), curStep + 1);

						upStat = "Waiting to see image name " + curFileTot + " for step " + gcnew String(std::to_string(curStep + 1).c_str());
						this->BeginInvoke(gcnew UpdateCamStatus(this, &UEMAuto::CamStatUpdater), upStat);

						fileFound = 0;
						// WAITING FOR FILE TO APPEAR. WILL TIME OUT AFTER AN HOUR OF WAITING
						while (fileFound == 0 && toCounter < timeout) // as of August 14th, 2019 this is still experimental
						{
							if (filechecker = fopen(msclr::interop::marshal_as<std::string>(curFileTot).c_str(), "r"))
							{
								fclose(filechecker);
								fileFound = 1;
							}

							toCounter++;
							System::Threading::Thread::Sleep(250);
						}

						if (toCounter < timeout)
							this->BeginInvoke(gcnew DelRunGridRowUp(this, &UEMAuto::DelGridRowUp), "Acquired.");
						else
							this->BeginInvoke(gcnew DelRunGridRowUp(this, &UEMAuto::DelGridRowUp), "Timed out.");

						toCounter = 0;

						recvSignal = 1;

						this->BeginInvoke(gcnew upDelRunProg(this, &UEMAuto::upDelProgRun), curStep);

						curStep++;

						timeTrack = DateTime::Now;

						addTime = timeTrack - timeInit;
						cumulTime = cumulTime.Add(addTime);

						timeSpent = cumulTime.TotalSeconds;
						timePer = timeSpent / (curStep + 1);

						this->BeginInvoke(gcnew upEstTime(this, &UEMAuto::upTimeEst), timePer, curStep);
					}
					else
					{
						if (firstPause == 1)
						{
							upStat = "Paused on step " + gcnew String(std::to_string(curStep + 1).c_str()) + ".\n";
							this->BeginInvoke(gcnew UpdateCamStatus(this, &UEMAuto::CamStatUpdater), upStat);
							firstPause = 0;
						}
					}

				}
				else if (runStat == 3)
				{
					// Stop signal, stops and clears everything.

					upStat = "Stopped on step " + gcnew String(std::to_string(curStep + 1).c_str()) + ".\n";

					curStep = totPoints;

					this->BeginInvoke(gcnew UpdateCamStatus(this, &UEMAuto::CamStatUpdater), upStat);
				}
				else if (runStat == 4)
				{

					timeInit = DateTime::Now;
					System::Threading::Thread::Sleep(50);
					// write all the camera communication files and wait for acquisition before moving on
					
					// ADJUST FOR DECIMAL DELAYS, WITH LIMITER TO A SINGLE DECIMAL PLACE
					curDelay = curTimePoint;
					if (fmod(curDelay, 1) != 0)
					{
						curDelay = round(curDelay * 10);
						delayText = gcnew String(std::to_string((int)curDelay).c_str()) + "x10";
					}
					else
					{
						delayText = gcnew String(std::to_string((int)curDelay).c_str());
					}

					curFileName = this->fileNameBase->Text + "_0_" + gcnew String(std::to_string(curStep + 1).c_str()) + "_" + delayText + gcnew String(units) + ".dm4";
					curFileTot = this->fileSavePath->Text + "\\" + curFileName;
					ulgFileName = this->fileSavePath->Text + "\\" + this->fileNameBase->Text + ".ulg";
					
					upStat = "Updating DM communication for step " + gcnew String(std::to_string(curStep + 1).c_str()) + ".\n";
					this->BeginInvoke(gcnew UpdateCamStatus(this, &UEMAuto::CamStatUpdater), upStat);
					// UPDATE CAMERA COMMUNICATION DOCUMENT 
					dmCommWriter.WriteData("X:\\TestFile\\InputFileTest.txt", msclr::interop::marshal_as<std::string>(this->fileSavePath->Text), msclr::interop::marshal_as<std::string>(this->fileNameBase->Text), std::string(units), std::to_string(curStep+1), msclr::interop::marshal_as<std::string>(delayText));

					upStat = "Updating ULG file for step " + gcnew String(std::to_string(curStep + 1).c_str()) + ".\n";
					this->BeginInvoke(gcnew UpdateCamStatus(this, &UEMAuto::CamStatUpdater), upStat);

					// UPDATE ULG
					ulgWriter.WriteData(msclr::interop::marshal_as<std::string>(ulgFileName), msclr::interop::marshal_as<std::string>(this->fileSavePath->Text), msclr::interop::marshal_as<std::string>(this->fileNameBase->Text), std::to_string(totPoints), std::to_string(curStep+1), std::to_string(curDelay), msclr::interop::marshal_as<std::string>(curFileName), curStep+1);

					upStat = "Waiting to see image name " + curFileTot + " for step " + gcnew String(std::to_string(curStep + 1).c_str());
					this->BeginInvoke(gcnew UpdateCamStatus(this, &UEMAuto::CamStatUpdater), upStat);

					fileFound = 0;
					// WAITING FOR FILE TO APPEAR. WILL TIME OUT AFTER AN HOUR OF WAITING
					while (fileFound == 0 && toCounter < timeout) // as of August 14th, 2019 this is still experimental
					{
						if (filechecker = fopen(msclr::interop::marshal_as<std::string>(curFileTot).c_str(), "r"))
						{
							fclose(filechecker);
							fileFound = 1;
						}

						toCounter++;
						System::Threading::Thread::Sleep(250);
					}

					if (toCounter < timeout)
						this->BeginInvoke(gcnew DelRunGridRowUp(this, &UEMAuto::DelGridRowUp), "Acquired.");
					else
						this->BeginInvoke(gcnew DelRunGridRowUp(this, &UEMAuto::DelGridRowUp), "Timed out.");

					toCounter = 0;

					recvSignal = 1;

					if (butPressMeantime == 0)
					{
						runStat = 1;
					}

					this->BeginInvoke(gcnew upDelRunProg(this, &UEMAuto::upDelProgRun), curStep);

					curStep++;

					timeTrack = DateTime::Now;

					addTime = timeTrack - timeInit;
					cumulTime = cumulTime.Add(addTime);

					timeSpent = cumulTime.TotalSeconds;
					timePer = timeSpent / (curStep + 1);

					this->BeginInvoke(gcnew upEstTime(this, &UEMAuto::upTimeEst), timePer, curStep);
				}

				memset(cc_buffer, 0, sizeof(cc_buffer));

			} while (curStep < totPoints);

			cc_buffer[0] = '0';
			cc_buffer[1] = '\0';

			send(cc_server, cc_buffer, sizeof(cc_buffer), 0);
			memset(cc_buffer, 0, sizeof(cc_buffer));

			this->BeginInvoke(gcnew delStopRun(this, &UEMAuto::stopDelRun));

		}

		/* ScanRunner_DoWork and associated delegate functions
			Handles all the work for organizing the individual steps in a run.

			UpdateDelStatus-DelStatUpdater delegate pair: Updates the status in the bar below
		*/
		delegate System::Void UpdateDelStatus(String^ appStat);
		System::Void DelStatUpdater(String^ appStat)
		{
			this->statusWindow->AppendText(appStat);
		}
		private: System::Void ScanRunner_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) 
		{

			int rundel = 0;

			char curChar;
			int sizeDelayData;
			int tracker = 0;
			char* delaydata;
			int a;
			double curDistPoint;

			while (true)
			{

				tracker = 0;

				this->BeginInvoke(gcnew UpdateDelStatus(this, &UEMAuto::DelStatUpdater), gcnew String("Awaiting incoming data.\n"));
				recv(camcomm_client, cc_buffer, sizeof(cc_buffer), 0);

				if (cc_buffer[0] == '1')
				{
					rundel = 1;
				}
				else
				{
					rundel = 0;
				}

				if (rundel == 1)
				{
					curChar = cc_buffer[1];
					sizeDelayData = 0;

					while (curChar != '|')
					{
						sizeDelayData++;
						tracker++;
						curChar = cc_buffer[tracker];
					}

					delaydata = new char[sizeDelayData + 1];

					for (a = 1; a <= sizeDelayData + 1; a++)
					{
						delaydata[a - 1] = cc_buffer[a];
					}

					delaydata[sizeDelayData] = '\0';

					memset(cc_buffer, 0, sizeof(cc_buffer));

					curDistPoint = std::stod(delaydata) / mm_to_fs + curZero;

					this->BeginInvoke(gcnew UpdateDelStatus(this, &UEMAuto::DelStatUpdater), gcnew String("Data received and moving delay stage to position "  ".\n"));
					this->BeginInvoke(gcnew UpdateDelStatus(this, &UEMAuto::DelStatUpdater), gcnew String(delaydata));
					this->BeginInvoke(gcnew UpdateDelStatus(this, &UEMAuto::DelStatUpdater), gcnew String(".\n"));

					if (!SoloistMotionMoveAbs(handle, curDistPoint, std::stod(msclr::interop::marshal_as<std::string>(this->delaySpd->Text))))
					{
						cleanupSoloist();
					}
					else
					{
						if (!SoloistMotionWaitForMotionDone(handle, WAITOPTION_MoveDone, -1, NULL))
						{
							cleanupSoloist();
						}
					}

					System::Threading::Thread::Sleep(50);

					cc_buffer[0] = '1\0';

					send(camcomm_client, cc_buffer, sizeof(cc_buffer), 0);

					memset(cc_buffer, 0, sizeof(cc_buffer));
				}

				System::Threading::Thread::Sleep(1000);

			}

		}

		/* PauseButton_Click
			Sets the pause state if another button has not already been pressed.
		*/
		private: System::Void PauseButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
	
			if (butPressMeantime != 1)
			{
				runStat = 2;
				butPressMeantime = 1;
				this->pauseButton->ForeColor.Red;
				this->pauseButton->Refresh();
				this->playRun->ForeColor.Black;
				this->playRun->Refresh();
			}

		}

		/* PlayRun_Click
			Resumes the scan if another button has not already been pressed.
		*/
		private: System::Void PlayRun_Click(System::Object^ sender, System::EventArgs^ e) 
		{

			if (butPressMeantime != 1)
			{
				runStat = 1;
				butPressMeantime = 1;
				this->pauseButton->ForeColor.Black;
				this->pauseButton->Refresh();
				this->playRun->ForeColor.AliceBlue;
				this->playRun->Refresh();
			}

		}

		/* StopButton_Click
			Stops the scan.
		*/
		private: System::Void StopButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{

			runStat = 3;
			butPressMeantime = 1;

		}

		/* PsIndicator_CheckedChanged
			Adjusts the unit used for our delay values to ps
		*/
		private: System::Void PsIndicator_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
		{

			if (this->psIndicator->Checked == TRUE)
			{
				this->nsIndicator->Checked = FALSE;
				units[1] = 'p';
			}
			else
			{
				this->nsIndicator->Checked = TRUE;
				units[1] = 'n';
			}

		}

		/* NsIndicator_CheckedChanged
			Adjusts the unit used for our delay values to ns
		*/
		private: System::Void NsIndicator_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
		{

			if (this->nsIndicator->Checked == TRUE)
			{
				this->psIndicator->Checked = FALSE;
				units[1] = 'n';
			}
			else
			{
				this->psIndicator->Checked = TRUE;
				units[1] = 'p';
			}

		}

		private: System::Void printSoloistError()
		{
			CHAR data[1024];
			SoloistGetLastErrorString(data, 1024);
			this->statusWindow->AppendText(gcnew String(data) + "\n");
		}

		private: System::Void cleanupSoloist()
		{
			if (handleCount > 0) 
			{
				this->statusWindow->AppendText("Soloist error, disconnecting from delay stage.\n");
				if (!SoloistDisconnect(handles)) 
				{ 
					printSoloistError(); 
				}
			}
		}

		/* BrowseFilePath_Click
			Browses for a directory to store DM images in
		*/
		private: System::Void BrowseFilePath_Click(System::Object^ sender, System::EventArgs^ e) 
		{
		
			FolderBrowserDialog^ imgDirectory = gcnew FolderBrowserDialog;

			imgDirectory->Description = "Select your dm4 file location.";
			imgDirectory->ShowNewFolderButton = true;

			imgDirectory->ShowDialog();

			this->fileSavePath->Text = imgDirectory->SelectedPath;
			this->fileSavePath->Refresh();

		}

		private: System::Void DelayMovBack_Click(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{

			if (!SoloistMotionFreeRun(handle, -1 * std::stod(msclr::interop::marshal_as<std::string>(this->delaySpd->Text))))
			{
				SoloistMotionFreeRunStop(handle);
				cleanupSoloist();
			}

		}

		private: System::Void DelayMovBack_Unclick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{

			if (!SoloistMotionFreeRunStop(handle))
			{
				cleanupSoloist();
			}

		}

		private: System::Void DelayMovFor_Click(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{

			if (!SoloistMotionFreeRun(handle, std::stod(msclr::interop::marshal_as<std::string>(this->delaySpd->Text))))
			{
				SoloistMotionFreeRunStop(handle);
				cleanupSoloist();
			}

		}

		private: System::Void DelayMovFor_Unclick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{

			if (!SoloistMotionFreeRunStop(handle))
			{
				cleanupSoloist();
			}

		}

		delegate System::Void delDistUpdater();
		System::Void distDelUpdater()
		{
			this->delayPosDist->Text = gcnew String(std::to_string(positionFeedback).c_str());
		}
		delegate System::Void delTimeUpdater();
		System::Void timeDelUpdater()
		{
			this->delayPosTime->Text = gcnew String(std::to_string(curdelTime).c_str());
		}
		delegate System::Void killDelUpdater();
		System::Void delKillUpdater()
		{
			this->delayValueUpdater->CancelAsync();
		}
		private: System::Void DelayValueUpdater_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) 
		{

			while (true)
			{
				if (!SoloistStatusGetItem(handle, STATUSITEM_PositionFeedback, &positionFeedback))
				{
					this->BeginInvoke(gcnew killDelUpdater(this, &UEMAuto::delKillUpdater));
					cleanupSoloist();
				}
				curdelTime = (((positionFeedback - curZero) / 1000) / spdlght) * 1e12;
				this->BeginInvoke(gcnew delDistUpdater(this, &UEMAuto::distDelUpdater));
				this->BeginInvoke(gcnew delTimeUpdater(this, &UEMAuto::timeDelUpdater));
				System::Threading::Thread::Sleep(100);
			}

		}
};

}
