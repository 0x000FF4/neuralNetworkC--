/*
 * outputLayer.h
 *
 *  Created on: 20.01.2014
 *      Author: x000ff4
 */

#ifndef OUTPUTLAYER_H_
#define OUTPUTLAYER_H_


#include "neuron.h"
#include "layer.h"
#include <map>
#include <boost/thread.hpp>
#include <boost/bind/bind.hpp>
#include <boost/thread/mutex.hpp>
class outputLayer : public layer{
private:
	std::vector<double> input;

public:
	double getNeuronDelta(int neuron);
	void train(neuronData& data) override;
	outputLayer(std::vector<NEURON*> const neurons, std::vector<double> inputs, int number);
	~outputLayer();


};




#endif /* OUTPUTLAYER_H_ */
