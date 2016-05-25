/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int Counter(struct node *n)
{
	int c = 1;

	if (n == NULL)
		return 0;
	else
	{
		c += Counter(n->left);
		c += Counter(n->right);
		return c;
	}
}
struct node** createQueue(int *front, int *rear, int size)
{
	struct node **queue =
		(struct node **)malloc(sizeof(struct node*)*size);

	*front = *rear = 0;
	return queue;
}

void add(struct node **queue, int *rear, struct node *new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}

struct node *del(struct node **queue, int *front)
{
	(*front)++;
	return queue[*front - 1];
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int rear=0, front=0;
	struct node **queue =(struct node **)malloc(sizeof(struct node*)*Counter(root));
	struct node *temp = root;
	int *arr, i = 0;
	arr = (int*)malloc(sizeof(int)*Counter(root));
	while (i<Counter(root))
	{
		arr[i] = temp->data;
		if (temp->right)
			add(queue, &rear, temp->right);
		if (temp->left)
			add(queue, &rear, temp->left);
		temp = del(queue, &front);
		i++;
	}
	return arr;
}