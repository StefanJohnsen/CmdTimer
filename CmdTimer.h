#pragma once
#include <chrono>
#include <string>

/*----------------------------------------------------------------
  CmdTimer.h

  Header-only helpers for simple timer console tool.
  Requirements:	C++17
  OS Support:Windows/Linux/MacOS

  License: MIT
  Author: Stefan Falk Johnsen
  Copyright (c) 2025 FalconCoding

  GitHub: https://github.com/StefanJohnsen/CmdTimer
----------------------------------------------------------------*/

namespace timer
{
	using namespace std::chrono;

	using Clock = steady_clock;

	inline time_point<Clock> start_time;

	inline time_point<Clock> now()
	{
		return Clock::now();
	}

	inline void start()
	{
		start_time = now();
	}

	inline std::string stop(const time_point<Clock>& start)
	{
		const auto duration = duration_cast<std::chrono::microseconds>(now() - start);
		const auto hours = duration_cast<std::chrono::hours>(duration);
		const auto minutes = duration_cast<std::chrono::minutes>(duration % std::chrono::hours(1));
		const auto seconds = duration_cast<std::chrono::seconds>(duration % std::chrono::minutes(1));
		const auto milliseconds = duration_cast<std::chrono::milliseconds>(duration % std::chrono::seconds(1));
		const auto microseconds = duration_cast<std::chrono::microseconds>(duration % std::chrono::milliseconds(1));

		std::string result;

		if (hours.count() > 0 || minutes.count() > 0)
		{
			result += (hours.count() < 10 ? "0" : "") + std::to_string(hours.count()) + ":";
			result += (minutes.count() < 10 ? "0" : "") + std::to_string(minutes.count()) + ":";
			result += (seconds.count() < 10 ? "0" : "") + std::to_string(seconds.count());
		}
		else if (seconds.count() > 0)
			result += std::to_string(seconds.count()) + " seconds";
		else if (milliseconds.count() > 0)
			result += std::to_string(milliseconds.count()) + " milliseconds";
		else
			result += std::to_string(microseconds.count()) + " microseconds";

		return result;
	}

	inline std::string stop()
	{
		return stop(start_time);
	}
}
