#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

//# define BUFFER_SIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_list{
      size_t            fd;
      char              *buffer;
      struct s_list     *next;
} t_link;


#endif