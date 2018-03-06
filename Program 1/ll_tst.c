/**
 * cs251sp2016 linked list project 1 test suite pt2.
 * Creates a log file of expected test results against actual test results.
 *
 * REMINDER: This test suite is NOT exhaustive. Passing all of these tests does
 * NOT mean you will get 100%% on the project.
 * 
 * Tests included:
 * 0 Example rests for provided function lst_push_backk.
 * 1 lst_print_rev
 * 2 lst_count
 * 3 lst_pop_back
 * 4 lst_reverse
 * 5 lst_is_sorted
 * 6 lst_insert_sorted
 * 7 lst_length
 * 8 lst_merge_sorted
 * 9 lst_clone
 * 10 lst_from_array
 * 11 lst_to_array
 * 12 lst_prefix
 * 13 lst_filter_leq
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "list.h"

#define FREE(x) lst_free(x)




/** ElemType may be changed for application
 * specific needs.
 *
 * However, it should be a numeric type.
 */

typedef int ElemType;
#define FORMAT " %i "
#define DEFAULT 0

// hidden implementation of list_struct
typedef struct list_struct LIST;

extern LIST *lst_create(); 
extern void lst_free(LIST *l);
extern void lst_print(LIST *l); 


extern void lst_push_front(LIST *l, ElemType val); 
extern void lst_push_back(LIST *l, ElemType val); 

/** TODO
 * function:  lst_length
 *
 * description:  returns the length of the given list.
 *
 * CONSTRAINTS:
 *
 *      runtime:  O(1)
 *		  (you will rewrite the THETA(n) version
 *		  already given to you).
 *
 * NOTES:
 *
 *      since the LIST struct is "hidden" in the .c file,
 *      you ARE free to change it; this will almost certainly
 *      be necessary to achive the O(1) runtime.
 *
 *      furthermore, the real work you do to make this work
 *	in O(1) time will be in _other_ functions which affect
 *	the length of lists.
*/
extern int lst_length(LIST *l);

extern int lst_is_empty(LIST *l);

/** TODO
 *    function:  lst_count
*     description:  Counts number of occurrences 
*     		of x in the list and returns 
*     		that value.
*/
extern int lst_count(LIST *l, ElemType x); 

// sanity checker functions - DONE
extern int lst_sanity1(LIST *l);
extern int lst_sanity2(LIST *l);
extern int lst_sanity3(LIST *l);

extern ElemType lst_pop_front(LIST *l); 


/** TODO
 * function:  lst_pop_back
 *
 * description:  removes last element from list
 * 	and returns that value.
 *
 * Note:  if list is empty, the return value is
 * 	implementation specific -- i.e., caller's
 * 	fault.  Optionally, your implementation can
 *	print a message to stderr
 *
 * RUNTIME:  THETA(n)
 */
extern ElemType lst_pop_back(LIST *l);

/**
*
* TODO:  
*   function:  lst_are_equal
*   description:  returns true(1) if lst1 and lst2
*      contain exactly the same sequenc of values.
*      Returns 0 otherwise.
**/
int lst_are_equal(LIST *lst1, LIST *lst2);

/** TODO
 * function:  lst_print_rev
 *
 * description:  prints the elements of the list
 * 	but in reverse order.
 */
extern void lst_print_rev(LIST *l); 


/** TODO 
 * function:  lst_reverse
 *
 * description:  reverses the given list.
 * 	this is different from printing it
 * 	in reverse order!
 *
 * 	The ordering of the actual list is
 * 	reversed.
 *
 * constraints:  
 *
 *	for full credit,  NO MEMORY ALLOCATION is 
 *	allowed in this function; it just re-links 
 *	the already existing nodes
 *
 *	RUNTIME:  THETA(n)
 */
extern void lst_reverse(LIST *l); 


/**  DONE
 * function:  lst_remove_first
 *
 * Description:  The FIRST OCCURRENCE of x 
 *    in list (if any) is removed.
 *    If x not in list, list is unchanged.
 *
 *    NOT THE SAME AS lst_pop_front
 *
 * returns 1 if removal made; 0 otherwise
*/ 
extern ElemType lst_remove_first(LIST *l, ElemType x) ;


