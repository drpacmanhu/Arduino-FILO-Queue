#include "LIFOQueue.h"
#include "Arduino.h"

LiFoQueue::LiFoQueue(int paramMaxQueueSize) {
  maxQueueSize = paramMaxQueueSize;
  //this is the constructor do what needs to be done
  head = NULL;
  head = (node_t*)malloc(sizeof(node_t));
  head->value = 0;
  head->next = NULL;
}

void LiFoQueue::pushValue(double value){
  node_t * current = head;
  //if the list has more items then 10 we need to remove the oldest one
  if (getSize() > maxQueueSize) {
    node_t * oldest = head->next;
    head->next = oldest->next;
    free(oldest);
  }
  while (current->next != NULL) {
    current = current->next;
  } 

  /* now we can add a new variable */
  current->next = (node_t*)malloc(sizeof(node_t));
  current->next->value = value;
  current->next->next = NULL;
}

int LiFoQueue::getSize(){
  int counter = 0;
  node_t * current = head->next;
  while (current != NULL) {
    counter++;
    current = current->next;
  }
  return counter;
}

double LiFoQueue::getAvarage() {
  double avarage = 0;
  int counter = 0;
  node_t * current = head->next;
  while (current != NULL) {
    avarage += current->value;
    counter++;
    current = current->next;
  }
  return avarage/counter;
}

void LiFoQueue::printQueue() {
  Serial.println("The items in the queue are the followings:");
  node_t * current = head->next;
  while (current != NULL) {
    Serial.println(current->value);
    current = current->next;
  }
}

