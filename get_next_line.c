#include "get_next_line.h"

int add_buff(char **saveline, int fd){
    char buff[BUFF_SIZE + 1];
    char *tmp;
    int  re;

    tmp = *saveline;
    re = read(fd, buff, BUFF_SIZE - 1);
    buff[BUFF_SIZE] = '\0';
    if (re < 1)
        return re;
    if (*saveline == NULL)
        *saveline = ft_strdup(buff);
    else {
        tmp = *saveline;
        *saveline = ft_strjoin(*saveline, buff);
        ft_strdel(&tmp);
    }
    return (re);
}

int get_next_line(const int fd, char **line)
{
    static char *saveLine = NULL;
    static int  read_re = 1;
    char        *newLine;
    char        *tmp;

    if (fd == -1)
        return (-1);
    while (saveLine == NULL || ((newLine = ft_strchr(saveLine, '\n')) == NULL && read_re > 0))
        read_re = add_buff(&saveLine, fd);
    if (read_re == -1)
    {
        ft_strdel(&saveLine);
        return(-1);
    }
    if (saveLine == NULL)
        return (0);
    if (newLine == NULL)
    {
        *line = ft_strdup(saveLine);
        ft_strdel(&saveLine);
        return(1);
    }
    *line = ft_strsub(saveLine, 0, (int)(newLine - saveLine));
    tmp = saveLine;
    saveLine = ft_strsub(saveLine, (int)(newLine - saveLine), (ft_strlen(saveLine) - ((int)(newLine - saveLine))));
    ft_strdel(&tmp);
    return (1);
}