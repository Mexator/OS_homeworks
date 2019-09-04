#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    struct node *prev;
    int value;
};
void print_list(struct node head);
/**
  * Inserts node with value {value} after node with index {index}
 **/
void insert_node(struct node *head, int index, int value);
/**
  * Deletes node with index {index}
 **/
void delete_node(struct node **head, int index);
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->value = 0;
    head->next = NULL;
    head->prev = NULL;
    insert_node(head, 0, 9);
    insert_node(head, 0, 19);
    insert_node(head, 0, 39);
    print_list(*head);
    delete_node(&head, 0);
    delete_node(&head, 0);
    delete_node(&head, 0);
    delete_node(&head, 0);
}
void insert_node(struct node *head, int index, int value)
{
    struct node *cur_node = head;
    int counter = 0;

    while (cur_node->next != NULL && counter < index)
    {
        cur_node = cur_node->next;
        counter++;
    }
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = cur_node->next;
    new_node->prev = cur_node;
    if (cur_node->next != NULL)
    {
        cur_node->next->prev = new_node;
    }
    cur_node->next = new_node;
}
void delete_node(struct node **head, int index)
{
    struct node *cur_node = *head;
    int counter = 0;
    while (cur_node->next != NULL && counter < index)
    {
        cur_node = cur_node->next;
        counter++;
    }
    if (cur_node->prev != NULL)
        cur_node->prev->next = cur_node->next;
    else
        *head = cur_node->next;
    if (cur_node->next != NULL)
        cur_node->next->prev = cur_node->prev;
    free(cur_node);
}
void print_list(struct node head)
{
    int counter = 0;
    while (head.next != NULL)
    {
        head = *head.next;
        printf("%d. %d\n", counter, head.value);
        counter++;
    }
}