/* FIXME: Implement! */
#include <stdio.h>

char smallest_character(char str[], char c);

int main()
{
    char str[] = "cfjpv";
    printf("%c\n", smallest_character(str, 'c'));
    return 0;
}

char smallest_character(char str[], char c)
{
    int i = 0;
    while(str[i] != '\0') {
        if(str[i] > c)
            return str[i];
        i++;
    }
    return str[0];
}
