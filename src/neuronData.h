/*
 * neuronData.h
 *
 *  Created on: 22.01.2014
 *      Author: x000ff4
 */

#ifndef NEURONDATA_H_
#define NEURONDATA_H_

class neuronData {
private:
	double sum;
	double momentum;
	double alpha;
public :
	neuronData(double sum, double momentum, double alpha);
	~neuronData();
	double getSum();
	double getMomentum();
	double getAlpha();
	void setSum(double sum);
	void setMomentum(double momentum);
	void setAlpha(double alpha);
};

#endif /* NEURONDATA_H_ */
