#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "WriteTimepoints.h"

int includeLast = 0;

namespace MakeTimepoints {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MakeTimes : public System::Windows::Forms::Form
	{
	public:
		MakeTimes(void)
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
		~MakeTimes()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ TimeInput;
	protected:

	protected:




	private: System::Windows::Forms::Button^ completeButton;
	private: System::Windows::Forms::CheckBox^ includeCheck;



	private: System::Windows::Forms::Button^ loadTimepoints;

	private: System::Windows::Forms::Button^ saveTimepoints;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ startPoints;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ endPoints;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ separations;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ numPoints;






	protected:
	private: System::ComponentModel::IContainer^ components;

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
			this->TimeInput = (gcnew System::Windows::Forms::DataGridView());
			this->completeButton = (gcnew System::Windows::Forms::Button());
			this->includeCheck = (gcnew System::Windows::Forms::CheckBox());
			this->loadTimepoints = (gcnew System::Windows::Forms::Button());
			this->saveTimepoints = (gcnew System::Windows::Forms::Button());
			this->startPoints = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->endPoints = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->separations = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->numPoints = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimeInput))->BeginInit();
			this->SuspendLayout();
			// 
			// TimeInput
			// 
			this->TimeInput->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->TimeInput->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->startPoints,
					this->endPoints, this->separations, this->numPoints
			});
			this->TimeInput->Location = System::Drawing::Point(11, 58);
			this->TimeInput->Name = L"TimeInput";
			this->TimeInput->Size = System::Drawing::Size(455, 487);
			this->TimeInput->TabIndex = 0;
			this->TimeInput->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MakeTimes::TimeInput_CellValueChanged);
			// 
			// completeButton
			// 
			this->completeButton->Location = System::Drawing::Point(377, 9);
			this->completeButton->Name = L"completeButton";
			this->completeButton->Size = System::Drawing::Size(89, 43);
			this->completeButton->TabIndex = 1;
			this->completeButton->Text = L"Presto!";
			this->completeButton->UseVisualStyleBackColor = true;
			this->completeButton->Click += gcnew System::EventHandler(this, &MakeTimes::completeButton_Click);
			// 
			// includeCheck
			// 
			this->includeCheck->AutoSize = true;
			this->includeCheck->Location = System::Drawing::Point(238, 23);
			this->includeCheck->Name = L"includeCheck";
			this->includeCheck->Size = System::Drawing::Size(133, 17);
			this->includeCheck->TabIndex = 2;
			this->includeCheck->Text = L"Include Last Timepoint";
			this->includeCheck->UseVisualStyleBackColor = true;
			this->includeCheck->CheckedChanged += gcnew System::EventHandler(this, &MakeTimes::includeCheck_CheckedChanged);
			// 
			// loadTimepoints
			// 
			this->loadTimepoints->Location = System::Drawing::Point(106, 9);
			this->loadTimepoints->Name = L"loadTimepoints";
			this->loadTimepoints->Size = System::Drawing::Size(89, 43);
			this->loadTimepoints->TabIndex = 3;
			this->loadTimepoints->Text = L"Load Timepoints";
			this->loadTimepoints->UseVisualStyleBackColor = true;
			this->loadTimepoints->Click += gcnew System::EventHandler(this, &MakeTimes::loadTimepoints_Click);
			// 
			// saveTimepoints
			// 
			this->saveTimepoints->Location = System::Drawing::Point(11, 9);
			this->saveTimepoints->Name = L"saveTimepoints";
			this->saveTimepoints->Size = System::Drawing::Size(89, 43);
			this->saveTimepoints->TabIndex = 4;
			this->saveTimepoints->Text = L"Save Timepoints";
			this->saveTimepoints->UseVisualStyleBackColor = true;
			this->saveTimepoints->Click += gcnew System::EventHandler(this, &MakeTimes::saveTimepoints_Click);
			// 
			// startPoints
			// 
			this->startPoints->DataPropertyName = L"int[] startPoints";
			this->startPoints->HeaderText = L"Start Point (ps)";
			this->startPoints->Name = L"startPoints";
			this->startPoints->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->startPoints->Width = 105;
			// 
			// endPoints
			// 
			this->endPoints->DataPropertyName = L"int[] endPoints";
			this->endPoints->HeaderText = L"End Point (ps)";
			this->endPoints->Name = L"endPoints";
			this->endPoints->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// separations
			// 
			this->separations->DataPropertyName = L"int[] separations";
			this->separations->HeaderText = L"Separation (ps)";
			this->separations->Name = L"separations";
			this->separations->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->separations->Width = 105;
			// 
			// numPoints
			// 
			this->numPoints->DataPropertyName = L"int[] numPoints";
			this->numPoints->HeaderText = L"Points";
			this->numPoints->Name = L"numPoints";
			this->numPoints->ReadOnly = true;
			this->numPoints->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// MakeTimes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(477, 555);
			this->Controls->Add(this->saveTimepoints);
			this->Controls->Add(this->loadTimepoints);
			this->Controls->Add(this->includeCheck);
			this->Controls->Add(this->completeButton);
			this->Controls->Add(this->TimeInput);
			this->Name = L"MakeTimes";
			this->Text = L"Make Timepoints";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimeInput))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TimeInput_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) 
	{

	}
	private: System::Void TimeInput_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		String^ value1 = (String^)this->TimeInput->Rows[e->RowIndex]->Cells[0]->Value;
		String^ value2 = (String^)this->TimeInput->Rows[e->RowIndex]->Cells[1]->Value;
		String^ value3 = (String^)this->TimeInput->Rows[e->RowIndex]->Cells[2]->Value;

		if (!value1->IsNullOrEmpty(value1) && !value2->IsNullOrEmpty(value2) && !value3->IsNullOrEmpty(value3))
		{
			std::string stdvalue1 = msclr::interop::marshal_as<std::string>(value1);
			std::string stdvalue2 = msclr::interop::marshal_as<std::string>(value2);
			std::string stdvalue3 = msclr::interop::marshal_as<std::string>(value3);

			std::string valInt = std::to_string((int) floor(abs((std::stod(stdvalue2) - std::stod(stdvalue1))) / std::stod(stdvalue3)));
			String^ addValue = gcnew String(valInt.c_str());
			this->TimeInput->Rows[e->RowIndex]->Cells[3]->Value = addValue;
		}
	}
