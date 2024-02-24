#ifndef _DOUBLE_LINKED_LIST
#define _DOUBLE_LINKED_LIST

typedef struct Node
{
    unsigned int node_data;
    struct Node *node_left_link;
    struct Node *node_right_link;

}Node_t;

void Insert_At_Beginning(Node_t **head_list , unsigned int data);
void Insert_At_End(Node_t *head_list , unsigned int data);
void Insert_After_Node(Node_t *head_list,unsigned int data,unsigned int position);
void Delete_At_Beginning(Node_t **head_list);
void Delete_At_specific_Node(Node_t *head_list , unsigned int position);
void Display_Forward(Node_t *head_list);
void Display_Reverse(Node_t *head_list);


#endif // _DOUBLE_LINKED_LIST

