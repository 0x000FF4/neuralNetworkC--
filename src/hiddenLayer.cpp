/*
 * hiddenLayer.cpp
 *
 *  Created on: 19.01.2014
 *      Author: x000ff4
 */

#include "hiddenLayer.h"

#include <stddef.h>
#include <vector>

#include "main_network.h"

hiddenLayer::hiddenLayer(std::vector<NEURON*> neurons, int number, layer* layers) :
		layer(neurons, number, layers) {

	pF = NULL;
	m_Thread = NULL;
	sum = 0.0;
	errorg = 0.0;
	errorc = 0.0;
	csum = 0.0;
	delta = 0.0;
	udelta = 0.0;
	output = 0.0;
}

hiddenLayer::~hiddenLayer() {
}
double hiddenLayer::getNeuronDelta(int neuron) {
	return neuronDelta[neuron];
}
void hiddenLayer::train(neuronData &data) {
	for (unsigned int i = 0; i < neurons.size(); i++) {
		output = neurons[i]->output;
		double sum = 0;
		for (unsigned int j = 0; j < neurons.size(); j++) {
			neuronDelta[neurons[i]->inputs[j]] = 0;
		}

		sum = pervLayer->getNeuronDelta(neurons[i]->number);
		errorc = sum * neurons[i]->output * (1 - neurons[i]->output);
		for (unsigned int j = 0; j < neurons[i]->input_multipler.size(); j++) {
			neuronDelta[neurons[i]->inputs[j]] += neurons[i]->input_multipler[j]
					* errorc;

			//update weights
			neurons[i]->input_multipler[j] += data.getAlpha() * errorc
					* main_neuron_list[neurons[i]->inputs[j]].output;
//			neurons[i]->theta += -data.getAlpha() * errorc;

		}
	}
	data.setSum(csum);
	csum = 0;
}
