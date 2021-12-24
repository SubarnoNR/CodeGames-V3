# CodeGames V3 Editorial

## A. Halloween Heist

As the constraints are small, we can use a simple algorithm that iterates over all the possible keys, decodes the given string using this key, and checks if the decoded string contains `CHEDDAR` or not.

A slightly more efficient algorithm would be to calculate the difference array, where each a[i] = s[i+1] - s[i] (distance between consecutive characters of the string). Encoding the string using a Caesar substitution cipher will not change the difference array, and we can find the position where `CHEDDAR` would be present in the original string, and then compare any of the letter with what it should actually have been at that position to get the key.

Naive Solution : [link](./Halloween%20Heist/SolutionCode.cpp)

Improved Solution : [link](./Halloween%20Heist/ImprovedSolution.cpp)

## B. Sheldon's Game

Consider values of `n` coins in a line are stored in an array called `arr`. Let `dp[i][j]` represent the maximum value by which a player can win considering the sequence from `i'th` coin to `j'th` coin. Thus `dp[0][n-1]` will give us the required ans.

Consider the sequence from `i'th` coin to `j'th` coin. Penny goes first so she can either select the `i'th` coin or the `j'th` coin. If she selects the `i'th` coin, the maximum value by which she can win is value of the `i'th` coin- max value by which a player can win in the sequence from `(i+1)'th` coin to `j'th` coin. Similarly, if she selects the `j'th` coin, the max value by which she can win is value of the `j'th` coin- max value by which a player can win in the sequence from `i'th` coin to `(j-1)'th coin`. This problem can easily be solved using dynamic programming in O(n^2) time complexity. 

