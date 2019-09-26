#include <stdio.h>
#include <signal.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>

int main(){
	int pid = fork();
	if (pid > 0){       //parrent
		sleep(10);
		kill(pid, SIGTERM);
	}
	else if(pid == 0){
		while(1){
			printf("I am alive\n");
			sleep(1);
		}
	} 	
}
