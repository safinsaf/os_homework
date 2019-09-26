#include <stdio.h>
#include <signal.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int p[2];
	pipe(p);
	int first_child_for_parrent, second_child_for_parrent;
	if ((first_child_for_parrent = fork())>0){
		if ((second_child_for_parrent = fork())>0){					//parrent
    		write(p[1], &second_child_for_parrent, sizeof(int));
    		printf("Parrent: I have written to pipe, will wait for changing status of second child\n");
    		int status = 0;
    		waitpid(second_child_for_parrent, &status, 0); 
    		printf("Parrent: my second child is stopped. I terminate\n");
		}
		else{ 														//second child
			while(1){
				printf("Second child: I am in loop\n");
				sleep(2);
			}
		}
	}
	else{
		int second_child_for_first;
		sleep(2);															//first child
		read(p[0], &second_child_for_first, sizeof(int));
		printf("First shild: I have read pid of second shild. I will stop it\n");
		kill(second_child_for_first, SIGSTOP);
		printf("First child: I have stopped second child, I will terminate\n");
	}
}

/*
Description is wrong, waitpid does not react to SIGSTOP
*/
