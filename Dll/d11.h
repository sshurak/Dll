#pragma once
class ComplexClass
{
public:
	virtual void Clear() = 0;
	virtual void Out() = 0;
	virtual void Maiting() = 0;
	virtual void SetReIm(float a, float b) = 0;
	virtual float GetRe() = 0;
	virtual float GetIm() = 0;

	virtual ComplexClass* Plus(ComplexClass* B) = 0;
	virtual ComplexClass* Plus(float B) = 0;
	virtual ComplexClass* Minus(ComplexClass* B) = 0;
	virtual ComplexClass* Minus(float B) = 0;
	virtual ComplexClass* Multiply(ComplexClass* B) = 0;
	virtual ComplexClass* Multiply(float B) = 0;
	virtual ComplexClass* Divide(ComplexClass* B) = 0;
	virtual ComplexClass* Divide(float B) = 0;
	virtual ComplexClass* Power(int Power) = 0;
};