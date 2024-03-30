
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 21
#pragma warning(disable:4996) 

struct MyData {
	int howMany;
	char theText[MAX_SIZE];
	char directoryPath[MAX_SIZE];
	char filename[MAX_SIZE];
};
// initialized the structure

int main(int argc, char** argv) {
	if (argc != 5) {
		printf("invalid amount of arguments please enter exactly 4 arguments.");
		return 0;
		//if the user does not enter all the arguments it will quit the program
	}
	struct MyData myArgs;
	myArgs.howMany = atoi(argv[1]);
	strncpy(myArgs.theText, argv[2], sizeof(myArgs.theText) - 1);
	strncpy(myArgs.directoryPath, argv[3], sizeof(myArgs.directoryPath) - 1);
	strncpy(myArgs.filename, argv[4], sizeof(myArgs.filename) - 1);
	
	FILE* file;
	char nameAndPath[MAX_SIZE * 2];
	sprintf(nameAndPath, "%s/%s", myArgs.directoryPath, myArgs.filename);
	
	file = fopen(nameAndPath, "w");
		if (!file) {
		printf("unable to create a the file");
		return 0;
		
	}
	for (int i = 0; i < myArgs.howMany; i++) {
		fprintf(file, "%s\n", myArgs.theText);
		
	}
	fclose(file);
	
	printf("file has been successfully created at the specified destination");
	
	return 0;
}

