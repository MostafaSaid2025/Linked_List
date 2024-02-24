#include <stdio.h>
#include "S_Linked_List.h"

Node_t *head_list = NULL;

void Insert_At_Beginning(Node_t **head_list , unsigned int data)
{
    Node_t *temp_node = NULL;
    temp_node = (Node_t *)malloc(sizeof(Node_t));
    if (NULL != temp_node)
    {
        if (NULL == head_list) // empty list
        {
            temp_node->node_link = NULL;
            *head_list = temp_node;
            temp_node->node_data = data;
        }
        else // not empty list
        {
            temp_node->node_data = data;
            temp_node->node_link = *head_list;
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
    temp_node = (Node_t *)malloc(sizeof(Node_t));
    if (NULL != temp_node)
    {
        temp_node->node_link = NULL;
        temp_node->node_data = data;
        Node_counter = head_list;
        while (NULL != Node_counter->node_link)
        {
            Node_counter = Node_counter->node_link;
        }
        Node_counter->node_link = temp_node;
    }
    else
    {
        printf("Can`t allocate the node!!\n");
    }
}
void Insert_After_Node(Node_t *head_list , unsigned int data , unsigned int position)
{
    Node_t *temp_node = NULL;
    Node_t *Node_counter = NULL;
    unsigned int node_position = position;
    temp_node = (Node_t *)malloc(sizeof(Node_t));
    if (NULL != temp_node)
    {
        temp_node->node_data = data;
        Node_counter = head_list;
        while (node_position > 1)
        {
          Node_counter = Node_counter->node_link;
          node_position--;
        }
        temp_node->node_link = Node_counter->node_link;
        Node_counter->node_link = temp_node;
    }
    else
    {
        printf("Can`t allocate the node!!\n");
    }

}
void Insert_Before_Node(Node_t *head_list , unsigned int data , unsigned int position)
{
    Node_t *temp_node = NULL;
    Node_t *Node_counter = NULL;
    unsigned int Node_position = position , count = 1;
    temp_node = (Node_t *)malloc(sizeof(Node_t));
    if (NULL != temp_node)
    {
        if (1 == Node_position)
        {
            printf("Error use Insert_At_Beginning!!\n");
        }
        else
        {
            temp_node->node_data = data;
            Node_counter = head_list;
            while (Node_position > count+1)
            {
                Node_counter = Node_counter->node_link;
                Node_position--;
            }
            temp_node->node_link = Node_counter->node_link;
            Node_counter->node_link = temp_node;
        }
    }
    else
    {
        printf("Can`t allocate the node!!\n");
    }
}
void Delete_From_Beginning(Node_t **head_list)
{
    Node_t *temp_node = NULL;
    temp_node = *head_list;
    if (NULL == *head_list) //empty list
    {
        printf("It is empty list , can`t delete!!\n");
    }
    else
    {
        *head_list = temp_node->node_link;
        temp_node->node_link = NULL;
        free(temp_node);
    }
}
void Delete_At_Specific_Node(Node_t *head_list , unsigned int position)
{
    Node_t *temp_node = NULL;
    temp_node = head_list;
    Node_t *Node_counter = NULL;
    unsigned int Node_position = position , count = 1;
    if (1 == Node_position)
    {
        printf("Error use Delete_From_Beginning!!\n");
    }
    else
    {
        while (position -1 > count)
        {
            temp_node = temp_node->node_link;
            position--;
        }
        Node_counter = temp_node->node_link;
        temp_node->node_link = Node_counter->node_link;
        free(Node_counter);
    }
}
void Display_All(Node_t *head_list)
{
    Node_t *temp_node = NULL;
    temp_node = head_list;
    printf("Data : ");
    printf("%i  ",temp_node->node_data);
    while (NULL != temp_node->node_link)
    {
        temp_node = temp_node->node_link;
        printf("%i  ",temp_node->node_data);
    }
    printf("\n");
}
