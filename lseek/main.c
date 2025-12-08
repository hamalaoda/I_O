#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
/*
实现文件的读写定位,将读位置设置为从起始位置向后偏移10个字节
*/
int main(int argc, char const *argv[])
{
    int fd;
    int ret;
    char buf[256];
    off_t len ;                     // lseek的返回值，是偏移的字节数
    fd = open("test.txt", O_RDWR); // 读写方式打开文件
    if (fd == -1)
    {
        perror("open");
        return -1;
    }

    printf("len = %ld\n",len);

    /*定位到起始位置向后偏移10个字节*/
    len = lseek(fd, 10, SEEK_SET);
    if (len == (off_t)-1) // 转换-1的类型为off_t
    {
        perror("lseek");
        return -1;
    }
    printf("len = %ld\n",len);

    memset(buf,0,sizeof(buf));
    ret = read(fd,buf,10);
    printf("%s\n",buf);

    close(fd);
    return 0;
}
