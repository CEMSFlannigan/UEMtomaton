#include "WriteULG.h"
#include <msclr\marshal_cppstd.h>
#include <ctime>
#include <time.h>
#include <string>
/* 

Purpose: To write to InputFileTest.txt, which passes data from the delay stage to the DM Script. 

Parameters:
	String FilePath: Path of InputFileTest.txt
	String FileName: InputFileTest.txt

	int DelayTime: the delay time of the delay stage (sourced from delay stage automation)
	int stepNumber: the current step number (sourced from delay stage automation)
	String dm3path: the path to save images in (sourced from camera computer user input)
	String dm3FN: the file name of the dm3 (sourced from both camera computer user input)
	String delayunits: the units on the delay (sourced from delay stage automation)
	int scannum: the current scan number (sourced from delay stage automation)
	int Lambda: the wavelength of pump used (sourced from camera computer user input)
	int RepRate: the repetition rate used (sourced from camera computer user input)
	int Power: the power of the pump (sourced from camera computer user input)

*/

void WriteULG::WriteData(std::string FileName, std::string val1, std::string val2, std::string val3, std::string val4, std::string val5, std::string val6, int row)
{

	std::ofstream OpenFile;
	time_t mytime = time(NULL);

	if (row == 1)
	{
		OpenFile.open(FileName);

		OpenFile << "[Info Directory\t]\t" + val1 + "\n";
		OpenFile << "[Base Name ]\t" + val2 + "\n";
		OpenFile << "[Date\t]\t" + msclr::interop::marshal_as<std::string>(gcnew System::String(ctime(&mytime)));
		OpenFile << "[Number of Steps\t]\t" + val3 + "\n" + "[Number of Scans\t]\t" + "0" + "\n";
		OpenFile << "\t\n";
		OpenFile << "[Column Descriptions\t]:\tStep,Delay,Scan,Scan Step,File Name,Time\n";
		OpenFile << "\n";
		OpenFile << "\t\n";
		OpenFile << ",,,,,\n";
		OpenFile << val4 + "," + val5 + ",0," + val4 + "," + val6 + "," + msclr::interop::marshal_as<std::string>(gcnew System::String(ctime(&mytime))) + "\n";

		OpenFile.close();
	}
	else
	{
		OpenFile.open(FileName, std::ios_base::app);

		OpenFile << val4 + "," + val5 + ",0," + val4 + "," + val6 + "," + msclr::interop::marshal_as<std::string>(gcnew System::String(ctime(&mytime))) + "\n";

		OpenFile.close();
	}

	return;
}