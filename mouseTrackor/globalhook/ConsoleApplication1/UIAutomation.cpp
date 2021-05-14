#include "UIAutomation.h"
#include <uiautomationclient.h>
#include <stdio.h>
//#include <windows.h>

HRESULT UIAutomation::windowAtPoint(POINT P) {
    IUIAutomation* g_pAutomation;
    CoInitialize(NULL);
    HRESULT hr = CoCreateInstance(__uuidof(CUIAutomation), NULL,
        CLSCTX_INPROC_SERVER, __uuidof(IUIAutomation),
        (void**)&g_pAutomation);
    if (FAILED(hr))
        return (hr);

    // Get the element under the cursor
    // Use GetPhysicalCursorPos to interact properly with
    // High DPI
    //POINT pt;
    //GetPhysicalCursorPos(&pt);

    IUIAutomationElement* pAtMouse;
    hr = g_pAutomation->ElementFromPoint(P, &pAtMouse);
    if (FAILED(hr))
        return hr;

    // Get the element's name and print it
    BSTR name;
    hr = pAtMouse->get_CurrentName(&name);
    if (SUCCEEDED(hr))
    {
        wprintf(L"Element's Name: %s \n", name);
        SysFreeString(name);
    }

    // Get the element's Control Type (in the current languange)
    // and print it
    BSTR controlType;
    hr = pAtMouse->get_CurrentLocalizedControlType(&controlType);
    if (SUCCEEDED(hr))
    {
        wprintf(L"Element's Control Type: %s \n", controlType);
        SysFreeString(controlType);
    }

    // Clean up our COM pointers
    pAtMouse->Release();
    g_pAutomation->Release();
    CoUninitialize();
    return 0;

	//IUIAutomationElement* element, * parent;
	//HRESULT hRESULT = g_pAutomation->ElementFromPoint(P, &element);
    //printf("IUIAutomationElement Mouse position X = %d  Mouse Position Y = %d , Child  Handle = %10x name = %s\n", P.x, P.y, element, element->get_CurrentName());
   // hRESULT = element->GetCachedParent(&parent);
   // printf("IUIAutomationElement Mouse position X = %d  Mouse Position Y = %d , Parent Handle = %10x\n", P.x, P.y, parent);
}
