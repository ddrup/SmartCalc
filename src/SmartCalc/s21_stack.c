#include "s21_stack.h"

void push_back(stack **head, double val, int priority, type_t type) {
  stack *tmp = malloc(sizeof(stack));
  if (tmp != NULL) {
    tmp->next = *head;
    tmp->priority = priority;
    tmp->type = type;
    tmp->value = val;
    *head = tmp;
  }
}

void pop_back(stack **head) {
  if ((*head) != NULL) {
    stack *tmp = *head;
    *head = (*head)->next;
    free(tmp);
  }
}

void peek_back(stack **head, double *val, int *priority, type_t *type) {
  if ((*head) != NULL) {
    *val = (*head)->value;
    *priority = (*head)->priority;
    *type = (*head)->type;
  }
}

void free_stack(stack **head) {
  while (*head != NULL) {
    stack *tmp = *head;
    *head = (*head)->next;
    free(tmp);
  }
}
