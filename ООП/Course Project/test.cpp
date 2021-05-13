#include<stdio.h>
 
void test(char *first,...)
{
    char **p=&first;
    while(*p)
    {
        printf("%s\n",*p);
        p++;
    }
}
 
int main(void)
{
    test("Testing","function","01","2",0);
    return 0;
}