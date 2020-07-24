#include<iostream>
#include<cstdlib>
#include<string.h>
#include<cmath>
#include<time.h>
#include "Neuron.h"
#include"Layer.h"

using namespace std;

Layer::Layer(int NeuronSize,int AFindex,int prevLayerInputSize)//fully connected
{
	
	this->NeuronSize = NeuronSize;
	
	for (int i = 0; i < NeuronSize; i++)
	{
		neuron = new Neuron(i,prevLayerInputSize);
		neuron->SetActivationFunction(AFindex);
		neuron->setRandomWeights();
		Neurons.push_back(neuron);
		this->setThreshold();
	}
}
Neuron* Layer::getNeuron(int index)
{
	return Neurons.at(index);
}
int Layer::getSize()
{
	return Neurons.size();
}
float Layer::getThreshold()
{
	return Threshold;
}
void Layer::setThreshold()
{
	Threshold = 1.0f;
}