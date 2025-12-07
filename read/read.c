#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
/*
使用read函数接口实现读文件操作访问
从文件描述符fd所引用的文件中读取count字节数据到buf指针所指向的缓冲区中；
*/
int main(int argc, char const *argv[])
{
    int fd = 0;    // 标识唯一确定打开的文件
    char buf[256]; // 数据缓冲区
    int ret;       // read函数的返回值，实际读取字节数

    fd = open("read.txt", O_RDWR | O_CREAT | O_APPEND, 0777); // 读写打开，不存在则创建，存在则写在文件末尾
    if (-1 == fd)
    {
        perror("open");
        return -1;
    }

    /*将fd所标识的文件内容写到缓冲区*/
    memset(buf, 0, sizeof(buf));
    while (1) // 循环写入字节
    {
        // 清空buf缓冲区的内容
        ret = read(fd, buf, sizeof(buf)-1);//期望读取到的字节数
        if (ret == -1)
        {
            perror("read");
            return -1;
        }
        else if (ret == 0)
        {
            printf("读取文件完成，已写入缓冲区\n");
            break;
        }
    }
    printf("%s", buf);

    /* 关闭文件描述符fd，释放fd所引用文件的资源 */
    if (close(fd) == -1)
    {
        perror("close");
    }
    return 0;
}