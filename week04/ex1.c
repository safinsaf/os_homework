#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
        int n = 0;

        if ((n = fork()) > 0){
                printf("Hello from parent [%d-%d]\n", getpid(), n);
        }
        else{
                printf("Hello from child [%d-%d]\n", getpid(), n);
        }

}

/*
insaf@DESKTOP-E38DT9F:~/OS/os_homework/week04$ for i in range{1..10}; do     ./ex1; done;

Hello from parent [62-63]
Hello from child [63-0]
Hello from parent [64-65]
Hello from child [65-0]
Hello from parent [66-67]
Hello from child [67-0]
Hello from parent [68-69]
Hello from child [69-0]
Hello from parent [70-71]
Hello from child [71-0]
Hello from parent [72-73]
Hello from child [73-0]
Hello from parent [74-75]
Hello from child [75-0]
Hello from parent [76-77]
Hello from child [77-0]
Hello from parent [78-79]
Hello from child [79-0]
Hello from parent [80-81]
Hello from child [81-0]

Here we can see that PID of children is one greater than PID of parent

Also, PID of parent from current programm is one greater than PID of children of previous program
This means that all processes are counted somewhere and their PID is global

If we run the program, then do something, then run the program:
some PIDs may be used by system
*/

