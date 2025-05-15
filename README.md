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
This assignment uses ACSL to formally specify and verify a C function corresponding to the following exercise:

**Exercise:**  
Demonstrate that:  
{ i * j + 2 * j + 3 * i = 0 }  
j := j + 3;  
i := i + 2;  
{ i * j = 6 }

We wrote a contract that captures the precondition and postcondition, and verified the function's correctness using Frama-C's WP plugin.

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

## Contract Explanation and Verification
The ACSL contract specifies the expected behavior of the function tarea by defining preconditions and a postcondition:

  -Preconditions (requires): These conditions restrict the valid input values for the function parameters i and j. In this case, i and j must be between -10 and 10, and must satisfy the equation i     *j + 2 * j + 3 * i == 0 before the function executes.

  -Postcondition (ensures): This condition must hold true after the function execution. It states that after updating i and j (by adding 2 and 3, respectively), the product (i + 2) * (j + 3) should    equal 6.

  Frama-C's WP plugin uses these annotations to formally verify that the implementation of the function respects the specified contract. When the verification succeeds, it guarantees that for all     inputs meeting the preconditions, the postcondition will always be true after executing the function. This helps ensure the correctness of the code according to its formal specification.

## Repository Contents
This repository contains only the essential files for this assignment:  
  tarea3.c – C function with ACSL contract  
  README.md – This documentation file  
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
