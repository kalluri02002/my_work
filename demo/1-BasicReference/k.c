#include<stdio.h>
int main() {
    int count = 0, x;
    x = 0;

    while (count++ != 5) {// what value it will take fist it will exicute 
    //anther case is if ++ is before the value i will increament then it will take;
        x = x ^ 1;
        printf("%d ", x);
    }

    return 0;
}