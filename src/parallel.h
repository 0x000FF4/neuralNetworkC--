/*
 * parallel.h
 *
 *  Created on: 03.11.2013
 *      Author: x000ff4
 */

#ifndef PARALLEL_H_
#define PARALLEL_H_

#include <fstream>

#include <vector>

#include "main_network.h"
#include <boost/thread.hpp>
#include <boost/bind/bind.hpp>
#include <boost/thread/mutex.hpp>
using namespace std;
class parallel {
private:
	double smallVector;
	int trainNeuron;
	unsigned int local_number;
	int note;
	std::vector<double> cc;
	boost::array<double, 3> old_colors;
	boost::array<double, 3> new_colors;
	int start_of_output_neurons;
	int neurons_per_note;
	int output_neurons_begin;
	int output_neurons_end;
	int neuron_list_begin;
	int neuron_list_end;
	int neuron_list_forbidden;
	boost::thread *m_Thread;
	static boost::mutex *pNumberMutex ;
	static boost::mutex *pMutex ;
	void compute(int numberOfThread);
	void random_weights();
public:
	std::vector<double> neuronTest;
	bool isThis;
	parallel(int neurons_per_note, int start_of_output_neurons,
			int output_neurons_begin, int output_neurons_end,
			unsigned int local_number);
	 parallel(const parallel& p);
	void set_neuron_list(int begin, int end, int forbidden);
	void start(int numberOfThread);
	void stop();

};

#endif /* PARALLEL_H_ */
