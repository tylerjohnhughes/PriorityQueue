#ifndef READY_QUEUE_H
#define READY_QUEUE_H

#define PRIORITY_CLASSES 64


typedef enum state_types {
    NEW,
    READY,
    RUNNING,
    WAITING,
    HALTED
} StateType;


typedef struct pcb {
    int processID;
    int priority;
    StateType state;
} PCB;

typedef struct pcb_node {
    PCB *pcb;
    struct pcb_node *next;
} PCBNode;

typedef struct fifo_queue {
    PCBNode *head;
    PCBNode *tail;
} FIFOQueue;

typedef struct priority_queue {
    FIFOQueue queues[PRIORITY_CLASSES];
} PriorityQueue;


PCB *PriorityQueue_dequeue(PriorityQueue *);

void PriorityQueue_enqueue(PriorityQueue *queue, const PCB *pcb);


#endif // READY_QUEUE_H
