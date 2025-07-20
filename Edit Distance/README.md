**Edit Distance** 

**Problem Statement: Edit Distance**

We are given two strings ‘S1’ and ‘S2’. We need to convert S1 to S2. The following three operations are allowed:

Deletion of a character.
Replacement of a character with another one.
Insertion of a character.
We have to return the minimum number of operations required to convert S1 to S2 as our answer.

**Algorithm :**
For every index of string S1, we have three options to match that index with string S2, i.e replace the character, remove the character or insert some character at that index. Therefore, we can think in terms of string matching path as we have done already in previous questions.

As there is no uniformity in data, there is no other way to find out than to try out all possible ways. To do so we will need to use recursion.

Steps to form the recursive solution: 

We will first form the recursive solution by the three points mentioned in the Dynamic Programming Introduction. 

**Step 1 :** Express the problem in terms of indexes.
We are given two strings. We can represent them with the help of two indexes i and j. Initially, i=n-1 and j=m-1, where n and m are lengths of strings S1 and S2. Initially, we will call f(n-1,m-1), which means the minimum number of operations required to convert string S1[0…n-1] to string S2[0…m-1].

**Step 2:** Try out all possible choices at a given index.
Now, i and j represent two characters from strings S1 and S2 respectively. There are only two options that make sense: either the characters represented by i and j match or they don’t.

(i) When the characters match
if(S1[i]==S2[j]), 
If this is true, now as the characters at i and j match, we would not want to do any operations to make them match, so we will just decrement both i and j by 1 and recursively find the answer for the remaining string portion. We return 0+f(i-1,j-1). 

ii) When the characters don’t match
if(S1[i] != S2[j]) is true, then we have to do any of three operations to match the characters. We have three options, we will analyze each of them one by one.

**Case 1:** Inserting a character
Now if we have to match the strings by insertions, what would we do?: 
We would have placed an ‘s’ at index 5 of S1.
Suppose i now point to s at index 5 of S1 and j points are already pointing to s at index j of S2.
Now, we hit the condition, where characters do match. (as mentioned in case 1).
Therefore, we will decrement i and j by 1. They will now point to index 4 and 1 respectively.
Now, the number of operations we did were only 1 (inserting s at index 5) but do we need to really insert the ‘s’ at index 5 and modify the string? The answer is simply NO. As we see that inserting a character (here ‘s’ at index 5), we will eventually get to the third step. So we can just return 1+ f(i,j-1) as i remains there only after insertion and j decrements by 1. We can say that we have hypothetically inserted character s.

**Case 2:** Deleting a character
We can simply delete the character at index 4 and check from the next index.
Now, j remains at its original index and we decrement i by 1. We perform 1 operation, therefore we will recursively call 1+f(i-1,j).

**Case 3:** Replacing a character
If we replace the character ‘e’ at index 4 of S1 with ‘s’, we have matched both the characters ourselves. We again hit the case of character matching, therefore we decrement both i and j by 1. As the number of operations performed is 1, we will return 1+f(i-1,j-1).

To summarise, these are the three choices we have in case characters don’t match:

return 1+f(i-1,j) // Insertion of character.
return 1+f(i,j-1) // Deletion of character.
return 1+f(i-1,j-1) // Replacement of character.
Step 3: Return the minimum of all choices.
As we have to return the minimum number of operations, we will return the minimum of all operations.

**Base Cases:**

We are reducing i and j in our recursive relation, there can be two possibilities, either i becomes -1 or j becomes -1., i,e we exhaust either S1 or S2 respectively.


**Steps to memoize a recursive solution:**

If we draw the recursion tree, we will see that there are overlapping subproblems. In order to convert a recursive solution the following steps will be taken:

 i)Create a dp array of size [n][m]. The size of S1 and S2 are n and m respectively, so the variable i will always lie         between ‘0’ and ‘n-1’ and the variable j between ‘0’ and ‘m-1’.

 ii) We initialize the dp array to -1.

 iii) Whenever we want to find the answer to particular parameters (say f(i,j)), we first check whether the answer is already  calculated using the dp array(i.e dp[i][j]!= -1 ). If yes, simply return the value from the dp array.

 iv) If not, then we are finding the answer for the given value for the first time, we will use the recursive relation as      usual but before returning from the function, we will set dp[i][j] to the solution we get.
