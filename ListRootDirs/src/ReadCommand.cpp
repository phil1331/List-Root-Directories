#include "pch.h"
#include "Headers/ReadCommand.h"
#include "Configuration/Config.h"

[[nodiscard]] std::string ReadCommand(const char* command) {
	std::unique_ptr<FILE, int(*)(FILE*)> ptr_Pipe{ POPEN_S(command, "r"), PCLOSE_S };
	std::string s = "";
	for (std::array<char, 128> buffer; fgets(buffer.data(), static_cast<int>(buffer.size()), ptr_Pipe.get()); s += buffer.data());
#ifdef PH_DEBUG
	if (!ptr_Pipe)
		throw std::runtime_error("Could not open pipe.");
#endif
	return s;
}