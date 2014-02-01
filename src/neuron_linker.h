/*
 * neuron_linker.h
 *
 *  Created on: 05.11.2013
 *      Author: x000ff4
 */

#ifndef NEURON_LINKER_H_
#define NEURON_LINKER_H_

#include "main_network.h"
class NeuronLinker {
private:

public:
	 NeuronLinker();
	enum link_type {
		LINEAR_LINK, LINEAR_LINK_FEEDBACK, RANDOM_LINK, NETWORK_LINK, RECURSIVE_LINK
	};
	void link_neurons(link_type type, std::vector<NEURON*> &input,
			std::vector<std::vector<NEURON*> > &hidden, std::vector<NEURON*> &output);
};

#endif /* NEURON_LINKER_H_ */
