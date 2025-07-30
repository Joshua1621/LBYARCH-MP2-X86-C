# LBYARCH-MP2-X86-C

**LBYARCH MP2 X86-C Interface Programming Repository**

**Group 4 Members:**  
- Joshua Benedict B. Co  
- Llandro Massimo B. Colcol

---

## 📌 Project Specification

This project implements a **SAXPY** (`Z[i] = A * X[i] + Y[i]`) kernel using:

- ✅ A C program implementation  
- ✅ An x86-64 assembly language implementation  

---

### 🔧 Requirements

- Use **functional scalar SIMD registers**
- Use **functional scalar SIMD floating-point instructions**

---

### 🧮 Input

- `n` — Length of vectors (integer)
- `A` — Scalar multiplier (single-precision float)
- `X`, `Y` — Input vectors (single-precision float)

---

### ⚙️ Process

Compute each element of output vector `Z` using the formula: (`Z[i] = A * X[i] + Y[i]`)

---

### 📤 Output

- Store result in vector `Z`
- Display the **first 10 elements** of `Z` for:
  - C version
  - x86-64 assembly version
 
---

### Comparative Analysis

|  n  |  C  |  Assembly  |
| :---: | :---: | :---: |
| 2<sup>20</sup> |  0.001700  |  0.000667  |
| 2<sup>24</sup> |  0.031200  |  0.012900  |
| 2<sup>28</sup> |  0.613500  |  0.232767  |

**Table 1. Summary of execution time and performance**

Insert Analysis here...

---
### Comparative execution time and short analysis of the performance of the kernels
### Take a screenshot of the program output with the correctness check (C)
### Take a screenshot of the program output, including the correctness check (x86-64)
### Short videos (5-10mins) showing your source code, compilation, and execution of the C and x86-64 program
