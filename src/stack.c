#include "stack.h"

// Add a definition for struct Node here.

// This should really just return `NULL'
Stack mkStack();

int stPush(Stack *st, SData data);

// Non-destructive inspection.
int stPeek(Stack *st, SData *dest);

size_t stLength(Stack *st);

// Destroys the head of the list.
int stPop(Stack *st, SData *dest);

void stDestroy(Stack *st, void (*kill)(SData));
