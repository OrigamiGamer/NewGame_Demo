#pragma once

#define UNICODE
#define _D2D
#define _OPENAL

// Windows
#include <Windows.h>

// ChaosEngine
#include "chaos_engine.h"
#include "chaos_engine.cpp"	// DEBUG

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);
bool on_init();
bool on_exit();
void on_update();
void on_render();