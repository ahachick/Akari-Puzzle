#include"a_puzzle.h"

typedef struct A{
	int a;
} *pA;

pA test(){
	pA pa = (pA) malloc(sizeof(struct A));
	printf("test");
	return pa;
}

int main() {

	pA pa = test();
	read_dimension(&m, &n);
	p_broad = (Elem_type*) malloc(sizeof(Elem_type) * m * n);
	read_broad(p_broad);
	Barrier_list barriers = create_barrier_list(p_broad);
	int solved = solve_puzzle(barriers, p_broad);
	
	if(solved)
		print_broad(p_broad);
	else
		printf("no solution!");

}

void read_dimension(int* row, int* col) {
	printf("Please input the row & column:\n");
	scanf("%d %d", row, col);
}

void read_broad(Elem_type* broad) {
	//printf("Please input the broad:\n");
	int i;
	for(i = 0; i < m*n; i++)
		scanf("%d", &broad[i]);
}

void print_broad(Elem_type* broad) {
	int r, c;
	for(r = 0; r < m; r++) {
		for(c = n; c < n; c++)
			printf("%d ", broad[r*n + c]);
		printf("\n");
	}
}

Barrier_list create_barrier_list(Elem_type* broad) {

	int i;
	int type;
	Barrier_list header, p;
	for(i = 0; i < m*n; i++){
		if(broad[i*n + m] == BARRIER_0){
			Barrier_list q = (Barrier_list)malloc(sizeof(Num_barrier));
			q->row = i / n;
			q->col = i % n;
			q->number = 0;
			(header == NULL) ? (header = p = q) : (p->next = q);
		}
	}
		
	for(i = 0; i < m*n; i++){
		if(broad[i*n + m] == BARRIER_4){
			Barrier_list q = (Barrier_list)malloc(sizeof(Num_barrier));
			q->row = i / n;
			q->col = i % n;
			q->number = 4;
			(header == NULL) ? (header = p = q) : (p->next = q);
		}
	}
	for(i = 0; i < m*n; i++){
		if(broad[i*n + m] == BARRIER_3){
			Barrier_list q = (Barrier_list)malloc(sizeof(Num_barrier));
			q->row = i / n;	
			q->col = i % n;
			q->number = 3;
			(header == NULL) ? (header = p = q) : (p->next = q);
		}
	}
	for(i = 0; i < m*n; i++){
		if(broad[i*n + m] == BARRIER_1){
			Barrier_list q = (Barrier_list)malloc(sizeof(Num_barrier));
			q->row = i / n;
			q->col = i % n;
			q->number = 1;
			(header == NULL) ? (header = p = q) : (p->next = q);
		}
	}
	for(i = 0; i < m*n; i++){
		if(broad[i*n + m] == BARRIER_2){
			Barrier_list q = (Barrier_list)malloc(sizeof(Num_barrier));
			q->row = i / n;
			q->col = i % n;
			q->number = 2;
			(header == NULL) ? (header = p = q) : (p->next = q);
		}
	}
	return header;
}
int solve_puzzle(Num_barrier* barrier, Elem_type* broad) {

	if(NULL != barrier) {//first phase
		Num_barrier* p;
		Elem_type* cp_broad;
		int r, c;
		int handle;

		cp_broad = (Elem_type*)malloc(sizeof(Elem_type) * m * n);
		copy_broad(cp_broad, broad);

		p = barrier;
		r = p->row;
		c = p->col;
	
		switch(p->number){
		case 4:
			if(put_blub(r-1, c, cp_broad)
				&&put_blub(r, c-1, cp_broad)
				&&put_blub(r+1, c, cp_broad)
				&&put_blub(r, c+1, cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			break;
		case 3:
			if(put_blub(r-1, c, cp_broad)
				&&put_blub(r, c-1,cp_broad)
				&&put_blub(r+1, c, cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			//restore the state of broad
			copy_broad(cp_broad, broad);
			if(!handle && put_blub(r, c-1, cp_broad)
				&&put_blub(r+1, c, cp_broad)
				&&put_blub(r, c+1, cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			//
			copy_broad(cp_broad, broad);
			if(!handle && put_blub(r+1, c, cp_broad)
				&&put_blub(r, c+1, cp_broad)
				&&put_blub(r-1, c, cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			//
			copy_broad(cp_broad, broad);
			if(!handle && put_blub(r, c+1, cp_broad)
				&&put_blub(r-1,c,cp_broad)
				&&put_blub(r,c-1,cp_broad))
				handle = solve_puzzle(p->next,cp_broad);
			break;
		case 2:
			if(put_blub(r-1,c, cp_broad) && put_blub(r,c-1, cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			copy_broad(cp_broad, broad);
			if(!handle && put_blub(r-1, c, cp_broad) && put_blub(r+1,c,cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			copy_broad(cp_broad, broad);
			if(!handle && put_blub(r-1, c, cp_broad) && put_blub(r, c+1, cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			copy_broad(cp_broad,broad);
			if(!handle && put_blub(r, c-1, cp_broad) && put_blub(r+1, c, cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			copy_broad(cp_broad, broad);
			if(!handle && put_blub(r, c-1, cp_broad) && put_blub(r, c+1, cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			copy_broad(cp_broad, broad);
			if(!handle && put_blub(r+1, c, cp_broad) && put_blub(r, c+1, cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			break;
		case 1 :
			if(put_blub(r-1, c, cp_broad)) 
				handle = solve_puzzle(p->next, cp_broad);
			if(!handle && put_blub(r, c-1, cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			if(!handle && put_blub(r+1, c, cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			if(!handle && put_blub(r, c+1, cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			break;
		case 0:
			if(put_dot(r-1, c,cp_broad)
					&& put_dot(r, c-1, cp_broad)
					&& put_dot(r+1, c, cp_broad)
					&& put_dot(r, c+1, cp_broad))
				handle = solve_puzzle(p->next, cp_broad);
			break;
		default:
			break;
		}
		free(cp_broad);
		cp_broad = NULL;
		return handle;
	} else {//second phase
		return handle_empty(next_empty(-1, broad), broad);
	}
}

int handle_empty(int cur, Elem_type* broad) {
	
	Elem_type* cp_broad;

	if(check_complete(broad)){
		copy_broad(p_broad, broad);
		return 1;
	}
	if(cur == -1)
		return 0;

	cp_broad = (Elem_type*)malloc(sizeof(Elem_type) * m * n);
	copy_broad(cp_broad, broad);

	if(put_blub(cur / n, cur % n, cp_broad))
		return handle_empty(next_empty(cur, cp_broad), cp_broad);
	else {
		//retore the previous state of the broad
		copy_broad(cp_broad, broad);
		return handle_empty(next_empty(cur, cp_broad), cp_broad);
	}
}
/*
*Copy the src broad to des
*/
void copy_broad(Elem_type* des, const Elem_type* src) {
	int i;
	for(i = 0; i < m*n; i++)
		des[i] = src[i];
}

int check_complete(Elem_type* broad){
	int i;
	for(i = 0; i < m*n; i++)
		if(broad[i] < COVER)
			return 0;

	return 1;
}

int put_blub(int row, int col, Elem_type* broad) {
	
	int r, c;

	if(row < 0 && row >= m
		|| col < 0 && col >= n)
		return 0;
	//judge can put?
	if(broad[row * n + col] > DOT)
		return 0; 
	else 
		broad[row * n + col] = BLUB;
	// illuminate four directions 
	for(r = row -1 , c = col; c >= 0 && broad[r * n+c] < BARRIER; c--)
		broad[r*n + c] = COVER;
	for(r = row, c = col - 1; r >= 0 && broad[r * n+c] < BARRIER; r--)
		broad[r*n + c] = COVER;
	for(r = row + 1, c = col; c < m && broad[r * n + c] < BARRIER; c++)
		broad[r*n + c] = COVER;
	for(r = row, c = col +1; r < n && broad[r*n + c] < BARRIER; r++)
		broad[r*n + c] = COVER;
	
	return 0;

}

int put_dot(int row, int col, Elem_type* broad) {
	if((row >= 0 || row < m)
		&& (col >= 0 &col < n))
		if(broad[row*n + m] > COVER)
			return 0;
	return 1;
}

int next_empty(int cur, Elem_type* broad){
	int i;

	for(i = cur++; i < m *n; i++)
		if(broad[cur] < COVER)
			return i;

	return -1;
}
