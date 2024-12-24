# Time & Space Complexity

---
## why

 we even need time complexity , measurement? , why we don't take the time that the machine we are running the algorithm into? the answer for this is taken from the question itself , The machine if U 're sure that all the machine 'll take the same time to run your algorithm,then we can do that , bu it's impossible. let's consider that example. U run an algorithm in a mac machine with high computing power , and it takes 2s , do U expect it to take the same time when run it in an old machine runs on windows xp? , surly,not it may take 4s or something like that. lets go to the next section to dive to what's really the time complexity measurement is.

 ---
 ## What 

- Time complexity is a measure of the amount of time an algorithm takes to complete as a function of the length of the input. It helps to evaluate the efficiency of an algorithm by estimating its running time, typically expressed using Big O notation (e.g., O(n), O(log n), O(n^2)). This allows for comparison of different algorithms regardless of the hardware used.

- It's rate at which time taken increases with respect to the input size.  U can call is as  an average way to calculate the algorithm taken time. so we use something named (Big-Oh) notation.
  
---
## How to Analyze Time Complexity:

- Identify the key operations: Determine the operations that are most frequently executed within the algorithm (e.g., comparisons, assignments, loops).
- Count the number of operations: Estimate how many times these key operations are executed as a function of the input size.
- Express the time complexity: Express the number of operations using Big O notation.

## Space complexity (memory space) -> it's combination of 

- input space -> space that U take to store the input.
- Auxiliary space -> space U take to solve the problem (**If U take any extra space to solve the problem it treated as(c=a+b->c here is auxiliary a,b are input space)**), in recursive programs the space complexity is the height of the tree,only interlinked function work in the same branch.