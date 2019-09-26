#include <stdio.h>
#include <signal.h> 
#include <stdlib.h>
void signal_handler(int sig){
	printf("\nsignal caught\n");
}

int main(){
	signal(SIGINT, signal_handler);
	while (1) ;	
}
