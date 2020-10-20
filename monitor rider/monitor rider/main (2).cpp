#define _UNICODE
#include<Windows.h>
#include <iostream>
#include<string>


int DisplayResourceNAMessageBox(MONITORINFOEXA mon)
{
    std::string a = std::to_string(mon.rcMonitor.right - mon.rcMonitor.left);
    std::string b = std::to_string(mon.rcMonitor.bottom - mon.rcMonitor.top);
    
   
    int msgboxID = MessageBoxA(
        NULL,
       //(LPCWSTR) a ,
        (LPCSTR) (a+"X"+b).c_str(),
        //(LPCWSTR)(d),
        (LPCSTR) mon.szDevice,
        MB_ICONINFORMATION | MB_OK | MB_DEFBUTTON1
    );

    switch (msgboxID)
    {
    case IDOK:
        // TODO: add code
        break;
   
    }

    return msgboxID;
}


BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData)
{
	MONITORINFOEXA mon = {};
	mon.cbSize = sizeof(mon);
	GetMonitorInfoA(hMonitor, &mon);
	//std::cout << mon.szDevice << "\n"<< mon.rcMonitor.right - mon.rcMonitor.left <<"X"<< mon.rcMonitor.bottom - mon.rcMonitor.top << std::endl;
    DisplayResourceNAMessageBox(mon);
	return TRUE;
}

int main()
{
	EnumDisplayMonitors(nullptr, nullptr, MonitorEnumProc, 0);

}

