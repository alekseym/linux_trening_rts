#include <stdio.h>
unsigned int factorial(unsigned int n, unsigned int a){
    if (n == 0)  return a;
    return factorial(n-1, n*a);
}
int main(int argc, char* argv[]){
    unsigned int number = 5;
    printf("Factorial of number %d is %d\n", 
            number, 
            factorial(number, 1));
    return 0;
}
