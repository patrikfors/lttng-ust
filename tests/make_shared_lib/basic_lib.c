#include <stdio.h>
#include <ust/marker.h>

void myfunc(void)
{
	trace_mark(ust, in_lib, MARK_NOARGS);
	printf("testfunc\n");
}

//MARKER_LIB