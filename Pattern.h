#pragma once
#ifndef  PATTERN_H
#define  PATTERN_H

class Pattern
{
public:
	void setDesiredValue(float);
	Pattern(float*,int);
	Pattern(int);
	float getElem(int);
	void setElem(int,float);
	float getNormElem(int);
	void setNormElem(int,float);
	void setBias(float);
	int getClassID();
	float getDesiredValue();
	float getBias();
	void setClassID(int id);
	int getSize();
private:
	int cid,Size;
	float desired,bias;
	float* Inputs;
	float* NormInputs;


};

#endif // ! PATTERN_H
