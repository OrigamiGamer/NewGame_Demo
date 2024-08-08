#pragma once

#include "new_game.h"

using namespace std;
using namespace ChaosEngine;

Window main_window;
Engine engine;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	using namespace basic_chaos_engine;
	basic_window::INITIAL_WINDOW_PROPERTY wnd_prop{};
	wnd_prop.title = L"game window on Windows platform";
	wnd_prop.width = 1280;
	wnd_prop.height = 720;
	wnd_prop.on_init = &on_init;
	wnd_prop.on_exit = &on_exit;
	wnd_prop.style = WindowStyle::DEFAULT | WindowStyle::VISIBLE;
	main_window.Initialize(wnd_prop);

	INITIAL_ENGINE_PROPERTY engine_prop{};
	engine_prop.window = &main_window;
	engine_prop.on_update = &on_update;
	engine_prop.on_render = &on_render;
	engine.Initialize(engine_prop);
	engine.Run();
	return 0;
}
bool on_init() {
	basic_type::vec2<int> size = main_window.GetSize();
	OutputDebugStringW(std::to_wstring(size.x).c_str());
	OutputDebugStringW(L"\n");
	OutputDebugStringW(std::to_wstring(size.y).c_str());
	OutputDebugStringW(L"\n");
	return true;
}
bool on_exit() {
	if (MessageBoxW(main_window.GetHandle(), L"Really quit?", L"Tips", MB_OKCANCEL) == IDOK)
		if (engine.Shutdown()) return true;
	return false;
}
void on_update() {
}
void on_render() {
	engine.graphic.set_stroke_width(10.0f);
	engine.graphic.draw_line({ 10,10 }, { 200,200 });
}