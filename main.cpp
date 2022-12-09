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
    cout<<"BCL will launch the program "<<target<<" in "<<directory<<endl;
    cout<<"Do you want to continue?[Y/n] ";
    if(getchar()=='Y'){
        cout<<"Writing configurations to BCL.cfg"<<endl;
        FILE* file=fopen("bcl.cfg","w");
        fputs(target,file);
        fputs("\n",file);
        fputs(directory,file);
        fputs("\n",file);
        fputs("-----Background-Console-Launcher-----",file);
        fputs("[Info] Created new configuration file.\n",logg);
        fputs("\n",file);
        fclose(file);
        return 0;
    }
    cout<<"Abort."<<endl;
    Sleep(1501);
    fputs("[op] The user gave up the configurations.\n\n",logg);
    fputs("[Critical] BCL was aborted.\n\n",logg);
    fputs("[Info] BCL exited with code 2.\n\n",logg);
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
    // ShowWindow(GetConsoleWindow(), SW_HIDE); 
    // LPWSTR("C:\\alist-windows-4.0-amd64.exe");F:\Eddie\D\Github\Background-Console-Launcher\bullseye.exe
    // init
    FILE *file=fopen("bcl.cfg","r");
    freopen("%%USERPROFILE%\\.bcl\\stderr.log","a+",stderr);
    fputs("[Info] BCL Launched.\n",logg);
    cout<<"Welcome to Background Console Launcher!"<<endl;
    if(!file){
        fputs("[Info] Entered configuration panel.\n",logg);
        fclose(file);
        cout<<"The BCL is not configured. Entering configuration pannel..."<<endl;
        config();
    }
    fgets(target,100,file);
    fgets(directory,100,file);

    //logging
    for(int i=0;i<=100;i++){
        cout<<int(target[i])<<" ";
    }
    cout<<endl;
    for(int i=0;i<=100;i++){
        cout<<int(directory[i])<<" ";
    }
    cout<<endl;

    formating();
    cout<<"At console "<<stdout<<", Launching file "<<file<<" "<<target<<" "<<directory<<" ..."<<endl;
    
    //logging
    for(int i=0;i<=100;i++){
        cout<<int(target[i])<<" ";
    }
    cout<<endl;
    for(int i=0;i<=100;i++){
        cout<<int(directory[i])<<" ";
    }
    cout<<endl<<endl;

    // CreateProcess
    STARTUPINFO si;
	memset(&si, 0,sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;
	PROCESS_INFORMATION pii;
	memset(&pii, 0,sizeof(PROCESS_INFORMATION));
    CreateProcess(TEXT(target),NULL, NULL, NULL, false, 0, NULL, TEXT(directory), &si, &pii);
    fputs("[Info] BCL created the specified process.\n",logg);
    fputs("[Info] BCL exited with code 0.\n\n",logg);
    return 0;
}

