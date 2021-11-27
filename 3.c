#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


char *readFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    char *code;
    size_t n = 0;
    int c;

    if (file == NULL) {
        return NULL; //could not open file
    }
    code = malloc(1000);
    while ((c = fgetc(file)) != EOF) {
        code[n++] = (char) c;
    }
    code[n] = '\0';
    return code;
}


char **str_split(char *a_str, const char a_delim) {
    char **result = 0;
    size_t count = 0;
    char *tmp = a_str;
    char *last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;
    while (*tmp) {
        if (a_delim == *tmp) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }
    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;
    result = malloc(sizeof(char *) * count);

    if (result) {
        size_t idx = 0;
        char *token = strtok(a_str, delim);

        while (token) {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    return result;
}



int main(int argc, char *argv[]) {
    char *fileStr = readFile( argv[1]);
    const char *delim = ",";
    char **split = str_split(fileStr, delim[0]);
    const char *name = split[0];
    const char *sname = split[1];
    const char *fname = split[2];
    FILE *fptr;
    fptr = fopen(argv[2], "w");
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    fprintf(fptr, "%c.%c.%s", name[0], fname[0], sname);
    fclose(fptr);

    printf("Name is: %s \n",name);
    printf("Surname: %s \n",sname);
    printf("Patronymic: %s \n",fname);


    return 0;
}