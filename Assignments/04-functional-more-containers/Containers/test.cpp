#include <Windows.h>
#include <Psapi.h>
#include "defs.hpp"
#include <iostream>

std::string get_proc_name(uint32_t pid)
{
	HANDLE		hProc = NULL;
	HMODULE		hMod = NULL;
	DWORD   	sizeNeeded = 0;

	char buffer[MAX_PATH + 1] = { 0 };
	std::string buf;

	if (NULL == (hProc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid))) {
		if (5 == GetLastError())
			return "Unable to open process. Skipping...";

		return "";
	}
	try {
		if (EnumProcessModules(hProc, &hMod, sizeof(hMod), &sizeNeeded)) {
			GetModuleBaseName(hProc, hMod, buffer, sizeof(buffer));
			buf = buffer;
		}
		else {
			std::cout << " Getting mod name failed!" << std::endl;
		}
	}
	catch (std::runtime_error e) {
		
	}
	CloseHandle(hProc);

	return  buf;
}

uint32_t get_pidlist(std::vector<uint32_t>& buf)
{
	DWORD sizeNeeded = 0;

	if (!EnumProcesses(reinterpret_cast<DWORD*>(buf.data()), buf.capacity()*sizeof(DWORD), &sizeNeeded))
		return 0;

	return sizeNeeded;
}
