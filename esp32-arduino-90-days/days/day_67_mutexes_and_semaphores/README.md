# Day 67: Mutexes and semaphores

**Goal:** Protect a shared variable while multiple tasks access it.

## Run
Upload and open Serial Monitor at 115200 baud. Two tasks increment and print the same counter while holding a mutex.

## Concepts
A mutex provides mutual exclusion. A task must take it before accessing the shared counter and give it back afterward. Keep the protected section short; never wait for unrelated events while holding a mutex.

## Exercise
Add a short calculation inside the protected section and compare behavior with and without the mutex.