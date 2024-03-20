#include <stdio.h>
#include <stdlib.h>

int main() {
//	printf("%s", "歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩:");
	int num = 0;
	scanf("%d", &num);
//	printf("%s %d %s", "以為您購買的", num, "組樂透組合輸出至 lotto.txt"); 
	if(num<1 && num>5){
		return 1;
	}
		
//	time_t curtime;
//	time(&curtime);
//	char* time_str;
//	time_str = ctime(&curtime);
//    time_str[strcspn(time_str, "\n")] = 0;
	FILE* fp;
	srand(1);
	char matrix[5][7];
	int ans;
    fp = fopen("lotto.txt","w");
    
    for(int i=0; i<num; i++){
    	for(int j=0; j<7; j++){
    		matrix[i][j] = rand() % 69 + 1;
    		for(int m = 0; m < j; m++){
    			if(matrix[i][m] == matrix[i][j]){
    				matrix[i][j] =  rand() % 69 + 1;
				}
			}
		}
	}
    
    fprintf(fp,"========= lotto649 =========\n");
//    fprintf(fp,"%s%s%s", "=", time_str, "=\n");
	for(int i=0; i<5; i++){
		fprintf(fp, "%s%d%s", "[", i+1,"]:");
		for(int j=0; j<7;j++){
			if(i >= num){
				fprintf(fp, " __");
			}
			else if(matrix[i][j]/10 ==0){
				fprintf(fp, " %d%d", 0, matrix[i][j]);
			}
			else{
				fprintf(fp, " %d", matrix[i][j]);
			}
		}
		fprintf(fp, "\n");
	}
    fprintf(fp,"========= csie@CGU =========\n");
    fclose(fp);
	
	return 0;
}
