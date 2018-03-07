//
// Created by Renan on 07/03/2018.
//

#ifndef CHASH_HASH_TABLE_H
#define CHASH_HASH_TABLE_H
#include <stdlib.h>
#include <stdio.h>
#include <intrin.h>
struct Person{
    int id;
    char *name;
};
// ----------------------------------------------------------------------
struct Hash_Table{
    int QUANTITY,TABLE_SIZE;
    struct Person **people;
};
// ----------------------------------------------------------------------
typedef struct Hash_Table Hash;
typedef struct Person Person;

Hash* createHash(int size);
int valueString(char *string);
int insertWithoutCollision(Hash* hash, Person *person);
int searchWithoutCollision(Hash* hash, int id , Person *person);
int insert(Hash* hash, Person *person);
int search(Hash* hash, int id , Person *person);
int keyDivision(int key,int size );
void freeHash(Hash* hash);

#endif //CHASH_HASH_TABLE_H
