/* maxTurbulenceSize
题目描述:当 A 的子数组 A[i], A[i+1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：
若 i <= k < j，当 k 为奇数时， A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
或 若 i <= k < j，当 k 为偶数时，A[k] > A[k+1] ，且当 k 为奇数时， A[k] < A[k+1]。
也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。
返回 A 的最大湍流子数组的长度。
来源:leetcode
完成日期:2021.3.21
*/

#include <stdio.h>

int maxTurbulenceSize(int *arr, int arrSize)
{
    int t = 1;
    for (int i = 0; i < arrSize - 1; i++)
        if (arr[i] == arr[i + 1])
            ;
        else
            t = 0;
    if (t == 1)
        return 1;
    if (arrSize <= 2 && t == 1)
        return 1;
    else if (arrSize <= 2 && t != 1)
        return 2;
    else
    {
        int data[arrSize - 1], record = 0, num = 0;
        for (int i = 0; i < arrSize - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                data[i] = 1;
            else if (arr[i] < arr[i + 1])
                data[i] = 0;
            else if (arr[i] == arr[i + 1])
                data[i] = -1;
        }
        for (int i = 0; i < arrSize - 2; i++)
        {
            if (data[i] != data[i + 1] && (data[i + 1] != -1 && data[i] != -1))
                num++;
            else
            {
                if (num > record)
                    record = num;
                num = 0;
            }
            if (num > record)
                record = num;
        }
        return record + 2;
    }
}