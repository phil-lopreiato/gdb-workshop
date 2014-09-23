#include "list.h"

int main() {
  struct linked_list* list1 = ll_create();
  ll_destroy(list1);
  
  struct linked_list* ll = ll_create();
  
  ll_add(ll, 10);
  ll_add(ll, 10); 
  ll_add(ll, 34);
  ll_add(ll, 22);
  
  ll_remove_first(ll);
 
  ll_add(ll, 10);
  ll_add(ll, 10); 
  ll_add(ll, 34);
  ll_add(ll, 22);
  
  printf("%d\n", ll->head->data);
  
  printf("%d\n", ll->head->data);
  printf("%d\n", ll->head->data);


  if(ll_remove_first(ll) == NULL) printf("works\n");  

  ll_add(ll, 10);
  ll_add(ll, 34);
  ll_add(ll, 44);
  
  printf("%d\n", ll_contains(ll, 9));
  printf("%d\n", ll_contains(ll, 10));
  printf("%d\n", ll_contains(ll, 44));
  
  struct node* n = ll->head;
  
  while(n != NULL) {
    printf("%d\n", n->data);
    n = n->next;
  }

  ll_destroy(ll);

  return 0;
}
