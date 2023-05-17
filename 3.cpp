#include<stdio.h>
#include<stdlib.h>
//it should be used because a function like scanf
#pragma warning(disable:4996)
#define MAX_SIZE 200
int arr[MAX_SIZE];

typedef struct alfa* alfaptr;

struct alfa {
	long long x;
	alfaptr next;
};
alfaptr rear = NULL, front = NULL;
void push(int x)
{
	alfaptr node;
	node = (alfaptr)malloc(sizeof(struct alfa));
	node->x = x;
	//almost the whole thing is worng
	//it should be like this
	/*if (!front)
		front = node;
	else {
		rear->next = node;
		rear = node;
	}*/
	alfaptr temp;
	temp = front;
	front = node;
	if (!rear) {
		rear = front;
	}
	node->next = temp;
	free(temp);
}

void pop()
{
	alfaptr node;
	if (!front)
		printf("ERROR1\n");// i added \n
	else
	{
		node = front->next;
		front = node;
		if (!front) {
			rear = front;
		}
		//it could be added for optimized operation
		//free(node);
	}
}
void search(int x)
{
	alfaptr node = front;
	int counter = 0;
	while (node) {
		if (node->x == x)
			//printf("%d", counter);
			//counter variable must incremented by 1
			counter++;
		else {
			//printf("ERROR2");
			//the value of counter variable should be printed
			printf("%d\n", counter);// i added \n
			break;
		}
		node = node->next;//this statement must be in the loop
	}
}

void rpop() {//pop last element
	alfaptr node = front;
	alfaptr temp = NULL;
	if (front) {
		while (node->next) {//the termination condtion of the loop must be changed from node to node->next
			temp = node;
			node = node->next;
		}
		//it is absolutley wrong
		//it should be like this
		/*free(rear);
		rear = node;*/

		temp->next = NULL;
		rear = temp;
	}
	else {
		rear = NULL;
	}


}

void set()
{
	alfaptr node = front;
	for (int i = 0; i < MAX_SIZE && node; i++, node = node->next)
		arr[i] = node->x;

}

int size()
{
	alfaptr node = front;
	int count = 0;//count variable must be initialized to zero
	while (node) {
		count++;
		node = node->next;//this statement must be in the loop
	}
	return count;
}

void show()
{
	if (!front) {
		for (int i = 0; i < MAX_SIZE; i++)
			printf("%d ", arr[i]);
	}
	else
	{
		printf("ERROR3\n");// i added \n
	}
}

int average()
{

	alfaptr node = front;
	int sum = 0, count = 0;//count must be initialized to zero
	while (node) {
		sum += node->x;
		count++;
		node = node->next;
	}
	return sum / count;
}

void main()
{
	int cmd;
	long long int x;
	while (true)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1://push
			getchar();//it should be added for input issue
			scanf("%lld", &x);
			push(x);
			break;
		case 2://pop
			pop();
			break;
		case 3://rpop
			rpop();
			break;
		case 4://search
			getchar();//it should be added for input issue
			scanf("%lld", &x);
			search(x);
			break;
		case 5://set
			set();
			break;
		case 6://show
			show();
			break;
		case 7://size
			printf("%d\n", size());// i added \n
			break;
		case 10:
			exit(0);
		}
	}
}