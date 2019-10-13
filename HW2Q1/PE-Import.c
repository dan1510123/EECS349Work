#include <stdio.h>
#include <string.h>

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
        	file = freopen(filename, "a", file); // open in append mode
	    	fputs(target, file);
	    	fclose(file);
		}
        
        return 1;
    }
    else {
    	file = fopen(filename, "w");

    	fputs(target, file);    	
    	return 1;
	}
    
}

