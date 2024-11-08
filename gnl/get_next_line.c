#include "get_next_line.h"

// char *get_next_line(int fd)
// {
//     t_gnl.i = 0;
//     printf("aaaaaaa\n");
//     t_gnl.str = malloc(BUFFER);

//     t_gnl.i = read(fd, t_gnl.str, BUFFER);
//     printf("%zu\n", t_gnl.i);
//     printf("%s\n", t_gnl.str);
//     return(t_gnl.str);
// }
int main()
{

    int fd = open("fd.c", O_CREAT | O_WRONLY, 777);

    t_gnl.i = 0;
    t_gnl.str = malloc(BUFFER + 1);
    t_gnl.i = read(fd, t_gnl.str, BUFFER);
    printf("%zu\n", t_gnl.i);
    printf("%s\n", t_gnl.str);

}