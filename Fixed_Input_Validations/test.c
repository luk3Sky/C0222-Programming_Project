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
//int streakByColumn(char *array,int column_height);
//int streakByRow(char *array,int row_width);


//static variables
static int grid_len = 0;
//static int word1_length = 0;
//static int word2_length = 0;
static int used_word_number = 0;
static int puzzle_count = 0;
static int word_count = 0;
//static int special_case = 0;

static int grid[10];
//static int result_Array_Row_Str[2];
//static int result_Array_Column_Str[2];
static char word_Array[2][10];
static char puzzle_Array[10][10];
static char result_Array[10][10];

//methods
void getLength(){
	int i;
	for (i = 0; i < 10; ++i){
		if (grid[i] == 0){
			break;
		}else{
			grid_len++;
		}
	}
	//printf("%s\n",grid );
	return;
}

void printArray(){
	int i,j;

	//printf("%s\n",result_Array[0]);
	//printf("%s\n",result_Array[1]);
	//printf("%s\n",result_Array[2]);
	if ((puzzle_count == 0)&&(word_count == 0)){
		return;
	}
	for (i = 0; i < 10; ++i){
        if(grid[i] == 0){
            continue;
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


// -1 --> immediate return;
// 0  --> empty case return;
// 1  --> normal return;
int readPuzzleGrid(){
	
	int puzzle_check_end = 0;
	int row = 0;
	int column = 0;
	char prev = 0;
	char readChar;
	int words = 0;


	while(puzzle_check_end == 0){
		scanf("%c",&readChar);
		//printf("words %d\n",words);
		//printf("F\n");
		//printf("grid %d column %d\n",grid[row],column );
		if (readChar == '\n'){
			grid[row] = column;
			if((readChar == '\n')&&(readChar == prev )){
				//check for double newline - fixed
				puzzle_check_end = 1;
				//printf("AA\n");
				break;
				//return 1;
			}
				
			row++;
			column = 0;
			prev = readChar;
		}else if( !(((readChar == '*') || (readChar == '#')) || (isalpha(readChar))) ){
			puzzle_check_end = -1;
			break;
		}else{
			//printf("CC\n");
			puzzle_Array[row][column] = readChar;
			result_Array[row][column] = readChar;
			words++;
			column++;
			puzzle_count++;
			prev = 0;
		}
	}


	//printf("column %d\n",column );
	if ((words == 0) && (puzzle_check_end == 1)){
		//printf("Empty case return\n");
		return 0;
	}
	printf("puzzle end  %d\n",puzzle_check_end );
	if (puzzle_check_end == 1){
		//printf("normalcase\n");
		return 1;
	}else if (puzzle_check_end = -1){
		return -1;
	}
	//return puzzle_check_end;
}

int read(char *array){
	int check_end = 0;
}

int readInputWords(){
	
	int words_check_end = 0;
	int row = 0,column = 0,count = 10;
	char prev = 0;
	char readChar;
	printf("read input\n");

	while(words_check_end == 0){
		scanf("%c",&readChar);
		//printf("F\n");
		//printf("grid %d column %d\n",grid[row],column );
		if (readChar == '\n'){
			//grid[row] = column;
			if((readChar == '\n')&&(readChar == prev )){
				words_check_end = -1;
				break;
				//return 1;
			}
			row++;
			//column = 0;
			//prev = readChar;
		}else{
			//printf("CC\n");
			if (!isalpha(readChar)){
				//printf("char %c\n", readChar);
				//printf("NOT ALPHABETIC\n");
				words_check_end = -1;
				break;
			}else{
				word_Array[row][column] = readChar;
				result_Array[row][column] = readChar;
				//printf("AA %c\n",readChar);
				column++;
			}
		}
		word_count++;
		prev = readChar;
		//words_check_end = 1;

	}
	words_check_end = 1;

	printf("%d\n",words_check_end );
	//printf("%s\n",word_Array[0] );
	//printf("%s\n",word_Array[1] );
	if ((words_check_end == 1)&&(word_count != 0)){
		return 1;
	}else if(words_check_end == -1){
		printf("AAAAAA\n");
		return -1;
	}else{
		//printf("SMASH\n");
		return 0;
	}
	return 0;
}


int solvePuzzle(){
	getLength();
}

int main(){

	int readPuzzleOutput = readPuzzleGrid();
	printf("readPuzzleGrid() output : %d\n",readPuzzleOutput );
	if (readPuzzleOutput == -1){
		return 0;
	}
	int readWordOutput = readInputWords();
	if (readWordOutput == -1){
		return 0;
	}
	printf("readInputWords() output = %d\n", readWordOutput);
	if ( (readPuzzleOutput == 1)&&(readWordOutput == 1) ){
		printf("SOLVE\n");
		//solvePuzzle(;)
	}else if ( (readPuzzleOutput == 1)&&(readWordOutput == 0) ){
		printArray();
		return 0;
	}else if ( (readPuzzleOutput == 0)&&(readWordOutput == 1) ){
		printf("IMPOSSIBLE\n");
		return 0;
	}else{
		return 0;
	}

	return 0;
}