#pragma once
#include <cmath>

namespace Math
{

	static constexpr float Pi = 3.141592653589793f; // 180
	static constexpr float twoPi = 6.283185307179586f; // 360
	static constexpr float halfPi = 1.5707963267948966f; // 90

	constexpr float RadToDeg(float radians) { return radians * (180.0f / Pi); }
	constexpr float DegToRad(float degrees) { return degrees * (Pi / 180.0f); }


	inline float Sin(float radians) {
		return sinf(radians);

	}

	inline float Cos(float radians) {
		return cosf(radians);

	}
	/// <summary>
	/// Returns the Maximum Value of a and b
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a">value</param>
	/// <param name="b">value</param>
	/// <returns> The maximum value between a and b. </returns>
	 
	
	template<typename T>
	T Max(T a, T b) {
		return (a > b) ? a : b;
		// ? = if : = else
	}
	template<typename T>
	T Min(T a, T b) {
		return (a < b) ? a : b;
		// ? = if : = else
	}

	template <typename T>
	T Abs(T value) {
		return (value < 0) ? -value : value;
	}

	template <typename T>
	T Clamp(T value, T min, T max) {
		return (value < min) ? min : (value > max) ? max : value;
	}

};

