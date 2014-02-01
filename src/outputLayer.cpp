/*
 * outputLayer.cpp
 *
 *  Created on: 20.01.2014
 *      Author: x000ff4
 */
#include "outputLayer.h"

outputLayer::outputLayer(std::vector<NEURON*> neurons,
		std::vector<double> inputs, int number) :
		layer(neurons, number, NULL) {

	pF = NULL;
	m_Thread = NULL;
	sum = 0.0;
	errorg = 0.0;
	errorc = 0.0;
	csum = 0.0;
	delta = 0.0;
	udelta = 0.0;
	output = 0.0;
	input = inputs;
	int size = inputs.size();
}

outputLayer::~outputLayer() {
}

double outputLayer::getNeuronDelta(int neuron) {
	return neuronDelta[neuron];
}

void outputLayer::train(neuronData &data) {
	data.setSum(0);
	for (unsigned int i = 0; i < neurons.size(); i++) {
		for (unsigned int j = 0; j < neurons[i]->input_multipler.size(); j++) {
			neuronDelta[neurons[i]->inputs[j]] = 0;
		}
	}
	for (unsigned int i = 0; i < neurons.size(); i++) {
		output = neurons[i]->output;
		errorc = (input[i] - output) * output * (1 - output);
//		if (i == 10) {
//			std::cout << "output" << errorc << std::endl;
//
//			std::cout.flush();
//		}
		for (unsigned int j = 0; j < neurons[i]->input_multipler.size(); j++) {
			if (i == 10 && j == 10) {

				//std::cout << "target" <<output<< "output"<< 	 errorc  <<std::endl;
				std::cout.flush();
			}
			neuronDelta[neurons[i]->inputs[j]] += neurons[i]->input_multipler[j]
					* errorc;
			neurons[i]->input_multipler[j] += data.getAlpha() * errorc
					* main_neuron_list[neurons[i]->inputs[j]].output;
		}
//		neurons[i]->theta +=
//				-data.getAlpha()*errorc;
	}
}
