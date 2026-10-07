# Processes & Threads

v.kalka@innopolis.university

## Exercise 1

### What is the problem?
Create two child processes. and execution time.

### Algorithm
1. Create the first child using fork(). Create second 
2. Print PID, PPID, and execution time.
3. Wait for both children using wait().

ничего сложного
---

## Exercise 2

### What is the problem?
Call fork() in a loop and observe how the number of processes changes for different values of n

### Algorithm
1. Read n 
2. Call fork() n times.
3. Sleep for 5 seconds after fork().
4. Use pstree to observe the processes
5. Compare results for n=3 and n=5.
---
## Exercise 3

### What is the problem?
Create a simple shell that can execute commands with arguments and run them in the background

### Algorithm
1. Read and split command into arg
2. Create a child process using fork().
3. Execute the command using execve().
4. Let parent continue without waiting child

### Was it difficult?
I had to understand how fork() and execve() work together(((
