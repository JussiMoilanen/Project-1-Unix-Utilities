// Jussi Moilanen
// Käyttöjärjestelmät ja systemiohjelmointi Harjoitustyö H1, my-cat.c
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(int argc, char * argv[]){

	char temp[1000];
	FILE *file;
	
	if (argc < 3) {
      		printf("Not enough command line parameters given!\n");
      		return 3;
    	} 
	for (int i = 2; i < argc; i++) {
		file = fopen(argv[i],"r");
		if (file == NULL)
			{
				printf("File not found.\n");
				exit(1);
			}

		while(!feof(file))
		{
			fgets(temp,1000,file);
			if(strstr(temp,argv[1]))
			  printf("%s",temp);
		}
		printf("\n");
		fclose(file);
	}
	return 0;
}
