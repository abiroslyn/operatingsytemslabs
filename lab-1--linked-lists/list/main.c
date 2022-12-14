#include <stdio.h>
#include "list.h"

int main() 
{
    printf("Write your Tests for your linked list implementation\n");
    
    list_t *mylist;
    
    mylist = list_alloc();
    
    list_add_to_front(mylist, 1);
    list_add_to_back(mylist, 3);
    list_add_at_index(mylist, 2, 1);
    list_add_to_back(mylist, 4);
    list_print(mylist);
    printf("My list contains %d elements\n", list_length(mylist));

    int second_elem = list_remove_at_index(mylist, 2); // 0
    int back_elem = list_remove_from_back(mylist); // 4
    int front_elem = list_remove_from_front(mylist); // 1
    printf("Third element: %d\nBack of list: %d\nFront of list: %d\n", second_elem, back_elem, front_elem);

    if (list_is_in(mylist, 2)) {
        printf("2 is in the list because it was not removed.\n");
    }
    if (!list_is_in(mylist, 4)) {
        printf("4 is not in the list because it was removed.\n");
    }

    int element = list_get_elem_at(mylist, 1);
    int index = list_get_index_of(mylist, element);
    printf("The element %d is at index %d\n", element, index);