#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void intHandler();
void intHandler2();
void intHandler3();

int main()
{
	int pid;
	if (pid=fork() == 0 ) {
		print_gugu();
		pause();
	}else {
		signal(SIGINT, intHandler);
	}
}

void print_gugu():{

	for (int i = 1; i < 30;i++ ){
		for (int j = 1; i < 10; j++) {
			printf("&d \* &d = &d",i,j,i*j);
		}
		if(i==9)
			signal(SIGINT, intHandler3);
		sleep(1);

		
	}
}

void intHandler(int signo)
{
	kill(child_id, SIGINT);
}
void intHandler2(int signo)
{
	printf("can not terminate \n");
}
void intHandler3(int signo)
{
	kill(-getppid(), SIGKILL);
}


