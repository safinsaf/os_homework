#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>  
int main(){
	int PID;

	fork();
	fork();
	fork();
	fork();
	fork();
	sleep(5);
}



/*
If we run with 3 forks:
init(1)┬init(3)bash(4)ex2(560)┬ex2(561)┬ex2(563)ex2(567)
        │                              │          └ex2(566)
        │                              ├ex2(562)ex2(565)
        │                              └ex2(564)
        └init(546)bash(547)pstree(568)
*/

/*
If we run with 5 forks:
init(1)┬init(3)bash(4)ex2(578)┬ex2(579)┬ex2(580)┬ex2(583)┬ex2(589)ex2(597)
        │                              │          │          │          └ex2(596)
        │                              │          │          ├ex2(587)ex2(595)
        │                              │          │          └ex2(594)
        │                              │          ├ex2(582)┬ex2(586)ex2(599)
        │                              │          │          └ex2(601)
        │                              │          ├ex2(588)ex2(600)
        │                              │          └ex2(598)
        │                              ├ex2(581)┬ex2(585)┬ex2(592)ex2(603)
        │                              │          │          └ex2(602)
        │                              │          ├ex2(593)ex2(605)
        │                              │          └ex2(604)
        │                              ├ex2(584)┬ex2(591)ex2(609)
        │                              │          └ex2(608)
        │                              ├ex2(590)ex2(607)
        │                              └ex2(606)
        └init(546)bash(547)pstree(610)
*/

/*
2^(number of fork calls) processes created
Because each time fork() is called the duplicate of current process is created
And all remaining calls to fork() are going to be executed in both current process and its duplicate
*/
