Linked List Cycle II
Problem

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return NULL.

Approach

This problem is solved using Floyd's Cycle Detection (Tortoise and Hare).

Step 1: Detect the Cycle
Initialize two pointers:
slow moves one step.
fast moves two steps.
If they meet, a cycle exists.
If fast reaches NULL, there is no cycle.
Step 2: Find the Starting Node
Reset slow to the head.
Keep fast at the meeting point.
Move both pointers one step at a time.
The node where they meet again is the starting node of the cycle.
Why does this work?

Let

a = distance from head to cycle start
b = distance from cycle start to meeting point
c = length of the cycle

At the first meeting,

Slow distance = a + b
Fast distance = 2(a + b)

Also,

Fast distance = a + b + k × c

Therefore,

2(a + b) = a + b + k × c

a + b = k × c

a = k × c - b

This means:

From head → cycle start = a
From meeting point → cycle start = k × c - b

So after resetting one pointer to the head and moving both one step at a time, they will meet exactly at the cycle's starting node.

Complexity
Time: O(n)
Space: O(1)