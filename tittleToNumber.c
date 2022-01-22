/*
给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。返回该列名称对应的列序号。
*/
#include <stdio.h>
#include <string.h>
int titleToNumber(char *columnTitle)
{
    int answer = 0, a = 0;
    long t = 1;
    for (int i = strlen(columnTitle) - 1; i >= 0; i--)
    {
        a = columnTitle[i] - 64;
        a *= t;
        answer += a;
        t *= 26;
    }
    return answer;
}