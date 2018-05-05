#include <iostream>

using namespace std;

typedef struct myNode {
    int intData;
    struct myNode* nextNode;
} myNodeType;

int main()
{
    // Create a null node for the head of the list, i.e. a0
    myNodeType* listNode = NULL;
    cout << listNode << endl;

    //Assign an address to the head node. Populate the next node with a null node.
    listNode = (myNodeType*)malloc(sizeof(myNodeType));
    if(listNode == NULL) return 1;
    listNode->intData = 0;
    listNode->nextNode = NULL;
    cout << "Current Address: " << listNode << endl;
    cout << '\t' << "Current Data: " << listNode->intData << endl;
    cout << "\t\t" << "Next Address: " << listNode->nextNode << endl;

    //Assign an address to the nextNode. Populate the next node with an empty node.
    listNode->nextNode = (myNodeType*)malloc(sizeof(myNodeType));
    if(listNode->nextNode == NULL) return 1;
    listNode->nextNode->intData = 1;
    listNode->nextNode->nextNode = NULL;
    cout << "Current Address: " << listNode->nextNode << endl;
    cout << '\t' << "Current Data: " << listNode->nextNode->intData << endl;
    cout << "\t\t" << "Next Address: " << listNode->nextNode->nextNode << endl;

    //Assign an address to the nextNode. Populate the next node with an empty node.
    listNode->nextNode->nextNode = (myNodeType*)malloc(sizeof(myNodeType));
    if(listNode->nextNode == NULL) return 1;
    listNode->nextNode->nextNode->intData = 2;
    listNode->nextNode->nextNode->nextNode = NULL;
    cout << "Current Address: " << listNode->nextNode->nextNode << endl;
    cout << '\t' << "Current Data: " << listNode->nextNode->nextNode->intData << endl;
    cout << "\t\t" << "Next Address: " << listNode->nextNode->nextNode->nextNode << endl;

    cout << "------------------------------------------" << endl;
    //Create an empty node to use for iterating through the list.
    myNode* current = NULL;
    //Set the iteration to begin at the first node that was created.
    current = listNode;

    while(current != NULL){
        cout << '\t' << "Address: " << current << endl;
        cout << "\t\t" << "Data: " << current->intData << endl;
        cout << "\t\t\t" << "Next Node Address: " << current->nextNode << endl;
        current = current->nextNode;
    }

    //Create an empty node to use as the new tail node, which will need its nextNode to NULL after the last node is deleted.
    myNode* tailNode = NULL;

    //Release the memory from the third node, i.e. delete it.
    current = listNode;
    while(current->nextNode != NULL){
        tailNode = current;
        current = current->nextNode;
    }
    if(current->nextNode == NULL){
        free(current);
        tailNode->nextNode = NULL;
    }

    //Iterate through the list to see remaining nodes
    cout << "------------------------------------------" << endl;
    current = listNode;
    while(current != NULL){
        cout << '\t' << "Address: " << current << endl;
        cout << "\t\t" << "Data: " << current->intData << endl;
        cout << "\t\t\t" << "Next Node Address: " << current->nextNode << endl;
        current = current->nextNode;
    }

    //Release the memory from the second node, i.e. delete it.
    current = listNode;
    while(current->nextNode != NULL){
        tailNode = current;
        current = current->nextNode;
    }
    if(current->nextNode == NULL){
        free(current);
        tailNode->nextNode = NULL;
    }

    //Iterate through the list to see remaining nodes
    cout << "------------------------------------------" << endl;
    current = listNode;
    while(current != NULL){
        cout << '\t' << "Address: " << current << endl;
        cout << "\t\t" << "Data: " << current->intData << endl;
        cout << "\t\t\t" << "Next Node Address: " << current->nextNode << endl;
        current = current->nextNode;
    }

    //Release the memory from the first node, i.e. delete it.
    if(listNode->nextNode == NULL){
        free(listNode);
        listNode = NULL;
    }

    //Iterate through the list to see remaining nodes
    cout << "------------------------------------------" << endl;
    if(listNode != NULL){
        cout << '\t' << "Address: " << current << endl;
        cout << "\t\t" << "Data: " << current->intData << endl;
        cout << "\t\t\t" << "Next Node Address: " << current->nextNode << endl;
        current = current->nextNode;
    }
    else
        cout << '\t' << "No nodes to display. All memory has been freed." << endl;


    return 0;
}