/** DONE
 * function:  lst_remove_all_slow
 *
 * description:  removes all occurrences of x
 *    from list and returns number of matches.
 *
 * implementation:  simply repeatedly calls 
 *    lst_remogve_first on x until it fails.
 *
 * why is it slow?
 *
 *   The number of operations this function performs
 *   may depends on:
 *              n:  the length of the list
 *              m:  the number of matches of x
 *              maybe the structure of the list
 *                 (e.g., where in the list the
 *                 matches occur).
 *
 *   It seems like we should be able to perform
 *   the operation in time proportional to n.
 *
 *   However, I claim that there are cases for which
 *   the approach of lst_remove_all_slow takes time
 *   proportional to n^2 
 */
extern ElemType lst_remove_all_slow(LIST *l, ElemType x) ;

/** 
 * DONE  
 * function: lst_sra_bad_case (sra:  slow_remove_all)
 *
 * description: constructs a list of length n such that 
 * the above function takes quadratic time to remove
 * all occurrences of a specified value. 
 *
 * By convention, the specified value will be 0
 */
extern LIST *lst_sra_bad_case(int n); 

/** TODO
*   function:  lst_remove_all_fast
*   description:  same behavior/semantics as
*      lst_remove_all_slow.  However, this function
*      must guarantee linear time worst case 
*      runtime (hence, "fast").
*
*   REQUIREMENT:  linear worst-case runtime.
*
*   Note:  your solution may be either recursive or 
*   iteratieve.
**/
extern int lst_remove_all_fast(LIST *l, ElemType x) ;

/** DONE
 * function:  lst_is_sorted
 *
 * description:  returns 1 if the list is sorted in 
 * 	non-decreasing order; 0 otherwise
 */
extern int lst_is_sorted(LIST *l);


/** TODO
* function:  lst_insert_sorted
*
* description:  assumes given list is already in sorted order
*	   and inserts x into the appropriate position
* 	   retaining sorted-ness.
* Note 1:  duplicates are allowed.
*
* Note 2:  if given list not sorted, behavior is undefined/implementation
* 		dependent.  We blame the caller.
* 		So... you don't need to check ahead of time if it is sorted.
*/
extern void lst_insert_sorted(LIST *l, ElemType x);

/** TODO
 * function:  lst_merge_sorted
 *
 * description:  assumes both list a and b are in
 * 	sorted (non-descending) order and merges them
 * 	into a single sorted list with the same
 * 	elements.  
 *
 * 	This single sorted list is stored in a while
 * 	b becomes empty.
 *
 * 	if either of given lists are not sorted, 
 * 	we blame the caller and the behavior is
 * 	implementation dependent -- i.e., don't worry
 * 	about it!
 *
 *      Condition in which both parameters are the same
 *      list (not merely "equal"), the function simply 
 *      does nothing and returns.  This can be tested
 *      with simple pointer comparison.
 *
 * 	Example:
 *
 * 		a:  [2 3 4 9 10 30]
 * 		b:  [5 8 8 11 20 40]
 *
 * 		after call on (a,b)
 *
 * 		a:  [2 3 4 5 8 8 9 10 11 20 30 40]
 * 		b:  []
 * 
 * implementation:  should not allocate ANY new list
 * 	nodes -- it should just re-link existing
 * 	nodes.
 *
 * 	Must be linear time in the |a|+|b| -- i.e.,
 * 	the total number of elements being processed.
 */
extern void lst_merge_sorted(LIST *a, LIST *b);


/**
*
* TODO
*
* function:  lst_clone
*
* description:  makes a "deep copy" of the given list a
*   and returns it (as a LIST pointer).
*
*/
extern LIST * lst_clone(LIST *a);



/**
* TODO
*
* function:  lst_from_array 
*
* description:  creates a new list populated with the
*      elements of array a[] in the same order as 
*      they appear in a[] (element at a[0] will be the
*      first element in the list and so-on).  List is
*      returned as a LIST pointer.
*
*      Parameter n indicates the length of the given array.
*
* runtime requirement:  THETA(n)
*/
extern LIST * lst_from_array(ElemType a[], int n); 


/**
* TODO
*
* function:  lst_to_array 
*
* description:  allocates an array of ElemType and populates
*         it with the elements in the given list (as with
*         lst_from_array elements are in the same order in
*         both data structures).
*
* runtime requirement:  THETA(n)
*
*/
extern ElemType * lst_to_array(LIST *lst);


