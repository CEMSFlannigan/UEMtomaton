#include "WriteSettings.h"

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

void WriteSettings::WriteSet(std::string FileName, std::string val1, std::string val2, std::string val3)
{

	std::ofstream OpenFile;

	OpenFile.open(FileName);

	OpenFile << val1 + "\n\0";
	OpenFile << val2 + "\n\0";
	OpenFile << val3;

	OpenFile.close();

	return;
}