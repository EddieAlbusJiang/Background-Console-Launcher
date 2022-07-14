#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

char target[105],directory[105];
FILE *logg=fopen("bcl.log","a+");

int config(){
    cout<<"Please give out the executable path: ";
    gets(target);
    cout<<"Please give out the prefix directory: ";
    gets(directory);
    cout<<"Please confirm the following :"<<endl;
    cout<<"BCF will launch the program "<<target<<" in "<<directory<<endl;
    cout<<"Do you want to continue?[Y/n] ";
    if(getchar()=='Y'){
        cout<<"Writing configurations to BCF.cfg"<<endl;
        FILE* file=fopen("bcl.cfg","w");
        fputs(target,file);
        fputs("\n",file);
        fputs(directory,file);
        fputs("\n",file);
        fputs("-----Background-Console-Launcher-----",file);
        fputs("\n",file);
        fclose(file);
        return 0;
    }
    cout<<"Abort."<<endl;
    Sleep(1501);
    fputs("BCL exited with code 2.\n\n",logg);
    exit(2);
}

int formating(){
    int i=0;
    while(target[i]!='\n'){
        i++;
    }
    target[i]=' ';
    i=0;
    while(target[i]!='\n'){
        i++;
    }
    target[i]=' ';
    return 0;
}

int main(){
    // LPWSTR("C:\\alist-windows-4.0-amd64.exe");F:\Eddie\D\Github\Background-Console-Launcher\bullseye.exe
    // init
    FILE *file=fopen("bcl.cfg","r");
    fputs("BCL Launched.\n",logg);
    cout<<"Welcome to Background Console Launcher!"<<endl;
    if(!file){
        fputs("Enter configuration panel.\n",logg);
        fclose(file);
        cout<<"The BCF is not configured. Entering configuration pannel..."<<endl;
        config();
    }
    ShowWindow(GetConsoleWindow(), SW_HIDE); 
    fgets(target,100,file);
    fgets(directory,100,file);

    formating();
    cout<<"At console "<<stdout<<", Launching file "<<file<<" "<<target<<" "<<directory<<" ..."<<endl;

    // CreateProcess
    STARTUPINFO si;
	memset(&si, 0,sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;
	PROCESS_INFORMATION pii;
	memset(&pii, 0,sizeof(PROCESS_INFORMATION));
    CreateProcess(TEXT(target),NULL, NULL, NULL, false, 0, NULL, TEXT(directory), &si, &pii);
    fputs("BCL exited with code 0.\n\n",logg);
    return 0;
}

