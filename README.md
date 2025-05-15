# Assignment-3---Helen-Sanabria---Jeronimo-Rodriguez
Assignment 3 – Theory of Computation

## Students:
Helen Valentina Sanabria Guevara  
Jerónimo Rodríguez Restrepo

## Versions Used
  Operating system used: Windows 11 / using WSL version 2.4  
  Compiler used: Linux Distribution - Debian 12  
  Tools used: Frama-C Version 30.0, WP plugin (with options -wp and -wp-rte)

## Description
This assignment demonstrates the use of ACSL (ANSI/ISO C Specification Language) to formally specify and verify the behavior of a C function. We wrote a contract for the function provided in Exercise 5, Section 9.3, and verified the correctness of the implementation using Frama-C's WP plugin.

## Overview
This assignment uses ACSL to define:
  - Preconditions: input restrictions for the function.
  - Postcondition: a property that must be true after execution.
  - Formal verification: confirming that the implementation respects the contract.

## Instructions to Run the Solution
1. Save the following code into a file named `tarea3.c`:

/*@  
  requires -10 <= i <= 10;  
  requires -10 <= j <= 10;  
  requires i * j + 2 * j + 3 * i == 0;  
  ensures (i + 2) * (j + 3) == 6;  
*/  
void tarea(int i, int j) {  
  j = j + 3;  
  i = i + 2;  
}

2. Open a Debian terminal through WSL and navigate to the folder where the file is saved.  
   For example, if it's in the Downloads folder, run:  
   `cd downloads`

3. Launch Frama-C GUI and run verification automatically with:  
   `frama-c-gui -wp -wp-rte tarea3.c`

4. Once the GUI opens, the verification results will be ready.  
   You can click on the blue circles next to the function to see details or re-run proofs if needed.

5. A green mark indicates the contract is successfully verified.

## Repository Contents
This repository contains only the essential files for this assignment:  
  tarea3.c – C function with ACSL contract  
  README.md – This documentation file  
  documentation.pdf – Explanation of the contract  
  video.mp4 – Presentation of the work

## References
Grassmann, W.K., Tremblay, J.-P., & Grassmann, W.K. (1996).  
*Logic and Discrete Mathematics: A Computer Science Perspective*. Prentice Hall.

Correnson, L., Cuoq, P., Kirchner, F., et al. (2023).  
*Frama-C User Manual* (v30.0 Zinc).

Prevosto, V.  
*ACSL Mini-Tutorial*. CEALIST.

Baudin, P., Cuoq, P., Filliâtre, J.-C., et al.  
*ANSI/ISO C Specification Language v1.21 — Frama-C 30.0 Implementation*.

*Introduction to C Program Proof with Frama-C and its WP Plugin* (2020).

Frama-C official documentation:  
https://frama-c.com/html/documentation.html
