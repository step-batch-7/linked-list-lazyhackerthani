#include<stdio.h>
#include"list.h"
int main(void)
{
  List *list = create_list();
  char continue_option, operation_type;
    int value,position;
  Status operation_status;
  do
  {
    printf("Main Menu\n---------\n(a) add a number to the end of the list\n(b) add a number to the start of the list\n(c) insert a number at a given position in the list\n(d) add a unique item on the list at the end\n(e) remove a number from the beginning of the list\n(f) remove a number from the end of the list\n(g) remove a number from a given position in the list\n(h) remove first occurrence of a number\n(i) remove all occurrences of a number\n(j) clear the whole list\n(k) check if a number exists in the list\n(l) display the list of numbers\n(m) exit\n\nPlease enter the alphabet of the operation you would like to perform\n");
    scanf(" %c", &operation_type);
    
    switch (operation_type)
    {
    case 'a':
     printf("enter the number to add : ");
     scanf("%d", &value);
     add_to_end(list, value);
     break;
    case 'b':
     printf("enter the number to add : ");
     scanf("%d", &value);
     add_to_start(list, value);
     break;
    case 'c':
     printf("enter the number to add : ");
     scanf("%d", &value);
     printf("enter the position to add : ");
     scanf("%d", &position);
     insert_at(list, value, position);
     break;
     case 'd':
     printf("enter the number to add : ");
     scanf("%d", &value);
     add_unique(list, value);
     break;
     case 'e':
       remove_from_start(list);
       break;
       case 'f':
       remove_from_end(list);
       break;
       case 'g':
       printf("enter the position to remove : ");
     scanf("%d", &position);
       remove_at(list,position);
         break;
          case 'h':
          printf("enter the number to remove : ");
     scanf("%d", &value);
       remove_first_occurrence(list,value);
       break;
       case 'i':
          printf("enter the number to remove : ");
     scanf("%d", &value);
       remove_all_occurrences(list,value);
       break;
       case 'j':
       clear_list(list);
       break;
       case 'k':
       printf("enter the number to search : ");
     scanf("%d", &value);
       Status found=search(list,value);
       char *message = found == Success ? "found" : "not found";
       printf("%s\n", message);
       break;
       case 'l':
       print_list_elements(list);
       break;
       case 'm':
         continue_option = 'm';
         break;
       default:
         printf("invalid option\n");
         break;
    }
  } while (continue_option != 'm');

  return 0;
}

