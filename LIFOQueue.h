#ifndef LIFOQueue
#define LIFOQueue

// include Arduino basic header.
#include <Arduino.h>

class LiFoQueue {
  public:
    int maxQueueSize;
    typedef struct node {
      double value;
      struct node * next;
    } node_t;

    //Constructor
    LiFoQueue(int maxQueueSize);
    
    //Methods:
    void pushValue(double value);
    int getSize();
    double getAvarage();
    void printQueue();

  private:
    node_t * head;    
};
#endif
