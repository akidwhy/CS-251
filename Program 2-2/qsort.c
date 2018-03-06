#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "io.h"

LIST *quickSort(LIST *data){
	LIST *left, *right;
	int pivot;

	if(lst_length(data) <= 1){
		return data;
	}

	pivot = lst_pop_front(data);

	left = lst_filter_leq(data, pivot);

	right = data;

	left = quickSort(left);
	right = quickSort(right);

	lst_push_back(left, pivot);

	lst_merge_sorted(left, right);
	lst_free(right);

	return left;
}

int main(){
LIST *data;


  data = read_ints();
  data = quickSort(data);
  print_and_destroy(data);
 
}
