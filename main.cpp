#include<bits/stdc++.h>
#include<windows.h>
using namespace std;


int main(){
    ShowWindow(GetConsoleWindow(), SW_HIDE); 
    // LPWSTR("C:\\alist-windows-4.0-amd64.exe");
    // init
    // CreateProcess
    STARTUPINFO si;
	memset(&si, 0,sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;
	PROCESS_INFORMATION pii;
	memset(&pii, 0,sizeof(PROCESS_INFORMATION));
    CreateProcess(LPCSTR("C:\\alist-windows-4.0-amd64.exe"),NULL, NULL, NULL, false, 0, NULL, LPCSTR("C:\\"), &si, &pii);
    
    return 0;
}

