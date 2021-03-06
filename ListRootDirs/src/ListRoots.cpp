#include "pch.h"
#include "Configuration/Config.h"
#include "Headers/ListRoots.h"
#include "Headers/ReadCommand.h"

[[nodiscard]] const std::vector<std::string>& ListRoots() noexcept {
#if __has_include (<Windows.h>)
	static std::vector<std::string> toBeFilled;
	if (toBeFilled.empty()) {
		static const std::string commandOutput = ReadCommand("wmic logicaldisk get name | findstr :");
		static const std::regex reg(R"([^\s]+)", std::regex::optimize);
		for (std::sregex_iterator iter(commandOutput.begin(), commandOutput.end(), reg); iter != invalid_iter; ++iter)
			toBeFilled.emplace_back(std::move(iter->str()) + "\\");
	}
	return toBeFilled;
#else 
	return { "/" };
#endif // __has_include (<Windows.h>)
}