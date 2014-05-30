#include"stdio.h"
#include"stdlib.h"

#define EMPTY 0
#define DOT 1
#define COVER 2
#define BARRIER 3
#define BARRIER_0 4
#define BARRIER_1 5
#define BARRIER_2 6
#define BARRIER_3 7
#define BARRIER_4 8
#define BLUB 9 

typedef int Elem_type;

typedef struct Node{
	int number;
	size_t row;
	size_t col;
	struct Node* next;
}Num_barrier, *Barrier_list;

int m;//row num
int n;//column num

Elem_type* p_broad;//the global broad

void read_dimension(int*, int*);
void read_broad(Elem_type*);
void print_broad(Elem_type*);
Barrier_list create_barrier_list(Elem_type*);

void copy_broad(Elem_type*, const Elem_type*);

int check_complete(Elem_type*);

int solve_puzzle(Barrier_list, Elem_type*);
int put_blub(int, int, Elem_type*);
int put_dot(int, int, Elem_type*);

int handle_empty(int, Elem_type*);
int next_empty(int, Elem_type*);
