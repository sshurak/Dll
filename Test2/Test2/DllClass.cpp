
#include "d11.h"
#include <iostream>
#include <windows.h>

typedef ComplexClass* (__cdecl *ComplexClass_factory)();

void main()
{
	HINSTANCE hmodule = LoadLibrary("Dll.dll");
	if (!hmodule)
	{
		std::cout << "Loading failed!\n";
		return;

	}
	ComplexClass_factory CreateClass = reinterpret_cast<ComplexClass_factory>(GetProcAddress(hmodule, "CreateClass"));
	if (!CreateClass)
	{
		std::cout << "Loading failed!\n";
		FreeLibrary(hmodule);
		return;

	}
	ComplexClass* A = CreateClass();
	ComplexClass* B = CreateClass();
	ComplexClass* C = CreateClass();
	A->SetReIm(2, -8);
	B->SetReIm(9, 3);
	A->Out();
	B->Out();
	C = A->Plus(B);
	C->Out();
	C = A->Multiply(B);
	C->Out();
	C = A->Divide(B);
	C->Out();
	C = A->Power(3);
	C->Out();
	C->Maiting();
	C->Out();
	A->Clear();
	B->Clear();
	C->Clear();
	FreeLibrary(hmodule);
	system("pause");
}
