*This project has been created as part of the 42 curriculum by olistoke, archowdh*

# push_swap project

## Description
- Push swap is a project that implements a custom sorting algorithm for integer stacks. It evaluates the disorder of a given stack and selects the most efficient sorting strategy based on the input.
- The goal is to sort stack a using the fewest possible operations while only using a restricted set of operations which are mentioned below.
- The algorithm must be optimized and tailored for the constraits of stack based movements.
- The goal of this project is to discover algorithmic complexity in a very concrete way.

### <u>Disorder</u>
- The disorder measures between 0 and 1 to indicate how far the initial stack 'a' is from being sorted.
- The disorder is 0, if the numbers are already in the right order. 
- The disorder is 1, if they are in the worst possible order.
- Intermediate values indicate partial disorder.

### <u>Calculation</u>
- To calculate it, you can think of looking at all the possible pairs of numbers in the stack.
- Each time a bigger number appears before a smaller one, that pair counts as a mistake.
- The more mistakes you have, the closer the disorder is to 1.

### <u>Operations</u>
This project consists of certain operations which include: <br>
**sa** - Swap the top 2 elements of stack A <br>
**sb** - Swap the top 2 elements of stack B <br>
**ss** - Perform both sa and sb simultaneously <br>
**pa** - Push the top of stack B onto stack A <br>
**pb** - Push the top of stack A onto stack B <br>
**ra** - Rotate stack A (shift up: first becomes last) <br>
**rb** - Rotate stack B (shift up: first becomes last) <br>
**rr** - Perform both ra and rb simultaeously <br>
**rra** - Reverse rotate stack A (shift down: last becomes first) <br>
**rrb** - Reverse rotate stack B (shift down: last becomes first) <br>
**rrr** - Perform both rra and rrb simultaneously <br>

### <u>Algorithms implemented</u>
1. **Selection Sort**
This algorithm is used for small stack sizes due to its simplicity and low overhead.
- (O(n²))

2. **Chunk Based Sort**
This algorithm divides the problem into smaller, manageable parts
- (O(n√n))

3. **Radix Sort**
This algorithm is the most efficient which can be used for large datasets.
- (O(n log n))

### <u>Key functions used</u>
> t_stack *ft_new_content(int content) 
- Creates a new stack node.
> void ft_add_back(int content, t_stack **stack)
- Adds a node to the end of the stack.
> int ft_stack_size(t_stack *stack)
- Returns the size of the stack.
> void ft_stack_print(t_stack *stack)
- Prints the stack contents.
> int ft_find_min(t_stack *stack)
- Returns the position index of the minimum element.
> int ft_find_max(t_stack *stack)
- Returns the position index of the maximum element.
> void ft_assign_index(t_stack *a_stack)
- Assigns an index to each stack element.
> int ft_sqrt(int n)
- Computes the integer square root.
> void ft_push_chunks(t_stack **a_stack, t_stack **b_stack, t_ops *ops_count)
- Pushes the chunks for sorting.
> void ft_sort_b(t_stack **b_stack, int pos, t_ops *ops_count)
- Sorts the stack b.
> void ft_chunk_sort(t_stack **a_stack, t_stack **b_stack, t_ops *ops_count)
- Performs the chunk based sorting algorithm.
> void ft_radix_sort(t_stack **a_stack, t_stack **b_stack, t_ops *ops_count)
- Performs the radix based sorting algorithm.
> void ft_selection_sort(t_stack **a_stack, t_stack **b_stack, t_ops *ops_count)
- Performs the selection based sorting algorthm.
> int ft_strcmp(const char *s1, const char *s2)
-  Compares strings.
> double ft_compute_disorder(t_stack *a_stack)
- Computes the disorder of the stack.
> void ft_print_bench_ops(t_ops *ops_count, float disorder)
- Prints the operations and benchmark.
> void ft_flag_count(int argc, char **argv, t_flags *flag, int *start)
- Handles all the flags.
> void ft_strategy_selection(t_stack **a_stack, t_stack **b_stack,
- Chooses the sorting strategy.
> char **string_converter(int argc, char **argv, int *split, int start)
- Converts input strings to integers.
> int errorcheck(char **argv)
- Checks for invalid inputs.
> int isdup(char **argv)
- Checks for duplicates.
> int main(int argc, char **argv)
- entry point of the project.


## Instructions
### <u>Compilation</u>
1. Clone the repository; 
> git@vogsphere-v2.codam.nl:vogsphere/intra-uuid-c8d42334-1b3d-45a9-a921-4a2ed8b512c2-7330533-olistoke

2. Compile the project;
> **make/make all** - Compiles the project into an executable program.

3. Clean up the files;
> **make clean** - Removes all object files, (.o). <br>
> **make fclean** - Removes object files and the executable. <br>
> **make re** - Performs a full recompilation (fclean, then make).

### <u>Usage:</u>
You can pass integers either as separate arguments or as a single quoted string:
```
./push_swap 1 5 3 7 2 4
./push_swap "1 5 3 7 2 4"
```
## Resources
**Push Swap tutorial:** <br>
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e <br>
**Deepdive into sorting algorithms:** <br>
https://www.geeksforgeeks.org/dsa/sorting-algorithms/ <br>
**Sorting algorithms visualiser:** <br>
https://github.com/o-reo/push_swap_visualizer <br>
**A.I help:** <br>
https://gemini.google.com/app <br>
**Bitwise operations:** <br>
https://www.programiz.com/c-programming/bitwise-operators <br>


