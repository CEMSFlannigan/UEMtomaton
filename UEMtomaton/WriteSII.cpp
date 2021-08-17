#include "WriteSII.h"

/*

Purpose: To write to InputFileTest.txt, which passes data from the delay stage to the DM Script.

Parameters:
	String FilePath: Path of SIIFileInput.txt
	String FileName: SIIFileInput.txt

	int DelayTime: the delay time of the delay stage (sourced from delay stage automation)
	int stepNumber: the current step number (sourced from delay stage automation)
	String dm3path: the path to save images in (sourced from camera computer user input)
	String dm3FN: the file name of the dm3 (sourced from both camera computer user input)

*/

void WriteSII::WriteData(std::string FileName, std::string val1, std::string val2, std::string val3, std::string val4)
{

	std::ofstream OpenFile;

	OpenFile.open(FileName);

	OpenFile << val1 + "\\.ext\n\0";
	OpenFile << val2 + ".ext\n\0";
	OpenFile << "\n\0";
	OpenFile << val3 + "\n\0";
	OpenFile << val4 + "\n\0";

	OpenFile.close();

	return;
}