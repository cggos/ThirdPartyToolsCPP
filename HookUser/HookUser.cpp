#include "HookUser.h"

HHOOK g_hookMouse;
HHOOK g_hookKeyboard;

HookUser::HookUser(void)
{
}

HookUser::~HookUser(void)
{
}

int HookUser::InstallHook()
{
	g_hookMouse = SetWindowsHookEx (WH_MOUSE_LL, HookProcMouse,GetModuleHandle(NULL),0); //为鼠标设置一个钩子 来监听用户的鼠标点击和移动 
	g_hookKeyboard = SetWindowsHookEx (WH_KEYBOARD_LL, HookProcKeyboard,GetModuleHandle(NULL),0);

	if (g_hookMouse == NULL || g_hookKeyboard == NULL)//判断钩子是否设置成功
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void HookUser::MsgLoop()
{
	// 设置消息循环
	MSG msg;
	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg);
		DispatchMessage (&msg);
	}
}

void HookUser::UninstallHook()
{
	UnhookWindowsHookEx (g_hookMouse);
}

LRESULT CALLBACK HookProcMouse (int nCode, WPARAM wP, LPARAM lP)
{
	switch(wP)
	{
	case WM_LBUTTONDOWN:
		printf("按下左键\n");
		break;
	case WM_LBUTTONUP:
		printf("抬起左键\n");
		break;
	default:
		printf("x:%d\ty:%d\n",((PMSLLHOOKSTRUCT)lP)->pt.x,((PMSLLHOOKSTRUCT)lP)->pt.y);
		break;
	}

	return CallNextHookEx (g_hookMouse, nCode, wP, lP);
}

LRESULT CALLBACK HookProcKeyboard(int nCode, WPARAM wP, LPARAM lP)
{
	printf((wP==WM_KEYDOWN)?"按下%c\n":"抬起%c\n",((PKBDLLHOOKSTRUCT)lP)->vkCode);

	return CallNextHookEx (g_hookKeyboard, nCode, wP, lP);
}