/**
* TODO
* function:  lst_prefix
*
* description:  removes the first k elements from the
*               given list which are used to form a new list
*		which is then returned.
*
*		if n is the length of the given list, we have the
*		following boundary conditions:
*
*		  if k==0:
*			lst unchanged and an empty list returned
*		  if k>=n:
*			lst becomes empty and a list containing
*			all elements previously in lst is returned.
*
*		examples:
*
*		  EX1:  lst:  [2, 3, 9, 7, 8]
*			k:    3
*
*			after call:
*			   lst:  [7, 8]
*			   returned list:  [2, 3, 9]
*
*		  EX2  lst:  [2, 3, 9, 7, 8]
*			k:    0
*
*			after call:
*			   lst:  [2, 3, 9, 7, 8]  (unchanged)
*			   returned list:  []
*
*		  EX3  lst:  [2, 3, 9, 7, 8]
*			k:    5
*
*			after call:
*			   lst:  []
*			   returned list:  [2, 3, 9, 7, 8]
*
* REQUIREMENTS:
*
*	RUNTIME:  THETA(n) worst case where n is the length of the given list
*
*       ORDERING:  the ordering of the returned prefix should be the same as
*                  in the given list
*
*       MEMORY:    for full credit, no new nodes should be allocated or deallocated;
*		   you should just "re-use" the existing nodes.  HOWEVER, you will
*		   need to allocate a LIST structure itself (i.e., for the returned
*		   list).
*/
extern LIST * lst_prefix(LIST *lst, unsigned int k);




/**
* TODO
*
* function:  lst_filter_leq
*
* description:  removes all elements of the given list (lst) which
*		are less than or equal to a given value (cutoff)
*		
*		A list containing the removed elements is returned.
*
* examples:
*
*	EX1: 	lst:  [4, 9, 2, 4, 8, 12, 7, 3]
*		cutoff:  4
*
*		after call:
*			lst:  [9, 8, 12, 7]
*			returned list:  [4, 2, 4, 3]
*
*       -----------------------------------------
*	EX2: 	lst:  [6, 5, 2, 1]
*		cutoff:  6
*
*		after call:
*			lst:  []
*	 		returned list:  [6, 5, 2, 1]
*
* REQUIREMENTS:
*
*	RUNTIME:  THETA(n) where n is the length of the given list
*
*       ORDERING:  the ordering of the returned list should be the same as
*                  in the given list
*
*       MEMORY:    for full credit, no new nodes should be allocated or deallocated;
*		   you should just "re-use" the existing nodes.  HOWEVER, you will
*		   need to allocate a LIST structure itself (i.e., for the returned
*		   list).
*			
*/
extern LIST * lst_filter_leq(LIST *lst, ElemType cutoff);




/**
* TODO
* function:  lst_concat
*
* description:  concatenates lists a and b; resulting
*    concatenation is reflected in list a; list b becomes
*    empty.
*
*    example:
*
*	EX1:  a: [2, 9, 1]
*	      b: [5, 1, 2]
*
*	after call:
*
*		a: [2, 9, 1, 5, 1, 2]
*		b: []
*
* REQUIREMENTS:  
*
*     runtime:  O(1)
*
*     sanity:  this operation makes sense when a and b
*		are distinct lists.  For example, we don't
*		want/allow the caller to do something like
*		this:
*
*			LIST *my_list;
*
*			lst_push_front(my_lst, 4);
*			lst_push_front(my_lst, 2);
*
*			lst_concat(my_lst, my_lst);
*
*		your implementation must detect if it is being
*		called this way.  If so the function does nothing
*		and (optionally) prints an error message to
*		stderr.
*	
*/
extern void lst_concat(LIST *a, LIST *b);


void helper_arr_print_no_newline(int *arr, int n) {
    printf("[");
    for (int i=0; i<n; i++) {
      printf(" %d ", arr[i]);
    } printf("]\n");
}


