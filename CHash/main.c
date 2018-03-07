#include "Hash_Table.h"

Person* newPerson(char* name,int id){
    Person *new = malloc(sizeof(Person));
    new->id = id;
    new->name = malloc(strlen(name));
    strcpy(new->name, name);
    return new;
}

int main() {
    Hash* hash;
    printf("Creating a Hash Table!\n");
    hash = createHash(997);

    printf("Populating the Table!\n");

    Person *a = newPerson("Wenzel Otto",775);
    Person *b = newPerson("Livie Paulina",171);
    Person *c = newPerson("Elina Alma",844);
    Person *d = newPerson("Ariel Brett",520);
    Person *e = newPerson("Viviane Winston",294);

    insertWithoutCollision(hash,a);
    insertWithoutCollision(hash,b);
    insertWithoutCollision(hash,c);
    insertWithoutCollision(hash,d);
    insertWithoutCollision(hash,e);

    printf("Displaying the Table!\n");
    if(searchWithoutCollision(hash,a->id,a)){
        printf("(Name: %s / Id: %d)",a->name,a->id);
    }
}

