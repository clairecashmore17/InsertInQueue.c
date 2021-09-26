//Claire Cashmore
// CS315 HW #3
// Queue in a circular linked list

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct circularList{
   char userChar;
   struct circularList* next;
} CLL; //CLL  will be quicker to write out for circularLinkedLists

void printing(CLL** Q);
void insert(CLL** Q, CLL* ptrToNewTemp);
void removeChar(CLL** Q);

int main(){
// Create our beginning pointers.
   CLL* ptrToTopOfQueue = NULL;
   CLL* ptrToTemp;
   
   char userInput;
   
   //Ask the user what they want to do with the list.
   printf("Enter an i to insert, an r to remove, and a q to exit: ");
  
   
   scanf(" %c",&userInput);
   
   //While it's not quitting
   while(userInput != 'q'){
   
   /***********Insert******************/
      if(userInput == 'i'){
      //Enter in the character to put in the queue
         printf("\nEnter a character to be inserted: ");
         scanf(" %c",&userInput);
         //Create the block of memory for the temp;
         ptrToTemp = malloc(sizeof(CLL));
         ptrToTemp->userChar = userInput;
         
         //Insert the new character into the queue
         insert(&ptrToTopOfQueue, ptrToTemp);
      }
      /*************Remove*********************/
      else if((userInput == 'r') && (ptrToTopOfQueue == NULL)){
         printf("\nEmpty List removal impossible\n\n");
      }
      else if(userInput == 'r'){
         removeChar(&ptrToTopOfQueue);
      }
      /**************Invalid Character***************/
      else{
         printf("\nInvalid operation.\n\n");
      }

      // Re-ask once the last user input was evaluated.
      printf("\nEnter an i to insert, an r to remove, and a q to exit: ");
   
     
      scanf(" %c",&userInput);
   }
   
   return 0;
}

/***************Insert Function*************************/
void insert(CLL** ptrToPtrTopOfQueue, CLL* ptrToNewguy){
    // Case: The first list item has not been put in yet
   if(*ptrToPtrTopOfQueue == NULL){
      *ptrToPtrTopOfQueue = ptrToNewguy;
      (*ptrToPtrTopOfQueue)->next = *ptrToPtrTopOfQueue;
   }
   // Case: First list item has been added
   else{
      ptrToNewguy->next = (*ptrToPtrTopOfQueue)->next;
      (*ptrToPtrTopOfQueue)->next = ptrToNewguy;
      *ptrToPtrTopOfQueue = ptrToNewguy;
   }
}
/**************Remove Function*************************/
void removeChar(CLL** ptrToPtrTopOfQueue){
   char removedValue;
   
   //Case: if the next does not have the same address as the top pointer
   if(((*ptrToPtrTopOfQueue)->next) != *ptrToPtrTopOfQueue){
      removedValue = ((*ptrToPtrTopOfQueue)->next)->userChar;
      (*ptrToPtrTopOfQueue)->next = ((*ptrToPtrTopOfQueue)->next)->next;
   }
   //Case: the next has the same address as the top pointer
   else if(((*ptrToPtrTopOfQueue)->next) == *ptrToPtrTopOfQueue){
      removedValue = ((*ptrToPtrTopOfQueue)->next)->userChar;
      *ptrToPtrTopOfQueue = NULL;
   }
   printf("Item removed: %c\n", removedValue);
}

/*****************Print function**********************/
void printing(CLL** ptrToPtrTopOfQueue){
   if(*ptrToPtrTopOfQueue != NULL){
      CLL* tracer;
      printf("\nHere is your list.\n");  
      tracer = (*ptrToPtrTopOfQueue)->next;
      do{
         printf("%c", tracer->userChar);
         tracer = tracer->next;
      }while(tracer != ((*ptrToPtrTopOfQueue)->next));
      putchar('\n');
   }
}
