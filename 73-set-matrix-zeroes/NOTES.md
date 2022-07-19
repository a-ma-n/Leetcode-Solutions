**Optimal soln:**
​
1) 1 traversal to chek if the top and the rigth rows have boundary 0s
​
one traversal from top left to bot right , set all top most and rightmost elements <an element> if we encounter a 0 in that matrix.
​
traverse back from bot right to top left and if the topmost element is 0 => set all rows /columns zero.
​
this will need 1 traversal for marking + 1 traversal for setting 0's => o(mn) time and constant space
​
Corner case: for top  row and rightmost col
-> if there is any 0 present in top row / right most column then set the rightmost element 0 then use 2 variables top0 & right0 to find out if the topmost row and the rightmost col are 0 or not
-> if yes then set that row to zero after top left traversing the array.
​
​