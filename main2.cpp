//#include "../../Dll2/Dll2/Header.h"
#include"pch.h"
#include <windows.h>

typedef int(*mp)(int, int);

int 
main()
{
	HMODULE mDll = LoadLibrary(L"Dll2.dll");
	try
	{
		mp mf =(mp) GetProcAddress(mDll,"multiply");
		cout << mf(2, 4);
	}
	catch (const exception&)
	{
		cout << "ERROR" << endl;

	}
	FreeLibrary(mDll);

}

