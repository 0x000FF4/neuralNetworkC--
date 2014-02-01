/*
 * file_reader.h
 *
 *  Created on: 08.11.2013
 *      Author: x000ff4
 */

#ifndef FILE_READER_H_
#define FILE_READER_H_
#include <vector>
#include <string>
#define STATUS_SUCCESS 1
struct WAV_HEADER{
    char ChunkID[4];
     int ChunkSize;
    char Format[4];
    char Subchunk1_ID[4];
     int Subchunk1_Size;
    short int AudioFormat;
    short int NumChannels;
     int SampleRare;
     int ByteRate;
    short int BlockAling;
    short int BitsPerSample;
};
struct DATA_HEADER{
	char Subchunk2_id[4];
	 int Subchunk2_size;
};
bool prase_file();

int Load_Wave_File(char *fname,unsigned int  ** WavData) ;
#endif /* FILE_READER_H_ */
