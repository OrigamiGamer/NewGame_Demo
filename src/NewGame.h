#pragma once

#define UNICODE
#define _D2D
#define _OPENAL

// Windows
#include <Windows.h>

// ChaosEngine
#include "ChaosEngine.h"
#include "ChaosEngine.cpp"	// DEBUG

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);
bool on_init();
bool on_exit();
void on_update();
void on_render();

// UnknownGame
#include "World.h"