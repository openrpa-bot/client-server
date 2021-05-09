#pragma once
#include <windows.h>
class GetWindowInformation
{
public:
	void windowAtPoint(POINT P);
	void windowAtFocus();
	HWND GetFocusGlobal();
};

