//
// Created by andy on 2021/8/5.
//

//一只青蛙一次可以跳上1级台阶，也可以跳上2级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法

//我们把n级台阶时的跳法看成是n的函数，记为f(n)当
// n>2时，第一次跳的时候就有两种不同的选择：
// 一是第一次只跳1级，此时跳法数目等于后面剩下的n-1级台阶的跳法数目，即为f(n-1)；
// 另外一种选择是跳一次跳2级，此时跳法数目等于后面剩下的n-2级台阶的跳法数目，即为f(n-2)。
// 因此n级台阶的不同跳法的总数f(n)=f(n-1)+f(n-2)。
// 分析到这里，我们不难看出这实际上就是斐波那契数列

int jumpFloor(int number)
{
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;
    if (number == 2)
        return 2;

    int first = 1, second = 2, third = 0;
    for (int i = 3; i <= number; i++)
    {
        third = first + second;
        first = second;
        second = third;
    }
    return third;
}