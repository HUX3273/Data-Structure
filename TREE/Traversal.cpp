#include "Create_Complete_Binary_Tree.h"

// ABC
void Preorder_Traversal( TreeNode *treeNode ){

    printf("%c ",treeNode->data.value);

    if(treeNode->lchild!=NULL){
        Preorder_Traversal(treeNode->lchild);
    } 
    
    if(treeNode->rchild!=NULL){
        Preorder_Traversal(treeNode->rchild);
    }

    return;
}

// BAC
void Inorder_Traversal( TreeNode *treeNode ){

    if(treeNode->lchild!=NULL){
        Inorder_Traversal(treeNode->lchild);
    } 

    printf("%c ",treeNode->data.value);

    if(treeNode->rchild!=NULL){
        Inorder_Traversal(treeNode->rchild);
    }

    return;
}

//BCA
void Postorder_Traversal( TreeNode *treeNode ){

     if(treeNode->lchild!=NULL){
        Postorder_Traversal(treeNode->lchild);
    } 

    if(treeNode->rchild!=NULL){
        Postorder_Traversal(treeNode->rchild);
    }

    printf("%c ",treeNode->data.value);

    return;
}



int main(){
    TreeRoot treeRoot = createTree('A');
    printf("%c TREEROOT\n",treeRoot->data.value);
    QueueRoot queueRoot = createQueue(treeRoot);
    insertNode(queueRoot,'B');
    insertNode(queueRoot,'C');
    insertNode(queueRoot,'D');
    insertNode(queueRoot,'E');
    insertNode(queueRoot,'F');

    printf("Preorder Traversal:");
    Preorder_Traversal(treeRoot);
    printf("\n");

    printf("Inorder Traversal:");
    Inorder_Traversal(treeRoot);
    printf("\n");

    printf("Postorder Traversal:");
    Postorder_Traversal(treeRoot);
    printf("\n");

    // printQueue(queueRoot);

    return 0;
}