int main() {
  // Test values.
  LIST *empty = lst_create();
  LIST *anotherEmptyList = lst_create();
  LIST *one = lst_create();  // List of one element [ 5 ].
  LIST *medium = lst_create();  // List of ten elements [ 1 2 ... 9 10 ].
  LIST *evenList;  // Lst of five even elements [ 2 4 6 8 10 ].
  LIST *oddList;  // List of five odd elements [ 1 3 5 7 9 ].
  LIST *dupsOfevenList; // List of some even duplicate elements [ 4 8 12 16 20 ].
  LIST *resultList;

  srand(time(NULL));
  lst_push_back(one, 5);
  for(int i = 1; i <= 10; ++i) { lst_push_back(medium, i); }

  /**
  * Unit test for void lst_push_back(LIST *l, ElemType val);
  */
  printf("\n\nTest: 0A\nDescription: Testing lst_push_back with List of length 0 with elements [] and val=42\nExpected output: [ 42 ]\n");
  printf("Your output:");
  lst_push_back(empty, 42);
  lst_print(empty);
  FREE(empty);
  empty = lst_create();

  printf("\n\nTest: 0B\nDescription: Testing lst_push_back with List of length 1 with elements [ 5 ] and val=42\nExpected output: [ 5 42 ]\n");
  printf("Your output:");
  lst_push_back(one, 42);
  lst_print(one);
  FREE(one);
  one = lst_create();
  lst_push_back(one, 5); // Reset one for later tests.

  evenList = lst_create();
  for (int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); }
  printf("\n\nTest: 0C\nDescription: Testing lst_push_back with List of length 5 with elements [2 4 6 8 10] and val=42\nExpected output: [ 2 4 6 8 10 42 ]\n");
  printf("Your output:");
  lst_push_back(evenList, 42);
  lst_print(evenList);
  FREE(evenList);


  /**
   * 2. Unit tests on function: int lst_count(LIST *l, ElemType x);
   */ 
  printf("\n\nTest: 2A\nDescription: Testing lst_count with List of length 0 and x=5\nExpected output: 0\n");
  printf("Your output: %d\n",  lst_count(empty, 5));

  printf("\n\nTest: 2B\nDescription: Testing lst_count with List of length 10 and x=-5\nExpected output: 0\n");
  printf("Your output: %d\n", lst_count(medium, -5));

  printf("\n\nTest: 2C\nDescription: Testing lst_count with List of length 10 and x=5\nExpected output: 1\n");
  printf("Your output: %d\n", lst_count(medium, 5));

  lst_push_front(medium, 10);
  printf("\n\nTest: 2D\nDescription: Testing lst_count with List of length 10 and x=10\nExpected output: 2\n");
  printf("Your output: %d\n", lst_count(medium, 10));
  lst_pop_front(medium); // Reset value for later tests.


  /**
   * 4. Unit tests on function: void lst_reverse(LIST *l);
   */
  printf("\n\nTest: 4A\nDescription: Testing lst_reverse with List of length 0\nExpected output: []\n");
  printf("Your output: ");
  lst_reverse(empty);
  lst_print(empty);

  printf("\n\nTest: 4B\nDescription: Testing lst_reverse with List of length 1\nExpected output: [ 5 ]\n");
  printf("Your output: ");
  lst_reverse(one);
  lst_print(one);

  printf("\n\nTest: 4C\nDescription: Testing lst_reverse with List of length 10\nExpected output: [ 10  9  8  7  6  5  4  3  2  1 ]\n");
  printf("Your output: ");
  lst_reverse(medium);
  lst_push_back(medium, 99);
  lst_pop_back(medium); // Check for tail correctness.
  lst_print(medium);
  FREE(medium);

  /**
   * 6. Unit tests on void lst_insert_sorted(LIST *l, ElemType x);
   */
  evenList = lst_create();
  for(int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); }
  printf("\n\nTest: 6A\nDescription: Testing lst_insert_sorted with List of length 0 and x=5\nExpected output: [ 5 ]\n");
  printf("Your output: ");
  lst_insert_sorted(empty, 5);
  lst_print(empty);
  FREE(empty);
  empty = lst_create(); // Resets value for later tests.

  printf("\n\nTest: 6B\nDescription: Testing lst_insert_sorted with List of length 5 and x=5\nExpected output: [ 2  4  5  6  8  10 ]\n");
  printf("Your output: ");
  lst_insert_sorted(evenList, 5);
  lst_print(evenList);
  FREE(evenList);
  evenList = lst_create();
  for(int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); }

  printf("\n\nTest: 6C\nDescription: Testing lst_insert_sorted with List of length 5 and x=0\nExpected output: [ 0  2  4  6  8  10 ]\n");
  printf("Your output: " );
  lst_insert_sorted(evenList, 0);
  lst_print(evenList);
  FREE(evenList);
  evenList = lst_create();
  for(int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); }

  printf("\n\nTest: 6D\nDescription: Testing lst_insert_sorted with List of length 5 and x=12\nExpected output: [ 2  4  6  8  10  12 ]\n");
  printf("Your output: ");
  lst_insert_sorted(evenList, 12);
  lst_print(evenList);
  FREE(evenList);
  evenList = lst_create();
  for(int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); } // Reset value for later tests.


  /**
   * 8. Unit tests on void lst_merge_sorted(LIST *a, LIST *b);
   */
  printf("\n\nTest: 8A\nDescription: Testing lst_merge_sorted with List a of length 0 with elements [] and List b of length 0 with elements []\n");
  printf("Your output:");
  lst_merge_sorted(anotherEmptyList, empty);
  lst_print(anotherEmptyList);
  FREE(anotherEmptyList);
  FREE(empty);
  empty = lst_create();

  printf("\n\nTest: 8B\nDescription: Testing lst_merge_sorted with List a of length 1 with elements [ 5 ] and List b of length 0 with elements []\n");
  printf("\nExpected output: [ 5 ]\n");
  printf("Your output: ");
  lst_merge_sorted(one, empty);
  lst_print(one);
  FREE(one);
  FREE(empty);
  one = lst_create();
  empty = lst_create();
  lst_push_back(one, 10);

  printf("\n\nTest: 8C\nDescription: Testing lst_merge_sorted with List a of length 0 with elements [] and List b of length 1 with elements [ 10 ]\n");
  printf("\nExpected output: [ 10 ]\n");
  printf("Your output: ");
  lst_merge_sorted(empty, one);
  lst_print(empty);
  FREE(empty);
  FREE(one);
  empty = lst_create();
  one = lst_create();
  lst_push_back(one, 5);

  oddList = lst_create();
  for(int i=0; i<5; ++i) { lst_push_back(oddList, i*2+1); }
  printf("\n\nTest: 8D\nDescription: Testing lst_merge_sorted with List a of length 5 with elements [ 2  4  6  8  10 ] and List b of length 5 with elements [ 1  3  5  7  9 ]");
  printf("\nExpected output: [ 1  2  3  4  5  6  7  8  9  10 ]\n");
  printf("Your output: ");
  lst_merge_sorted(evenList, oddList);
  lst_print(evenList);
  FREE(evenList);
  FREE(oddList);

  evenList = lst_create();
  dupsOfevenList = lst_create();
  for (int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); lst_push_back(dupsOfevenList, i*4); }
  printf("\n\nTest: 8E\nDescription: Testing lst_merge_sorted with List a of length 5 with elements [ 2  4  6  8  10 ] and List b of length 5 with elements [ 4  8  12  16  20 ]\n");
  printf("\nExpected output: [ 2  4  4  6  8  8  10  12  16  20 ]\n");
  printf("Your output: ");
  lst_merge_sorted(evenList, dupsOfevenList);
  lst_print(evenList);
  FREE(evenList);
  FREE(dupsOfevenList);


  /**
   * 10. Unit tests on LIST * lst_from_array(ElemType a[], int n);
   **/
  int emptyArray[] = {};
  int oneArray[] = {5};
  int manyArray[] = {1,2,3,4,5};

  printf("\n\nTest: 10A\nDescription: Testing lst_from_array with array of length 0 with elements [] and n=0\nExpected output: []\n");
  printf("Your output:");
  resultList = lst_from_array(emptyArray, 0);
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList);}

  printf("\n\nTest: 10B\nDescription: Testing lst_from_array with Array of length 1 with elements [ 5 ] and n=1\nExpected output: [ 5 ]\n");
  printf("Your output:");
  resultList = lst_from_array(oneArray, 1);
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList); }

  printf("\n\nTest: 10C\nDescription: Testing lst_from_array with Array of length 5 with elements [ 1  2  3  4  5 ] and n=5\nExpected output: [ 1  2  3  4  5 ]\n");
  printf("Your output:");
  resultList = lst_from_array(manyArray, 5);
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList); }


  /**
   * 12. Unit tests for LIST * lst_prefix(LIST *lst, unsigned int k);
   */
  printf("\n\nTest: 12A\nDescription: Testing lst_prefix with List of length 0 with elements [] and k=0\nExpected output: []\n");
  printf("Expected return value: []");
  printf("Your output:\n");
  resultList = lst_prefix(empty, 0);
  lst_print(empty);
  printf("Your return value: ");
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList); }
  FREE(empty);
  empty = lst_create();

  printf("\n\nTest: 12B\nDescription: Testing lst_prefix with List of length 0 with elements [] and k=3\nExpected output: []\n");
  printf("Expected return value: []\n");
  printf("Your output:");
  resultList = lst_prefix(empty, 3);
  lst_print(empty);
  printf("Your return value: ");
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList); }
  FREE(empty);
  empty = lst_create();

  printf("\n\nTest: 12C\nDescription: Testing lst_prefix with List of length 1 with elements [ 5 ] and k=0\nExpected output: [ 5 ]\n");
  printf("Expected return value: []\n");
  printf("Your output:");
  resultList = lst_prefix(one, 0);
  lst_print(one);
  printf("Your return value: ");
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList); }
  FREE(one);
  one = lst_create();
  lst_push_back(one, 5);

  evenList = lst_create();
  for(int i=1; i<=5; i++) { lst_push_back(evenList, i*2); }
  printf("\n\nTest: 12D\nDescription: Testing lst_prefix with List of length 5 with elements [ 2  4  6  8  10 ] and k=3\nExpected output: [ 8 10 ]\n");
  printf("Expected return value: [ 2  4  6 ]\n");
  printf("Your output: ");
  resultList = lst_prefix(evenList, 3);
  lst_print(evenList);
  printf("Your return value: ");
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList); }
  FREE(evenList);


  /**
   * 14. Unit test for void lst_concat(LIST *a, LIST *b);
   */
  anotherEmptyList = lst_create();
  evenList = lst_create();
  oddList = lst_create();
  for(int i=1; i<=5; i++) { lst_push_back(evenList, i*2); lst_push_back(oddList, i*2-1); }  // 2 4 6 8 10
  printf("\n\nTest: 14A\nDescription: Testing lst_concat with List a of length 0 with elements [] and List b of length 0 with elements []\nExpected output: []\n");
  printf("Your output:");
  lst_concat(anotherEmptyList, empty);
  lst_print(anotherEmptyList);
  FREE(anotherEmptyList);
  FREE(empty);

  anotherEmptyList = lst_create();
  printf("\n\nTest: 14B\nDescription: Testing lst_concat with List a of length 1 with elements [ 5 ] and List b of length 0 with elements []\nExpected output: [ 5 ]\n");
  printf("Your output:");
  lst_concat(one, anotherEmptyList);
  lst_print(one);
  FREE(one);
  FREE(anotherEmptyList);
  anotherEmptyList = lst_create();
  one = lst_create();
  lst_push_back(one, 10);

  printf("\n\nTest: 14C\nDescription: Testing lst_concat with List a of length 0 with elements []");
  printf(" and List b of length 1 with elements [ 10 ]\nExpected output: [ 10 ]\n");
  printf("Your output:");
  lst_concat(anotherEmptyList, one);
  lst_print(anotherEmptyList);
  FREE(anotherEmptyList);
  FREE(one); 

  printf("\n\nTest: 14D\nDescription: Testing lst_concat with List a of length 5 with elements [ 2  4  6  8  10]");
  printf(" and List b of length 5 with elements [ 1  3  5  7  9 ]\nExpected output: [ 2  4  6  8  10  1  3  5  7  9 ]\n");
  printf("Your output:");
  lst_concat(evenList, oddList);
  lst_print(evenList);
  FREE(evenList);
  FREE(oddList);

  evenList = lst_create();
  dupsOfevenList = lst_create();
  for(int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); lst_push_back(dupsOfevenList, i*4); }
  printf("\n\nTest: 14E\nDescription: Testing lst_concat with List a of length 5 with elements [ 2  4  6  8  10 ] and List b of length 5 with elements [ 4  8  12  16  20 ]\n"
    "Expected output: [ 2  4  6  8  10  4  8  12  16  20 ]\n");
  printf("Your output:");
  lst_concat(evenList, dupsOfevenList);
  lst_print(evenList);
  FREE(evenList);
  FREE(dupsOfevenList);
}
