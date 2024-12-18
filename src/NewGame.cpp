#pragma once

#include "NewGame.h"

using namespace std;
using namespace ChaosEngine;

Window main_window;
Engine engine;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	using namespace basic_chaos_engine;
	basic_window::INITIAL_WINDOW_PROPERTY wnd_prop{};
	wnd_prop.title = L"game window on Windows platform";
	wnd_prop.width = 1280;
	wnd_prop.height = 720;
	wnd_prop.on_init = &on_init;
	wnd_prop.on_exit = &on_exit;
	wnd_prop.style = Const::WindowStyle::DEFAULT | Const::WindowStyle::VISIBLE;
	main_window.Initialize(wnd_prop);

	INITIAL_ENGINE_PROPERTY engine_prop{};
	engine_prop.window = &main_window;
	engine_prop.on_update = &on_update;
	engine_prop.on_render = &on_render;
	engine_prop.interval_window_update = chrono::milliseconds(1000 / 60);
	engine_prop.interval_game_update = chrono::milliseconds(1000 / 60);
	engine_prop.interval_game_render = chrono::milliseconds(1000 / 60);
	engine.Initialize(engine_prop);
	engine.Run();
	return 0;
}

basic_chaos_engine::basic_audio::basic_sound_player sound_player;
basic_chaos_engine::basic_audio_openal openal;
bool on_init()
{
	basic_type::vec2<int> size = main_window.GetSize();
	OutputDebugStringW(std::to_wstring(size.x).c_str());
	OutputDebugStringW(L"\n");
	OutputDebugStringW(std::to_wstring(size.y).c_str());
	OutputDebugStringW(L"\n");

	// sound_player.initialize();
	// if (sound_player.load_sound_file(L"./res/sound/uplifting.wav", L"uplifting")) {
	// 	auto channel_main = sound_player.create_channel(L"main");
	// 	if (channel_main != nullptr) {
	// 		channel_main->insert_sound(0, sound_player.get_sound(L"uplifting"));
	// 	}
	// 	sound_player.playback();
	// }

	openal.initialize();
	basic_chaos_engine::type::BufferID buffer_id = openal.load_sound_file(L"./sound/ShichSason - Run Girls, Run! - Share the light Assertive Hardcore Bootleg.mp3");
	basic_chaos_engine::type::SourceID source_id = openal.create_source();
	openal.source_queue_buffer(source_id, buffer_id);
	openal.source_play(source_id);
	openal.source_set_volume(source_id, 0.1f);

	return true;
}
bool on_exit()
{
	if (MessageBoxW(main_window.GetHandle(), L"Really quit?", L"Tips", MB_OKCANCEL) == IDOK)
		if (engine.Shutdown())
		{
			openal.release();
			return true;
		}
	return false;
}
long number = 0;
long addition = 1;
float stroke_width = 0.0f;
long tick = 0;
unsigned long long this_time = 0;
void on_update()
{
	number++;
	if (number >= 1)
	{
		number = 0;
		stroke_width += addition * 0.1f;
		if (stroke_width >= 10.0f || stroke_width <= 0.0f)
		{
			addition = -addition;
		}
		engine.graphic.set_stroke_width(stroke_width);
	}

	tick++;
	// 1000ms
	if (engine.last_time_update - this_time >= 1000)
	{
		this_time = engine.last_time_update;
		SetWindowText(engine.properties.window->GetHandle(),
			(L"FPS " + to_wstring(tick)).c_str()
		);
		tick = 0;
	}
}
void on_render()
{
	engine.graphic.draw_line({ 50,50 }, { 200,200 });
	engine.graphic.draw_circle({ 300,200 }, 100);
}