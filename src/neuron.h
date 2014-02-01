#ifndef NEURON_N
#define NEURON_N
#include <vector>

struct NEURON{
	std::vector<float> input_multipler;
	std::vector<int> inputs;
	std::vector<double> deltavalues;
	double output;
	double green;
	double red;
	double blue;
	double gain;
	double theta;
	double delta;
	int aa;
	int number;
};

#endif
