/*
 * layer.cpp
 *
 *  Created on: 20.01.2014
 *      Author: x000ff4
 */

#include "layer.h"

layer::layer(std::vector<NEURON*> neurons, int number, layer *layers) {
	this->neurons = neurons;
	pF = NULL;
	m_Thread = NULL;
	errorg = 0.0;
	errorc = 0.0;
	csum = 0.0;
	delta = 0.0;
	udelta = 0.0;
	output = 0.0;
	uniqueNumber = number;
	pervLayer = layers;
	int size = neurons[0]->inputs.size();
	layer::isReady.push_back(number);

}

layer::~layer() {
}
void layer::start(neuronData &data) {
	boost::thread m_Thread = boost::thread(
			boost::bind(&layer::compute, this, boost::ref(data)));
	this->m_Thread = &m_Thread;
}
std::vector<bool> layer::isReady;
void layer::compute(neuronData &data) {
	while (true) {
		if (isReady[uniqueNumber] == true) {
			for (unsigned int i = 0; i < neurons.size(); i++) {

				if (pF != NULL) {
					pF(i, *neurons[i]);
				}
				data.setSum(0);
				sum = 0;
				for (unsigned int j = 0; j < neurons[i]->inputs.size(); j++) {
					int size = neurons[i]->inputs.size();
					sum += (neurons[i]->input_multipler[j]/ neurons[i]->inputs.size())
								* main_neuron_list[neurons[i]->inputs[j]].output;
//					if(main_neuron_list[neurons[i]->inputs[j]].output == 0)
//					{
//							std::cout <<"inputs "<< 1.0 / (1.0 + exp(-sum))<< std::endl;
//									std::cout.flush();
//					}
					//	std::cout <<"inputs "<< neurons[i].inputs[j] << std::endl;
					//	std::cout.flush();

				}
				//sum += neurons[i]->theta;
//				if(uniqueNumber == 0)
//				{
//				std::cout << uniqueNumber << "  " << sum  << std::endl;
//				std::cout.flush();
//				}
				neurons[i]->output = 1.0 / (1.0 + exp(-sum));
				isReady[uniqueNumber] = false;
			}
		}
	}
}
void layer::alertNeuron(int (*f)(int posiiton, struct NEURON &neuron)) {
	this->pF = f;
}

