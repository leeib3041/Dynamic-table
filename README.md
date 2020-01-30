# Dynamic Tables

In this assignment, we will verify if the accounting method does a good job in estimating the complexity of a sequence of insertion in a dynamic table.


### Step 1 - Setup

The `main.cpp` file provides the code needed to test your implementation of the Dynamic Table. Nothing to be changed here so far.

`Time.*` are also two external libraries that will help you estimating the time required for performing certain operations. Nothing to be changed here.

`DynamicTable.*` contains the DynamicTable class that you have to implement. Before starting with that, let's try to compile the project to check that everything is ready.

If you are familiar with `cmake`, I am already providing a cmake file for compiling the project. In this case just run the following commands:

```bash
mkdir build
cd build
cmake ..
make
```

you should obtain the executable named `dynamicTable` in the `build` directory.
If you do not want to use cmake you can compile the program from the main folder with the following command.

```bash
g++ main.cpp DynamicTable.cpp Timer.cpp -o dynamicTable
```

```
Command I had to run in order to compile
Using zsh
g++ main.cpp DynamicTable.cpp Timer.cpp -o dynamicTable -std=c++11
```

### Step 2 - Implementing the Dynamic Table

As we have seen in class, a dynamic table is an array that automatically resize itself when it gets full. This can be implemented by combining two simple functions, `insert` and `resize`.

* Header file - Start from `DynamicTable.h`, and implement the constructor and destructor of the table. This are the functions called when you create a new Dynamic Table or when you don't need it anymore.

* Implementation - Now implement the two functions insert and resize in `DynamicTable.cpp`

### Step 3 - Testing and Evaluation

According to `main.cpp` we are inserting an integer (the value 10) into the table `op` times. Check that everything is correct by running the program with increasing values of `op`. `Timer` is tracking the time needed to perform the insertions into the table. You can add the line

```c++
cout << time.getElapsedTime() << endl;
```
to print out the time occurred. Once you are confident the implementation is correct uncomment the remaining commented lines

What is the code supposed to do now?
[PUT YOUR ANSWER HERE]
```
        1. The code create and opens an output file
        2. Loops 999 times, each loop creating an instance of a dynamic table
        3. Timer starts
        4. Each instance of the dynamic table that is created loops through N amount of times (N being whatever iteration it's in out of the 999 first for loop), then inserts the value 10
        5. Timer ends
        6. Write the elapsed time to the output text file created at step 1
        7. When loop reaches last iteration, close file write

        File:
        The file will have the printout of the elapsed time from the executable written from step 6.
```

We want to test if it is true that by increasing the size of our input the increase in complexity is not quadratical (`O(n^2)`) but linear (`O(n)`). Once the program has been executed you should get a file in output `results.txt`. Run the following command in python to get a graphical representation of the timings (be sure that plot_time.py and results.txt are in the same folder when you run it)

```bash
python plot_time.py
```

```
No file "plot_time.py", the repo has "plot_results.py" instead
Using zsh
python plot_results.py
```

How is the graph obtained related to amortized analysis?
[PUT YOUR ANSWER HERE]
```
        We established using the amortized analysis Accounting Method that:
        - ADD (or in this case, insert) payment = 3 coins
        - RESIZE payment = 0 coins

        Below is a short visualization of the code, the number at the end signifies the amount of coin left over after some event (ADD or RESIZE) and we'll call this the "Pot":

        size
        1    []  0
        1    [x] 2
        2    [x][x] 3
        4    [x][x][x][] 3 ---> [x][x][x][+2] 5
        8    [x][x][x][x][x][][][] 3 ---> [x][x][x][x][x][+2][+2][+2] 9
        16   [x][x][x][x][x][x][x][x][x][][][][][][][] 3 ---> [x][x][x][x][x][x][x][x][x][+2][+2][+2][+2][+2][+2][+2] 17
        32   [x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][][][][][][][][][][][][][][][] 3 ---> [x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][x][+2][+2][+2][+2][+2][+2][+2][+2][+2][+2][+2][+2][+2][+2][+2] 33

        The graph, when "op<1000", almost looked like O(logn). To confirm that wasn't the case, I changed the for loop to keep going until "op<5000". This gave me a bigger picture to see that it was indeed linear.

        The graph and amortized analysis is related in how the amount of coins are in the "pot". The pot gradually increases by 2 every time there is an insert. The pattern is not noticeable until the size of the array gets bigger.
        When the array is full, a new array of double size is created and the values are copied over from the previous array. This operation is particularly expensive. It is because of this expense that the graph has a higher spike in time before it averages out back to a constant time complexity. Therefore, the time complexity for Insertion is O(1).

        The Accounting Method seems to do a good job of estimating the time complexity of a sequence of insertion in a dynamic table.
```
