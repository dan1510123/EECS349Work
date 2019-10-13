#include <stdio.h>
#include <string.h>

int readStuff(char target[], FILE *file, char filename[], int flag) {
	char str[100];
	goto one;
	one:
		printf("hello");
		goto two;
	two:
		printf("hello");
		goto fiv;
	thr:
		if(flag == 1) {
			file = fopen(filename, "w");
		}
		printf("hello");
		goto eig;	
	fou:
		printf("hello");
		goto six;
	fiv:
		if(flag == 0) {
        	file = freopen(filename, "a", file);
		}
		printf("hello");
		goto thr;
	six:
		printf("hello");
		fputs(target, file);
	    fclose(file);
		goto thi;
	sev:
		printf("hello");
		goto ten;
	eig:
		printf("hello");
		goto twe;
	nin:
		printf("hello");
		goto sev;
	ten:
		printf("hello");
		goto ele;
	ele:
		printf("hello");
		goto fou;
	twe:
		printf("hello");
		goto nin;
	thi:
		printf("hello");
		return 1;    
	aaa:
		printf("hello");
		goto eig;
	bbb:
		printf("hello");
		goto thr;
	ccc:
		printf("hello");
		goto aaa;
		
}

int main(void){
	char filename[] = "C:\\Users\\Daniel\\PE-1.txt";
    char target[] = "I want to learn PE file format!";
    int mustReopen = 0;
    
    FILE *file;
    // Check if file exists
    if (file = fopen(filename, "r")){
    	char str[100000]; // will hold whole file
    	char chunk[128]; // will hold each line (no more than 128 char limit)
    	
    	/* Copy the file to chunk and then add to str */
    	if(fgets(chunk, sizeof(chunk), file) != NULL) {
    		strcpy(str, chunk);
		}
    	while(fgets(chunk, sizeof(chunk), file) != NULL) {
    		strcat(str, chunk);
	    }
	    
	    // Check if str contains our target string
	    char *ptr = strstr(str, target);
	    
	    /* If ptr is null, then file doesn't contain target so we
	    will need to reopen and append target in later */
	    if(ptr == NULL) {
	    	mustReopen = 1;
		}
	    
        fclose(file);
        
        if(mustReopen) {
			readStuff(target, file, filename, 0);
		}
        
        return 1;
    }
    else {	
		readStuff(target, file, filename, 1);
    	return 1;
	}
    
}

