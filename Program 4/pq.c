//start
#include "pq.h"
#include <stdlib.h> 
#include <stdio.h>

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
typedef struct node {
    int id;
    double priority;
}NODE;

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
struct pq_struct {
  int size;
  int capacity;
  int type;
  int *position;
  NODE *heap;
};

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
PQ * pq_create(int capacity, int min_heap) {
  int i = 0;

  PQ *p = malloc(sizeof(PQ));

  (*p).heap = malloc(sizeof(NODE) * (capacity + 1));
  (*p).position = malloc(sizeof(int) * capacity);

  for (i = 0; i < capacity; i++) {
    (*p).position[i] = -1;
  }

  (*p).size = 0;
  (*p).capacity = capacity;
  (*p).type = min_heap;

  return p;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
void pq_free(PQ * pq) {
  free((*pq).position);
  free((*pq).heap);
  free(pq);
}


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
PQ * perc_up(PQ * pq, int i) {

  if (i / 2 < 1){
    return pq;
  }

  int parentNode = (*pq).heap[i / 2].id;
  int identification = (*pq).heap[i].id;

  if ((*pq).type != 0) {

    if ((*pq).heap[i / 2].priority >= (*pq).heap[i].priority) {

      NODE temp = (*pq).heap[i / 2];

      (*pq).heap[i / 2] = (*pq).heap[i]; 
      (*pq).heap[i] = temp;
      (*pq).position[parentNode] = i;
      (*pq).position[identification] = i / 2; 

      return perc_up(pq, i / 2);
    } 
    else{
      return pq;
    }
  } 
  if ((*pq).heap[i / 2].priority <= (*pq).heap[i].priority) {
    NODE temp = (*pq).heap[i / 2];

    (*pq).heap[i / 2] = (*pq).heap[i]; 
    (*pq).heap[i] = temp;
    (*pq).position[parentNode] = i;
    (*pq).position[identification] = i / 2;

    return perc_up(pq, i / 2);
  } 
  else{
    return pq;
  }
}


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
PQ * perc_down(PQ * pq, int i) {
    if ((i * 2) > (*pq).size){
      return pq;
    }

    int target;
    int identification = (*pq).heap[i].id;

    if ((*pq).type != 0) {
      if ((*pq).heap[(i * 2) + 1].priority > (*pq).heap[i * 2].priority){
        target = i * 2;
      }
      else{
        target = (i * 2) + 1;
      }

      int targetID = (*pq).heap[target].id;

      if ((*pq).heap[target].priority <= (*pq).heap[i].priority) {

        NODE temp = (*pq).heap[target];

        (*pq).heap[target] = (*pq).heap[i]; 
        (*pq).heap[i] = temp;
        (*pq).position[identification] = target;
        (*pq).position[targetID] = i; 

        return perc_down(pq, target);
      } 
      else{
        return pq;
      }
    } 
    else {
      if ((*pq).heap[(i * 2) + 1].priority < (*pq).heap[i * 2].priority){
        target = i * 2;
      }
      else{
        target = (i * 2) + 1;
      }

      targetID = (*pq).heap[target].id;

      if ((*pq).heap[target].priority >= (*pq).heap[i].priority) {

        NODE temp = (*pq).heap[target];

        (*pq).heap[target] = (*pq).heap[i]; 
        (*pq).heap[i] = temp;
        (*pq).position[identification] = target;
        (*pq).position[targetID] = i; 

        return perc_down(pq, target);
      } 
      else{
        return pq;
      }
    }
  }


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int pq_insert(PQ * pq, int id, double priority) {
  if (((*pq).capacity) < ((*pq).size) + 1){
    return 0;
  }
  if ((*pq).capacity < id){
    return 0;
  }
  if ((*pq).position[id] != -1){
    return 0;
  }
  if (id < 0){
    return 0;
  }

  (*pq).size++;

  (*pq).heap[(*pq).size].priority = priority;
  (*pq).heap[(*pq).size].id = id;
  (*pq).position[id] = (*pq).size;

  pq = perc_up(pq, (*pq).size);

  return 1;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int pq_change_priority(PQ * pq, int id, double new_priority) {
  if ((*pq).capacity < id){
    return 0;
  }
  if ((*pq).position[id] == -1){
    return 0;
  }
  if (id < 0){
    return 0;
  }

  if (new_priority == (*pq).heap[(*pq).position[id]].priority){
    return 0;
  }

  (*pq).heap[(*pq).position[id]].priority = new_priority; 

  if ((*pq).type != 0) { 
    if ((*pq).heap[(*pq).position[id]].priority < new_priority){
      pq = perc_down(pq, (*pq).position[id]);
    }
    else {
      pq = perc_up(pq, (*pq).position[id]);
    }
  }
  else {
    if ((*pq).heap[(*pq).position[id]].priority < new_priority){
      pq = perc_up(pq, (*pq).position[id]);
    }
    else {
      pq = perc_down(pq, (*pq).position[id]);
    }
  }

  return 1;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int pq_remove_by_id(PQ * pq, int id) {

  if ((*pq).size < 1){
    return 0;
  }
  if ((*pq).capacity < id){
    return 0;
  }
  if ((*pq).position[id] == -1){
    return 0;
  }
  if (id < 0){
    return 0;
  }

  (*pq).heap[(*pq).position[id]] = (*pq).heap[(*pq).size]; 
  (*pq).position[(*pq).heap[(*pq).size].id] = (*pq).position[id]; 
  (*pq).position[id] = -1; 
  (*pq).size--; 

  pq = perc_down(pq, (*pq).position[id]);

  return 1;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int pq_get_priority(PQ * pq, int id, double * priority) {
  if ((*pq).capacity < id){
    return 0;
  }
  if ((*pq).position[id] == -1){
    return 0;
  }
  if (id < 0){
    return 0;
  }
 
  *priority = (*pq).heap[(*pq).position[id]].priority;

  return 1;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int pq_delete_top(PQ * pq, int *id, double *priority) {
  if ((*pq).size < 1){
    return 0;
  }

  *priority = (*pq).heap[1].priority;
  *id = (*pq).heap[1].id;

  (*pq).heap[1] = (*pq).heap[(*pq).size]; 
  (*pq).position[*id] = -1; 
  (*pq).position[(*pq).heap[(*pq).size].id] = 1;
  (*pq).size--; 

  pq = perc_down(pq, 1);

  return 1;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int pq_peek_top(PQ * pq, int * id, double * priority) {
  if ((*pq).size < 1){
    return 0;
  }

  return 1;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int pq_capacity(PQ * pq) {
  return (*pq).capacity;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
int pq_size(PQ * pq) {
    return (*pq).size;
} 
//end
