#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 10;
    int* p = &x;
    int* q = p;

    *p = 15;

    printf("%d\n", *p);



    /*int x = 10;
    int* p = &x;
    int** q = &p;
    int*** s = &q;


    printf("%d\n", **s);
    printf("%d\n", &x);
    */
    return 0;

}
