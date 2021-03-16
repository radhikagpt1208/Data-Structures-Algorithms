/* Problem Statement:
One day Nauuo was playing cards but found that the cards were mixed with some empty ones.
There are n cards numbered from 1 to n, and they were mixed with another n empty cards.
She piled up the 2n cards and drew n of them. The n cards in Nauuo's hands are given.
The remaining n cards in the pile are also given in the order from top to bottom.
In one operation she can choose a card in her hands & play it,put it at the bottom of the pile,then draw the top card from the pile.
Nauuo wants to make the n numbered cards piled up in increasing order(the i-th card in the pile from top to bottom is the card i)
as quickly as possible. Can you tell her the minimum number of operations?
-> Input :
The first line contains a single integer n(1 <= n <= 2*10^5)-the number of numbered cards.
The second line contains n integers a1,a2,..,an (0<= ai <= n) - the initial cards in Nauuo's hands. 0 represents an empty card.
The third line contains n integers b1,b2,..,bn (0 <= bi <= n) - the initial cards in the pile, given in order from top to bottom.
0 represents an empty card.
It is guaranteed that each number from 1 to n appears exactly once, either in a1..n or b1..n
-> Output :
The output contains a single integer - the minimum number of operations to make the n numbered cards piled up in increasing order.

Approach :
Obs - For n numbers given, the max number of moves required to arrange them in inc order will surely be 2*n moves.
      This can be analyzed because for every 0 in the array, there is definitely a number(i.e,non-zero) present in the pile.
      So just put all the non zero elements from the pile to the array and then since there is no sorted order in the array,
      you can then swap every 0 with a non-zero number
Now since we have found the upper bound ans to this question(i.e,2*n) and the lower bound is 0,and we know that it is a greedy
question,we can apply binary search. Also,to apply binary search it must be an inc func
Assume that we can achieve the required order in x steps, then it is obvious that we can also solve it using (x+1),(x+2),...steps
(this can be done by putting in the pile one step later,i.e, after swapping once we start putting numbers in the pile).Hence it is
an increasing function.

