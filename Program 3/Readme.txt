///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//NOTE: HEADER FILE IS ALSO INCLUDED BECAUSE I HAD TO CHANGE THE NAME OF THE FUNCTION bst_num_range TO bst_num_ranges//
//Also tester that was used is included////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Name:	Abdullah Kidwai

-----------------------------------------------

Describe what augmentations to the bst data structures you made to complete the 
project -- i.e., what typedefs did you change and why?
	
	in my node struct i added sizeLeft and sizeRight. 
	they would allow me keep track of the right and left sizes when adding or removing 
	from the node.
	
	for my tree struct i added size, min, and max. size was used to keep track of the 
	size of my bst. min was used to hold the smallest bst value and max was used to hold
	the largest bst value.





-----------------------------------------------
Which functions did you need to modify as a result of the augmentations from the previous
question?  

BST * bst_create();
static NODE * insert(NODE *r, int x);
void bst_insert(BST * t, int x);
static NODE *remove_r(NODE *r, int x, int *success);
int bst_remove(BST * t, int x);
bst_size(BST * t);
int bst_min(BST * t);
int bst_max(BST * t);







-----------------------------------------------
For each function from the previous question, how did you ensure that the (assymptotic) runtime 
remained the same?

the runtime remained the same for all them except bst_size, bst_min, and bst_max because
i only added a few more initializing statements and incrementation. for the three functions
that i mentioned, the runtime is faster.







-----------------------------------------------
For each of the assigned functions, tell us how far you got using the choices 0-5 and
answer the given questions.  


0:  didn't get started
1:  started, but far from working
2:  have implementation but only works for simple cases
3:  finished and I think it works most of the time but not sure the runtime req is met. 
4:  finished and I think it works most of the time and I'm sure my design leads to 
       the correct runtime (even if I still have a few bugs).
5:  finished and confident on correctness and runtime requirements


bst_to_array level of completion:  _____4________  


-----------------------------------------------
bst_get_ith level of completion:  _____3______  

    How did you ensure O(h) runtime?

    ANSWER: not sure if the runtime is met. however i tried to achieve that runtime
			by using a while loop to go through it by keeping its condition as a NODE p.

-----------------------------------------------
bst_get_nearest level of completion:  ____2_______  

    How did you ensure O(h) runtime?

    ANSWER:	i did not get this to work completely
  
-----------------------------------------------
bst_num_geq level of completion:  ____5_______  

    How did you ensure O(h) runtime?

    ANSWER:	using recursion this function finds the correct values but iterating through the function
			h number of time.

-----------------------------------------------
bst_num_leq level of completion:  _____5_______

    How did you ensure O(h) runtime?

    ANSWER:using recursion this function finds the correct values but iterating through the function
			h number of time.

-----------------------------------------------
bst_num_range level of completion:  _____1_______

    How did you ensure O(h) runtime?

    ANSWER:	i did not get this to work at all

-----------------------------------------------
Implementation of size-balanced criteria according to 
the given guidelines (including bst_sb_work):

    Level of completion: ____0_______


Write a few sentences describing how you tested your solutions.  Are there
any tests that in retrospect you wish you'd done?

	i used a test cases that were provided on piazza. they helped me get through each problem
	one at a time.
	
	i wish had put more print statements throughout my code. i find using print statements
	help me better identify the problem.





