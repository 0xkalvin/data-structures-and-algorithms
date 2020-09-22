#include "tree.h"

/*  
                    10
            1           12
        0       5           15
*/

int main(void){

    Tree* myTree = createTree();

    insert(myTree, 10);
    insert(myTree, 12);
    insert(myTree, 1);
    insert(myTree, 15);
    insert(myTree, 5);
    insert(myTree, 0);

    printf("\n IN ORDER\n");
    printInOrder(myTree->root);
    
    printf("\n\n PRE ORDER\n");
    printPreOrder(myTree->root);

    printf("\n\n POST ORDER\n");
    printPostOrder(myTree->root);

    printf("\n\n There is %d nodes on the tree\n", count(myTree->root));

    printf("\n Height is %d \n", getHeight(myTree->root));

    printf("\n There is %d leafs on the tree\n", countLeafs(myTree->root));

    printf("\n Max node is %d \n", max(myTree->root));

    printf("\n Min node is %d \n", min(myTree->root));

    return 0;
}