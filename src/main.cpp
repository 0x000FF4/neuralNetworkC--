//============================================================================
// Name        : gre.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <QtGui>
#include <QApplication>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <boost/thread.hpp>
#include <boost/bind/bind.hpp>
#include <fcntl.h>
#include <pthread.h>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>
#include <boost/thread.hpp>
#include "/usr/include/stdlib.h"
#include "file_reader.h"
#include "main_network.h"
#include "neuron.h"
#include "neuron_linker.h"
#include "parallel.h"
#include "neuronData.h"
#include "inputLayer.h"
#include "hiddenLayer.h"
#include "outputLayer.h"
#include "layer.h"

using namespace std;

int main() {

	int end_neurons_per_thread;
	bool first_negative = true;
	unsigned int * aa;
	unsigned int ** WavData = &aa;
//	/int isSS = isatty(std::cout);
	std::cout << "dd";
	cout.flush();
	printf("df");
	Load_Wave_File(NULL, WavData);
	std::vector<NEURON> list;
	std::vector<double> desOutput;
	int thread_count;
	int count = 0;
	int forbidden_neurons;
	int sheet[] = { 64, 63, 64, 63, 64, 59, 62, 60, 57, 48, 52, 57, 59, 52, 56,
			59, 60, 48, 52, 57, 59, 52, 56, 59, 60, 52, 64, 51, 64, 51, 64, 59,
			62, 60, 57, 48, 52, 57, 59, 52, 60, 59, 57 };
	neuronData data(0.0, 0.1, 0.2);
	vector<parallel> parallel_array;
	int i = 0;
	int j = 0;
	int countIntr = 0;
	std::vector<NEURON>::iterator it = main_neuron_list.begin();
	for (i = 0; i < NEURONS_SIZE; i++) {
		NEURON neuron;
		neuron.theta = 0;
		neuron.number = i;
		it = main_neuron_list.insert(it, neuron);
	}
	for (i = 0; i < INPUT_SIZE; i++) {
		NEURON neuron;
		neuron.theta = 0;
		neuron.output = 1;
		it = main_neuron_list.insert(it, neuron);
	}

	std::vector<double> inputs;
	std::vector<NEURON*> inputNeurons;
	std::vector<NEURON*> hiddenNeurons1;
	std::vector<NEURON*> hiddenNeurons2;
	std::vector<NEURON*> hiddenNeurons3;
	std::vector<NEURON*> hiddenNeurons4;
	std::vector<NEURON*> hiddenNeurons5;
	std::vector<NEURON*> hiddenNeurons6;
	std::vector<NEURON*> hiddenNeurons7;
	std::vector<NEURON*> hiddenNeurons8;
	std::vector<NEURON*> hiddenNeurons9;
	std::vector<NEURON*> hiddenNeurons10;
	std::vector<NEURON*> outputNeurons;
	cout << NEURONS_SIZE * 0.25;
	for (i = 0; i < (NEURONS_SIZE) * 0.05; i++, j++) {
		inputNeurons.push_back(&main_neuron_list[j]);
	}
	for (i = 0; i < (NEURONS_SIZE) * 0.09; i++, j++) {
		hiddenNeurons1.push_back(&main_neuron_list[j]);
	}
	for (i = 0; i < (NEURONS_SIZE) * 0.09; i++, j++) {
		hiddenNeurons2.push_back(&main_neuron_list[j]);
	}
	for (i = 0; i < (NEURONS_SIZE) * 0.09; i++, j++) {
		hiddenNeurons3.push_back(&main_neuron_list[j]);
	}
	for (i = 0; i < (NEURONS_SIZE) * 0.09; i++, j++) {
		hiddenNeurons4.push_back(&main_neuron_list[j]);
	}
	for (i = 0; i < (NEURONS_SIZE) * 0.09; i++, j++) {
		hiddenNeurons5.push_back(&main_neuron_list[j]);
	}
	for (i = 0; i < (NEURONS_SIZE) * 0.09; i++, j++) {
		hiddenNeurons6.push_back(&main_neuron_list[j]);
	}

	for (i = 0; i < (NEURONS_SIZE) * 0.09; i++, j++) {
		hiddenNeurons7.push_back(&main_neuron_list[j]);
	}
	for (i = 0; i < (NEURONS_SIZE) * 0.09; i++, j++) {
		hiddenNeurons8.push_back(&main_neuron_list[j]);

	}
	for (i = 0; i < (NEURONS_SIZE) * 0.09; i++, j++) {
		hiddenNeurons9.push_back(&main_neuron_list[j]);
	}
	for (i = 0; i < (NEURONS_SIZE) * 0.09; i++, j++) {
		hiddenNeurons10.push_back(&main_neuron_list[j]);
	}
	for (i = 0; i < (NEURONS_SIZE) * 0.05; i++, j++) {
		outputNeurons.push_back(&main_neuron_list[j]);
	}
	std::vector<std::vector<NEURON*> > hiddenNeurons;
	hiddenNeurons.push_back(hiddenNeurons1);
	hiddenNeurons.push_back(hiddenNeurons2);
	hiddenNeurons.push_back(hiddenNeurons3);
	hiddenNeurons.push_back(hiddenNeurons4);
	hiddenNeurons.push_back(hiddenNeurons5);
	hiddenNeurons.push_back(hiddenNeurons6);
	hiddenNeurons.push_back(hiddenNeurons7);
	hiddenNeurons.push_back(hiddenNeurons8);
	hiddenNeurons.push_back(hiddenNeurons9);
	hiddenNeurons.push_back(hiddenNeurons10);
	NeuronLinker neuronLinker;
	cout << "Building neurons" << endl;
	cout.flush();
	std::vector<parallel>::iterator it_parallel = parallel_array.begin();
	cout << hiddenNeurons1[0]->input_multipler.size() << endl;
	cout << "end of building neurons";
	cout.flush();

	neuronLinker.link_neurons(neuronLinker.LINEAR_LINK, inputNeurons,
			hiddenNeurons, outputNeurons);
//	for (i = 0; i <  inputNeurons.size(); i++) {
//		for(int j = 0; j <inputNeurons[i].input_multipler.size(); j++)
//			{
//		std::cout << "inputNeurons mult" << inputNeurons[i].input_multipler[j]
//					<< std::endl;
//		std::cout << "inputNeurons inp" <<inputNeurons[i].inputs[j]
//							<< std::endl;
//			std::cout.flush();
//	}
//	}
//	for (i = 0; i <  hiddenNeurons[0].size(); i++) {
//		for(int j = 0; j < hiddenNeurons[0][i].input_multipler.size(); j++)
//			{
//		std::cout << "hidden0 mult" << hiddenNeurons[0][i].input_multipler[j]
//					<< std::endl;
//		std::cout << "hidden0 inp" << hiddenNeurons[0][i].inputs[j]
//							<< std::endl;
//			std::cout.flush();
//	}
//	}
//	for (i = 0; i <  hiddenNeurons[1].size(); i++) {
//			for(int j = 0; j < hiddenNeurons[1][i].input_multipler.size(); j++)
//				{
//			std::cout << "hidden1 mult" << hiddenNeurons[1][i].input_multipler[j]
//						<< std::endl;
//			std::cout << "hidden1 inp" << hiddenNeurons[1][i].inputs[j]
//								<< std::endl;
//				std::cout.flush();
//		}
//		}
//	for (i = 0; i < outputNeurons.size(); i++) {
//			for(int j = 0; j < outputNeurons[i].input_multipler.size(); j++)
//				{
//			std::cout << "output mult" << outputNeurons[i].input_multipler[j]
//						<< std::endl;
//			std::cout << "output inp" << outputNeurons[i].inputs[j]
//								<< std::endl;
//				std::cout.flush();
//		}
//		}
//		unsigned int * dataSound = *WavData;
//	for (i = 0; i < (NEURONS_SIZE - INPUT_SIZE) * 0.15; i++) {
//		targetOutput.push_back(
//				(((double) (dataSound[i]) - ((double) UINT_MAX / 2))
//						/ ((double) UINT_MAX / 2.0)));
//		//main_neuron_list[i].output =( rand()%100/100.0) ;
//	}

//
	for (i = 0; i < (NEURONS_SIZE) * 0.05; i++) {
		targetOutput.push_back((sheet[i] / 63.0) - 1);
	}
	for (i = 0; i < targetOutput.size(); i++) {
		inputs.push_back(1);
	}

	outputLayer outputLayers(outputNeurons, targetOutput, 11);
	hiddenLayer hiddenLayer10(hiddenNeurons[9], 10, &outputLayers);
	hiddenLayer hiddenLayer9(hiddenNeurons[8], 9, &hiddenLayer10);
	hiddenLayer hiddenLayer8(hiddenNeurons[7], 8, &hiddenLayer9);
	hiddenLayer hiddenLayer7(hiddenNeurons[6], 7, &hiddenLayer8);
	hiddenLayer hiddenLayer6(hiddenNeurons[5], 6, &hiddenLayer7);
	hiddenLayer hiddenLayer5(hiddenNeurons[4], 5, &hiddenLayer6);
	hiddenLayer hiddenLayer4(hiddenNeurons[3], 4, &hiddenLayer5);
	hiddenLayer hiddenLayer3(hiddenNeurons[2], 3, &hiddenLayer4);
	hiddenLayer hiddenLayer2(hiddenNeurons[1], 2, &hiddenLayer3);
	hiddenLayer hiddenLayer1(hiddenNeurons[0], 1, &hiddenLayer2);
	inputLayer inputLayer(inputNeurons, inputs, 0, &hiddenLayer1);

	inputLayer.start(data);
	hiddenLayer1.start(data);
	hiddenLayer2.start(data);
	hiddenLayer3.start(data);
	hiddenLayer4.start(data);
	hiddenLayer5.start(data);
	hiddenLayer6.start(data);
	hiddenLayer7.start(data);
	hiddenLayer8.start(data);
	hiddenLayer9.start(data);
	hiddenLayer10.start(data);
	outputLayers.start(data);
	j = 0;
//
//	for (i = 0; i <  hiddenNeurons[0].size(); i++) {
//		cout << "hidden1 mult" << hiddenNeurons[0][i].input_multipler.size()
//				<< endl;
//		cout.flush();
//	}
//	for (i = 0; i < hiddenNeurons2.size(); i++) {
//		cout << "hidden2 mult" << hiddenNeurons[1][i].input_multipler.size()
//				<< endl;
//		cout.flush();
//	}
//	for (i = 0; i < outputNeurons.size(); i++) {
//		for (int j = 0; j < outputNeurons[i].inputs.size(); j++)
//
//		{
//			cout << "outputNeurons mult"
//					<< outputNeurons[i].inputs[j] << endl;
//			cout.flush();
//		}
//	}
	while (true) {

		if (countIntr < 5000) {
			for (i = 0; i < layer::isReady.size(); i++) {
				if (layer::isReady[i] == false) {
					j++;
					continue;
				}
			}

			if (j == layer::isReady.size()) {
				count++;
				if (count == 12) {
					countIntr++;

					cout << i << " outputNeurons 0" << outputNeurons[0]->output
							<< endl;
					cout << i << " outputNeurons 1" << outputNeurons[1]->output
							<< endl;
					cout << i << " outputNeurons 2" << outputNeurons[2]->output
							<< endl;
					cout << i << " outputNeurons 3" << outputNeurons[3]->output
							<< endl;
					cout << i << " outputNeurons 4" << outputNeurons[4]->output
							<< endl;

					cout << i << " outputNeurons 5" << outputNeurons[5]->output
							<< endl;
					cout.flush();

					outputLayers.train(data);
					hiddenLayer1.train(data);
					hiddenLayer2.train(data);
					hiddenLayer3.train(data);
					hiddenLayer4.train(data);
					hiddenLayer5.train(data);
					hiddenLayer6.train(data);
					hiddenLayer7.train(data);
					hiddenLayer8.train(data);
					hiddenLayer9.train(data);
					hiddenLayer10.train(data);
					inputLayer.train(data);

					for (i = 0; i < layer::isReady.size(); i++) {
						layer::isReady[i] = true;
					}
					j = 0;
					count = 0;
				}
			} else {

				j = 0;
			}
		} else {
			for (i = 0; i < layer::isReady.size(); i++) {
				if (layer::isReady[i] == false) {
					j++;
					continue;
				}
			}

			if (j == layer::isReady.size()) {
				count++;
				if (count == 5) {
					int n = 0;
//					for (i = NEURONS_SIZE, n = 0; i < INPUT_SIZE + NEURONS_SIZE;
//							i++, n++) {
//						main_neuron_list[i].output =(i - NEURONS_SIZE) /12
//					}

					cout
							<< "--------------------------------------------------------------"
							<< endl;
					cout.flush();
					for (int i = 0; i < outputNeurons.size(); i++) {
						cout << i << "---"
								<< (outputNeurons[i]->output + 1) * 64 << endl;
					}

					for (i = 0; i < layer::isReady.size(); i++) {
						layer::isReady[i] = true;
					}
					j = 0;
					count = 0;
				}
			} else {
				j = 0;
			}
		}
	}

	return 0;
}
