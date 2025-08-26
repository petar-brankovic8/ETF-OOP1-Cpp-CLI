#pragma once

#include <cstddef>

inline constexpr std::size_t maxLineSize = 512;

enum class InputStreamType {
	NoInputStream,
	Default,
	QuoteArgument,
	TxtFile
};

enum class OutputStreamType {
	NoOutputStream,
	Default,
	TxtFileOverwrite,
	TxtFileAppend
};