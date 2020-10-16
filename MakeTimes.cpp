#include "MakeTimes.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MakeTimepoints::MakeTimes form;
	Application::Run(% form);
}