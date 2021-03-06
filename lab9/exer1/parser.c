#include"parser.h"

char** parser(char* filename) {
	FILE* fp = NULL;
	fp = fopen(filename, "r");

	if( fp == NULL) {
		printf("Error! in opening file\n");
		exit(-1);
	}

	char ** book;
	book = (char **) malloc(sizeof( char*) * MAX);
	char *str;
	int size = MAX, i, flag;
	count = 0;
	while( !feof(fp)) {
		if( count == size) {
			book = (char **) realloc(book, sizeof( char*) * size*2);
		}

		flag = 1;
		str = (char *)malloc(sizeof(char)*50);
		fscanf(fp, "%s\n", str);
		// printf("%d\n", count);
		for( i=0; i<strlen(str); i++) {
			if( ! (( str[i] >= 'A' && str[i] <= 'z') || (str[i] >= 'a' && str[i] <= 'z')) ) {
				free(str);
				flag = 0;
				continue;
			}
		}

		if( flag == 0)
			continue;
		book[count] = str;
		strcpy(book[count], str);
		// printf("%s\n", book[count]);
		count++;
	}
	
	printf("Total number of valid strings are: %d\n", count);
	fclose(fp);
	return book;
}