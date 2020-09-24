#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"

typedef struct Pair Pair;
typedef struct HashMap HashMap;
int enlarge_called=0;

struct Pair {
     char * key;
     void * value;
};

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {
int position = hash(key,map->capacity);
int i;
Pair * uwu = createPair(key,value);

for (i = position ; position <= map->capacity ;i++){
  if ((map->buckets[i] == NULL) || (uwu->key == NULL)){
    map->buckets[i] = uwu;
    map->size++;
    break;
   }
  if (i == (map->capacity - 1)){
    i = 0;
  }

 }
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {
  HashMap * mappsi = (HashMap*) malloc(sizeof(HashMap));
  mappsi->buckets = (Pair **) calloc(capacity, sizeof(Pair *));
  mappsi-> capacity = capacity;
  mappsi-> current = -1;
return mappsi;
}

void eraseMap(HashMap * map,  char * key) {    
 int iwi = hash(key,map->capacity);
 int i;
 for (i = iwi;iwi<map->capacity;i++){
  if (map->buckets[i] != NULL){
    map->buckets[i]->key = NULL;
    map->buckets[i]->value = NULL;
    map->size--;
    break;
  }
 }

}

void * searchMap(HashMap * map,  char * key) {   
   int possibly = hash(key,map->capacity);
   int i;
   for (i = possibly;possibly < map->capacity;i++){
     if (map->buckets[i] != NULL){
      if (is_equal(key, map->buckets[i]->key ) == 1){
        map->current = i;
        return  map->buckets[i]->value;
      }
    }
    else
    break;
   }

    return NULL;
}

void * firstMap(HashMap * map) {

    return NULL;
}

void * nextMap(HashMap * map) {

    return NULL;
}
