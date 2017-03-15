#include <string>
#include <Windows.h>
#include <tlhelp32.h>

class ProcessOpt
{
public:
	ProcessOpt(void);
	~ProcessOpt(void);

	static bool EnumProcess();
	static bool	GetPIDbyName(TCHAR *ProcessName, DWORD& dwPid);
	static int	KillProcess(DWORD pid);
};
