#pragma once

#include <cstdint>

class CPlatform final
{
public:
	enum class Priority : std::uint8_t { LOW, HIGH };
	static void setProcessPriority(CPlatform::Priority priority) noexcept;

	#ifdef _WIN32
	static void fixResize() noexcept;
	#endif
};
