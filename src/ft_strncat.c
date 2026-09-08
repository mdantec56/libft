#include "libft.h"

char    *ft_strncat(char *dest, char *src, int n)
{
        int     i;
        int     len_dest;
        int     len_src;

        len_dest = ft_strlen(dest);
        len_src = ft_strlen(src);
        i = 0;
        while (i < len_src && i < n)
        {
                dest[len_dest + i] = src[i];
                ++i;
        }
        dest[len_dest + i] = '\0';
        return (dest);
}
