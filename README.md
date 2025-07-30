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

### 📋 Comparative Analysis

|  n  |  C  |  Assembly  |
| :---: | :---: | :---: |
| 2<sup>20</sup> |  0.001800  |  0.000633  |
| 2<sup>24</sup> |  0.030167  |  0.012200  |
| 2<sup>28</sup> |  0.530233  |  0.193000  |

**Table 1. Summary of execution time and performance**

The results in Table 1 shows a clear and consistent performance advantage of the x86-64 Assembly implementation over the C implementation of the SAXPY operation. As the vector size (n) increases, both versions take more time to complete, but it also shows that the Assembly version consistently executes faster.

At n = 2<sup>20</sup>, The Assembly implementation is almost 3x faster than the C version.

At n = 2<sup>24</sup>, it shows almost 2.5x faster.

And lastly, at n = 2<sup>28</sup>, it is more than 2.5x faster.

This performance gain can be attributed to the use of scalar SIMD floating-point instructions in the assembly in which it offers more control over low-level operations and it allows better optimization of the computational pipeline compared to the standing C version. Despite having both implementations achieving correct results, the version which is more efficient for high-performance vectorized computation as the data size scales up is the Assembly version.

---

### 📷 Screenshot of Output

![ScreenshotOfOutput](images/LBYARCH-MP2-X86-C_Output_Group4.png)

---

### 🔗 Link to Short Video Demo

Google Drive Link: https://drive.google.com/drive/folders/1YeBKtaViG5r0Mw-57eqS0H3bR5OYW2Ry?usp=sharing

---
