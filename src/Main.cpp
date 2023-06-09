#include "ElfLoader.h"
#include <libos/Defines.h>
#include <string>
int main(int, char**)
{
	libOSInit();
	std::string x("$[binary_base]/../../../tests/echo");
	loseExecInfo info{};
	info.exeBits = LOSE_ALL;
	info.path = x.c_str();
	info.path_size = x.size();
	int ret =  loseExec(info);
	libOSCleanUp();
	return ret;
}