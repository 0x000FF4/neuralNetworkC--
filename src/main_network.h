/*
 * main_network.h
 *
 *  Created on: 03.11.2013
 *      Author: x000ff4
 */

#ifndef MAIN_NETWORK_H_
#define MAIN_NETWORK_H_
#include <pthread.h>
#include <string>
#include <boost/lockfree/stack.hpp>
#include "neuron.h"
extern bool *is_output_done;
const int NEURONS_SIZE = 860;
const int INPUT_SIZE = NEURONS_SIZE * 0.3;
extern std::vector<std::string> note_list;
extern pthread_rwlock_t lock;
extern std::vector<NEURON> main_neuron_list;
extern std::vector<double> main_note_output;
extern std::vector<bool> main_note_output_lock;
extern boost::lockfree::stack<double> stack;
extern std::vector<double> targetOutput;
#endif /* MAIN_NETWORK_H_ */
