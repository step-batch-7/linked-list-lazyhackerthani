#include<stdlib.h>
#include"list.h"
#include<stdio.h>
List * create_list(){
  List *new_list = calloc(1, sizeof(List));
  return new_list;
}

Node * create_node(int value){
  Node *new_node = calloc(1, sizeof(Node));
  new_node->value = value;
  return new_node;
}

Status add_to_end(List* number_list,int value){
  Status operation_status;
  Node *curr_node = create_node(value);
    operation_status = curr_node == NULL ? Failure : Success;
    if (number_list->count==0)
    {
      add_first_element(number_list, curr_node);
    }else if (number_list->count==1)
    {
      add_second_element(number_list, curr_node);
    }
    else
    {
      number_list->last->next = curr_node;
      number_list->last = curr_node;
      number_list->count++;
    }

  return operation_status;
}
Status add_to_start(List* number_list, int value){
  Status operation_status;
  Node *curr_node = create_node(value);
    operation_status = curr_node == NULL ? Failure : Success;
    if (number_list->count==0)
    {
      add_first_element(number_list, curr_node);
    }else if (number_list->count==1)
    {
      number_list->last = number_list->head;
      number_list->head= curr_node;
      number_list->head->next = number_list->last;
      number_list->count++;
    }
    else
    {
      curr_node->next = number_list->head;
      number_list->head = curr_node;
      number_list->count++;
    }

  return operation_status;
}

List * add_first_element(List* number_list,Node * node){
  number_list->head = node;
  number_list->count++;
  return number_list;
}

List * add_second_element(List* number_list,Node * node){
  number_list->head->next = node;
  number_list->last = node;
  number_list->count++;
  return number_list;
}

void print_list_elements(List * list){
  int index = list->count;
  Node *curr_node = list->head;
  printf(" List |-> ");
  while (index > 0)
  {
    printf("%d -> ", curr_node->value);
    curr_node = curr_node->next;
    index--;
  }
  printf("\n");
}