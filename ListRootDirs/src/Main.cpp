#include "pch.h"
#include "Headers/ListRoots.h"

int main() {
	for (const std::string& s : ListRoots()) {
		std::cout << s << '\n';
	}
	return 0;
}