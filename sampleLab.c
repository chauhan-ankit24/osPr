// 1 - Windows subsystem for linux
// 2 - Virtual box
// 3 - Dual boot

// nano file_name.c // create or open existing
// gcc file_name.c // execute
// ./a.out // run
// man write // man 2 read // man lseek - to open manual

// ctrl + x - back
// ctrl + l - clear

// File descriptor  // 0 stdin - keyboard
// 1 stdout - on screen
// 2 stderr - screen
// rest user defined ( can be known by open call)

// ************************* WRITE system call *************************
#include <unistd.h>
#include <stdio.h>
int main()
{
    int n;
    n = write(1, "Hare Krishna\n", 13);
    printf("value returned is %d\n", n);
}

// ************************* READ system call *************************
#include <unistd.h>
int main()
{
    int n;
    char b[30];
    n = read(0, b, 30);
    write(1, b, n);
}

// ************************* OPEN system call *************************
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    int n, fd, fd1;
    char buf[50];

    // fd = open("test.txt", O_RDONLY);
    // n = read(fd, buf, 10);
    // fd1 = open("target", O_CREAT | O_WRONLY, 0642);

    n = read(0, buf, 20);
    fd1 = open("target", O_WRONLY);

    write(fd1, buf, n);
}

// *************************  lseek system call *************************
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int n, f, f1;
    char buff[10];
    f = open("seeking", O_RDWR); // 1234567890abcdefghijx1x2x3x4x5

    read(f, buff, 10); // 1234567890 // from pointer at 1
    write(1, buff, 10);
    read(f, buff, 10); // abcdef // from pointer at a
    write(1, buff, 10);

    read(f, buff, 10); // 1234567890
    write(1, buff, 10);
    lseek(f, 10, SEEK_CUR); // re-positioning the pointer
    read(f, buff, 10);      // abcdefghij
    write(1, buff, 10);

    f1 = lseek(f, 10, SEEK_SET); // return final setted position of pointer
    printf("Pointer is at %d position\n", f1);
    read(f, buff, 10);
    write(1, buff, 10); // abcdefghij

    f1 = lseek(f, -11, SEEK_END);
    read(f, buff, 10);
    write(1, buff, 10); // x1x2x3x4x5
}
// *************************  system call *************************

// *************************  system call *************************

// *************************  system call *************************
