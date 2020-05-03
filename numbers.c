#include<stdio.h>
#include"list.h"
int main(void)
{
  List *list = create_list();
  char continue_option, operation_type;
  Status operation_status;
  int value;
  do
  {
    printf("Main Menu\n---------\n(a) add a number to the end of the list\n");
    scanf(" %c", &operation_type);
    
    switch (operation_type)
    {
    case 'a':
    printf("enter the number to add");
    scanf("%d", &value);
      break;
    
    default:
      break;
    }
    
    printf("do you want to continue(press y for yes and any key for no)?");
    scanf(" %c", &continue_option);
  } while (continue_option == 'y');

  return 0;
}

