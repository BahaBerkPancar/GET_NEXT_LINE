#include "get_next_line.h"

char *bytes_read(int fd, char *str)
{
    t_gnl s;
    s.i = 0;
    while(str[s.i] != '\n' && str[s.i] != '\0')
        s.i++;
    s.str = calloc(1, s.i + 2);
    if(!s.str)
        return(NULL);
    s.str = ft_substr(str, 0, s.i++);
    if(str[s.i] == '\0')
        s.str[s.i++] = str[s.i];
    s.str[s.i] = '\0';
    return(s.str);
}
char *remains(int fd, char *str)
{
    t_gnl s;
    int i = 0;
    s.i = 0;
    while(str[s.i] != '\n' && str[s.i] != '\0')
        s.i++;
    if(str[s.i] == '\n')
        s.i++;
    while(str[i++] != '\0');
    str += i;
    return(str);
}
char *reads(int fd, char *str)
{
    t_gnl s;

    s.str = calloc(1, BUFFER + 1); // you must free in every situation
    s.i = 1;    // bites read
    while(!ft_strchr(str, '\n') && s.i != 0)
    {
        s.i = read(fd, s.str, BUFFER);
        if(s.i == -1) // faliure
            return(free(s.str), free(str), NULL);
        str = ft_strjoin(str, s.str); // put together
    }
    return(free(s.str), str); // freeing our struct and returning final
}
char *get_next_line(int fd)
{
    char *final;
    static t_gnl s;
    s.str = reads(fd, s.str); //reading first line
    if(!s.str)  // failure
        return(NULL);
    final = bytes_read(fd, s.str);
    s.str = remains(fd, s.str);
    return (final);
}
