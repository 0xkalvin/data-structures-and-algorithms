#include "tree.h"

/*  
                    10
            1           12
                5           15
*/

int main(void){

    Tree* myTree = createTree();

    insert(myTree, 10);
    insert(myTree, 12);
    insert(myTree, 1);
    insert(myTree, 15);
    insert(myTree, 5);

    printf("\nIN ORDER\n");
    printInOrder(myTree->root);
    
    printf("\nPRE ORDER\n");
    printPreOrder(myTree->root);

    printf("\nPOST ORDER\n");
    printPostOrder(myTree->root);

    printf("\n There is %d nodes on the tree\n", count(myTree->root));

    printf("\n Height is %d \n", getHeight(myTree->root));


    return 0;
}