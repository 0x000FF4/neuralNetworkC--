/*
 * parallel.cpp
 *
 *  Created on: 03.11.2013
 *      Author: x000ff4
 */

#include "parallel.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>
boost::mutex *mutex = new boost::mutex();
boost::mutex *parallel::pMutex = mutex;
boost::mutex *parallel::pNumberMutex = new boost::mutex();
parallel::parallel(int neurons_per_note, int start_of_output_neurons,
		int output_neurons_begins, int output_neurons_end,
		unsigned int local_number) {
	this->local_number = local_number;
	this->start_of_output_neurons = start_of_output_neurons;
	this->neurons_per_note = neurons_per_note;
	this->neuron_list_begin = 0;
	this->neuron_list_end = 0;
	output_neurons_begin = output_neurons_begins;

	cout << flush;
	cc.push_back(0.0);
	this->output_neurons_end = output_neurons_end;
	if (local_number == 0) {
		boost::mutex *mutex = new boost::mutex();
		parallel::pMutex = mutex;
		parallel::pNumberMutex = new boost::mutex();
	}
}

parallel::parallel(const parallel& p) {

}

void parallel::random_weights() {
	std::ifstream secure_stream;
	int neuronSize = main_neuron_list.size();
	char * secure_char;
	secure_char = (char*) malloc(4);
	secure_stream.open("/dev/random", ios::binary);

	for (int i = 0; i < 3; i++) {
		secure_stream.readsome(secure_char, 4);
		//*secure_char = (*secure_char)/256;
		old_colors[i] = *secure_char;
		old_colors[i] = old_colors[i] / 256.0;
	}

}
void parallel::set_neuron_list(int begin, int end, int forbidden) {
	this->neuron_list_begin = begin;
	this->neuron_list_end = end;
	this->neuron_list_forbidden = forbidden;
	new_colors = { {0,0,0}};
	old_colors = { {0,0,0}};
	for (int i = begin + forbidden; i < end; i++) {
		cc.push_back(0.0);
	}
	random_weights();
}

void parallel::start(int numberOfThead) {

	boost::thread m_Thread = boost::thread(
			boost::bind(&parallel::compute, this, numberOfThead));
	this->m_Thread = &m_Thread;     // don`t touch magic
}

void parallel::stop() {
	this->m_Thread->join();
}

void parallel::compute(int numberOfThread) {
	int i = 0;
	double errorg = 0.0;
	double output = 0.0;
	double errorc = 0.0;
	double delta = 0.0;
	double udelta = 0.0;
	int locked_notes = 0;
	unsigned int j = 0;
	int m = 0;
	double current_output = 0.0;
	while (true) {
		for (i = neuron_list_begin + neuron_list_forbidden; i < neuron_list_end;
				i++) {
			current_output = 0;
			for (j = 0; j < main_neuron_list[i].input_multipler.size(); j++) {

				current_output += pow(
						main_neuron_list[main_neuron_list[i].inputs[j]].output
								- main_neuron_list[i].input_multipler[j], 2);

			}

			current_output = sqrt(current_output);

			cc[i - (neuron_list_begin + neuron_list_forbidden)] =
					current_output;

			main_neuron_list[i].output = pow(M_E,
					-pow((current_output * 1), 2));
			//printf("\n mm  %.20f",main_neuron_list[i].output);
		}

		smallVector = cc[0];
		trainNeuron = 0 + (neuron_list_begin + neuron_list_forbidden);

		for (i = 0; i < cc.size(); i++) {
			if (smallVector > cc[i]) {
				smallVector = cc[i];
				trainNeuron = i + (neuron_list_begin + neuron_list_forbidden);
			}
		}
		trainNeuron = 0 + (neuron_list_begin + neuron_list_forbidden);
		if (main_neuron_list[trainNeuron].input_multipler.size() > 18) {
			int sizeOfNeurons =
					rand()
							% (main_neuron_list[trainNeuron].input_multipler.size()
									- 18);

			for (i = sizeOfNeurons; i < sizeOfNeurons + 18; i++) {

				if (!stack.empty()) {
					double someDouble = 0.0;
					if (!stack.pop(someDouble)) {

						break;				// the matrix
					}
					main_neuron_list[trainNeuron].input_multipler[i] =
							someDouble;
				}
			}
		}

		pMutex->lock();

		is_output_done[numberOfThread] = false;
		for (int n = output_neurons_begin; n < this->output_neurons_end; n++) {

			int b = this->output_neurons_begin;
			int lock_i = (int) floor(
					(n - this->start_of_output_neurons)
							/ this->neurons_per_note);

			main_note_output[lock_i] += main_neuron_list[n].output
					* (1.0 / this->neurons_per_note);
			if (lock_i
					< (int) floor(
							((n + 1) - this->start_of_output_neurons)
									/ this->neurons_per_note)) {
				main_note_output_lock[lock_i] = true;
			}
		}
		for (int n = output_neurons_begin; n < output_neurons_end; n++) {
			output = current_output;
			errorc = (targetOutput[n] - output) * output * (1 - output);
			errorg+=(targetOutput[n] - output) * (targetOutput[n] - output) ;
		      for(unsigned int j=0;j<main_neuron_list[n].inputs.size();j++)
		        {
		            //get the current delta value
		    	  	main_neuron_list[n].deltavalues[j];
		            delta=main_neuron_list[n].deltavalues[j];
		            //update the delta value

		        }



		}
		pMutex->unlock();
		while (true) {
			pMutex->lock();

			if (is_output_done[numberOfThread]) {

				pMutex->unlock();

				break;
			}

			locked_notes = 0;
			for (i = 0; i < 128; i++) {
				if (main_note_output_lock[i] == true) {
					locked_notes += 1;
				}
			}

			if (locked_notes == 128) {

				for (int k = 0; k < 127; k++) {
					double output = main_note_output[k];
					stack.push(output*12);
					printf("\n s : %.20f", output * 12);
					if (output != 0) {
						while (output< 1) {
							output*= 10.0f;
						}
					}

				}
				for (i = 0; i < 128; i++) {
					main_note_output[i] = 0;
					main_note_output_lock[i] = false;
				}
				for (i = 0; i < 8; i++) {
					is_output_done[i] = true;
				}

			}
			pMutex->unlock();
		}
	}

}

