//
// Created by andy on 2021/8/3.
//

//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
// NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

#include <vector>
#include <iostream>

//顺序寻找最小值
int MinInOrder(vector<int>&num,int left,int right)
{
    int result =num[left];
    for(int i=left+1;i<right;i++)
    {
        if(num[i]<result)
        {
            result=num[i];
        }
    }
    return result;
}

int Solution(vector<int> rotateArray)
{
    int size=rotateArray.size();

    if (size==0)
        return 0;

    int left=0;//头指针
    int right=size-1;//尾指针
    int mid=0;//中间指针

    while (rotateArray[left]>=rotateArray[right])
    {
        if (right-left==1)
        {
            mid=right;
            break;//左右指针相邻
        }

        mid=left+(right-left)/2;//计算中间指针位置

        if (rotateArray[left]==rotateArray[right]&&rotateArray[mid]==rotateArray[left])
            return MinInOrder(rotateArray,left,right);

        //中间元素位于前面的递增子数组，此时最小元素位于中间元素的后面
        if(rotateArray[mid] >= rotateArray[left]){
            left = mid;
        }
        //中间元素位于后面的递增子数组，此时最小元素位于中间元素的前面
        else{
            right = mid;
        }
    }
    return rotateArray[mid];
}