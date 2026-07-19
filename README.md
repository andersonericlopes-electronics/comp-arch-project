# ChampSim Assignment Report

This repository contains the completed work for the Computer Architecture assignment that replaces the three labs. It includes the uploaded result logs, supporting source files, and a concise report for each task completed in the ChampSim simulator.

## GitHub Repository

Repository link: https://github.com/andersonericlopes-electronics/comp-arch-project


## What Is Included

- Branch predictor experiments for Task 1A
- LLC set-size and cache configuration study for Task 2A
- Cache associativity study for Task 2B
- Replacement policy study for Task 2C
- Support program for trace generation in Task 1A
- Result logs for single-core and multi-core simulations

## Files and Folders in This Repository

- Task 1A: [task1 a](task1%20a)
  - Branch predictor comparison for single-core traces and 4-core mix
  - Supporting source file: [task1 a/4 core/random_trace_generator.c](task1%20a/4%20core/random_trace_generator.c)
- Task 2A: [task 2a](task%202a)
  - Results for different LLC set counts and cache configurations
- Task 2B: [task2b](task2b)
  - Results for 8-way and 16-way cache associativity experiments
- Task 2C: [task2c](task2c)
  - Results for multiple replacement policies including LRU, MRU, Random, DRRIP, SRRIP, and SHIP

## Task 1A — Branch Predictor Evaluation

### Objective
To compare the impact of different branch predictors on performance using the ChampSim simulator.

### Experiments Performed
The repository contains results for the following predictors:
- Bimodal
- GShare
- Hashed Perceptron
- Perceptron

### Observations from the Uploaded Results
- For trace 403, the branch prediction accuracy improved from 99.6671% with bimodal to 99.7915% with GShare, 99.9641% with Hashed Perceptron, and 99.8409% with Perceptron. The IPC also improved from 1.1868 to 1.20768 with Hashed Perceptron.
- For trace 434, Hashed Perceptron achieved the highest accuracy at 99.9315% and the highest IPC of 1.21331.
- For trace 437, Hashed Perceptron again produced the best accuracy at 99.9586% and the best IPC of 1.00223.
- For trace 462, Hashed Perceptron gave the strongest improvement, reaching 99.9881% accuracy and an IPC of 0.505895.
- In the 4-core mixed workload, Hashed Perceptron achieved the highest IPC of 0.839334, compared with 0.786501 for Bimodal, 0.799895 for GShare, and 0.79667 for Perceptron.

### Conclusion
Hashed Perceptron was the most effective predictor for the supplied traces and performed best overall in both single-core and multi-core experiments.

## Task 2A — LLC Set-Count / Cache Configuration Study

### Objective
To study how changing the number of cache sets affects the cache behavior and overall processor performance in ChampSim.

### Observations from the Uploaded Results
- The 4-core workload showed an IPC improvement as the cache configuration moved from the smaller set count to the larger one:
  - 1MB / 1024 sets: 0.738247 IPC
  - 2MB / 2048 sets: 0.821364 IPC
  - 4MB / 4096 sets: 0.973002 IPC
  - 8MB / 8192 sets: 1.02883 IPC
- The single-core logs showed the same general trend, with the larger configurations giving better or equal execution results for the selected traces.

### Conclusion
Increasing the cache set count improved the observed performance for the uploaded workloads, especially in the multi-core case.

## Task 2B — Associativity Study

### Objective
To evaluate the effect of changing cache associativity on performance.

### Observations from the Uploaded Results
- The uploaded 8-way and 16-way logs show very small differences in performance.
- In the 4-core result set, 16-way achieved 0.0974307 IPC, while 8-way achieved 0.0972329 IPC.
- The difference is minor, which suggests that associativity had a limited impact on these particular traces.

### Conclusion
For the tested workloads, increasing associativity from 8-way to 16-way did not produce a major performance gain.

## Task 2C — Replacement Policy Study

### Objective
To compare different LLC replacement policies and determine which one gives the best performance in ChampSim.

### Policies Tested
- Random
- LRU
- MRU
- DRRIP
- SRRIP
- SHIP

### Observations from the Uploaded Results
- In the 4-core workload, SHIP achieved the best IPC at 0.661574.
- SRRIP followed with 0.59975 IPC.
- DRRIP achieved 0.58433 IPC.
- LRU and MRU both produced 0.566958 IPC.
- Random gave the lowest IPC at 0.534405.

### Conclusion
SHIP performed best among the tested replacement policies for the uploaded workload, while Random was the least effective.

## Where the Simulator Changes Were Applied

The assignment work was completed by modifying the relevant ChampSim configuration and policy modules used by the simulator:

- Branch predictor selection and predictor implementation changes for Task 1A
- Cache configuration changes for the set-count and associativity study in Task 2A and Task 2B
- Replacement policy selection and integration for Task 2C

In a standard ChampSim installation, these changes are typically made in the following areas:
- Branch predictor files under the predictor source directory
- Cache configuration files for LLC size, sets, and ways
- Replacement policy source files for LRU, MRU, Random, DRRIP, SRRIP, and SHIP

## Reproducibility Notes

The results stored in this repository were generated using ChampSim and the corresponding configuration changes needed for each task. The logs are organized by task and experiment type so the results can be reviewed and compared directly.

## Final Remarks

This repository provides a complete documentation package for the assignment, including experimental results, implementation notes, and the simulator change points used to generate the reported outcomes. The work is prepared for submission and for future review in a structured GitHub repository.
