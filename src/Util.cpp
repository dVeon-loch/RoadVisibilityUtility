#include "Util.h"
#include <regex>

bool Util::isNumber(std::string string)
{
	return std::regex_match(string, std::regex(("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?")));
}
