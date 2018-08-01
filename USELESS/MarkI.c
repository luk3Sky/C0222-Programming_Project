#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  node{
	char *word;
	int length;
	struct node *next;
} Node;

int ite;
//int checkWordLength();
void addWord(Node *head, int to, char *text);
void printList(Node *head);
/*int checkWordLength(){

}
*/
//add a word to a given list
void addWord(Node *head, int to, char *text){
	Node *current;
	current = head;
	while(current != NULL){
		if (ite == to){
			current->word = strdup(text);
			current->length = strlen(text);
			current->next = malloc(sizeof(Node));
			ite = 0;
			return;
		}
		ite++;
		current = current->next;
	}
	current->next = NULL;
	return;
}

//print the whole list
void printList(Node *head){
	
	Node *current;
	current = head;

	while(current->next != NULL){
		printf("%d %s\n",current->length, current->word);
		current = current->next;
	}
	if (current == NULL){
		return;
	}
	return;
}




int main(){
	char *read;
	char adtnlChar,readChar;


	int puzzle_check_end,index = 0, count = 0;
	static char puzzle_Array[10][10];
	static char word_Array[10][10];

	while(1){
		scanf("%c",&readChar);
		if (puzzle_check_end != 1){
			if (readChar == '\n'){
				if (index == count-1){
					puzzle_check_end = 1;
				}
				index++;
				count = 0;
			}else{
				puzzle_Array[index][count++] = readChar;
				//printf("enter success!\n");
			}
		}
		
	}


	//Node *head = (Node *)malloc(sizeof(Node));
	//head->next = (Node *)malloc(sizeof(Node));
	//int d,count = 0;
/*	while(1){
		d = scanf("%c",&adtnlChar);
		if (d == 0){
			break;
		}
		count ++;
		printf("%c \t count = %d\n",adtnlChar,count);
	}

*/	
/*
	int isEnd = 0;
	while(isEnd != 2){

	}

*/
	return 0;
}