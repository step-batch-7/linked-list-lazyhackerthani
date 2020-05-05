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

Status insert_at(List* number_list, int value, int position){
  Status operation_status;
  Node *curr_node = create_node(value);
    operation_status = curr_node == NULL ? Failure : Success;
if(position>number_list->count || position<0 ){
  operation_status = Failure;
  return operation_status;
}
if (position==0)
    {
      add_to_start(number_list, value);
    }
    else if (position==number_list->count)
    {
      add_to_end(number_list, value);
    }else
    {
      int index = 0;
      Node *temp_node=number_list->head;
      while (index<position-1)
      {
        temp_node = temp_node->next;
        index++;
      }
      curr_node->next = temp_node->next;
      temp_node->next = curr_node;
      number_list->count++;
    }

return operation_status;
}

Status add_unique(List* number_list, int value){
  Status operation_status;
  Node *curr_node = create_node(value);
  int index = get_index_of(value, number_list);
  if(curr_node == NULL ||index>=0){
    operation_status = Failure;
    return operation_status;
  }
  add_to_end(number_list,value);
  operation_status = Success;
  return operation_status;
}

int get_index_of(int value,List * list){
  int position = -1;
  int index = 0;
  Node *curr_node = list->head;
  while(position<0&&index<list->count){
    if(curr_node->value==value){
      position = index;
    }
    index++;
    curr_node = curr_node->next;
  }
  return position;
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
  printf("\n\n");
}

Status remove_from_start(List * list){
  Status operation_status;
  if(list->count <= 0){
    operation_status = Failure;
    return operation_status;
  }
  Node *node_to_delete = list->head;
  list->head = list->head->next;
  free(node_to_delete);
  list->count--;
  operation_status = Success;
  return operation_status;
}

Node * get_nth_node(List * list,int position){
  int index = 0;
  if(list->count<position ||position<0){
    return NULL;
  }
  Node *curr_node = list->head;
  while (index < position)
  {
    curr_node = curr_node->next;
    index++;
  }
  return curr_node;
}

Status remove_from_end(List * list){
  Status operation_status;
  if(list->count <= 0){
    operation_status = Failure;
    return operation_status;
  }
  Node *previous_of_last_node = get_nth_node(list, list->count - 1);
  free(list->last);
  list->last = previous_of_last_node;
  list->count--;
  operation_status = Success;
  return operation_status;
}

Status remove_at(List * list, int position){
Status operation_status;
if(position<0 || position>=list->count){
operation_status = Failure;
    return operation_status;
}
if(position==0){
    operation_status = remove_from_start(list);
    return operation_status;
}if (list->count-1==position)
  {
    operation_status = remove_from_end(list);
    return operation_status;
  }
Node *previous_node = get_nth_node(list, position - 1);
Node *node_to_delete = previous_node;
previous_node->next = previous_node->next != NULL ? previous_node->next->next : NULL;
free(node_to_delete);
operation_status = Success;
list->count--;
return operation_status;
}

Status remove_first_occurrence(List * list, int value){
  Status operation_status;
  int position = get_index_of(value, list);
  if (position<0)
  {
   operation_status = Failure;
    return operation_status;
  }
  
operation_status =remove_at(list,position);
return operation_status;
}

Status remove_all_occurrences(List * list, int value){
Status operation_status=remove_first_occurrence(list,value);
Status temp_status = operation_status;
while (temp_status != Failure)
{
  temp_status=remove_first_occurrence(list,value);
}
return operation_status;
}

Status clear_list(List * list){
  Status operation_status;
  int index = list->count-1;
  if(list->count<=0){
    operation_status = Failure;
    return operation_status;
  }
  Node *curr_node=list->head;
  while (index >= 0)
  {
    Node *node_to_delete=curr_node;
    curr_node = curr_node->next;
    list->count--;
    free(node_to_delete);
    index--;
  }
  operation_status = Success;
return operation_status;
}

Status search(List * list,int value){
Status operation_status;
  int index = get_index_of(value,list);
  operation_status = index >= 0 ? Success : Failure;
  return operation_status;
}