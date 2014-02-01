/*
 * neuron_linker.cpp
 *
 *  Created on: 05.11.2013
 *      Author: x000ff4
 */
#include "neuron_linker.h"
#include "neuron.h"
#include <vector>
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
NeuronLinker::NeuronLinker() {

}
void NeuronLinker::link_neurons(link_type type,  std::vector<NEURON*> &input,
		std::vector<std::vector<NEURON*> > &hidden,
		std::vector<NEURON*> &output) {
	unsigned int i;
	unsigned int j;
	unsigned int n;
	int size = 0;
	std::vector<NEURON*> hiddenLayer;
	std::vector<NEURON*> lastLayer;
	bool isFirst = true;
	switch (type) {
	case LINEAR_LINK:

		for (n =NEURONS_SIZE; n <  NEURONS_SIZE  + input.size(); n++) {
			input[n-NEURONS_SIZE]->inputs.push_back(n);
			input[n-NEURONS_SIZE]->input_multipler.push_back(0.1f);
			input[n-NEURONS_SIZE]->deltavalues.push_back(0.1f);

		}

		lastLayer = input;
		for (i = 0; i <  hidden.size(); i++) {

			if (isFirst) {
				hiddenLayer = hidden[i];

				std::cout << "size of hidden layer:" << hiddenLayer.size()
						<< std::endl;
				std::cout.flush();

				for (j = 0; j < hiddenLayer.size(); j++) {

					for (n = size; n < size + lastLayer.size(); n++) {
						hidden[i][j]->inputs.push_back(n);
						hidden[i][j]->deltavalues.push_back(0.1);
						hidden[i][j]->input_multipler.push_back(0.1);
						//std::cout << "inputs size:" << input[n].inputs.size() <<  std::endl;
						//	std::cout << "input_multipler size:" << input[n].input_multipler.size() <<  std::endl;
					}

				}
				size =n;
				isFirst = false;

				lastLayer = hidden[i];
			} else {
				hiddenLayer = hidden[i];

				for (j = 0; j < hiddenLayer.size() ; j++) {

					for (n = size; n <size + lastLayer.size(); n++) {
						hidden[i][j]->inputs.push_back(n);
						hidden[i][j]->deltavalues.push_back(0.1);
						hidden[i][j]->input_multipler.push_back(0.1);
						//std::cout << "inputs size:" << input[n].inputs.size() <<  std::endl;
						//	std::cout << "input_multipler size:" << input[n].input_multipler.size() <<  std::endl;
					}
				}
				size =n;
				lastLayer = hidden[i];
			}
		}
//		j = 0;
		for (i = 0; i < output.size(); i++) {
			for (j = size; j < size + lastLayer.size(); j++) {
				output[i]->inputs.push_back(j);
				output[i]->deltavalues.push_back(0.1);
				output[i]->input_multipler.push_back(0.1f);
			}

		}
		size +=n;
//		for(int i = 0 ; i < input.size();i++)
//		{
//		for (int n =0; n <   input[i].inputs.size(); n++) {
//
//			std:: cout << " n:" << n << "inputs" << input[i].inputs[n]<<std::endl;
//	    	std::cout.flush();
//		}
//		}
//		for (i = 0; i <  hidden[0].size(); i++) {
//			for(int j = 0; j < hidden[0][i].input_multipler.size(); j++)
//				{
//			std::cout << "hidden1 mult" << hidden[0][i].input_multipler[j]
//						<< std::endl;
//				std::cout.flush();
//		}
//		}
		break;
	case LINEAR_LINK_FEEDBACK:
		break;
	case RANDOM_LINK:
		break;
	case NETWORK_LINK:
		break;
	}
}

