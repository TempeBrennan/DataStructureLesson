
#define MAXQUEUESIZE 100000

typedef struct {
	int data[MAXQUEUESIZE];
	int front, rear;
}Queue, *QueuePTR;

QueuePTR CreateQueue();

bool EnterQueue(QueuePTR q, int x);

int DeleteQueue(QueuePTR q);

bool EmptyQueue(QueuePTR q);