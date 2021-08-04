//
// Created by andy on 2021/8/4.
//

int Fibonacci(int n)
{
    if(n<=0)
        return 0;
    if(n==1)
        return 1;
    for (int i = 2; i <= n; i++) {
        third = first + second;
        first = second;
        second = third;
    }
    return third;
}