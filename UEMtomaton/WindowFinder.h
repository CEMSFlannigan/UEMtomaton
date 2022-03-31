#pragma once
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
#include <chrono>       // std::chrono::system_clock
#include <random>       // std::default_random_engine

class WindowSearcher
{

public:
	HWND FocusWindow();
	static BOOL CALLBACK FindTheDesiredWnd(HWND hWnd, LPARAM lParam);

};
extern WindowSearcher finder;
#pragma once