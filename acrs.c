/*
Arthur Carlos da Rocha Silva
Árvore binária de busca
https://www.urionlinejudge.com.br/judge/pt/problems/view/1195
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodes
{
    int info;
    struct Nodes *leftNode ;
    struct Nodes *rightNode;

} Node; 

Node* createTree(int rootValue, Node* inputLeftNode, Node* inputRightNode)
{
    Node *root;
    root = (Node*)malloc(sizeof(Node));
    root->info = rootValue;
    root->leftNode = inputLeftNode;
    root->rightNode = inputRightNode;
    return root;
}

Node* insertInTree(int newValue, Node* treeRoot)
{
    if (treeRoot == NULL) 
    {
        treeRoot = createTree(newValue,NULL,NULL);
    }
    else
    {
        if(newValue < treeRoot->info)
        { 
            treeRoot->leftNode = insertInTree(newValue,treeRoot->leftNode);

        }
        else
        {
            treeRoot->rightNode = insertInTree(newValue,treeRoot->rightNode);
        }
    }

    return treeRoot; 
}

void printPreOrder(Node* currentNode)
{
    if(currentNode != NULL)
    {
        printf(" %d",currentNode->info);
        printPreOrder(currentNode->leftNode);
        printPreOrder(currentNode->rightNode);
    }
}

void printInOrder(Node* currentNode )
{
    if(currentNode != NULL)
    {
        printInOrder(currentNode->leftNode);
        printf(" %d",currentNode->info);
        printInOrder(currentNode->rightNode);
    }
}

void printPostOrder(Node* currentNode)
{
    if(currentNode != NULL)
    {
        printPostOrder(currentNode->leftNode);
        printPostOrder(currentNode->rightNode);
        printf(" %d",currentNode->info);
    }
}

int main()
{ 
    Node *tree = NULL;
    int numberOfTestCases;
    int numberOfNodes;
    int testCaseNumber; 
    int scannedValue;
    int i;
    scanf("%d", &numberOfTestCases);
    for(testCaseNumber = 0; testCaseNumber < numberOfTestCases; testCaseNumber++)
    {
        scanf("%d", &numberOfNodes);
        for(i = 0 ; i < numberOfNodes; i++)
        {
            scanf("%d",&scannedValue);
            tree = insertInTree(scannedValue,tree);
        } 
        printf("Case %d:\n",testCaseNumber + 1);
        printf("Pre.:");
        printPreOrder(tree);
        printf("\nIn..:");
        printInOrder(tree);
        printf("\nPost:");
        printPostOrder(tree);
        printf("\n\n");
        tree = NULL; 
    }
    return 0;
}