#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
	FILE *fp;
	fp = fopen("input.txt", "r");
	char *first = NULL, *last = NULL;
	int max = 60;
	char str[max];
	unsigned int sum = 0;
	int line_number = 1;

	for(int i=0; i<1000; i++){
		fgets(str, max, fp);
		int l = 0;
		int r = strlen(str) - 1;

		while(l < strlen(str)-1){
			if((str[l]>47 && str[l]<58) && first == NULL){
				first = &str[l];
			}
			if((str[r]>47 && str[r]<58) && last == NULL){
				last = &str[r];
			}
			l++;
			r--;
		}

		if(!first){
			sum += ((int) *last - 48) * 10 + ((int) *last - 48);
			printf("line number: %d\t", line_number);
			printf("line total: %d\n", ((int) *last - 48) * 10 + ((int) *last - 48));
		}
		else if(!last){
			sum += ((int) *first - 48) * 10 + ((int) *first - 48);
			printf("line number: %d\t", line_number);
			printf("line total: %d\n", ((int) *first - 48) * 10 + ((int) *first - 48));
		}
		else{
			sum += ((int) *first - 48) * 10 + ((int) *last - 48);
			printf("line number: %d\t", line_number);
			printf("line total: %d\n", ((int) *first - 48) * 10 + ((int) *last - 48));
		}

		first = NULL;
		last = NULL;
		line_number++;
	}
	printf("total sum: %u\n", sum);
	fclose(fp);
	return 0;
}