Solution : [link](./Sheldon's%20Game/solution.cpp)

## C. Hermione's Dilemma 

The problem statement requires us to find the maximum overlap between any 2 bit-strings. A straight-forward solution would be iterating over all pairs of strings, and finding the intersection in linear time. The overall time complexity will be O(NxNxD), which will be enough to pass 70% of the test cases.

Notice the fact that finding intersection between 2 bit-strings is equivalent to counting the number of bits present in the bitwise AND of the 2 bit-strings. We can utilise the fact that bitwise AND of integers is an O(1) operation by storing the bitstrings as a collection of integers in their binary representation. The `bitset` class of C++ makes implementation much easier. All we have to do now is iterate over all pairs of strings, and calculate the intersection by taking the bitwise AND and counting the bits that remain. Thus, calculating intersections redcues to atleast O(D/32) or O(D/64), which is a significant decrease, enough to pass the remaining 30% of the test cases.

Solution : [link](./Hermione's%20Dilemma/trial.cpp)

For more applications on bitsets, you can read [this wonderful post](https://codeforces.com/blog/entry/73558) by Errichto. The problem statement was inspired by the workers example given in this post.

## D. The Army of the Dead

The Problem can be reframed as : Given a graph G(V,E), find number of vertices v belonging to (V - {1}) such that their removal can cause the previously connected graph to be split into 2 or more connected components.

This is the standard problem of finding articulation points in any graph, which can easily be solved by running DFS whilst keeping track of the earliest discovery time of any vertex that the subtree at any vertex has a back-edge to, as any subtree in the DFS Tree which doesn't have a single back-edge to some previously dicovered vertex, must have an articulation point as its root.

You may read more about it [here](https://cp-algorithms.com/graph/cutpoints.html).

The solution can be found [here](./The%20Army%20of%20the%20Dead/sol.cpp)


## E. Save the Gold

The problem can be thought of as a sequence `a` of `n` integers where we have to find the max value of `a[i] mod a[j]` for all `a[i] >= a[j]`. 

Let us iterate over all different `a[j]`. Since we need to maximize , then iterate all integer `x` (such `x` divisible by `a[j]`) in range from `2*a[j] to M`, where `M` — doubled maximum value of the sequence. For each such `x` we find maximum `a[i]`, such that `a[i]<x` using a set. After that, update answer by value `a[i] mod a[j]` if answer is less than that value. Constraints for numbers in sequence `a` allow to do this in time O(1) with an array. Total time complexity is O(nlogn+MlogM). 

Solution : [link](./Save%20the%20Gold/soln.cpp)

## F. Squid Game

Prerequisites : [Sprague-Grundy Theorem](https://cp-algorithms.com/game_theory/sprague-grundy-nim.html)

This is an impartial 2 player game, and we will aim to reduce it to an equivalent game of Nim with multiple piles, by assigning a grundy value `g(A,k)` to each heap. Experimenting with different values of A for a fixed k, (can be done easily using brute force), we observe the following pattern : 

1. `g(A,k) = A/k`  if A is divisible by k
2. `g(A,k) = g(A - floor(A/k) - 1, k)`  otherwise
   
This can be proven using strong induction as follows :

Let, `g(A,k)` be correctly calculated using the above formula for all A <= xk. Now we will prove this for xk+1, xk+2, ...., xk+k. `g(xk,k) = x (From 1)`, and since from state (xk,k), only x states (`floor(xk/k) = x`) are reachable and the mex of the grundy values for these states is `x`, therefore they form a permutation of 0,1,...,x-1. Hence, the grundy values for states `{(xk-x,k),(xk-x+1,k),....,(xk,k)}` form a permutation of 0,1,...,x.

Now, from (xk+1,k), floor((xk+1)/k) states are reachable, from (xk-x+1,k),..,(xk,k). Since including the (xk-x,k) state among these values would have resulted in a permutation of their grundy values as 0,..,x , therefore the mex of grundy values of `{(xk-x+1,k),...,(xk,k)}` will be `g(xk-x,k)`. Thus `g(xk+1,k) = g(xk-x,k)`, as should have been according to the formula. We can extend this argument to prove that this holds for all states `{(xk+1,k),....,(xk+k-1,k)}`.

For the state (xk+k,k), `floor((xk+k)/k) = x+1` states are reachable, the grundy values of which will form the entire permutation `0,...,x`. Therefore, `g(xk+k,k) = mex({0,...,x}) = x+1`.

How can we compute grundy numbers using the fact above? We start with an integer A, and while A is not divisible by K, we keep replacing A with A − floor(A/K) − 1. We are interested in the final value
of A. However, a straightforward implementation of this will result in TLE.

To make it faster, notice that if the value of floor(A/K) doesn’t change after an operation, we can perform multiple steps at once. More explicitly, if currently floor(A/K) = d, we keep decreasing A by d + 1 while A ≥ dK. Thus, instead of performing steps one by one, we can make multiple steps at once until we first get A < dK.

Time Complexity after improvement :
- Since the value of floor(A/K) decreases in each step, this is at most O(A/K).
- Since the value of A is multiplied by a factor of at most `(K-1)/K = (1-1/K)` in each step, in every K steps this is multiplied by a factor of approximately 1/e. Thus, this is at most O(K log A).

We should take the better of the two analysis above: it’s O(min(N/K, K log N) = O(√(N log N)).

Solution : [link](./Squid%20Game/SolutionCode.cpp)

## G. The Tournament of Power

Let's look at all the information we have :

1) Two disjoint list of warriors
2) A Bunch of liked fights between warriors in different lists only (As the Grandminister has already observed that the Army kings don't like fights among warriors in their own tablets)
3) Some liked players (which should remain in the end)
4) Some disliked players (which shouldn't remain in the end)

And we need to make sure that :

1) at least one of the warriors of every liked fight remains
2) None of the disliked players remain.
3) All of the liked players remain

The Problem can be modelled aptly by a Bipartite Graph ```G(X,Y,E)``` , where X could be the warriors in the first army king's tablet, Y in second's and E could be composed of undirected edges signifying the interesting fights.

If ```D = {d_1 , d_2 , d_3 , ... , d_k }``` denote the disliked warriors, then all the warriors ```W = {w_1, w_2, w_3 ..... w_p}``` belonging to ``` X union Y``` such that there is an edge to/from each ```w_i``` and ```d_j``` , then all the warriors in ```W``` must be a part of the final arena.

Thus, Once we compute the list ```W``` (which can be done with simple iterations), all we need to do is update L to be ```L union W```.

Now, that we have taken care of all the disliked warriors.

We move to liked warriors(updated list).

As all of these will be a part of the final arena, we need not bother about any of the edges that come out of the vertices in this list, so after removing all the vertices signifying disliked warriors and removing all the edges starting from our updated list of liked warriors, we'd be left with ```G'(X',Y',E')``` and we need to find the minimum number of vertices such that we could cover all the interesting fights. (This is known as the Minimum [Vertex Cover](https://mathworld.wolfram.com/VertexCover) of a graph.)

Bipartite Graphs have a special property given by [Koenig's Theorem](https://mathworld.wolfram.com/Koenig-EgevaryTheorem.html), which states that the size of the minimum vertex cover of any bipartite graph is same as the size of the [maximum matching](https://en.wikipedia.org/wiki/Matching_(graph_theory)).

This reduces our problem to finding the Maximum Matching of the new Graph (```G'```), and standard algorithms are available for the same.

Using the [Hopcraft Karp](https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm) Algorithm for finding the maximum matching, will pass all testcases and so will an extremely efficient implementation of [Kuhn's Algorithm](https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html).

You may read about said algorithms and theorems from the hyperlinks above.
The solution is available [here](./The%20Tournament%20of%20Power/sol.cpp).


