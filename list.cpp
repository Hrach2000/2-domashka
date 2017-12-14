#include <iostream>

using namespace std;

struct list {
  list *next;
  list *prev;
  int key;
};
list *list_new(int key = 0) {
  list *n = new list;
  n->next = n->prev = n;
  n->key = key;
  return n;
}
void list_delete(list *l) {
  if (l == NULL)
    return;
  if (l->prev != l)
    (l->prev)->next = NULL;
  list_delete(l->next);
  delete l;
  return;
}
bool push(list *l, int a) {
  list *n = list_new(a);
  if (l == NULL)
    l = n;
  else {
    (l->prev)->next = n;
    n->next = l;
    n->prev = l->prev;
    l->prev = n;
  }
  return true;
}
bool pop(list *l) {
  if (l == NULL)
    return false;
  if (l->prev == l) {
    delete l;
    l = NULL;
    return true;
  }
  l->prev = (l->prev)->prev;
  l->prev->prev->next = l;
  delete l->prev;
  return true;
}
bool unshift(list *l, int a) {
  list *n = list_new(a);
  l->prev->next = n;
  n->prev = l->prev;
  n->next = l;
  l->prev = n;
  l = n;
  return true;
}
bool shift(list *l) {
  if (l == NULL)
    return false;
  if (l->next == l) {
    delete l;
    l = NULL;
    return true;
  }
  l->prev->next = l->next;
  l->next->prev = l->prev;
  delete l;
  return true;
}
int main()
{
    return 0;
}
