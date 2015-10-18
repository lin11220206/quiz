/* FIXME: Implement! */
#include <stdio.h>

char smallest_character(char str[], char c);

int main()
{
    FILE *fp;
    fp = fopen("testFile.txt", "r");
    if(fp == NULL) {
        printf("cannot open the file");
        return -1;
    }

    char line[50];
    int i = 0;

    char str[48], c;

    while(fgets(line, 50, fp)) {
        while(line[i] != 32) {
            str[i] = line[i];
            i++;
        }
        str[i] = '\0';
        c = line[i+1];
        printf("%c\n", smallest_character(str, c));
        i=0;
    }
	fclose(fp);

    return 0;
}

char smallest_character(char str[], char c)
{
    char nextChar;

    if(str[0] == '\0')	return 0;

    if(str[0] > c)
        return str[0];
    else {
        nextChar = smallest_character(str+1, c);
        if(nextChar <= c)
            return str[0];

        return nextChar;
    }
}
