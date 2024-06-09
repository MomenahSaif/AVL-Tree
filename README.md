In this assignment, you have the following tasks:

1. Create a program that reads in a list of integers from a file* and inserts them into an AVL tree. At every insertion, perform appropriate rotations to re-balance the tree. Also at every insertion, first display the tree** along with the balance factors of all nodes. Then, in case it is unbalanced, display the selected nodes x, y and z for rebalancing. Then display the selected case, and display the tree after one or both rotations you need to perform (depending on the case). 

2. Do the same for delete operations after all insertions in the file are complete. Randomly select nodes for deletion one by one, and delete until the tree is empty. At every deletion, recalculate balance factors, select (and display) the x, y and z nodes, identify the case, and display the tree after one or both rotations.

*Create the file of integers yourself, such that your program represents all cases of rotations in an AVL tree. Your program should also work with a different file of integers, and the number of integers can be variable. 
**Tree should be displayed as below. The following is the representation of the attached tree.
5
-3
--2
--4
-6
-
--7
---
---8

In short, your program should demonstrate the full working of an AVL tree. We should be able to use your code to demonstrate to a class of students how insertions and deletions in AVL trees work, how nodes for rotation are identified, how the case for rotation is identified, and how the tree is finally re-balanced.


Marking rubric:
Appropriate file creation that demonstrates all AVL rotation cases: 5 marks
Correct file reading (including reading new files): 5 marks
Insertion code: 5 marks (for correct BST insert)
Rebalancing code: 25 marks (5 marks for correct balance factor calculation; 5 for each case correctly implemented)
Displaying the tree appropriately: 15 marks (good display + displaying at every insertion/rebalancing + displaying of x,y,z nodes and identification of case)
Deletion code: 10 marks (for correct BST delete for all cases)
Rebalancing code: 20 marks (5 marks for each case correctly implemented)
Overall marks for high quality display and clarity of demonstration: 5 marks
90 marks in total.
