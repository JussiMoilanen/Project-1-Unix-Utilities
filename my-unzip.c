#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

int main(int argc, char *argv[]){

    FILE* file;
	char buffer[100];

	if (argc < 2){
		printf("my-unzip: file1 [file2 ...]\n");
		exit(1);
	} 
	for (int i = 1; i < argc; i++) {
		file = fopen(argv[i], "r");

		if (file == NULL){
			printf("File not found.\n");
			exit(1);
		}
		fseek(file, 0, SEEK_END); // seek to end of file
		//int size = ftell(file); // get current file pointer
		fseek(file, 0, SEEK_SET);
		fread(buffer, sizeof(buffer), 1, file);
		printf("%d%c%d%c\n",buffer[0],buffer[1],buffer[2],buffer[3]);
		fclose(file);	
	}
    return 0;
}


