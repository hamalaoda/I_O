```c
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t count); 
功能：
    从文件描述符fd所引用的文件中读取count字节数据到buf指针所指向的缓冲区中；
参数：
    参数1：fd表示所要读文件的文件描述符；
    参数2：buf指针是存储所读取的数据缓冲区起始地址；
    参数3：count期望读取数据字节数(实际读取字节数可能小于等于count)
返回值：
    成功返回实际读取数据字节数，如果为0表示读取到文件结束；失败返回-1且修改errno的值
```

