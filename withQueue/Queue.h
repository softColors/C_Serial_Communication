#ifndef _QUEUE_H_
#define _QUEUE_H_



#define QUEUE_MAX_SIZE 128

typedef char element;

typedef struct __circleQueue {
	int rear;
	int front;
	element data[QUEUE_MAX_SIZE];

}Queue;

int Push_Queue(Queue *q, element data);
element Pop_Queue(Queue *q);
void Init_queue(Queue *q);
bool is_full(Queue *q);
bool is_empty(Queue *q);
void Queue_Print(Queue q);
#endif