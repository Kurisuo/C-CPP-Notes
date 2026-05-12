# C-CPP-Notes

A personal repo tracking my C and C++ studies — code examples, exercises, and notes from working through programming books. I'm currently reading A Tour of C++ (Stroustrup) and plan to read Computer Systems: A Programmer's Perspective (Bryant and O'Hallaron) to complement my Systems Programming coursework.

The roadmap below outlines my study plan toward AI infrastructure and GPU programming work.

---

## Roadmap

### Background

Coming from a former Biomolecular Engineering & Bioinformatics background before switching to Computer Science with an Applied Mathematics minor. The math minor has expanded my interests into quantitative finance alongside my core focus on systems engineering and AI infrastructure. Through my upcoming work in the **Tech4Good lab at UCSC**, I expect to develop full-stack development skills in addition to my systems work. I'm also exploring **agentic coding** as a result of the stack I'll work with at the **NVIDIA x ASUS Hackathon**.

These tracks run in parallel — not sequentially. The Limit Order Book project is my active capstone, developed alongside my ongoing studies rather than after them.

---

### Active Capstone

**Extended Limit Order Book Matching Engine** *(C++)*
A high-performance matching engine implementing limit orders, cancellations, and partial fills, with two custom order types: a *Banded Execution Order* for flash crash protection and a *VWAP Pre-Execution Gate* for thin-book validation.

---

### Parallel Study Tracks

| Track | Focus | Primary Resources |
|---|---|---|
| **C++ Foundations** | Modern C++ fluency for systems-level work | *A Tour of C++* (3rd Ed., Stroustrup) · cppreference · learncpp |
| **Algorithms & Interview Prep** | Pattern recognition and algorithmic fluency | *Beyond Cracking the Coding Interview* (2025) · NeetCode · LeetCode |
| **Systems Programming** | How code executes at the hardware level | *Computer Systems: A Programmer's Perspective* · MIT Missing Semester |
| **Full-Stack Development** | Frontend and backend application engineering | Tech4Good Lab work (upcoming) |
| **Agentic Coding** | AI-augmented development workflows | NVIDIA Hackathon stack and continued exploration

---

### Long-Term Direction

**GPU Programming and AI Infrastructure** — Building toward roles within ML systems teams, and AI infrastructure organizations. 

**Resources**

- NVIDIA CUDA C++ Programming Guide

**Planned project**
**Neural Inference Engine** *(C++ / CUDA)* — A from-scratch forward-pass inference engine with planned CUDA port using shared memory tiling.

---

### UCSC Coursework

Upcoming
- **CSE 113** —- Parallel and Concurrent Programming
- **CSE 180** -- Databases
- **AM 20**   -- Differential Equations

Planned
- **CSE 120** —- Computer Architecture
- **CSE 138** -- Distributed Systems
- **CSE 142** -- Machine Learning
- **CSE 150** -- Computer Networks
- **CSE 187** -- Full Stack II
- **AM 148**  —- GPU Programming for Scientific Computations 
- Applied Mathematics minor coursework

---

## How I'm Using This Repo

Each chapter of *A Tour of C++* gets its own folder containing typed-out code examples and short notes with three sections: **NEW** (unfamiliar concepts), **USEFUL** (concepts to apply to projects), and **CONFUSED** (topics to revisit).

Other general notes live in their corresponding folder.

Major projects live in their own repositories.
