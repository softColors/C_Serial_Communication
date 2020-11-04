#ifndef _QUEUE_H_
#define _QUEUE_H_



#define MAX_QUEUE_SIZE MAX_RX_BUF_SIZE

typedef char element;

typedef struct __circleQueue {
	int rear;
	int front;
	element data[MAX_QUEUE_SIZE];

}Queue;

int Push_Queue(Queue *q, element data);
element Pop_Queue(Queue *q);
void Init_queue(Queue *q);
bool is_full(Queue *q);
bool is_empty(Queue *q);
void Queue_Print(Queue q);
#endif