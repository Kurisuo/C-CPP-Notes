# C-CPP-Notes

A personal repo tracking my C and C++ studies — code examples, exercises, and notes from working through programming books. I'm currently reading *A Tour of C++* (Stroustrup) and plan to read *Computer Systems: A Programmer's Perspective* (Bryant and O'Hallaron) to complement my Systems Programming coursework.

The roadmap below outlines my study plan toward AI infrastructure and GPU programming work.

---

## Roadmap

### Background

Coming from a former Biomolecular Engineering & Bioinformatics background before switching to Computer Science with an Applied Mathematics minor. The math minor has expanded my interests into quantitative finance alongside my core focus on systems engineering and AI infrastructure.

This summer I am contributing to two research labs simultaneously — the **AIEA Lab** (Prof. Leilani Gilpin, Explainable AI & autonomous systems) and the **Tech4Good Lab** (Gen AI/ML applications). I also explored **agentic coding** through the **NVIDIA x ASUS NemoClaw Hackathon**, where I built NVPilot — an autonomous GPU performance optimization agent.

These tracks run in parallel, not sequentially. The Limit Order Book project is my active capstone, developed alongside my ongoing studies rather than after them.

---

### Active Capstone

**[Extended Limit Order Book Matching Engine](https://github.com/Kurisuo/Limit-Order-Book)** *(C++)*

A high-performance matching engine implementing limit orders, cancellations, and partial fills, with two original custom order types:
- *Banded Execution Order* — configurable tolerance floor for flash crash protection
- *VWAP Pre-Execution Gate* — validates blended average fill cost before sweeping thin books

---

### Parallel Study Tracks

| Track | Focus | Primary Resources |
|---|---|---|
| **C++ Foundations** | Modern C++ fluency for systems-level work | *A Tour of C++* (3rd Ed., Stroustrup) · cppreference · learncpp |
| **Algorithms & Interview Prep** | Pattern recognition and algorithmic fluency | *Beyond Cracking the Coding Interview* (2025) · NeetCode · LeetCode |
| **Systems Programming** | How code executes at the hardware level | *Computer Systems: A Programmer's Perspective* · MIT Missing Semester |
| **AI Research** | Explainable AI, neural explanations, LLMs | AIEA Lab — UC Santa Cruz (CMPM 118S) |
| **Full-Stack Development** | Production application engineering | Tech4Good Lab — UC Santa Cruz |
| **Agentic Coding** | AI-augmented development workflows | NVIDIA NemoClaw stack — continued exploration |

---

### Long-Term Direction

**GPU Programming and AI Infrastructure** — Building toward roles in ML systems engineering and AI infrastructure at companies like NVIDIA, Apple, and Google.

**Resources**
- *Programming Massively Parallel Processors* — Kirk and Hwu
- NVIDIA CUDA C++ Programming Guide
- CoffeeBeforeArch CUDA tutorials
- Johns Hopkins GPU Programming Specialization (Coursera, in progress)

**Planned Project**

**[Neural Inference Engine](https://github.com/Kurisuo)** *(C++ / CUDA)* — A from-scratch forward-pass inference engine implementing matrix multiplication, ReLU, and Softmax without ML libraries. CUDA port planned with shared memory tiling for GPU acceleration.

---

### UCSC Coursework

**In Progress**
- **CSE 130** — Principles of Computer Systems Design

**Upcoming (Fall 2026)**
- **CSE 113** — Parallel and Concurrent Programming
- **CSE 180** — Databases
- **AM 20** — Differential Equations

**Planned**
- **AM 147** — Scientific Computing
- **AM 148** — GPU Programming for Scientific Computations *(after AM 147)*
- **CSE 120** — Computer Architecture
- **CSE 134** — Embedded Operating Systems
- **CSE 138** — Distributed Systems
- **CSE 140** — Artificial Intelligence
- **CSE 142** — Machine Learning
- **CSE 150** — Computer Networks
- Applied Mathematics minor coursework

---

## How I'm Using This Repo

This repo has grown into a comprehensive study hub covering multiple 
tracks simultaneously. Here's how each folder is organized:

**`A Tour of C++/`** — Chapter-by-chapter notes and typed-out code 
examples from Stroustrup's book. Each chapter folder contains three 
sections: **NEW** (unfamiliar concepts), **USEFUL** (concepts to apply 
to projects), and **CONFUSED** (topics to revisit).

**`C-Notes/`** — General C language review covering fundamentals 
like pointers, memory management, and systems-level programming 
concepts foundational to C++ work.

**`CPP-Notes/`** — Standalone C++ concept notes outside of the book 
walkthrough — STL containers, modern C++ features, patterns encountered 
while building projects.

**`Beej's Guide to C Programming/`** — Notes and exercises from 
working through Beej's Guide, focusing on pointers, memory, and 
systems programming foundations.

**`Beyond Cracking the Coding Interview/`** — Algorithm and data 
structure notes organized by pattern (arrays, linked lists, trees, 
graphs, dynamic programming) alongside LeetCode practice.

**`GPU Programming/`** — Notes from the Johns Hopkins GPU Programming 
Specialization (Coursera) covering CUDA kernels, memory hierarchy, 
thread management, and parallel algorithms.

**`other/`** — Miscellaneous notes, experiments, and concepts that 
don't fit neatly into the above categories.

Major projects live in their own repositories.