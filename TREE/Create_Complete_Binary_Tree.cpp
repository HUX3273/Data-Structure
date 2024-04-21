#include "Create_Complete_Binary_Tree.h"


int main() {
	// TreeRoot treeRoot = (TreeRoot) malloc (sizeof(TreeNode));
	// treeRoot->data.value = 'A';
	// treeRoot->father = NULL;
	// treeRoot->lchild = NULL;
	// treeRoot->rchild = NULL;

	TreeRoot treeRoot = createTree('A');
	
	// QueueRoot queueRoot = (QueueNode*) malloc (sizeof(QueueNode));
	// queueRoot->nextQueueNode = NULL;
	// queueRoot->treeNode = treeRoot;

	QueueRoot queueRoot = createQueue(treeRoot);


	printf("%c ROOT\n",treeRoot->data.value);


	insertNode(queueRoot,'b');

	insertNode(queueRoot,'c');
	
	insertNode(queueRoot,'d');

	insertNode(queueRoot,'e');
	
	insertNode(queueRoot,'f');

	insertNode(queueRoot,'g');

	insertNode(queueRoot,'h');
	
	insertNode(queueRoot,'i');

	printQueue(queueRoot);



	
	return 0;

}
