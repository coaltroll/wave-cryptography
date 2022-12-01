#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

#include "wavHeader.h"
#include "messageHeader.h"
#include "chacha.h"
#include "menuGUI.h"
#include "encoder.h"
#include "util.h"

#define LIGHTBLUE_TEXT "\033[34;1m"
#define RESET_COLOR "\033[0m"


void createNewWave() {
	FILE* pWavEncoded = fopen("../AudioFiles/wavEncoded.wav", "wb");
	fclose(pWavEncoded);
}

void printb(char binary) {
	for (int i = 0; i < 8; i++) {
		printf("%x", ((binary << i) & 0xff) >> 7);
	}
}

int listDirectoryContents(char* sDir) {
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;

	char sPath[2048];

	//Specify a file mask. *.* = We want everything!
	sprintf(sPath, "%s\\*.*", sDir);

	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		printf("Path not found: [%s]\n", sDir);
		return 0;
	}

	do
	{
		//Find first file will always return "."
		//    and ".." as the first two directories.
		if (strcmp(fdFile.cFileName, ".") != 0
			&& strcmp(fdFile.cFileName, "..") != 0)
		{
			//Is the entity a File or Folder?
			if (fdFile.dwFileAttributes &FILE_ATTRIBUTE_DIRECTORY)
			{
				printf(LIGHTBLUE_TEXT);
				printf("%s/    ", fdFile.cFileName);
			}
			else {
				printf(RESET_COLOR);
				printf("%s    ", fdFile.cFileName);
			}
		}
	} while (FindNextFile(hFind, &fdFile)); //Find the next file.

	FindClose(hFind); //Always, Always, clean things up!

	printf(RESET_COLOR);
	return 1;
}


int main() {
	
	/* List Directories
	
	//char path[] = "C:/Users/mortaza.ebeid/Documents/prog/c/wave-cryptography";
	char path[] = "C:/Users/theodor.kohler/Documents/Programmering/wave-cryptography/demo.txt";
	listDirectoryContents(path);
	*/


	// GUI menu
	// int nothing = GUIMenu();



	// Filepaths

	/* Morti paths 
	char containerFilepath[] = "C:/Users/mortaza.ebeid/Documents/prog/c/wave-cryptography/AudioFiles/BabyElephantWalk60.wav"; // !!! Change to real location after compiling code !!!
	char messageFilepath[] = "C:/Users/mortaza.ebeid/Documents/prog/c/wave-cryptography/demo.txt";
	*/

	/* Theo Paths */
	char containerFilepath[] = "C:/Users/theodor.kohler/Documents/Programmering/wave-cryptography/AudioFiles/BabyElephantWalk60.wav"; // !!! Change to real location after compiling code !!!
	char messageFilepath[] = "C:/Users/theodor.kohler/Documents/Programmering/wave-cryptography/demo.txt";
	

	/* Make WAV struct and Message struct
	
	// Read in target file and construct header
	struct WavHeader containerHeader;
	createContainerHeaderStruct(&containerHeader, containerFilepath);
	

	// Read in message file and construct header
	struct MessageHeader messageHeader;
	createMessageHeaderStruct(&messageHeader, messageFilepath, sizeof(messageFilepath));
	printMessageHeaderStruct(&messageHeader);
	*/

	
	/* Read message and target file
	
	// Read in message file and message file length
	unsigned int messageDataLength = fileLength(messageFilepath);
	char* pMessageData = (char*)malloc(messageDataLength);
	readInMessageData(pMessageData, messageFilepath);

	// Read in target file and target file length
	unsigned int targetDataLength = fileLength(targetFilepath);
	char* pTargetData = (char*)malloc(targetDataLength);
	readInTargetData(pTargetData, targetFilepath, targetHeader.subChunk2Size);
	*/


	/*
	// encoder
	unsigned char data[16] = {[0 ... 15] = 0x00};
	unsigned char message[] = {0xff, 0xff};
	int sampleSize = 2;
	int bitsPerByte = 2;

	printf("input data: \n");
	for(int i = 0; i < sizeof(data); i++){
		printb(data[i]);
		printf("\n");
	}
	printf("\n");

	printf("input message: \n");
	for(int i = 0; i < sizeof(message); i++){
		printb(message[i]);
		printf("\n");
	}
	printf("\n");

	printf("sample size: %d \n", sampleSize);
	printf("bits per byte: %d \n\n", bitsPerByte);

	encodeMessage(&data, sizeof(data), sampleSize, bitsPerByte, &message, sizeof(message));


	printf("output data: \n");
	for(int i = 0; i < sizeof(data); i++){
		printb(data[i]);
		printf("\n");
	}
	*/


	/*
	// chacha20 test
	uint8_t plainText[] = "Ladies and Gentlemen of the class of '99: If I could offer you only one tip for the future, sunscreen would be it.";
	int key[] = {
		0x03020100, 0x07060504, 0x0b0a0908, 0x0f0e0d0c,
		0x13121110, 0x17161514, 0x1b1a1918, 0x1f1e1d1c
		};
	int counter[] = {0x00000001};
	int nonce[] = {0x00000000, 0x4a000000, 0x00000000};

	//Printing original array
	for(int b = 0; b < 114; b++){
		printf("%x ", plainText[b]);
		if((b + 1) % 16 == 0 && b != 0) printf("\n");
	}

	chacha20(&plainText, 114, &key, &counter, &nonce);
	printf("\n\n");

	//Printing encrypted array
	for(int a = 0; a < 114; a++) {
		printf("%x ", plainText[a]);
		if((a + 1) % 16 == 0 && a != 0) printf("\n");
	}

	chacha20(&plainText, 114, &key, &counter, &nonce);
	printf("\n\n");

	//Printing decrypted array
	for(int a = 0; a < 114; a++) {
		printf("%x ", plainText[a]);
		if((a + 1) % 16 == 0 && a != 0) printf("\n");
	}
	*/

	//free(pMessageData);
	//free(pTargetData);
	return 0;
}
