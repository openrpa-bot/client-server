#include "GetWindowInformation.h"
#include <stdio.h>

void GetWindowInformation::windowAtPoint(POINT P)
{
	HWND Handle;

	Handle = WindowFromPoint(P);

	printf("Mouse position X = %d  Mouse Position Y = %d , Handle = %u\n", P.x, P.y, Handle);
}

void GetWindowInformation::windowAtFocus()
{
	POINT P;
	HWND Handle;

	GetCursorPos(&P);

	Handle = WindowFromPoint(P);
	printf("Mouse position X = %d  Mouse Position Y = %d , Handle = %u\n", P.x, P.y, Handle);
}
