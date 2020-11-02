# MemoryAllocationSimulator
Simulate memory allocation with hole-fitting algorithms (First-fit, Best-fit) and implement de-allocation and defragmentation.

Objective:
Simulate memory allocation with hole-fitting algorithms (First-fit, Best-fit) and implement de-allocation and defragmentation.

Specification:
The program simulates memory allocation with a chosen hole-fitting algorithm (First-fit, Best-fit) and implements de-allocation and defragmentation. A menu controls the operations, and each choice calls the appropriate procedure, where the choices are: 1) Enter parameters; 2) Allocate memory for a block; 3) Deallocate memory for a block; 4) Defragment memory; 5) Quit program and free memory.

Assignment:
The size of physical memory is represented by an integer pmsize.
The allocated blocks are contained within a linked list, where each allocated block is a structure containing an id, the starting address, the ending address, and a link to the next allocated block.
Each allocation request specifies the id and the size of the new block. If the id is a duplicate and/or the remaining physical memory is not enough to fit the request, the request is rejected.
Each de-allocation request specifies the id. If the id is invalid, the request is rejected.
Defragmentation compacts the blocks to be contiguous, and coalesces the holes into one hole at the far--right end (highest memory addresses) of physical memory.

Sample output: (Inputs: 1 1024 1 2 0 128 2 1 320 2 2 224 2 3 288 3 2 2 4 128 3 1 2 2 224 2 5 64 4 5)

Memory allocation strategies
----------------------------
1) Enter parameters
2) Allocate memory for block
3) Deallocate memory for block
4) Defragment memory
5) Quit program

Enter selection: 1
Enter size of physical memory: 1024
Enter hole-fitting algorithm (0=first fit, 1=best_fit): 1

Memory allocation strategies
----------------------------
1) Enter parameters
2) Allocate memory for block
3) Deallocate memory for block
4) Defragment memory
5) Quit program

Enter selection: 2
Enter block id: 0
Enter block size: 128

ID    Start   End
-------------------
0     0       128

Memory allocation strategies
----------------------------
1) Enter parameters
2) Allocate memory for block
3) Deallocate memory for block
4) Defragment memory
5) Quit program

Enter selection: 2
Enter block id: 1
Enter block size: 320

ID    Start   End
-------------------
0     0       128
1     128     448

Memory allocation strategies
----------------------------
1) Enter parameters
2) Allocate memory for block
3) Deallocate memory for block
4) Defragment memory
5) Quit program

Enter selection: 2
Enter block id: 2
Enter block size: 224

ID    Start   End
-------------------
0     0       128
1     128     448
2     448     672

Memory allocation strategies
----------------------------
1) Enter parameters
2) Allocate memory for block
3) Deallocate memory for block
4) Defragment memory
5) Quit program

Enter selection: 2
Enter block id: 3
Enter block size: 288

ID    Start   End
-------------------
0     0       128
1     128     448
2     448     672
3     672     960

Memory allocation strategies
----------------------------
1) Enter parameters
2) Allocate memory for block
3) Deallocate memory for block
4) Defragment memory
5) Quit program

Enter selection: 3
Enter block id: 2

ID    Start   End
-------------------
0     0       128
1     128     448
3     672     960

Memory allocation strategies
----------------------------
1) Enter parameters
2) Allocate memory for block
3) Deallocate memory for block
4) Defragment memory
5) Quit program

Enter selection: 2
Enter block id: 4
Enter block size: 128

ID    Start   End
-------------------
0     0       128
1     128     448
4     448     576
3     672     960

Memory allocation strategies
----------------------------
1) Enter parameters
2) Allocate memory for block
3) Deallocate memory for block
4) Defragment memory
5) Quit program

Enter selection: 3
Enter block id: 1

ID    Start   End
-------------------
0     0       128
4     448     576
3     672     960

Memory allocation strategies
----------------------------
1) Enter parameters
2) Allocate memory for block
3) Deallocate memory for block
4) Defragment memory
5) Quit program

Enter selection: 2
Enter block id: 2
Enter block size: 224

ID    Start   End
-------------------
0     0       128
2     128     352
4     448     576
3     672     960

Memory allocation strategies
----------------------------
1) Enter parameters
2) Allocate memory for block
3) Deallocate memory for block
4) Defragment memory
5) Quit program

Enter selection: 2
Enter block id: 5
Enter block size: 64

ID    Start   End
-------------------
0     0       128
2     128     352
4     448     576
3     672     960
5     960     1024

Memory allocation strategies
----------------------------
1) Enter parameters
2) Allocate memory for block
3) Deallocate memory for block
4) Defragment memory
5) Quit program

Enter selection: 4

ID    Start   End
-------------------
0     0       128
2     128     352
4     352     480
3     480     768
5     768     832

Memory allocation strategies
----------------------------
1) Enter parameters
2) Allocate memory for block
3) Deallocate memory for block
4) Defragment memory
5) Quit program

Enter selection: 5
Quitting program...
