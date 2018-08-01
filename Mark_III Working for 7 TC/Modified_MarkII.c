/* //////  CO222 - PROJECT - PUZZLE SOLVING PROGRAM	////////
------------------------------------------------------------
<<<<<<<<<<< ******* ==@luke==  E/15/142  ******* >>>>>>>>>>> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//method prototypes
int readPuzzleGrid();
int readInputWords();
int solvePuzzle();
void getLength();
void printArray();
void printArray_int(int *array,int m);
int streakByColumn(char *array,int column_height);
int streakByRow(char *array,int row_width);

//static variables
static int grid_len = 0;
static int word1_length = 0;
static int word2_length = 0;
static int used_word_number = 0;

static int grid[10];
static int result_Array_Row_Str[2];
static int result_Array_Column_Str[2];
static char word_Array[2][10];
static char puzzle_Array[10][10];
static char result_Array[10][10];

//methods
void getLength(){
	int i;

	word1_length = strlen(word_Array[0]);
	word2_length = strlen(word_Array[1]);
	for (i = 0; i < 10; ++i){
		if (grid[i] == 0){
			break;
		}else{
			grid_len++;
		}
	}

	return;
}

void printArray(){
	int i,j;
    //printf("AAA\n");
	//printf("char Array : ");
	if ((puzzle_count == 0)&&(word_count == 0)){
		return;
	}
	for (i = 0; i < 10; ++i){
        if(grid[i] == 0){
            break;
        }
        if (i != 0){
	        printf("\n");        	
        }
        for(j = 0; j<grid[i];j++){
            printf("%c", toupper(result_Array[i][j]));
        }
	}
	return;
}

void printArray_int(int *array,int m){
	int i;
	//printf("Grid Array : ");
	for (i = 0; i < m; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");
	return;
}

int readPuzzleGrid(){
	
	int puzzle_check_end = 0;
	int row = 0;
	int column = 0;
	char prev = 0;
	char readChar;

	while(puzzle_check_end == 0){
		scanf("%c",&readChar);

		if (readChar == '\n'){
			grid[row] = column;
			if((readChar == '\n')&&(readChar == prev )){
				puzzle_check_end = 1;
				//grid_height = column;
				//printf("DD \n");

				break;
			}
			row++;
			column = 0;
			prev = readChar;
		}else if( !(((readChar == '*') || (readChar == '#')) || (isalpha)) ){
			puzzle_check_end = -1;
			break;
		}else{
			puzzle_Array[row][column] = readChar;
			result_Array[row][column] = readChar;
			column++;
			puzzle_count++;
			prev = 0;
		}
		//prev = 0;
	}
	return puzzle_check_end;
}

int readInputWords(){
	char * word1;
	char * word2;
	char nextChar;

	//printf("read input\n");
	int i = 0,j = 0,count = 10;
	char prev = 0;
	for (i = 0; i < 2;){
		for (j = 0; j < count; j++){
			nextChar = getchar();
			if (nextChar == '\n'){
				//detect newline for one time and break input words
				i++;
				j = -1;
			}
		    if(nextChar == '\n' && prev == nextChar){
		        //  enter pressed twice!
		        // 	hence, exit
		        break;
		    }
		    prev = nextChar;
		    if (j != -1){
				word_Array[i][j] = nextChar;
		    	
		    }
			//printf("Array %d - %d = %c\n",i,j, word_Array[i][j]);
		}
	}
	
	return 0;
}


int streakByColumn(char *array,int column_height){
	int index = 0,prev = 0;
	int i,j,count = 0;
	int start;
	result_Array_Column_Str[0] = -1;// no streak default value -->> -1
	result_Array_Column_Str[1] = -1;

	//printf("%s\n",array);
	for (i = 0; i < column_height ; i++){
		if (array[i] == '#'){
			if ((array[i] == '#')&&(prev == 1)){
				count++;
				//printf("A\n");
			}
			if (index == 0){
				start = i;
				count++;
				prev = 1;
			}
			index++;
			
		}else{
			start = -1;
			prev = 0;
			//count = 0;
		}
	}
	

	//printf("count %d start %d\n", count,start);
	if( (count >= 2)&&((count>=word1_length) || (count>=word2_length)) ){

		if ((count == word1_length)&& (used_word_number != 1) ){
			//printf("matches word1\n");
			result_Array_Column_Str[1] = 1;
			//printf("word 1 == %d\n", result_Array_Column_Str[1]);
			result_Array_Column_Str[0] = start;
			//count = 0;
			used_word_number = 1;
		}else if ((count == word2_length)&& (used_word_number != 2)){
			//printf("matches word2\n");
			result_Array_Column_Str[1] = 2;
			//printf("word 2 == %d\n", result_Array_Column_Str[1]);
			result_Array_Column_Str[0] = start;
			//count = 0;
			used_word_number = 2;
		}else if ((count > word1_length)&&(count > word2_length)){
			//special_case = 1;
		}else{
			//printf("AAAA\n");	
			if (used_word_number == 1){
				//printf("word2 matches\n");
			}else if (used_word_number == 2){
				//printf("word1 matches\n");
			}
		}

	}
	if (result_Array_Column_Str[0] == -1){
		//printf("no matches column\n");
		return -1;
	}else{
		return 1;		
	}
}



// method to detect hash streak by row-wise 
// return no. of streaks if matches streaks
// otherwise -1 
// result_Array_Row_Str ----- [0] - index of the first hash occurence column in the array
//						----- [1] - index of the input word
int streakByRow(char *array,int row_width){
	int index = 0,prev = 0;
	int i,j,count = 0;
	int start;
	result_Array_Row_Str[0] = -1;// no streak default value -->> -1
	result_Array_Row_Str[1] = -1;

	//printf("%s\n", array);
	for (i = 0; i <row_width ; ++i){
		if (array[i] == '#'){
			if ((array[i] == '#')&&(prev == 1)){
				count++;
			}
			if (index == 0){
				start = i;
				count++;
				prev = 1;
			}
			index++;
			
		}else{
			start = -1;
			prev = 0;
			//count = 0;
		}
	}
	//printf("count %d start %d\n",count ,start);
	if( (count >= 2)&&((count>=word1_length) || (count>=word2_length)) ){
		/*if (count == 0){
			return -1;
		}*/
		if ((count == word1_length)&& (used_word_number != 1) ){
			//printf("matches word1\n");
			result_Array_Row_Str[1] = 1;
			//printf("word 1 == %d\n", result_Array_Row_Str[1]);
			result_Array_Row_Str[0] = start;
			//count = 0;
			used_word_number = 1;
		}else if ((count == word2_length)&& (used_word_number != 2)){
			//printf("matches word2\n");
			result_Array_Row_Str[1] = 2;
			//printf("word 2 == %d\n", result_Array_Row_Str[1]);
			result_Array_Row_Str[0] = start;
			//count = 0;
			used_word_number = 2;
		}else if ((count > word1_length)&&(count > word2_length)){
			//special_case = 1;
		}else{
			// printf("AAAA\n");	
			if (used_word_number == 1){
				//printf("word2 matches\n");
			}else if (used_word_number == 2){
				//printf("word1 matches\n");
			}
		}
				
	}
	if (result_Array_Row_Str[0] == -1){
		//printf("no matches row\n");
		return -1;
	}else{
		return 1;		
	}
}
int solvePuzzle(){
	getLength();
	//printf("word1 len : %d \n", word1_length);
	//printf("word2 len : %d \n", word2_length);
	//printf("grid grid_height %d\n",grid_height);
	int x;
	for ( x = 0; x < 10; x++){
		if (grid[x] == 0){
			break;
		}
		if( ((grid_len<word1_length)&&(grid[x] < word1_length)) || ((grid_len<word2_length)&&(grid[x] < word2_length))){
				return 0;
		}
	}
/*
	if((grid_height < word1_length) || (grid_height < word2_length)){
		// worse case 1 = grid height is lower than either word sizes
		// <<<<<<<<< Later Improvements >>>>>>>>>
		// both cases or one case??? --> Hackerrank
		// 
		return 0;
	}else{
		*/
		// analyze patterns
		int i,j,k,word_counter = 0;
		int grid_len = 0,word = 0;
		char temp_Array[grid_len];
		for (i = 0; i < 10; ++i){
			if (grid[i] == 0){
				break;
			}else{
				grid_len++;
			}
		}

		for (i = 0; i < 10; ++i){
				if (grid[i] == 0){
					break;
				}
				//printf("PUZZLE : %s grid len : %d %d\n",puzzle_Array[i],grid[i], grid_len );
				if (streakByRow((char *)puzzle_Array[i],grid[i]) == 1){
					//printf("streak found in column %d and word %d\n", result_Array_Row_Str[0] , result_Array_Row_Str[1] );
					//printf("%s\n", word_Array[result_Array_Row_Str[1]-1]);
					word_counter++;
					for (j = 0; j < strlen(word_Array[result_Array_Row_Str[1]-1]) ; j++){
						// Replace the hash with the letter 
						puzzle_Array[i][j+result_Array_Row_Str[0]] = word_Array[result_Array_Row_Str[1]-1][j];
					}
					continue;
				}
		}
		//printf("word_counter %d\n",word_counter );
		if (word_counter == 2){
			return 1;
		}
		for (i = 0; i < word1_length; i++){
			for (j = 0; j < word2_length; j++){
				if (word_Array[0][i] == word_Array[1][j]){
					// Common letter found!!!
					//printf("Common letter found %c \n", word_Array[1][j]);
					k = j;
					if (used_word_number == 1){
						puzzle_Array[0][j] = '#';
						//printf("is word 2 matches with the column %d\n",k);
						word = 2;
					}else{
						puzzle_Array[1][j] = '#';
						//printf("is word 1 matches with the column %d\n",k);
						word = 1;
					}
					/*for (k = 0; k < grid[i] ; k++){
						temp_Array[i] = puzzle_Array[k][j];
					}
					printf("temp %s\n", temp_Array);
					if (streakByColumn(temp_Array,grid_len) == 1){
						printf("streak found!!!\n");
					}
					*/

				}
			}
		}
		//printf("A k = %d\n",k);
		for (j = 0; j < grid_len ; j++){
			temp_Array[j] = puzzle_Array[j][k];
			//printf("%c\n", puzzle_Array[j][k]);
			//printf("%c",temp_Array[j]);
		}
		//printf("\n");
		// printf("temp %s\n", temp_Array);
		if (streakByColumn(temp_Array,grid_len) == 1){
			// printf("streak found!!!\n");
			// printf("%s\n", word_Array[result_Array_Column_Str[1]-1]);
			for (j = 0; j < strlen(word_Array[result_Array_Column_Str[1]-1]) ; j++){
				// Replace the hash with the letter 
				puzzle_Array[j][k] = word_Array[result_Array_Column_Str[1]-1][j];
			}
		}
		
		return 1;
	//}
}

int main(){

	//readPuzzleGrid();
	
	if (readPuzzleGrid() == -1){
		//printf("INPUT ERROR!!!\n");
		return 0;
	}else{
		readInputWords();	
	}
	
/*	if (getchar() != '\n'){
	}else{
		readInputWords();
	}
*/
	
	//solvePuzzle();
	// printArray_int(grid,10);
	if (solvePuzzle() == 0){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	//printf("width : %d\n", grid_height);
	//printf("word1 len : %d \n", word1_length);
	//printf("word2 len : %d \n", word2_length);
	//printf("grid height%d\n", grid_height);
	printArray();
	//printf("\n");
	return 0;
}