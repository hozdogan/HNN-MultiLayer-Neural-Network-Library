#include <iostream>
#include "Pattern.h"

using namespace std;

Pattern::Pattern(float* inputVector,int Size)
{
	this->Size = Size;
	Inputs = new float[Size+1];
	NormInputs = new float[Size+1];
	for (int i = 0; i < Size; i++)
	{
		this->Inputs[i] = inputVector[i];
	}
	Inputs[Size] = 1.0f;
	NormInputs[Size] = 1.0f;
 
}
Pattern::Pattern(int Size)
{
	this->Size = Size;
	Inputs = new float[Size + 1];
	NormInputs = new float[Size + 1];
	Inputs[Size] = 1.0f;
	NormInputs[Size] = 1.0f;

	
}
void Pattern::setDesiredValue(float d)
{
	desired = d;
}
float Pattern::getElem(int index)
{
	return Inputs[index];
}
void Pattern::setElem(int index,float elem)
{
	this->Inputs[index] = elem;
}


float Pattern::getDesiredValue()
{
	return desired;
}
void Pattern::setClassID(int id)
{
	this->cid = id;
}
int Pattern::getClassID()
{
	return cid;
}
float Pattern::getNormElem(int index)
{
	return NormInputs[index];
}
void Pattern::setNormElem(int index, float elem)
{
	this->NormInputs[index] = elem;
}
int Pattern::getSize()
{
	return Size;
}
float Pattern::getBias()
{
	return bias;
}
void Pattern::setBias(float)
{
	this->bias = bias;
}