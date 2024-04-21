#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// treeNode data type
struct ElementType {
	char value;
};

// tree
typedef struct TreeNode {
	ElementType data;
	TreeNode *father;
	TreeNode *lchild,*rchild;
} TreeNode,*TreeRoot;

// queue
typedef struct QueueNode {
	TreeNode *treeNode;
	QueueNode *nextQueueNode;
} QueueNode,*QueueRoot;

// print the whole queue
void printQueue(QueueRoot queueRoot){
	QueueNode *q = queueRoot; 
	printf("queue: ");
	while(q!=NULL){
		printf("%c ",q->treeNode->data);
		q = q->nextQueueNode;
	}
	printf("\n");
	return ;
}

// insert new node into queue
bool insertQueue(QueueRoot queueRoot,TreeNode *treeNode){
	QueueNode *queueNode = (QueueNode*) malloc (sizeof(QueueNode));
	queueNode->nextQueueNode = NULL;
	queueNode->treeNode = treeNode;
	
	QueueRoot q =  queueRoot;
	
	while(true){
		if(q->nextQueueNode!=NULL){
			q = q->nextQueueNode;
		}
		if(q->nextQueueNode==NULL){
			break;
		}
	}
	
	q->nextQueueNode = queueNode;

	return true;
}

// print treeNode data
void visit(TreeNode *T) {
	printf("%c \n",T->data.value);
	return;
}

// insert new treeNode into complete binary tree in sequence by using queue
void insertNode(QueueRoot queueRoot,char data) {
	TreeNode *p = (TreeNode *) malloc (sizeof(TreeNode));
	
	if(queueRoot->treeNode->lchild == NULL){
		queueRoot->treeNode->lchild = p;
		p->data.value = data;
		p->father = queueRoot->treeNode;
		p->lchild = NULL;
		p->rchild = NULL;
		printf("%c Father:%c \n", p->data.value , p->father->data.value);
		insertQueue(queueRoot,p);
		return;
	} else if(queueRoot->treeNode->rchild == NULL){
		queueRoot->treeNode->rchild = p;
		p->data.value = data;
		p->father = queueRoot->treeNode;
		p->lchild = NULL;
		p->rchild = NULL;
		printf("%c Father:%c \n", p->data.value , p->father->data.value);
		insertQueue(queueRoot,p);
		return;
	} else {
		queueRoot = queueRoot->nextQueueNode;
		insertNode(queueRoot,data);
	}
	
	return;
}

// create tree and initialize root data
TreeRoot createTree(char data){
	TreeRoot treeRoot = (TreeRoot) malloc (sizeof(TreeNode));
	treeRoot->data.value = data;
	treeRoot->father = NULL;
	treeRoot->lchild = NULL;
	treeRoot->rchild = NULL;

	return treeRoot;
}

// create queue and initialize root data
QueueRoot createQueue(TreeRoot treeRoot){
	QueueRoot queueRoot = (QueueNode*) malloc (sizeof(QueueNode));
	queueRoot->nextQueueNode = NULL;
	queueRoot->treeNode = treeRoot;

	return queueRoot;
}