#include "get_next_line.h"

char *bytes_read(char *str)
{
    t_gnl s;
    s.i = 0;
    while(str[s.i] != '\n' && str[s.i] != '\0')
        s.i++;
    s.str = malloc(sizeof(char) * s.i + 1);
    if(!s.str)
        return(NULL);
    s.str = ft_substr(str, 0, s.i);
    if(!s.str)
        return(NULL);
    if(str[s.i] == '\0')
        s.str[s.i++] = str[s.i];
    return(s.str);
}
char *remains(char *str)
{
    t_gnl s;
    s.i = 0;
    while(str[s.i] != '\n' && str[s.i] != '\0')
        s.i++;
    if(str[s.i] == '\n')
        s.i++;
    str = ft_strdup(str + s.i);
    if(!str)
        return(free(str), NULL);
    return(str);
}
char *reads(int fd, char *str)
{
    t_gnl s;

    if (!fd)
        return(NULL);
    s.str = calloc(1, BUFFER_SIZE + 1);
    s.i = 1;
    while(!ft_strchr(str, '\n') && s.i != 0)
    {
        s.i = read(fd, s.str, BUFFER_SIZE);
        if(!s.i)
            return(free(s.str), free(str), NULL);
        str = ft_strjoin(str, s.str);
    }
    return(free(s.str), str);
}
char *get_next_line(int fd)
{
    char *final;
    static t_gnl s;
    s.str = reads(fd, s.str);
    if(!s.str)
        return(NULL);
    final = bytes_read(s.str);
    s.str = remains(s.str);
    system("leaks a.out");
    return (final);
}
