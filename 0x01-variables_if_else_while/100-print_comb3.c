#include <stdio.h>

/**
 * main - prints all single digit numbers of base 10 starting from 0,
 * followed by a new line, using putchar
 * Return: Always 0 (Success)
 */
int main(void)
{
    int j ;
    int i ;
    for (i = 0; i < 9 ; i++)
    {
        
        for(j = i+1;j < 10 ; j++){
            putchar('0' + i);
            putchar('0' + j);
	    if(i != 8 || j!=9){
		putchar(',');
		putchar(32);
	    }
            
        }
    }
    return (0);
}
