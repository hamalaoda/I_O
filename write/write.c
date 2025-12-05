#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
/*
使用 write函数接口实现文件的读操作访问
从标准输入流获取数据，写入文件
*/
int main(int argc, char const *argv[])
{
    int fd;        // 创建文件描述符用于标识唯一的文件
    char buf[256]; // 数据缓冲区

    fd = open("a.txt", O_RDWR | O_CREAT | O_APPEND, 0777);
    if (-1 == fd)
    {
        perror("open");
        return -1;
    }

    /* 从标准输入流获取数据,将数据写入到缓冲区 */
    fgets(buf, sizeof(buf), stdin);
    /* 将缓冲区的数据写入到文件中 */
    if (-1 == write(fd, buf, strlen(buf)))
    {
        perror("write");
        return -1;
    }

    /* 关闭文件描述符，释放fd所引用文件的资源 */
    if (close(fd) == -1)
    {
        perror("perror");
        return -1;
    }

    return 0;
}
