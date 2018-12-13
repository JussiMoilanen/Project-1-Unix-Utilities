// Jussi Moilanen
// Käyttöjärjestelmät ja systemiohjelmointi Harjoitustyö H1, my-cat.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	FILE * file;
	char content;
	if (argc < 2){
	
    		printf("Usage mycat <filename> \n");
    		exit (0);
 	}
	for (int i = 1; i < argc; i++) {
		file = fopen(argv[i], "r"); // open user input file (argv[i])

		if (file == NULL)
		{
			printf("File not found.\n");
			exit(1);
		}


		content = fgetc(file);
		while (content != EOF) //print content
		{
			printf("%c", content);
			content = fgetc(file);
		}
		fclose(file);
	}
	
	return 0;
}
