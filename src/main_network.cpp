/*
 * main_network.cpp
 *
 *  Created on: 05.11.2013
 *      Author: x000ff4
 */

#include "main_network.h"
std::vector<std::string> note_list;
pthread_rwlock_t lock;
std::vector<NEURON> main_neuron_list;
std::vector<double> main_note_output(128);
std::vector<bool> main_note_output_lock(128);
boost::lockfree::stack<double> stack(80);
std::vector<double> targetOutput;
bool *is_output_done;

