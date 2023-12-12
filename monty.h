#ifndef _MONTY_H_
#define _MONTY_H_

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representing a stack or queue
 * @n: integer
 * @prev: points to the previous element of the stack or queue
 * @next: points to the next element of the stack or queue
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
