#pragma once
#ifndef NEURON_H
#define NEURON_H

class Neuron
{
public:
	
	Neuron(int,int inputSize = 0);

	void SetActivationFunction(int);
	
	float SoftMAX_Function(float*, int, float);
	void setInputElem(int, float);
	int getActivationFunctionIndex();
	float getInputElem(int index);
	float getWeightElem(int index);
	void setWeightElem(int index, float elem);
	float getTempWeightElem(int index);
	void setTempWeightElem(int index, float elem);
	float DeriveOutput();
	void setOutput(float);
	float ActivationFunc(float net, int index, bool state);
	int getID();
	float GetOutput();
	void setRandomWeights();
private:
	int stateThresFunction,inputSize,id;
	float* input_vector;
	float* input_Weights;
	float* temp_Weights;
	float outputvalue;
	

};



#endif // !NEURON_H
