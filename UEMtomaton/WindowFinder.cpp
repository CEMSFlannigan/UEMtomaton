#include "WindowFinder.h"

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

HWND WindowSearcher::FocusWindow()
{

	HWND hFoundWnd = NULL;
	EnumWindows((WNDENUMPROC)&WindowSearcher::FindTheDesiredWnd, reinterpret_cast<LPARAM>(&hFoundWnd));

	return hFoundWnd;
}

/*
		*/
BOOL CALLBACK WindowSearcher::FindTheDesiredWnd(HWND hWnd, LPARAM lParam)
{
	int length = ::GetWindowTextLength(hWnd);
	TCHAR* windowBuffer;
	windowBuffer = new TCHAR[length + 1];
	memset(windowBuffer, 0, (length + 1) * sizeof(TCHAR));
	GetWindowText(hWnd, windowBuffer, length + 1);
	std::string windowTitle;
	std::wstring wStr = windowBuffer;
	windowTitle = std::string(wStr.begin(), wStr.end());
	std::string checkTitle = "DigitalMicrograph";
	if (windowTitle.find(checkTitle) != std::string::npos)
	{
		*(reinterpret_cast<HWND*>(lParam)) = hWnd;
		return FALSE; // stop enumerating
	}
	return TRUE; // keep enumerating
}