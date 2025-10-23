#ifndef _SLIDE_LINE_H_
#define _SLIDE_LINE_H_

#include <stddef.h>

#define SLIDE_LEFT -1
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);

#endif /* _SLIDE_LINE_H_ */
