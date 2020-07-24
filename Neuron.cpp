#include<iostream>
#include<cstdlib>
#include<string.h>
#include<cmath>
#include<ctime>
#include "Neuron.h"
using namespace std;

void Neuron::SetActivationFunction(int state)
{
	stateThresFunction = state;
}
int Neuron::getActivationFunctionIndex()
{
	return stateThresFunction;
}
void Neuron::setInputElem(int index, float elem)
{
	input_vector[index] = elem;
}
int Neuron::getID()
{
	return id;
}
Neuron::Neuron(int id,int inputSize)
{
	this->inputSize = inputSize;
	this->id = id;
	input_vector = new float[inputSize+1];
	input_Weights = new float[inputSize+1];
	temp_Weights = new float[inputSize + 1];
	for (int i = 0; i < inputSize + 1; i++)
	{
		temp_Weights[i] = 0.0f;
	}
	input_vector[inputSize] = 1.0f;
	
}
void Neuron::setRandomWeights()
{
	
	for (int i = 0; i < inputSize + 1; i++)
	{
		this->input_Weights[i] = ((rand() % 10) / 10.0f) + ((rand() % 10) / 100.0f);
	}
}


float Neuron::GetOutput()
{
	return outputvalue;
}
float Neuron::getInputElem(int index)
{
	return input_vector[index];
}

float Neuron::getWeightElem(int index)
{
	return input_Weights[index];
}
void Neuron::setWeightElem(int index, float elem)
{
	input_Weights[index] = elem;
}

float Neuron::getTempWeightElem(int index)
{
	return temp_Weights[index];
}
void Neuron::setTempWeightElem(int index, float elem)
{
	temp_Weights[index] = elem;
}



float Neuron::SoftMAX_Function(float* arr, int index, float net)
{
	float sum = 0.0f, result;
	for (int i = 0; i < index; i++)
	{
		sum += expf(arr[i]);
	}
	result = expf(net) / sum;
	if (sum == 0.0f || result == NAN)
		return expf(net) / 0.001f;
	else
		return result;
}
void Neuron::setOutput(float outputvalue)
{
	this->outputvalue = outputvalue;
}

float Neuron::ActivationFunc(float net, int index, bool state)
{
	if (index == 1)
	{
		if (state == true)
			return (1 - (net * net)) / 2;
		else if (state == false)
			return tanhf(net);
	}
	else if (index == 0)
	{
		float res = (1 / (1 + exp(-net)));
		if (state == true)
			return net * (1 - net);
		else
			return res;
	}
	else if (index == 2)
	{
		if (state == true)
		{
			if (net >= 0)
				return 1.0f;
			else
				return 0.01f;
		}
		else
		{
			if (net >= 0)
				return net;
			else if (net < 0)
				return 0.01 * net;
		}
	}
	else if (index == 4)
	{
		if (net > 0)
			return 1.0;
		else if (net < 0)
			return -1.0f;
	}
}