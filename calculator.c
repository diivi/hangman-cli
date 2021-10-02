#include <stdio.h>

int add ( int a, int b)
{
    return a+b;
}

int subract ( int a, int b)
{
    return a-b;
}

int multiply (int a, int b)
{
    return a*b;
}

int divide (int a, int b)
{
    return a/b;
}

int main()
{
    int n;
    int a;
    int b;
    
    
    printf ("Welcome to this basic simple calculator made using C language!\n");
    printf ("Press 1 for adding a and b\n");
    printf ("Press 2 for subracting b from a\n");
    printf ("Press 3 for multiplying a with b\n");
    printf ("Press 4 for dividing a by b\n");
    scanf ("%d", &n);
    
    switch (n)
    
    {
        case 1:
        printf ("Enter the values for a and b");
        scanf ("%d", &a);
        scanf ("%d", &b);
        printf ("The sum of %d and %d is %d", a, b, add(a,b));
        break;
   
        case 2:
        printf ("Enter the values for a and b");
        scanf ("%d", &a);
        scanf ("%d", &b);
        printf ("The difference of  %d and %d is %d", a, b, subract(a,b));
        break;
   
        case 3:
        printf ("Enter the values for a and b");
        scanf ("%d", &a);
        scanf ("%d", &b);
        printf ("The product of  %d and %d is %d", a, b, multiply(a,b));
        break;
   
        case 4:
        printf ("Enter the values for a and b");
        scanf ("%d", &a);
        scanf ("%d", &b);
        printf ("The quotient %d and %d is %d", a, b, divide(a,b));
        break;
   }
    
    
    return 0;
}