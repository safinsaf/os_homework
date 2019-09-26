#include <stdio.h>
#include <signal.h> 
#include <stdlib.h>

void signal_handler1(int sig){
	printf("\nSIGINT caught\n");
}
void signal_handler2(int sig){
	printf("\nSIGSTOP caught\n");
}
void signal_handler3(int sig){
	printf("\nSIGUSR1 caught\n");
}

int main(){
	signal(SIGINT, signal_handler1);
	signal(SIGSTOP, signal_handler2);
	signal(SIGUSR1, signal_handler3);
	while (1) ;
}

/*
kill is a function that sends a signal to process
by default it is SEGTERM
When we send -2 SIGINT is caught
*/
