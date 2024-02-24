#include <stdio.h>
#include "Double_Linked_List.h"

void Insert_At_Beginning(Node_t **head_list , unsigned int data)
{
    Node_t *temp_node = NULL;
    temp_node = (Node_t *)malloc(sizeof(Node_t));
    if (NULL != temp_node)
    {
        temp_node->node_data = data;
        if (NULL == *head_list) //empty list
        {
            *head_list = temp_node;
            temp_node->node_left_link = NULL;
            temp_node->node_right_link = NULL;
        }
        else // not empty list
        {
            temp_node->node_left_link = NULL;
            temp_node->node_right_link = *head_list;
            (*head_list)->node_left_link = temp_node;
            *head_list = temp_node;
        }
    }
    else
    {
        printf("Can`t allocate the node!!\n");
    }

}
void Insert_At_End(Node_t *head_list , unsigned int data)
{
    Node_t *temp_node = NULL;
    Node_t *Node_counter = NULL;
    Node_counter = head_list;
    temp_node = (Node_t *)malloc(sizeof(Node_t));
    if (NULL != temp_node)
    {
        temp_node->node_data = data;
        if (NULL == head_list) //empty list
        {
            temp_node->node_left_link =NULL;
            temp_node->node_right_link =NULL;
            head_list = temp_node;
        }
        else // Not empty list
        {
            while (NULL != Node_counter->node_right_link)
            {
                Node_counter = Node_counter->node_right_link;
            }
            temp_node->node_right_link = NULL;
            temp_node->node_left_link = Node_counter;
            Node_counter->node_right_link = temp_node;
        }
    }
    else
    {
        printf("Can`t allocate the node!!\n");
    }


}
void Insert_After_Node(Node_t *head_list,unsigned int data,unsigned int position)
{
    Node_t *temp_node = NULL;
    Node_t *Node_counter = NULL;
    unsigned int Node_Position = position , count = 0;
    Node_counter = head_list;
    temp_node = (Node_t *)malloc(sizeof(Node_t));
    if (NULL != temp_node)
    {
        temp_node->node_data = data;
        while(Node_Position > count+1)
        {
            Node_counter = Node_counter->node_right_link;
            Node_Position--;
        }
        temp_node->node_left_link = Node_counter;
        temp_node->node_right_link = Node_counter->node_right_link;
        Node_counter->node_right_link->node_left_link = temp_node;
        Node_counter->node_right_link = temp_node;
    }
    else
    {
        printf("Can`t allocate the node!!\n");
    }
}
void Delete_At_Beginning(Node_t **head_list)
{
    Node_t *temp_node = NULL;
    temp_node = (*head_list);
    if (NULL == *head_list) //empty list
    {
        printf("Can`t delete the node, list is empty!!\n");
    }
    else
    {
       *head_list = (*head_list)->node_right_link;
       (*head_list)->node_left_link = NULL;
       temp_node = NULL;
       free(temp_node);
    }
}
void Delete_At_specific_Node(Node_t *head_list , unsigned int position)
{
    Node_t *temp_node = NULL;
    Node_t *Node_counter = NULL;
    unsigned int Node_position = position , count = 0;
    Node_counter = head_list;
    while(Node_position > count+1)
    {
        Node_counter = Node_counter->node_right_link;
        Node_position--;
    }
    temp_node = Node_counter->node_left_link;
    if (NULL == Node_counter->node_right_link) // last node
    {
        temp_node->node_right_link = NULL;
        free(Node_counter);
        Node_counter = NULL;

    }
    else // not the last node
    {
        temp_node->node_right_link = Node_counter->node_right_link;
        Node_counter->node_right_link->node_left_link = temp_node;
        free(Node_counter);
        Node_counter = NULL;
    }
}
void Display_Forward(Node_t *head_list)
{
    Node_t *Node_counter = NULL;
    Node_counter = head_list;
    printf("Data : ");
    printf("%i ",Node_counter->node_data);
    while(NULL != Node_counter->node_right_link)
    {
        Node_counter = Node_counter->node_right_link;
        printf("%i ",Node_counter->node_data);
    }
    printf("\n");
}
void Display_Reverse(Node_t *head_list)
{
    Node_t *Node_counter = NULL;
    Node_counter = head_list;
    while(NULL != Node_counter->node_right_link)
    {
        Node_counter = Node_counter->node_right_link;
    }
    printf("Data at Reverse ==> ");
    printf("%i ",Node_counter->node_data);
    while(NULL != Node_counter->node_left_link)
    {
        Node_counter = Node_counter->node_left_link;
        printf("%i ",Node_counter->node_data);
    }
    printf("\n");

}
