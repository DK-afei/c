#include <math.h>
#include <stdio.h>

float fun ( float num )
{   int s ;
    float n, t, pi ;

    t = 1 ;
	pi = 0 ;
	n = 1 ; 
	s = 1 ;
    while(t >= num)
    {
        pi = pi + t ;
        n = n + 2 ;
        s = -s ;
        t = (float)(s % (int)n) ;
    }
    pi = pi * 4 ;
    return pi ;
}

main( )
{   float n1, n2 ;

    printf("Enter a float number: ") ;
    scanf("%f", &n1) ;
    n2 = fun(n1) ;
    printf("%6.4f\n", n2) ;
}
