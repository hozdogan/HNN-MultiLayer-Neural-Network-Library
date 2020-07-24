#pragma once
#ifndef LAYER_H
#define LAYER_H
#include<vector>
#include "Neuron.h"
class Layer
{
public:	
	Layer(int,int,int);
	Neuron* getNeuron(int index);
	int getSize();
	float getThreshold();
	void setThreshold();

private:
	bool isOutputLayer; int NeuronSize;
	float Threshold;
	std::vector<Neuron*> Neurons;
	Neuron* neuron;
};





#endif