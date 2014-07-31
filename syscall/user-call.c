#define _GNU_SOURCE

#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {

	syscall(317);
	kill(1, SIGKILL);

	return 0;
}
