/*
 * hiddenLayer.h
 *
 *  Created on: 19.01.2014
 *      Author: x000ff4
 */

#ifndef HIDDENLAYER_H_
#define HIDDENLAYER_H_

#include "neuron.h"
#include "layer.h"
#include "neuronData.h"
#include <boost/thread.hpp>
#include <boost/bind/bind.hpp>
#include <boost/thread/mutex.hpp>
class hiddenLayer : public layer {
private:

public:
	double getNeuronDelta(int neuron);
	void train(neuronData &data) override;
	void alertNeuron(int (*f)(int position, struct NEURON &neuron));
	hiddenLayer(std::vector<NEURON*> const neurons , int number , layer * layer);
	~hiddenLayer();


};



#endif /* HIDDENLAYER_H_ */
