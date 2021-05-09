#include "GetWindowInformation.h"
#include <stdio.h>

void GetWindowInformation::windowAtPoint(POINT P)
{
	HWND Handle;

	Handle = WindowFromPoint(P);
    Handle = GetAncestor(Handle, GA_ROOT);

	printf("Mouse position X = %d  Mouse Position Y = %d , Handle = %10x\n", P.x, P.y, Handle);
}

void GetWindowInformation::windowAtFocus()
{
	
	HWND Handle = GetForegroundWindow();
    Handle = GetAncestor(Handle, GA_ROOT);
	HWND focusHandle = GetFocusGlobal();
	printf("Keyboard Window Handle = %10x & Focus Handle %10x\n", Handle, focusHandle);
}
HWND GetWindowInformation::GetFocusGlobal()
{
    HWND Wnd;
    HWND Result = NULL;
    DWORD TId, PId;

    Result = GetFocus();
    if (!Result)
    {
        Wnd = GetForegroundWindow();
        if (Wnd)
        {
            TId = GetWindowThreadProcessId(Wnd, &PId);
            if (AttachThreadInput(GetCurrentThreadId(), TId, TRUE))
            {
                Result = GetFocus();
                AttachThreadInput(GetCurrentThreadId(), TId, FALSE);
            }
        }
    }
    return Result;
}