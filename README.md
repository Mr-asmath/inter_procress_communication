# Shared Memory Communication (Parent-Child Process)

## Introduction
This program demonstrates **Inter-Process Communication (IPC)** using **Shared Memory** between a **Parent Process** and a **Child Process** in a UNIX-based system. The **Parent Process** writes data into shared memory, and the **Child Process** reads it.

## Features
- Uses `fork()` to create a child process.
- Implements **Shared Memory (`shmget`, `shmat`, `shmdt`, `shmctl`)**.
- The **Parent Process writes characters (`a` to `j`)** into shared memory.
- The **Child Process reads the data** and prints it.
- Ensures proper detachment and cleanup of shared memory.

## Compilation & Execution
### **Step 1: Compile the Program**
```sh
gcc -o shared_memory shared_memory.c
```

### **Step 2: Run the Program**
```sh
./shared_memory
```

## Code Explanation
1. **Create a Shared Memory Segment:**
   - `shmget(2041, 32, 0666 | IPC_CREAT)` creates a 32-byte shared memory.
2. **Attach the Shared Memory:**
   - `shmat(shmid, NULL, 0)` attaches the memory segment to the process.
3. **Write to Shared Memory (Parent Process):**
   - The parent writes characters (`a` to `j`) into shared memory.
4. **Read from Shared Memory (Child Process):**
   - The child reads the same data and prints it.
5. **Detach and Remove Shared Memory:**
   - `shmdt(shmptr);` detaches from shared memory.
   - `shmctl(shmid, IPC_RMID, NULL);` removes the shared memory segment.

## Sample Output
```
PARENT WRITING:
a b c d e f g h i j

CHILD IS READING:
a b c d e f g h i j
```

## Notes
- Ensure **IPC (Inter-Process Communication) support** is enabled in your system.
- Run the program **on a UNIX-based system**.
- **Use `ipcs -m`** to check active shared memory segments.
- **Use `ipcrm -m <shmid>`** to manually remove shared memory if needed.

## Author
- **Arshad Hisham**

---
Let me know if you need modifications or enhancements! 🚀

