/*
 * neuronData.cpp
 *
 *  Created on: 22.01.2014
 *      Author: x000ff4
 */


#include "neuronData.h"

neuronData::neuronData(double sum, double momentum, double alpha)
{

	this->sum = sum;
	this->momentum =  momentum;
	this->alpha = alpha;
}
double neuronData::getSum()
{
	return sum;
}
double neuronData::getMomentum()
{
	return momentum;
}
double neuronData::getAlpha()
{
	return alpha;
}
void neuronData::setSum(double sums)
{
	sum = sums;
}
void neuronData::setMomentum(double momentums)
{
	momentum = momentums;
}
void neuronData::setAlpha( double alphas)
{
	alpha = alphas;
}
neuronData::~neuronData()
{

}
