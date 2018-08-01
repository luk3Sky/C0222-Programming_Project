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
void swap(int *array,int x);
void bubbleSort(int *array,int *array2,int length);

//int streakByColumn(char *array,int column_height);
//int streakByRow(char *array,int row_width);


//static variables
static int grid_len = 0;
//static int word1_length = 0;
//static int word2_length = 0;
static int used_word_number = 0;
static int number_of_puzzle_rows = 0;
static int number_of_word_rows  = 0;
static int word_count = 0;
//static int special_case = 0;

static int grid_row_length_array[10];
//static int result_Array_Column_Str[2];
static char word_Array[2][10];
static int grid_Column_Array[2][10];
static int row_Counters[10];
static int sorted_Counters[10];
static int sorted_Column_counters[10];
static int row_Starts[10];
static int column_Counters[10];
static int column_Starts[10];
static char puzzle_Array[10][20];
static char result_Array[10][20];

//methods
void getLength(){
	int i;
	for (i = 0; i < 20; ++i){
		if (grid_row_length_array[i] == 0){
			break;
		}else{
			//printf("%d\n",grid_row_length_array[i]);
			grid_len++;
		}
	}
	//printf("row counter %d\n", number_of_puzzle_rows );
	return;
}

void swap(int *array,int x){
	int temp;
	if (array[x+1] == 0){
		return;
	}
	temp = array[x];
	array[x] = array[x+1];
	array[x+1] = temp;
	return;
}

void bubbleSort(int *array,int *array2,int length){
	int i,j;
	for (i = 0; i < length; ++i){
		for (j = 0; j < length; j++){
			if (array[j+1] == 0){
				//printf("%d DDD\n",j );
				return;
			}else if (array[j] < array[j+1]){
				//printf("continue\n");
				swap(array,j);
			}else if(array[j] > array[j+1]){
				//printf("swap\n");
				continue;
				//swap(array2,j);
			}
		}
	}

}

