
/* //////  CO222 - PROJECT - PUZZLE SOLVING PROGRAM	////////
------------------------------------------------------------
<<<<<<<<<<< ******* ==@luke==  E/15/142  ******* >>>>>>>>>>> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//method prototypes
int readPuzzleGrid();
int readInputWords();
int solvePuzzle();
void getLength();
void printArray();
void printArray_int(int *array,int m);

//static variables
static int grid_height = 0;
static int word1_length = 0;
static int word2_length = 0;
static int used_word_number = 0;

static int grid[10];
static int result_Array_Row_Str[2];
static char word_Array[2][10];
static char puzzle_Array[10][10];

//methods
void getLength(){
	word1_length = strlen(word_Array[0]);
	word2_length = strlen(word_Array[1]);
	return;
}

void printArray(){
	int i,j;
	//printf("char Array : ");
	for (i = 0; i < 10; ++i){
        if(grid[i] == 0){
            break;
        }
        for(j = 0; j<grid[i];j++){
            printf("%c", toupper(puzzle_Array[i][j]));
        }
        printf("\n");
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
		}else if( !((readChar == '*') || (readChar == '#')) ){
			puzzle_check_end = -1;
			break;
		}else{
			puzzle_Array[row][column] = readChar;
			column++;
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

// method to detect hash streak by row-wise 
// return no. of streaks if matches streaks
// otherwise -1 
// result_Array_Row_Str ----- [0] - index of the first hash occurence column in the array
//						----- [1] - index of the input word
int streakByRow(char *array,int row_width){
	int index = 0;
	int i,j,count = 0;
	int start;
	result_Array_Row_Str[0] = -1;// no streak default value -->> -1
	result_Array_Row_Str[1] = -1;


	for (i = 0; i <row_width ; ++i){
		if (array[i] == '#'){
			if (index == 0){
				start = i;
			}
			count++;
		}
	}
	if( (count>=2) && ((count>=word1_length) || (count>=word2_length)) ){
		if (count){
			/* code */
		}
		if ((count <= word1_length)&& (used_word_number != 1) ){
			//printf("matches word1\n");
			result_Array_Row_Str[1] = 1;
			//printf("word 1 == %d\n", result_Array_Row_Str[1]);
			result_Array_Row_Str[0] = start - count + 1;
			count = 0;
			used_word_number = 1;
		}else if ((count <= word2_length)&& (used_word_number != 2)){
			//printf("matches word2\n");
			result_Array_Row_Str[1] = 2;
			//printf("word 2 == %d\n", result_Array_Row_Str[1]);
			result_Array_Row_Str[0] = start - count + 1;
			count = 0;
			used_word_number = 2;
		}else{
			//printf("AAAA\n");	
			if (used_word_number == 1){
				//printf("word2 matches\n");
			}else if (used_word_number == 2){
				//printf("word1 matches\n");
			}
		}
				
	}
	if (result_Array_Row_Str[0] == -1){
		//printf("no matches \n");
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
		if( (grid[x] < word1_length) || (grid[x] < word2_length)){
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
		int i,j;

		for (i = 0; i < 10; ++i){
				if (grid[i] == 0){
					break;
				}
				//printf("PUZZLE : %s grid len : %d\n",puzzle_Array[i],grid[i] );
				if (streakByRow((char *)puzzle_Array[i],grid[i]) == 1){
					//printf("streak found in column %d and word %d\n", result_Array_Row_Str[0] , result_Array_Row_Str[1] );
					//printf("%s\n", word_Array[result_Array_Row_Str[1]-1]);
					for (j = 0; j < strlen(word_Array[result_Array_Row_Str[1]-1]) ; j++){
						puzzle_Array[i][j+result_Array_Row_Str[0]] = word_Array[result_Array_Row_Str[1]-1][j];
					}
					continue;
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
	//printArray_int(grid,10);
	if (solvePuzzle() == 0){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	//printf("width : %d\n", grid_height);
	//printf("word1 len : %d \n", word1_length);
	//printf("word2 len : %d \n", word2_length);
	//printf("grid height%d\n", grid_height);
	/*printArray(puzzle_Array[0],10);
	printArray(puzzle_Array[1],10);
	printArray(puzzle_Array[2],10);
	printArray(puzzle_Array[3],10);
    */
	//printf("\n");
    //int l;
    printArray();
	return 0;
}