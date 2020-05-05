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
    printf("Main Menu\n---------\n(a) add a number to the end of the list\n(b) add a number to the start of the list\n(c) insert a number at a given position in the list\n(d) add a unique item on the list at the end\n(e) remove a number from the beginning of the list\n(f) remove a number from the end of the list\n(g) remove a number from a given position in the list\n(h) remove first occurrence of a number\n");
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
       default:
         printf("invalid option\n");
         break;
    }
    
     print_list_elements(list);
    printf("\ndo you want to continue(press y for yes and any key for no)?");
    scanf(" %c", &continue_option);
  } while (continue_option == 'y');

  return 0;
}

