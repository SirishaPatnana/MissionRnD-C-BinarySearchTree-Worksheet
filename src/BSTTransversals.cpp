/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
int Count(struct node *n)
{
	int c = 1;

	if (n == NULL)
		return 0;
	else
	{
		c += Count(n->left);
		c += Count(n->right);
		return c;
	}
}
void inadd(int *arr, int data, int count)
{
	static int i = 0;
	arr[i++] = data;
	if (i == count)
		i = 0;
}
void in(struct node *root, int *arr, int i){
	if (root == NULL) return;
	in(root->left, arr, i);
	inadd(arr, root->data, i);
	in(root->right, arr, i);
}
void inorder(struct node *root, int *arr){
	if (root != NULL && arr != NULL)
		in(root, arr, Count(root));
}
void preadd(int *arr, int data, int count)
{
	static int i = 0;
	arr[i++] = data;
	if (i == count)
		i = 0;
}
void pre(struct node *root, int *arr, int j){
	if (root == NULL) return;
	preadd(arr, root->data, j);
	pre(root->left, arr, j);
	pre(root->right, arr, j);
}
void preorder(struct node *root, int *arr){
	if (root != NULL && arr != NULL)
		pre(root, arr, Count(root));
}
void postadd(int *arr, int data, int count)
{
	static int i = 0;
	arr[i++] = data;
	if (i == count)
		i = 0;
}
void post(struct node *root, int *arr, int k){
	if (root == NULL) return;
	post(root->left, arr, k);
	post(root->right, arr, k);
	postadd(arr, root->data, k);
}
void postorder(struct node *root, int *arr){

	if (root != NULL && arr != NULL)
		post(root, arr, Count(root));
}