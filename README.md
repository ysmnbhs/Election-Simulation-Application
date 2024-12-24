# Election Simulation Program

This is a C-based console application designed as a part of my first-year programming coursework. The program simulates an election system where users input votes for different political parties across various regions. It calculates and displays the results, including the distribution of parliamentary seats for each party based on a proportional representation system.

---

## Features
- **Dynamic Data Input**:
  - Accepts the region's license plate code and ensures its uniqueness.
  - Prompts for the total number of parliamentary seats (contingent) for each region.
  - Accepts vote counts for six parties (`A`, `B`, `C`, `D`, `E`, `F`).

- **Vote and Seat Calculation**:
  - Calculates the total valid votes per region and party.
  - Uses the **D'Hondt Method** to allocate parliamentary seats proportionally.

- **Sorting and Results Display**:
  - Sorts parties based on their vote counts in descending order for clear visualization.
  - Displays detailed election results for each region, including:
    - Total valid votes.
    - Vote percentage.
    - Allocated parliamentary seats.
  - Summarizes the national results with overall votes and seat distribution percentages.

- **Languages and Platform**:
  - Written in C for simplicity and clarity.
  - Runs on any platform with a C compiler.
