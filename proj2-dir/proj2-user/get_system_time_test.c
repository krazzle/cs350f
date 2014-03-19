#include <syscall.h>
#include <stdio.h>
#include <error.h>
#include <string.h>
#include <sys/time.h>

int main(){
	struct timeval t;
	if(syscall(352,&t) < 0)
	 	printf("Calling get_system_time failed with error code %d\n", n);

	printf("time is (%d,%d)\n", t.tv_sec, t.tv_usec);
	return 0;
}
