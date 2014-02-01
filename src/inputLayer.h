/*
 * inputLayer..h
 *
 *  Created on: 19.01.2014
 *      Author: x000ff4
 */

#ifndef INPUTLAYER__H_
#define INPUTLAYER__H_

#include "neuron.h"
#include "layer.h"
#include <boost/thread.hpp>
#include <boost/bind/bind.hpp>
#include <boost/thread/mutex.hpp>
class inputLayer : public layer {
private:
	std::vector<double> input;
public:
	double getNeuronDelta(int neuron);
	void train(neuronData &data) override;
	void alertNeuron(int (*f)(int position, struct NEURON &neuron));
	inputLayer(std::vector<NEURON*> const neurons , std::vector<double> inputs, int number, layer * layers);
	~inputLayer();


};

#endif /* INPUTLAYER__H_ */
