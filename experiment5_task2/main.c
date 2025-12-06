#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

//计算不同单词的数量 
int calculate_num(char *arr[], int arr_len);
 
int main(){
	//读入输入的字符串 存放在临时字符数组中
	char *arr[MAX_SIZE] = {0};
	char temp[MAX_SIZE] = {0};
	char cur[MAX_SIZE] = {0};
	
	fgets(temp, MAX_SIZE, stdin);
	temp[strcspn(temp, "\n")] = '\0';
	
//	printf("here\n");
	
	//从临时字符数组中输入英文单词 
	int temp_idx = 0; 
	int cur_idx = 0;
	int arr_idx = 0;
	while(temp[temp_idx] != '\0'){
		//跳过标点或空格 
		while(temp[temp_idx] != '\0' && !isalpha(temp[temp_idx])){
			temp_idx++;
		}
		
		//提取单词 并将大写字母转换成小写字母 
		while(temp[temp_idx] != '\0' && isalpha(temp[temp_idx])){
			cur[cur_idx++] = tolower((unsigned char)temp[temp_idx++]);
		}
		
		//提取到的单词存入指针数组
		if(cur_idx > 0){
			cur[cur_idx] = '\0';
		 	
		 	//分配内存空间 
			arr[arr_idx] = (char*)malloc(strlen(cur) + 1);
			if(arr[arr_idx] == NULL){
				printf("内存分配失败\n");
				return 1;
			}
			
			strcpy(arr[arr_idx], cur);
				
			cur_idx = 0;
			arr_idx++;
		} 		
	} 

//	printf("here\n");
		
	int arr_len = arr_idx;
	int i;
	
//	for(i = 0; i < arr_len; i++){
//		printf("%s\n", arr[i]);
//	} 
	
	printf("%d", calculate_num(arr, arr_len));
	
	//释放剩余内存
	for(i = 0; i < arr_len; i++){
		if(arr[i] != NULL){
			free(arr[i]);
		}
	} 
	
	return 0;
}

int calculate_num(char *arr[], int arr_len){
	int i, j;
	int cnt = 0;
	
	//标记重复的单词 遍历时跳过重复的单词 
	for(i = 0; i < arr_len; i++){
		if(arr[i] == NULL){
			continue;
		}else{
			for(j = i + 1; j < arr_len; j++){
				if(arr[j] != NULL && !strcmp(arr[i], arr[j])){
					free(arr[j]);
					arr[j] = NULL;
				}
			}
			cnt++;
		}	
	}
	
	return cnt;
}


