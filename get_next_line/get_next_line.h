#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
// #pragma once

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifdef BUFFER_SIZE
    #undef BUFFER_SIZE
#endif

char	*get_next_line(int fd);

#endif