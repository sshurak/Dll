// Dll.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"

#include "d11.h"
#include <iostream>
#include <windows.h>



class Complex : public ComplexClass
{
private:
	float re;
	float im;
public:
	Complex()
	{
		re = 0;
		im = 0;
	}
	Complex(float x, float y)
	{
		re = x;
		im = y;
	}
	~Complex()
	{
	}
	void Clear()
	{
		delete this;
	}
	void Out()
	{
		std::cout << re;
		if (im > 0) std::cout << "+";
		if (im != 0) std::cout << im << "i\n";
	}
	void Maiting()
	{
		im = im * (-1);
	}
	float GetRe()
	{
		return re;
	}
	float GetIm()
	{
		return im;
	}
	void SetReIm(float a, float b)
	{
		re = a;
		im = b;
	}
	ComplexClass* Plus(ComplexClass* B)
	{
		ComplexClass* C = new Complex;
		C->SetReIm(GetRe() + B->GetRe(), GetIm() + B->GetIm());
		return C;
	}
	virtual ComplexClass* Plus(float B)
	{
		ComplexClass* C = new Complex;
		C->SetReIm(GetRe() + B, GetIm());
		return C;
	}
	ComplexClass* Minus(ComplexClass* B)
	{
		ComplexClass* C = new Complex;
		C->SetReIm(GetRe() - B->GetRe(), GetIm() - B->GetIm());
		return C;
	}
	ComplexClass* Minus(float B)
	{
		ComplexClass* C = new Complex;
		C->SetReIm(GetRe() - B, GetIm());
		return C;
	}
	ComplexClass* Multiply(ComplexClass* B)
	{
		ComplexClass* C = new Complex;
		C->SetReIm((GetRe()*B->GetRe()) - (GetIm()*B->GetIm()), ((GetRe()*B->GetIm()) + (GetIm()*B->GetRe())));
		return C;
	}
	ComplexClass* Multiply(float B)
	{
		ComplexClass* C = new Complex;
		C->SetReIm((GetRe()*B), (GetIm()*B));
		return C;
	}
	ComplexClass* Divide(ComplexClass* B)
	{
		ComplexClass* C = new Complex;
		float x, y;
		x = ((GetRe()*B->GetRe() + GetIm()*B->GetIm()) / (B->GetRe()*B->GetRe() + B->GetIm()*B->GetIm()));
		y = ((GetIm()*B->GetRe() - GetRe()*B->GetIm()) / (B->GetRe()*B->GetRe() + B->GetIm()*B->GetIm()));
		C->SetReIm(x, y);
		return C;
	}
	ComplexClass* Divide(float B)
	{
		ComplexClass* C = new Complex;
		C->SetReIm((GetRe()*B) / (B*B), (GetIm()*B) / (B*B));
		return C;
	}
	ComplexClass* Power(int Power)
	{
		ComplexClass* C = new Complex;
		C->SetReIm(GetRe(), GetIm());
		if (Power > 0)
		{
			for (int i = 1; i < Power; i++)
			{
				C = C->Multiply(this);
			}
		}
		return C;
	}
};

extern "C" __declspec(dllexport) ComplexClass* __cdecl CreateClass()
{
	ComplexClass* A = new Complex;
	return A;
}

