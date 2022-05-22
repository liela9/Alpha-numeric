#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isanum(int c) /*Alpha-numeric by ascii*/
{
    if((96 < c && c < 123 )||
      (64 < c && c < 91) ||
      (47 < c && c < 58))
        return 1;
    return 0;
}

int main()
{
    int size = 5;
    int i = 0;
    int alpha_num = 0;
    char c;
    char *str;
    char *str_re;
    str = (char*) malloc(size* sizeof(char));
    printf("Enter any text\n");
    while((c = getchar()) != EOF)
    {
        str[i] = c;
        if(isanum(c))
            alpha_num++;
        i++;
        if(i > size) /*checking if the current block of memory is full*/
        {
            size = size*2;
            str_re = (char*) realloc(str, size); 
            if(!str_re) /*checking if there is enough memory*/
            {
                printf("Memory allocation faild");
                exit(0);
            }
            str = str_re;
        }
	
    }
    printf("\n");
    i = 0;
    while(i < strlen(str)) /*print the characters - one in row*/
    {
        printf("%c\n", str[i]);
        i++;
    }    
	printf("\nThe number of characters is: %d\n", strlen(str));
	printf("The number of Alpha-numeric characters is: %d\n", alpha_num);
	
    free(str);

    return 0;
}