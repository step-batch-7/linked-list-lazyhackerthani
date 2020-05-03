#include<stdlib.h>
#include"list.h"
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

List * add_first_element(List* number_list,Node * node){
  number_list->head = node;
  number_list->count++;
  return number_list;
}

List * add_second_element(List* number_list,Node * node){
  number_list->last = node;
  number_list->count++;
  return number_list;
}