//
// Created by Renan on 07/03/2018.
//

#include "Hash_Table.h"
// ----------------------------------------------------------------------
Hash* createHash(int size){
    Hash* hash = (Hash*) malloc(sizeof(Hash));
    if(hash != NULL){
        int i;
        hash->TABLE_SIZE = size;
        //Without pointer to pointer it is not possible to do this: hash->people[i].
        hash->people = (struct Person **) malloc(size * sizeof(struct Person));

        if(hash->people == NULL){
            printf("Error while memory allocation");
            free(hash);
            return NULL;
        }

        hash->QUANTITY = 0;
        for(i = 0; i < hash->TABLE_SIZE; i++){
            hash->people[i] = NULL;
        }
    }
    return hash;
}
// ----------------------------------------------------------------------
int valueString(char *string){

}
// ----------------------------------------------------------------------
int insertWithoutCollision(Hash* hash, Person *person){
    if(hash == NULL || hash->QUANTITY == hash->TABLE_SIZE){
        printf("Error, no Hash Table");
        return 0;
    }

    struct Person* new = (struct Person*) malloc(sizeof(struct Person));

    if(new == NULL){
        printf("Error while memory allocation");
        return 0;
    }

    new = person;
    hash->people[keyDivision(person->id,hash->TABLE_SIZE)] = new;
    hash->QUANTITY++;
    return 1;
};
// ----------------------------------------------------------------------
int searchWithoutCollision(Hash* hash, int id , struct Person* person){
    if (hash == NULL){
        printf("Hash table is empty");
        return 0;
    }else{
        int position = keyDivision(person->id,hash->TABLE_SIZE);
        if(hash->people[position] == NULL){
            printf("Hash table is empty at this position");
            return 0;
        } else{
            person = hash->people[position];
            return 1;
        }

    }

}
// ----------------------------------------------------------------------
int insert(Hash* hash, Person *person){}
// ----------------------------------------------------------------------
int search(Hash* hash, int id , Person* person){}
// ----------------------------------------------------------------------
void freeHash(Hash* hash){
    if(hash != NULL){
       for(int i = 0; i< hash->QUANTITY; i++){
           if(hash->people[i] != NULL){
               free(hash->people[i]);
           }
       }
        free(hash->people);
        free(hash);
    }
}
// ----------------------------------------------------------------------
int keyDivision(int key,int size ){
    return ( key & 0x7FFFFFFF) % size;
}
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------