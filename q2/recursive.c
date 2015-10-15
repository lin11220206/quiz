/* FIXME: Implement! */
#include <stdio.h>

char smallest_character(char str[], char c);

int main()
{
    char str[] = "cfjpv";
    printf("%c\n", smallest_character(str, 'a'));
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
