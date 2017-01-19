#include <iostream>
#include <windows.h>

using namespace std;
typedef void (*SomeFunction)(const LPCSTR);

HINSTANCE dll;

int main()
{
    dll = LoadLibrary("defaultdll.dll");

    if (dll != 0){
        cout << "The DLL is loaded.";
        SomeFunction MsgBox = (SomeFunction)GetProcAddress(dll, "SomeFunction");
        MsgBox((const LPCSTR)"The DLL was loaded into memory successfully.");
        FreeLibrary((HMODULE)dll);
    }
    else
    {
        cout << "Something went wrong.\n";
    }
    return 0;
}
