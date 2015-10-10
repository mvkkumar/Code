//
//  linkedListLoops.c
//  
//
//  Created by Kiran Matturi on 10/6/15.
//
//

#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
    int value;
    struct nod *next;
}node;

void insertNode( node* head, int value)
{
    node * newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    node * tempNode = head;
    while (tempNode->next != NULL)
    {
        tempNode  = tempNode->next;
    }
    tempNode->next = newNode;
}

void createLoop(node * head, int loopValue)
{
    node * tail = head;
    node * currentNode = head;
    
    while ( tail->next != NULL )
    {
        tail = tail->next;
    }
    printf("looped at %i \n",tail->value);
    
    while(  currentNode->value != loopValue )
    {
        currentNode = currentNode->next;
    }
    if( currentNode->value == loopValue )
    {
        tail->next = currentNode;
    }
        printf("looped to %i \n",currentNode->value);
    
}
node * findLoopHead( node* head)
{
    node* tortoise = head->next;
    node* hare = head->next->next;
    
    while ( (tortoise->next != NULL) && (hare->next != NULL) )
    {
        if ( tortoise->value == hare->value )
        {
            break;
        }
        else
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
    }
    //printf("Successfully Looped at %i \n",tortoise->value);
    /* Now we got the member of the loop, lets find the length */
    int count = 0;
    
    tortoise = tortoise->next;
    count++;
    while (tortoise->value != hare->value)
    {
        tortoise = tortoise->next;
        count++;
    }
    printf("number of elements in the loop is %i",count);
    
    /* Now find the start of the Loop */
    node * tempNode = head;
    
    while (tempNode->value != tortoise->value)
    {
        tempNode = tempNode->next;
        tortoise = tortoise->next;
    }
    
    return tempNode;
}
int main()
{
 
    node * head = NULL;
    head = (node*)malloc(sizeof(node));
    head->value = 1;
    head->next = NULL;
    
    node * loopHead = NULL;
//    insertNode(head,2);
    for ( int i = 0; i<15; i++)
        insertNode(head,(i+2));

    createLoop(head,4);
    
    loopHead = findLoopHead(head);
    printf("Found the Loop Head Loop Head is at %i \n",loopHead->value);
    return 0;
}