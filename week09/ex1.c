#include <stdio.h>
#define N 100000

/*
Algorithm:
	-take input into "arr"
	-take number of frames into "NUM_FR"
	-for each page:
		-check if it is already in frame
		-if no: check if there is a free place in frame
		-if no: find the one to change

*/


int main(){
	FILE *INP = fopen("input.txt", "r");

	int HIT = 0, MISS = 0;

	if (INP != NULL){
		int arr[N], count = 0;
		while (fscanf(INP, "%d", &(arr[count])) != EOF){
			count++;
		}

		int NUM_FR;
		scanf("%d", &NUM_FR);

		unsigned int R[NUM_FR];
		unsigned int age[NUM_FR];
		unsigned int curr_elem[NUM_FR];
		unsigned int free_spaces[NUM_FR];
		
		for (int i = 0; i < NUM_FR; i++){
			R[i] = 0;
			age[i] = 0;
			curr_elem[i] = 0;
			free_spaces[i] = 1;
		}

		
		for (int read_page = 0; read_page < count; read_page++){
			
			int INTERRUPT = 0;
			if (read_page % 7 == 0) INTERRUPT = 1;

			int is_in_frames = 0;
			for (int i = 0; i < NUM_FR; i++){
				if (arr[read_page] == curr_elem[i]){
					is_in_frames = 1;
					R[i] = 1;
				}
			}

			if (is_in_frames == 1) HIT += 1;
			else{
				//search for free spaces

				int free = -1;
				for (int i = 0 ; i < NUM_FR; i++){
					if (free_spaces[i] == 1) {
						free = i;
						free_spaces[i] = 0;
						break;
					}
				}

				if (free > 0){
					R[free] = 1;
					curr_elem[free] = arr[read_page];
				}

				else{

					//search for oldest unused
					unsigned int oldest_id = -1;
					unsigned int oldest_age = -1;  // max possible for unsigned int

					for (int i = 0; i < NUM_FR; i++){
						if (age[i] < oldest_age){
							oldest_age = age[i];
							oldest_id = i;
						}
					}

					curr_elem[oldest_id] = arr[read_page];
					R[oldest_id] = 1;
				}
				MISS+=1;
			}


			if (INTERRUPT){
				for (int i = 0; i < NUM_FR; i++){
					age[i] = (age[i] >> 1) + ( R[i]<< (8*sizeof(unsigned int)-1) );
					R[i] = 0;
				}
				INTERRUPT = 0;
			}
		}

		printf("HIT/MISS: %d/%d\n", HIT, MISS);


	}
	else{
		printf("Cant open the file");
	}
}


/*
insaf@DESKTOP-E38DT9F:~/OS/os_homework/week09$ ./ex1
10
HIT/MISS: 9/991
insaf@DESKTOP-E38DT9F:~/OS/os_homework/week09$ ./ex1
50
HIT/MISS: 48/952
insaf@DESKTOP-E38DT9F:~/OS/os_homework/week09$ ./ex1
100
HIT/MISS: 87/913
insaf@DESKTOP-E38DT9F:~/OS/os_homework/week09$ ./ex1
300
HIT/MISS: 243/757
insaf@DESKTOP-E38DT9F:~/OS/os_homework/week09$ ./ex1
500
HIT/MISS: 357/643
*/
