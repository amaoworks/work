#include <stdio.h>

int main(int argc ,char **argv ){
	//init the arrar
	int ( *(arrar[]) ) = {
		(int [] ) {1 , 2 , 3 , 4 , 5 } ,
		(int [] ) {6 , 7 , 8 } ,
		(int [] ) {9 , 10 , 11 , 12 } ,
		(int [] ) {13 , 14 }
	} ;
	int *ptr_arr = &arrar[0][0] ;
	printf("%p\t", &arrar[0][0]);
	printf("%p\t", &arrar[1][0]);
	printf("%p\t", &arrar[2][0]);
	printf("%p\t", &arrar[3][0]);

	//display the result
	int row = 0 ;
	int var = 0;
	int *ptr = &var ;
	for(int i = 0 ; i < 5 ; i++ ){
		printf("layer[%d][%d] Value: %d and address: %p\n", row , i ,*(ptr_arr + var) , (ptr_arr + var));
		*(ptr)+=1;
		//printf("%d\t%d",var,*ptr);
	}
	printf("\n");

	row = 1 ;
	for(int i = 0 ; i < 3 ; i++ ){
		//printf("layer[%d][%d] Value: %d\n", row , i , arrar[row][i]);
		//*(ptr)++;
		printf("layer[%d][%d] Value: %d and address: %p\n", row , i ,*(ptr_arr + var) , (ptr_arr + var));
		*(ptr)+=1;
	}
	printf("\n");

	row = 2 ;
	for(int i = 0 ; i < 4 ; i++ ){
		//printf("layer[%d][%d] Value: %d\n", row , i , arrar[row][i]);
		//*(ptr)++;
		printf("layer[%d][%d] Value: %d and address: %p\n", row , i ,*(ptr_arr + var) , (ptr_arr + var));
		*(ptr)+=1;
	}
	printf("\n");

	row = 3 ;
	for(int i = 0 ; i < 2 ; i++ ){
		//printf("layer[%d][%d] Value: %d\n", row , i , arrar[row][i]);
		//*(ptr)++;
		printf("layer[%d][%d] Value: %d and address: %p\n", row , i ,*(ptr_arr + var) , (ptr_arr + var));
		*(ptr)+=1;
	}
	printf("\n");

	return 0 ;
}
