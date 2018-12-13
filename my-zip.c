#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

int main(int argc, char *argv[]){
	printf("Turn textfile into zipfile with run lenght encoding\n");
    FILE* file, * zipfile;
	char c[255], new[255];
	size_t read;
	int merkki = 1, luku = 1;
	
	if (argc < 3){
		printf("my-zip: file1 [file2 ...]\n");
		exit(1);
	} 

	file = fopen(argv[1], "r");
	zipfile = fopen(argv[2], "w");
	if (file == NULL){
		printf("File not found.\n");
		exit(1);
	}
	int j = 0;
	while ((read = fread(c, 1, sizeof c, file)) > 0)
        fwrite(c, 1, read, stdout);
	for (int i = 0; i < strlen(c)-1; i++) {
		if (c[i] == c[i+1] && c != '\0') {
			merkki++;
			luku++;
		} else {
			if (c != '\0'){
				printf("%d%c",luku, c[i]);
				//fprintf(zipfile, "%d%c",luku, c[i]);
				new[j] = luku;
				new[j+1] = c[i];
				luku = 1;
				j = j+2;
			} 
			
		}
			
	}
	printf("\n");
	fwrite(new, sizeof(new)-1, 1, zipfile);
	fclose(file);	
	fclose(zipfile);

    return 0;
}


