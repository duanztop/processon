#include "processon.h"
char style[S_NUM] = {'-', '.', '#', '>', '+', '<'};
// 根据我们在Makefile中的选择可以使用不同符号打印进度条
void ProncessOn() // 函数的定义
{
    int cnt = 0;
    char bar[NUM];
    memset(bar, '\0', sizeof(bar)); // 将bar中sizeof(bar)大小的空间赋值为'\0'
    const char *lable = "|/-\\";    // 存放变化的符号
    // 101次 -- 从0到100
    while (cnt <= 100)
    {
        printf("[%-100s][%d%%][%c]\r", bar, cnt, lable[cnt % 4]); // 打印进度条的关键语句
        fflush(stdout);                                           // 刷新缓冲区，因为我们在此使用的是\r
        bar[cnt++] = style[2];

        // usleep()的单位是微秒 也就是一百万微秒等于1秒
        // 在这里设置50000也就是每次sleep50000微秒
        // 100次就是5秒，也就是五秒内把进度条打印完成
        usleep(50000);
    }
    printf("\n");
}