private: System::Void saveTimepoints_Click(System::Object^ sender, System::EventArgs^ e) 
{

	int curRow = 0;
	WriteTimepoints writer;
	String^ lastVal = (String^) this->TimeInput->Rows[curRow]->Cells[3]->Value;
	SaveFileDialog^ saveTimeDialog = gcnew SaveFileDialog();

	if (!lastVal->IsNullOrEmpty(lastVal))
	{
		saveTimeDialog->Filter = "Text file (*.txt)|*.txt";
		saveTimeDialog->Title = "Save a text file";

		saveTimeDialog->ShowDialog();
	}

	writer.WriteData(msclr::interop::marshal_as<std::string>(saveTimeDialog->FileName), std::to_string(includeLast), std::to_string(0), std::to_string(0),-1);

	do
	{

		std::string stdvalue1 = msclr::interop::marshal_as<std::string>((String^)this->TimeInput->Rows[curRow]->Cells[0]->Value);
		std::string stdvalue2 = msclr::interop::marshal_as<std::string>((String^)this->TimeInput->Rows[curRow]->Cells[1]->Value);
		std::string stdvalue3 = msclr::interop::marshal_as<std::string>((String^)this->TimeInput->Rows[curRow]->Cells[2]->Value);

		writer.WriteData(msclr::interop::marshal_as<std::string>(saveTimeDialog->FileName), stdvalue1, stdvalue2, stdvalue3, curRow);

		curRow++;

		if (curRow <= this->TimeInput->RowCount)
		{
			lastVal = (String^)this->TimeInput->Rows[curRow]->Cells[3]->Value;
		}
		else
		{
			lastVal = "";
		}

	} while (!lastVal->IsNullOrEmpty(lastVal));

}
private: System::Void loadTimepoints_Click(System::Object^ sender, System::EventArgs^ e) 
{

	this->TimeInput->Rows->Clear();
	this->TimeInput->Refresh();

	OpenFileDialog^ openTimeDialog = gcnew OpenFileDialog();
	openTimeDialog->ShowDialog();
	std::ifstream OpenFile(msclr::interop::marshal_as<std::string>(openTimeDialog->FileName));

	double startIn, endIn, sepIn;

	int curRow = 0;
	int lastQu, throwaway1, throwaway2;
	std::string line;

	getline(OpenFile, line);

	std::istringstream ss(line);

	ss >> lastQu >> throwaway1 >> throwaway2;
	includeLast = lastQu;

	if (includeLast == 1)
	{
		this->includeCheck->Checked.TrueString;
	}
	else
	{
		this->includeCheck->Checked.FalseString;
	}

	while (getline(OpenFile, line))
	{
		std::istringstream ss(line);
		ss >> startIn >> endIn >> sepIn;

		String^ startAdd = gcnew String(std::to_string(startIn).c_str());
		String^ endAdd = gcnew String(std::to_string(endIn).c_str());
		String^ sepAdd = gcnew String(std::to_string(sepIn).c_str());

		this->TimeInput->Rows->Add(startAdd, endAdd, sepAdd, gcnew String("0"));

		std::string valInt = std::to_string((int) floor(abs((endIn - startIn)) / sepIn));
		String^ addValue = gcnew String(valInt.c_str());
		this->TimeInput->Rows[curRow]->Cells[3]->Value = addValue;

		curRow++;
	}

	OpenFile.close();

}
private: System::Void completeButton_Click(System::Object^ sender, System::EventArgs^ e) 
{

	int curRow = 0;
	WriteTimepoints writer;
	String^ lastVal = (String^)this->TimeInput->Rows[curRow]->Cells[3]->Value;

	remove("TimeInputs.txt");

	writer.WriteData("TimeInputs.txt", std::to_string(includeLast), std::to_string(0), std::to_string(0), -1);

	do
	{

		std::string stdvalue1 = msclr::interop::marshal_as<std::string>((String^)this->TimeInput->Rows[curRow]->Cells[0]->Value);
		std::string stdvalue2 = msclr::interop::marshal_as<std::string>((String^)this->TimeInput->Rows[curRow]->Cells[1]->Value);
		std::string stdvalue3 = msclr::interop::marshal_as<std::string>((String^)this->TimeInput->Rows[curRow]->Cells[2]->Value);

		writer.WriteData("TimeInputs.txt", stdvalue1, stdvalue2, stdvalue3, curRow);

		curRow++;

		if (curRow <= this->TimeInput->RowCount)
		{
			lastVal = (String^)this->TimeInput->Rows[curRow]->Cells[3]->Value;
		}
		else
		{
			lastVal = "";
		}

	} while (!lastVal->IsNullOrEmpty(lastVal));

	exit(0);

}
private: System::Void includeCheck_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{

	if (this->includeCheck->Checked)
	{
		includeLast = 1;
	}
	else
	{
		includeLast = 0;
	}

}
};
}
