#ifndef _S_LINKED_LIST_
#define _S_LINKED_LIST_

typedef struct Node
{
    unsigned int node_data;
    struct Node *node_link;

}Node_t;

void Insert_At_Beginning(Node_t **head_list , unsigned int data);
void Insert_At_End(Node_t *head_list , unsigned int data);
void Insert_After_Node(Node_t *head_list , unsigned int data , unsigned int position);
void Insert_Before_Node(Node_t *head_list , unsigned int data , unsigned int position);
void Delete_From_Beginning(Node_t **head_list);
void Delete_At_Specific_Node(Node_t *head_list , unsigned int position);
void Display_All(Node_t *head_list);


#endif // _S_LINKED_LIST_
