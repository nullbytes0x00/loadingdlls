#include <iostream>
#include <windows.h>

using namespace std;
typedef void (*SomeFunction)(const LPCSTR); //defining a type associated with the function

HINSTANCE dll;

int main()
{
    dll = LoadLibrary("defaultdll.dll"); //loading the dynamic library

    if (dll != 0){
        cout << "The DLL is loaded.";
        SomeFunction MsgBox = (SomeFunction)GetProcAddress(dll, "SomeFunction"); //calling the function which is contained in the DLL
        MsgBox((const LPCSTR)"The DLL was loaded into memory successfully.");
        FreeLibrary((HMODULE)dll); //freeing the memory which was used by DLL
    }
    else
    {
        cout << "Something went wrong.\n"; //this will be shown if the DLL fails to load
    }
    return 0;
}
