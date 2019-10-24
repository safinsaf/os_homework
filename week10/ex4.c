#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int main(){

	int *count = (int*) malloc(N*sizeof(int));
	long long *inode = (long long*) malloc(N*sizeof(long long));
	for (int i = 0; i < N; i++){
		count[i] = 0;
		inode[i] = 0;
	}
	int taken = 0;

	DIR *dirp = opendir("tmp");
	if (dirp == NULL) return -1;
	struct dirent *dp;
	while ((dp = readdir(dirp)) != NULL){
		if (strcmp(dp->d_name, ".") == 0) continue;
		if (strcmp(dp->d_name, "..") == 0) continue;	
		int in_inode = 0;
		for (int i = 0 ; i < taken; i++){
			if (inode[i] == dp->d_ino){
				count[i]++;
				in_inode = 1;
				break;
			}
		}
		if (!in_inode){
			count[taken] = 1;
			inode[taken] = dp->d_ino;
			taken++;
		}
		if (taken >= N){
			return -1;
		}
		//printf("%ld, %s \n", dp->d_ino, dp->d_name);
	}
	for (int i = 0 ; i < taken; i++){
		if (count[i]>1){
			printf("%lld ", inode[i]);
			dirp = opendir("tmp");
			while ((dp = readdir(dirp)) != NULL){
				if (dp->d_ino == inode[i]) {
					printf("%s ", dp->d_name);
				}
			}
			printf("\n");
		}
	}
	closedir(dirp);
}
