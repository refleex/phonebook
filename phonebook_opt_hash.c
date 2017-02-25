#include <stdlib.h>

#include "phonebook_opt_hash.h"

unsigned int hash(char lastName[])
{
    int hash_number = 0;
    int h = 53;
    for (int i = 0; lastName[i] != '\0'; i++)
        hash_number = (hash_number * h + lastName[i]) % TABLE;
    return hash_number;
}
entry *findName(char lastName[], entry *pHead[])
{
    unsigned int n = hash(lastName);
    while (pHead[n] != NULL) {
        if (strcasecmp(pHead[n]->lastName, lastName) == 0)
            return pHead[n];
        pHead[n] = pHead[n]->pNext;
    }
    return NULL;
}
void append(char lastName[], entry *e[])
{
    /* allocate memory for the new entry and put lastName */
    int n = hash(lastName);
    e[n]->pNext = (entry *) malloc(sizeof(entry));
    e[n] = e[n]->pNext;
    strcpy(e[n]->lastName, lastName);
    e[n]->pNext = NULL;
}
