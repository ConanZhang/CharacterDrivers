#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char ** argv) 
{
	int time = atoi(argv[1]);
	int sleepy = open("/dev/sleepy0", O_WRONLY);

	while(1)
	{
		ssize_t sleepy_return = write(sleepy, &time, 4);
		if (sleepy_return == 0)
		{
			printf("Full sleep\n");
		}
		else 
		{
			printf("Woken with %d time left\n", (int)sleepy_return);
		}
	}
}