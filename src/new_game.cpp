#pragma once

#include "new_game.h"

#include <bitset>

using namespace ChaosEngine;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	using namespace basic_chaos_engine;
	basic_window::INITIAL_WINDOW_PROPERTY wnd_prop{};
	wnd_prop.title = L"game window on Windows platform";
	wnd_prop.on_init = &on_init;
	wnd_prop.on_exit = &on_exit;
	wnd_prop.style = basic_window::VISIBLE | basic_window::DEFAULT;
	basic_window::create_window(wnd_prop);
	return 0;
}
bool on_init() {
	return true;
}
bool on_exit() {
	if (MessageBoxW(NULL, L"Really quit?", L"", MB_OKCANCEL) == IDOK) return true;
	return false;
}