#pragma once

#define UNICODE

// Windows
#include <Windows.h>

// ChaosEngine
#include "chaos_engine.h"
#include "chaos_engine.cpp"	// DEBUG

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);
bool on_init();
bool on_exit();
