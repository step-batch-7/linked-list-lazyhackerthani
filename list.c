#include<stdlib.h>
#include"list.h"
List * create_list(){
  List *new_list = calloc(1, sizeof(List));
  return new_list;
}