void printArray(){
	int i,j;

	//printf("%s\n",result_Array[0]);
	//printf("%s\n",result_Array[1]);
	//printf("%s\n",result_Array[2]);
	if ((number_of_puzzle_rows == 0)&&(word_count == 0)){
		return;
	}
	for (i = 0; i < 20; ++i){
        if(grid_row_length_array[i] == 0){
            continue;
        }
        if (i != 0){
	        printf("\n");
        }
        for(j = 0; j<grid_row_length_array[i];j++){
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
		//printf("grid_row_length_array %d column %d\n",grid_row_length_array[row],column );
		if (readChar == '\n'){
			//grid_row_length_array[row] = column;

			//printf("%d\n",grid_row_length_array[row]);
			if((readChar == '\n')&&(readChar == prev )){
				//check for double newline - fixed
				puzzle_check_end = 1;
				//printf("AA\n");
				break;
				//return 1;
			}else{
				number_of_puzzle_rows++;
			row++;
			column = 0;
			prev = readChar;
			}
		}else if( !(((readChar == '*') || (readChar == '#')) || (isalpha(readChar))) ){
			puzzle_check_end = -1;
			break;
		}else{
			//printf("CC\n");
			puzzle_Array[row][column] = readChar;
			result_Array[row][column] = readChar;
			words++;
			column++;
			prev = 0;
		}

		grid_row_length_array[row] = (int) strlen(puzzle_Array[row]);
	}


	for (row = 0; row < grid_row_length_array[row]; row++){
		/*if (row == grid_row_length_array[row]-1){
			printf("BREAK\n");
			continue;
		}*/
		/*
		for (column = 0; column < grid_row_length_array[row]; column++){
			grid_Column_Array[row][column] = puzzle_Array[column][row];
			printf("%c ", grid_Column_Array[row][column]);
		}
		printf("\n");
		*/
	}



	//printf("column %d\n",column );
	if ((words == 0) && (puzzle_check_end == 1)){
		//printf("Empty case return\n");
		return 0;
	}
	//printf("puzzle end  %d\n",puzzle_check_end );
	if (puzzle_check_end == 1){
		//printf("normalcase\n");
		return 1;
	}else if (puzzle_check_end = -1){
		return -1;
	}
	//return puzzle_check_end;
}

// -1 --> immediate return;
// 0  --> empty case return;
// 1  --> normal return;
int readInputWords(){

	int words_check_end = 0;
	int row = 0,column = 0,count = 10;
	char prev = 0;
	char readChar;
	//printf("read input\n");

	while(1){
		scanf("%c",&readChar);
		//printf("F\n");
		//printf("grid_row_length_array %d column %d\n",grid_row_length_array[row],column );
		if (readChar == '\n'){
			//grid_row_length_array[row] = column;
			if((readChar == '\n')&&(readChar == prev )){
				//words_check_end = -1;
				break;
				//return 1;
			}
			row++;
			column = 0;
			//prev = readChar;
			number_of_word_rows++;
		}else{
			//printf("CC\n");
			if (!isalpha(readChar)){
				//printf("char %c\n", readChar);
				//printf("NOT ALPHABETIC\n");
				//words_check_end = -1;
				break;
			}else{
				word_Array[row][column] = readChar;
				//result_Array[row][column] = readChar;
				//printf("AA %c\n",readChar);
				word_count++;
				column++;
			}
		}
		prev = readChar;
		//words_check_end = 1;

	}
	words_check_end = 1;

	//printf("%d\n",word_count );
	//printf("%s\n",word_Array[0] );
	//printf("%s\n",word_Array[1] );
	if ((words_check_end == 1)&&(word_count != 0)){
		return 1;
	}else if(words_check_end == -1){
		//printf("AAAAAA\n");
		return -1;
	}else{
		//printf("SMASH\n");
		return 0;
	}
	return 0;
}


int solvePuzzle(){

	int row = 0;
	int column = 0;
	int index = 0;
	int start = -1;
	int prev = 0;
	int count = 0;
	int raw_Streaks[number_of_puzzle_rows];
	int cannot_Solve = 0;
	while(row < number_of_puzzle_rows){
		//printf("lol %s\n",puzzle_Array[row] );
		//printf("grid len %d\n",grid_row_length_array[row]);
		//column = 0;
		while(column < grid_row_length_array[row]){
			if (((puzzle_Array[row][column]) !='*')&&(prev == 1)){
				count++;
				//printf("row %d column %d %c count %d\n", row,column,puzzle_Array[row][column],count);
				index++;
			}else if ( ((puzzle_Array[row][column]) !='*') ){
				count++;
				prev = 1;
				if (index == 0){
					start = column;
				}
				index++;
				//column++;
			}else{
				prev = 0;
				if ((count >= 2)||(column == grid_row_length_array[row]-1)){
					//printf("final 1 count :%d start :%d \n",count,start);
					row_Counters[row] = count;
					sorted_Counters[row] = count;
					row_Starts[row] = start;
					column = 0;
					//column++;
					index = 0;
					start = -1;
					count = 0;
					row++;
					continue;
				}
			}
			if ((column == grid_row_length_array[row]-1)){
				//printf("final count %d start %d \n",count,start);
				row_Counters[row] = count;
				sorted_Counters[row] = count;
				row_Starts[row] = start;
				column = 0;
				//column++;
				index = 0;
				start = -1;
				count = 0;
				row++;
				continue;
			}
			column++;
			//index++;
			//prev = 0;
			//printf("count start %d %d\n",count,start);
		}
		row++;

	}


	getLength();

	bubbleSort(sorted_Counters,row_Starts,number_of_puzzle_rows);
	for (row = 0; row < number_of_puzzle_rows; row++){
		printf("%d ", sorted_Counters[row]);
	}
	for (row = 0; row < number_of_puzzle_rows; row++){
		printf("%d ", row_Starts[row]);
	}

	printf("\n");

	//printf("number_of_word_rows %d\n", number_of_word_rows);
	int i,j,x;
	printf("word_Array len for 0 %d\n", (int)strlen(word_Array[0]));
	printf("word_Array len for 1 %d\n", (int)strlen(word_Array[1]));
	for (i = 0; i < number_of_puzzle_rows; i++){
		if (row_Counters[i] == 0){
			//printf("Break\n");
		}else{
			for (j = 0; j < number_of_word_rows; j++){
				printf("count %d length %d j %d\n", row_Counters[i],strlen(word_Array[j]),j);
				if (row_Counters[i] == (int)strlen(word_Array[j])){
					printf("Match word length\n");
					for (x = 0; x < strlen(word_Array[j]); x++){
						if ( (tolower(puzzle_Array[i][x+row_Starts[i]]) == tolower(word_Array[j][x])) || (tolower(puzzle_Array[i][x+row_Starts[i]]) == '#') ){
							result_Array[i][x+row_Starts[i]] = word_Array[j][x];
							continue;
						}else{
							printf("%c %c\n",tolower(puzzle_Array[i][x+row_Starts[i]]),tolower(word_Array[j][x]));
						}
					}
					used_word_number++;

				}else{
					/*if ((row_Counters(i) > 0 )&&()){

                    }*/
					printf("Didnt match\n");
					continue;
				}
			}


			printf("matched words %d %s\n", used_word_number, result_Array[i]);
		}

	}

    row = 0;
	column = 0;
	prev = 0;
	index = 0;
	start = -1;
	count = 0;

	//column Countings
	//ERROR
	while(row < number_of_puzzle_rows){
	    //column = 0;
        while(column < grid_row_length_array[column]){
            printf("%c ",puzzle_Array[column][row]);
            if (((puzzle_Array[column][row]) !='*')&&(prev == 1)){
				count++;
				//printf("column %d row %d %c count %d\n", column,row,puzzle_Array[column][row],count);
				index++;
			}else if ( ((puzzle_Array[column][row]) !='*') ){
				count++;
				prev = 1;
				if (index == 0){
					start = column;
				}
				index++;
				//row++;
			}else{
				prev = 0;
				if ((count >= 2)||(column == grid_row_length_array[row]-1)){
					printf("final 1 count :%d start :%d \n",count,start);
					column_Counters[row] = count;
					sorted_Column_counters[row] = count;
					column_Starts[row] = start;
					//row = 0;
                    column = 0;
					//row++;
					index = 0;
					start = -1;
					count = 0;
					//column++;
					row++;
					continue;
				}
			}
			if ((column == grid_row_length_array[row]-1)){
				printf("final count %d start %d \n",count,start);
				column_Counters[row] = count;
				sorted_Column_counters[row] = count;
				column_Starts[row] = start;
				//row = 0;
				column = 0;
				//row++;
				index = 0;
				start = -1;
				count = 0;
				//column++;
				row++;
				continue;
			}
			column++;
			//index++;
			//prev = 0;
			//printf("count start %d %d\n",count,start);
		}
        row++;
	}

	for (row = 0; row < number_of_puzzle_rows; row++){
		printf("%d ", column_Counters[row]);
	}
	for (row = 0; row < number_of_puzzle_rows; row++){
		printf("%d ", column_Starts[row]);
	}





	// printf("%d\n", column_Counters[0]);
	// printf("%d\n", column_Counters[1]);
	// printf("%d\n", column_Counters[2]);

	i = 0;
	j = 0;
	int k = 0;

	for (i = 0; i < number_of_puzzle_rows; i++){
		if (column_Counters[i] == 0){
			//printf("Break\n");
		}else{
			for (j = 0; j < number_of_word_rows; j++){
				printf("count %d length %d j %d\n", column_Counters[i],strlen(word_Array[j]),j);
				if (column_Counters[i] == (int)strlen(word_Array[j])){
					printf("Match word length\n");
					for (x = 0; x < strlen(word_Array[j]); x++){
						if ( (tolower(grid_Column_Array[i][x+column_Starts[i]]) == tolower(word_Array[j][x])) || (tolower(grid_Column_Array[i][x+column_Starts[i]]) == '#') ){
							result_Array[i][x+column_Starts[i]] = word_Array[j][x];
							continue;
						}else{
							printf("%c %c\n",tolower(grid_Column_Array[i][x+column_Starts[i]]),tolower(word_Array[j][x]));
						}
					}
					used_word_number++;

				}else{
					/*if ((column_Counters(i) > 0 )&&()){

		            }*/
					printf("Didnt match\n");
					continue;
				}
			}


			printf("matched words %d %s\n", used_word_number, result_Array[i]);
		}

	}










	if (used_word_number == number_of_word_rows){
		printf("SOLVED\n");
	}else if ((used_word_number == 0) && (sorted_Counters[0] > 0)){
		printf("IMPOSSIBLE\n");
		return 0;
	}




	return 0;

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
		solvePuzzle();
		//printf("word count %d \n", word_count);
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
