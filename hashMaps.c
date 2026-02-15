#include <stdio.h>
#include "hashMapsFunctions.h"
#include <stdlib.h>

node **table;
int tableSize = 0;
int count = 0;
double loadFactor = 0;



int hash(int k);
void initFunction(int x, node **head);
int rehash(node **table1);
void debugPrint(int x, node **head);
void insert(int key, int value);
int deleteNode(int key);
void destroyTable(/*currently this is empty but normally we should be taking an argumrnt of the table*/);
int search(int key);



int main()
{
    tableSize =  7;
    table = malloc(tableSize*sizeof(*table));
    initFunction(tableSize, table);
    debugPrint(tableSize, table);
    insert(5, 10);
    debugPrint(tableSize, table);
    insert(58, 10);
    debugPrint(tableSize, table);
    insert(13, 10);
    debugPrint(tableSize, table);
    insert(22, 10);
    debugPrint(tableSize, table);
    insert(23, 10);
    debugPrint(tableSize, table);
    insert(24, 10);
    debugPrint(tableSize, table);
    insert(10, 10);
    insert(15, 10);
    insert(25, 10);
    insert(35, 10);
    debugPrint(tableSize, table);

    return 0;
}




int hash(int k)
{
    k = ((k % tableSize) + tableSize) % tableSize;
    return k;
}


void initFunction(int x, node **head)
{
    for (int i = 0; i < x; i++)
    {
        head[i] = NULL;
    }
}


int rehash(node **table1)
{
    node *oldCurrent = NULL;
    node *newCurrent = NULL;
    if (loadFactor >= 1)
    {
        // grow table       
        tableSize = tableSize * 2;
        node **newTable = malloc(tableSize * sizeof(*newTable));
        initFunction(tableSize, newTable);
        for (int i = 0; i < (tableSize / 2); i++)
        {
            if (table1[i] == NULL)
            {
                continue;
            }
            else
            {
                
                oldCurrent = table1[i];
                newCurrent = NULL;
                while (oldCurrent != NULL)
                {
                    int key2 = hash(oldCurrent->key);
                    if (newTable[key2] == NULL)
                    {
                        newTable[key2] = malloc(sizeof(node));
                        newTable[key2] -> key = oldCurrent -> key;
                        newTable[key2] -> value = oldCurrent -> value;
                        newTable[key2] -> next = NULL;  
                    }
                    else
                    {
                        
                        newCurrent = newTable[key2];
                        while(newCurrent -> next != NULL){
                           newCurrent = newCurrent -> next; 
                        }
                        node *newNode = malloc(sizeof(node));
                        newNode-> key = oldCurrent -> key;
                        newNode-> value = oldCurrent -> value;
                        newNode-> next = NULL;
                    }
                    oldCurrent = oldCurrent->next; 
                }
            }
        }
        free(table1);
        table = newTable; 
        return 0;
    }
    else if(loadFactor <= 0.45)
    {
        // shrink table
        int cTable = tableSize; 
        tableSize = (int) tableSize / 2;
        node **newTable = malloc(tableSize * sizeof(node));
        initFunction(tableSize, newTable);
        for (int i = 0; i < cTable; i++)
        {
            if (table1[i] == NULL)
            {
                continue;
            }
            else
            {
                oldCurrent = table1[i];
                newCurrent = NULL;
                while (oldCurrent != NULL)
                {
                    int key2 = hash(oldCurrent->key);
                    if (newTable[key2] == NULL)
                    {
                        newTable[key2] = malloc(sizeof(node));
                        newTable[key2] -> key = oldCurrent -> key;
                        newTable[key2] -> value = oldCurrent -> value;
                        newTable[key2] -> next = NULL;  
                    }
                    else
                    {
                        
                        newCurrent = newTable[key2];
                        while(newCurrent -> next != NULL){
                           newCurrent = newCurrent -> next; 
                        }
                        node *newNode = malloc(sizeof(node));
                        newNode-> key = oldCurrent -> key;
                        newNode-> value = oldCurrent -> value;
                        newNode-> next = NULL;
                    }
                    oldCurrent = oldCurrent->next; 
                }
            }
        }
        free(table1);
        table = newTable; 
        return 0;
    }
    printf("\ncouldn't resize the talbe");
    return -1;
}
void debugPrint(int x, node **head)
{
    for (int i = 0; i < x; i++)
    {
        if (head[i] == NULL)
        {
            printf("\nValue/s at position %d : empty", (i+1));
        }
        else
        {

            node *current = head[i];
            printf("\nValue/s at position %d :", (i+1));
            while (current->next != NULL)
            {
                printf(" (%d, %d) - >", current->key, current->value);
                current = current->next;
            }
            printf(" (%d, %d).", current->key, current->value);
        }
    }
}
void insert(int key, int value)
{
    int newKey = hash(key);

    if (table[newKey] == NULL)
    {
        node *newNode = malloc(sizeof(node));
        if (!newNode)
        {
            printf("\nMalloc did not work");
            return;
        }
        newNode->key = key;
        newNode->value = value;
        newNode->next = NULL;
        table[newKey] = newNode;
    }
    else
    {
        node *current = table[newKey];
        node *prev = NULL;
        while (current != NULL)
        {
            if (current->key == key)
            {
                current->value = value;
                return; // we return here because insert has performed its function.
            }
            prev = current;
            current = current->next;
        }

        node *newNode = malloc(sizeof(node));
        if (!newNode)
        {
            printf("\nMalloc did not work");
            return;
        }
        newNode->key = key;
        newNode->value = value;
        newNode->next = NULL;

        prev->next = newNode;
    }
    
    debugPrint(tableSize, table);
    count++; 
    loadFactor = count/tableSize;
        if(loadFactor >= 1 || loadFactor <= 0.45){
        printf("\nWe entered the if rehash function");
        rehash(table);
    } 
    printf("\nInserted successfully");
}

int deleteNode(int key)
{
    int newKey = hash(key);
    node *current = table[newKey];
    node *prev = NULL;

    while (current != NULL)
    {
        if (key == current->key)
        {
            if (prev == NULL)
            {
                table[newKey] = current->next;
                free(current);
                return 1;
            }
            else
            {
                prev->next = current->next;
                free(current);
                return 1;
            }
        }
        prev = current;
        current = current->next;
    }
    
    count--; 
    loadFactor = count/tableSize;
    if(loadFactor <= 0.45){
        rehash(table);
    }
    return 0;
}
void destroyTable(/*currently this is empty but normally we should be taking an argumrnt of the table*/)
{
    node *current = NULL;
    node *prev = NULL;
    for (int i = 0; i < tableSize; i++)
    {
        current = table[i];
        while (current != NULL)
        {
            prev = current;
            current = current->next;
            free(prev);
            prev = NULL;
        }
        table[i] = NULL;
    }
}
int search(int key)
{
    int newKey = hash(key);

    node *current = table[newKey];
    while (current != NULL)
    {
        if (current->key == key)
        {
            printf("\nA value for  key \"%d\" has been found: %d", current->key, current->value);
            return current->value;
        }
        current = current->next;
    }
    printf("\nA value for  key \"%d\" could not be found ", key);
    return -1;
}