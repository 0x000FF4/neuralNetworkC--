/*
 * file_reader.cpp
 *
 *  Created on: 09.11.2013
 *      Author: x000ff4
 */

#include "file_reader.h"
#include <iostream>
#include <dirent.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
//#include <sndfile.h>
#include <cstring>
#include <math.h>
#include <limits.h>


int Load_Wave_File(char *fname ,unsigned int ** WavData) {
	FILE *fp;
	int errorCode;
	int i;
	int max;
	unsigned int * pWavData;
	int Flag;
	int status;
	double fs_hz;
	short int* pU;
	char * Buffer;
	unsigned char* pC;
	int bufferLength;
	int remainingSize;
	char readBuffer[80];
	long int maxInSamples;
	fp = fopen("cc.wav", "rb");
	struct WAV_HEADER wavHeader;
	struct DATA_HEADER dataHeader;
	max = 0;
	if (&wavHeader == NULL || &dataHeader == NULL) {
		printf("Can`t allocate space");
		return NULL;
	}
	if (fp == NULL) {
		printf("Can`t load file");
		return NULL;
	}
	errorCode = fread((void*) &wavHeader, sizeof(WAV_HEADER), (size_t) 1, fp);
	if (errorCode != STATUS_SUCCESS) {
		printf("Can`t read file");
		return NULL;
	}
	for (i = 0; i < 4; i++) {
		readBuffer[i] = wavHeader.ChunkID[i];
	}
	readBuffer[4] = '\0';
	if (strcmp(readBuffer, "RIFF") != 0) {
		printf("Not a RIFF format");
		return NULL;
	}
	for (i = 0; i < 4; i++) {
		readBuffer[i] = wavHeader.Format[i];
	}
	readBuffer[4] = '\0';
	if (strcmp(readBuffer, "WAVE") != 0) {
		printf("Not a WAVE format");
		return NULL;
	}
	for (i = 0; i < 4; i++) {
		readBuffer[i] = wavHeader.Subchunk1_ID[i];
	}
	readBuffer[4] = '\0';
	if (strcmp(readBuffer, "fmt ") != 0) {
		printf("Not a fmt format");
		return NULL;
	}
	if (wavHeader.AudioFormat != 1) {
		printf("Not a  format tag");
		return NULL;
	}

	if ((wavHeader.BitsPerSample != 16) && (wavHeader.BitsPerSample != 8)) {
		printf("Not a 16 or 8 bit format tag");
		return NULL;
	}
	remainingSize = wavHeader.Subchunk1_Size - (sizeof(WAV_HEADER) - 20);
	if (0 != fseek(fp, remainingSize, SEEK_CUR)) {
		printf("Can't seek.");
		return NULL;
	}
	Flag = 1;
	while (Flag != 0) {

		if (Flag > 10) {
			printf("\nToo manu chunks");
			exit(-1);
		}

		status = fread((void*) &dataHeader, sizeof(DATA_HEADER),
				(size_t) 1, fp);
		if (1 != status) {
			printf("\n I just can't read data. Sorry!");
			exit(-1);
		}
		for (i = 0; i < 4; i++) {
			readBuffer[i] = dataHeader.Subchunk2_id[i];
		}
		readBuffer[4] = '\0';
		if (strcmp(readBuffer, "data") == 0) {
			break;
		}
		Flag++;
		remainingSize = fseek(fp, dataHeader.Subchunk2_size, SEEK_CUR);
		if (remainingSize != 0) {
			printf("Can't seek.");
			return NULL;
		}

	}
	bufferLength = dataHeader.Subchunk2_size;

	maxInSamples = dataHeader.Subchunk2_size;
	maxInSamples /= wavHeader.BitsPerSample / 8;

	Buffer = new char[bufferLength];
	if (Buffer == NULL) {
		printf("\nCan't allocate.");
		return NULL;
	}
	pWavData=  static_cast<unsigned int*>(malloc(sizeof(unsigned int)*maxInSamples));
	if (WavData == NULL) {
		printf("Can't allocate\n");
		return NULL;
	}
	remainingSize = fread((void*) Buffer, bufferLength, (size_t) 1, fp);
	if (1 != remainingSize) {
		printf("\nCan't read buffer.");
		return NULL;
	}
	if (wavHeader.BitsPerSample == 16) {
		pU = (short*) Buffer;
		for (i = 0; i < maxInSamples; i++) {
			pWavData[i] =  (unsigned int)(pU[i]);
			int size =sizeof(unsigned int);
			double ddf = pWavData[i];
			double ff = ((ddf)-((double)UINT_MAX/2.0));
			double mm = (double)UINT_MAX/2.0;
			double dded = ff/mm;
			//printf("\n %d : %.20f",i , dded);
		}
	} else {
		pC = (unsigned char*) Buffer;
		for (i = 0; i < maxInSamples; i++) {
			pWavData[i]= (unsigned int) (pC[i]);
		}
	}
	free(Buffer);
	fclose(fp);
	*WavData = pWavData;
	return STATUS_SUCCESS;
}

