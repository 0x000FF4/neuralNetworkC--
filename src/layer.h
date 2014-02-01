/*
 * layer.h
 *
 *  Created on: 20.01.2014
 *      Author: x000ff4
 */

#ifndef LAYER_H_
#define LAYER_H_
#include "main_network.h"
#include "neuronData.h"
#include "boost/thread/thread.hpp"
#include <boost/thread/thread.hpp>
#include "neuron.h"
#include <boost/thread.hpp>
#include <boost/bind/bind.hpp>
#include <boost/thread/mutex.hpp>
class layer
{
protected:
	std::vector<NEURON*> neurons;
	int uniqueNumber;
	int (*pF)(int position, struct NEURON &neuron);
	double sum;
	boost::thread *m_Thread;
	double errorg;
	double errorc;
	double csum ;
	double delta;
	double udelta;
	double output;
	neuronData *data;
	void   compute(neuronData &data);
	std::map<int ,double> neuronDelta;
	layer *pervLayer  ;
private:


public:
	virtual double getNeuronDelta(int neuron) = 0;
	static std::vector<bool> isReady;
	virtual void train(neuronData &data) = 0;
	void alertNeuron(int (*f)(int position, struct NEURON &neuron));
	layer(std::vector<NEURON*> neurons, int number, layer *layers );
	virtual ~layer();
	void start(neuronData &data);

};



#endif /* LAYER_H_ */
