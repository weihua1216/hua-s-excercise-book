//在1~n中找出m个不相邻的数字,共有几种方法.
#include <stdio.h>
int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int date[n - 2 * m + 1];
    date[0] = 1;
    for (int i = 1; i < n - 2 * m + 1; i++)
        date[i] = (m + 1) * date[i - 1];
    printf("%d\n", date[n - 2 * m]);
    return 0;
}