# C-App-Recursive-function-for-finding-a-list-node-is-smaller-than-the-product-of-the-next-2-nodes
The functionality of this C application is described as follows.
* The program asks from the user to enter the elements of a (non sorted) list of integers. The user can enter as many integers as he likes. 
* After that the program runs a recursive function "productCompare" to check if the list entered by the user has a node that is smaller that the product of the next 2 nodes (the last 2 nodes are excluded). For example the list **5->4->2->3->25->15->6** satisfies the condition above. The function "productCompare" returns NULL in case of seccess (a node found that is smaller from the product of the next 2 nodes). In case of a list that has 
