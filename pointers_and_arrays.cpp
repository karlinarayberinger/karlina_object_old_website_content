/**
 * file: pointers_and_arrays.cpp
 * type: C++ (source file)
 * author: Karlina Ray Beringer 
 * date: 05_MAY_2022
 */

/* preprocessing directives */
#include <iostream> // standard input and output operations (command line terminal and keyboard)
#include <fstream> // file input and output operations (text file generation)
#include <stdio.h> // library which contains NULL macro
#include <stdlib.h> // library for srand() and rand() functions
#include <time.h> // library for time() function
#define MAXIMUM_N 1000 // upper limit constant for values of N (and N represents the number of array elements to assign to a dynamic array named A)
#define MAXIMUM_S 1000 // upper limit constant for values of S (and S represents the number of unique states which each element of A can represent)

/* function prototypes */
void bubble_sort(int * A, int N);
int ** generate_two_dimensional_rectangular_array_of_integers(int number_of_rows, int number_of_columns);

/**
 * Use the Bubble Sort sorting algorithm to arrange the elements of array A in ascending order.
 * 
 * Note that, even though this function returns nothing, the array pointer which is passed in as a function parameter is updated.
 * 
 * Assume that there are at least N consecutive int-sized chunks of memory allocated to array A
 * (and that N is a natural number no larger than MAXIMUM_N).
 */
void bubble_sort(int * A, int N)
{
    int i = 0, placeholder = 0; 
    if (!A || (N < 1) || (N > MAXIMUM_N)) return;
    bool array_is_sorted = false, adjacent_elements_were_swapped = false;
    while (!array_is_sorted)
    {
        adjacent_elements_were_swapped = false;
        for (i = 1; i < N; i += 1)
        {
            if (A[i] < A[i - 1])
            {
                placeholder = A[i];
                A[i] = A[i - 1];
                A[i - 1] = placeholder;
                adjacent_elements_were_swapped = true;
            }
        }
        if (!adjacent_elements_were_swapped) array_is_sorted = true;
    }
}

/**
 * Dynamically instantiate a two-dimensional array which resembles a rectangular grid.
 * 
 * The memory address returned by this function is a pointer to a pointer to an int type variable.
 * 
 * The memory address returned by this function is the first element of an array comprised of 
 * number_of_rows one-dimensional arrays which are each number_of_columns in length.
 * 
 * Note that, because the two-dimensional array was allocated memory during runtime rather than at compile time,
 * the two-dimensional array will need to be de-allocated so that the computer can re-use that memory.
 * (Dynamic variables are not automatically deleted when the program terminates).
 * 
 * Assume that number_of_rows is a natural number and that number_of_columns is a natural number.
 */
int ** generate_two_dimensional_rectangular_array_of_integers(int number_of_rows, int number_of_columns)
{
    int i = 0, k = 0, value = 0;
    int ** rectangular_array = new int * [number_of_rows];
    for (i = 0; i < number_of_rows; i += 1) rectangular_array[i] = new int [number_of_columns];
    for (i = 0; i < number_of_rows; i += 1) 
    {
        for (k = 0; k < number_of_columns; k += 1) 
        {
            value += 1;
            rectangular_array[i][k] = value;
        }
    }
    return rectangular_array;
}

/* program entry point */
int main()
{
    // Declare four int type variables and set each of their initial values to 0.
    int N = 0, S = 0, i = 0, k = 0;

    /**
     * Declare an (int *)-type variable (i.e. pointer-to-int).
     * 
     * A will store the address of the first memory cell of N contiguous
     * int-sized memory blocks (and each one of the N int-sized memory 
     * blocks is comprised of 4 contiguous byte-sized memory cells).
     * 
     * Such an array is a dynamic variable because it is instantiated 
     * during program runtime rather than during program compile time.
     * 
     * Because the array pointed to by A is dynamically allocated, the computer 
     * does not know how much memory will be allocated to the array represented by 
     * the pointer named A until after the user eneters a value for N 
     * (and N is the number of elements in that array).
     * 
     * A will point to the first element of a one-dimensional array comrpised
     * of exactly N int-type elements.
     */
    int * A; // random integers array

    /**
     * Declare a pointer to a pointer-to-int type variable.
     * 
     * B will be used to represent a dynamically-allocated two-dimensional array 
     * whose length is some natural number named R and where each one of the R array 
     * elements is some one-dimensional array whose length is some natural number named C.
     * 
     * R represents the number of rows which are in the rectangular array pointed to by B.
     * 
     * C represents the number of columns which are in the rectangular array pointed to by B.
     * 
     * The total number of int-type elements which are in the array pointed to by B is
     * the product of R and C (i.e. the integer which is produced by multiplying R and C).
     */
    int ** B; // rectangular array

    // Declare a file output stream object.
    std::ofstream file;

    /**
     * If pointers_and_arrays_output.txt does not already exist in the same directory as pointers_and_arrays.cpp, 
     * then create a new file named pointers_and_arrays_output.txt.
     * 
     * Then open the plain-text file named factorial_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("pointers_and_arrays_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print the data size of various C++ data types to the command line terminal.
    std::cout << "\n\n// Print the data size of various C++ data types to the file output stream.";
    std::cout << "\nsizeof(bool) := " << sizeof(bool) << ". // number of contiguous byte-sized memory cells which a bool type variable occupies";
    std::cout << "\nsizeof(char) := " << sizeof(char) << ". // number of contiguous byte-sized memory cells which a char type variable occupies";
    std::cout << "\nsizeof(int) := " << sizeof(int) << ". // number of contiguous byte-sized memory cells which an int type variable occupies";
    std::cout << "\nsizeof(float) := " << sizeof(float) << ". // number of contiguous byte-sized memory cells which a float type variable occupies";
    std::cout << "\nsizeof(double) := " << sizeof(double) << ". // number of contiguous byte-sized memory cells which a double type variable occupies";
    std::cout << "\nsizeof(bool *) := " << sizeof(bool *) << ". // number of contiguous byte-sized memory cells which a pointer-to-bool type variable occupies ";
    std::cout << "\nsizeof(char *) := " << sizeof(char *) << ". // number of contiguous byte-sized memory cells which a pointer-to-char type variable occupies";
    std::cout << "\nsizeof(int *) := " << sizeof(int *) << ". // number of contiguous byte-sized memory cells which a pointer-to-int type variable occupies";
    std::cout << "\nsizeof(int **) := " << sizeof(int **) << ". // number of contiguous byte-sized memory cells which a pointer-to-pointer-to-int type variable occupies";
    std::cout << "\nsizeof(float *) := " << sizeof(float *) << ". // number of contiguous byte-sized memory cells which a pointer-to-float type variable occupies";
    std::cout << "\nsizeof(double *) := " << sizeof(double *) << ". // number of contiguous byte-sized memory cells which a pointer-to-double type variable occupies";
    std::cout << "\nsizeof(void *) := " << sizeof(void *) << ". // number of contiguous byte-sized memory cells which a void pointer (datatype independent pointer) occupies.";

    // Print the data size of various C++ data types to the file output stream.
    file << "\n\n// Print the data size of various C++ data types to the file output stream.";
    file << "\nsizeof(bool) := " << sizeof(bool) << ". // number of contiguous byte-sized memory cells which a bool type variable occupies";
    file << "\nsizeof(char) := " << sizeof(char) << ". // number of contiguous byte-sized memory cells which a char type variable occupies";
    file << "\nsizeof(int) := " << sizeof(int) << ". // number of contiguous byte-sized memory cells which an int type variable occupies";
    file << "\nsizeof(float) := " << sizeof(float) << ". // number of contiguous byte-sized memory cells which a float type variable occupies";
    file << "\nsizeof(double) := " << sizeof(double) << ". // number of contiguous byte-sized memory cells which a double type variable occupies";
    file << "\nsizeof(bool *) := " << sizeof(bool *) << ". // number of contiguous byte-sized memory cells which a pointer-to-bool type variable occupies ";
    file << "\nsizeof(char *) := " << sizeof(char *) << ". // number of contiguous byte-sized memory cells which a pointer-to-char type variable occupies";
    file << "\nsizeof(int *) := " << sizeof(int *) << ". // number of contiguous byte-sized memory cells which a pointer-to-int type variable occupies";
    file << "\nsizeof(int **) := " << sizeof(int **) << ". // number of contiguous byte-sized memory cells which a pointer-to-pointer-to-int type variable occupies";
    file << "\nsizeof(float *) := " << sizeof(float *) << ". // number of contiguous byte-sized memory cells which a pointer-to-float type variable occupies";
    file << "\nsizeof(double *) := " << sizeof(double *) << ". // number of contiguous byte-sized memory cells which a pointer-to-double type variable occupies";
    file << "\nsizeof(void *) := " << sizeof(void *) << ". // number of contiguous byte-sized memory cells which a void pointer (datatype independent pointer) occupies.";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Declare an int type variable which will be used to demonstrate how C++ pointers work.
    int test_int = 25;

    // Print the "int test_int = 25;" instruction to the command line terminal.
    std::cout << "\n\n// Declare an int type variable which will be used to demonstrate how C++ pointers work.";
    std::cout << "\nint test_int = 25;";

    // Print the "int test_int = 25;" instruction to the file output stream.
    file << "\n\n// Declare an int type variable which will be used to demonstrate how C++ pointers work.";
    file << "\nint test_int = 25;";

    // Declare a pointer which stores the address of the first cell of an int-sized block of memory.
    // (Note that intializing pointers to NULL prevents those variables from being set to "garbage" data).
    int * test_pointer_to_int = NULL;

    // Print the "int * test_pointer_to_int = NULL;" instruction to the command line terminal.
    std::cout << "\n\n// Declare a pointer which stores the address of the first cell of an int-sized block of memory.";
    std::cout << "\n// (Note that intializing pointers to NULL prevents those variables from being set to \"garbage\" data).";
    std::cout << "\nint * test_pointer_to_int = NULL;";

    // Print the "int * test_pointer_to_int = NULL;" instruction to the file output stream.
    file << "\n\n// Declare a pointer which stores the address of the first cell of an int-sized block of memory.";
    file << "\n// (Note that intializing pointers to NULL prevents those variables from being set to \"garbage\" data).";
    file << "\nint * test_pointer_to_int = NULL;";

    // Store the address of test_int in test_pointer_to_int using the reference (&) operator.
    test_pointer_to_int = &test_int;

    // Print the "test_pointer_to_int = &test_int;" insruction to the command line terminal.
    std::cout << "\n\n// Store the address of test_int in test_pointer_to_int using the reference (&) operator.";
    std::cout << "\ntest_pointer_to_int = &test_int;";

    // Print the "test_pointer_to_int = &test_int;" insruction to the file output stream.
    file << "\n\n// Store the address of test_int in test_pointer_to_int using the reference (&) operator.";
    file << "\ntest_pointer_to_int = &test_int;";

    // Print "test_pointer_to_int := {test_pointer_to_int}." to the command line terminal.
    std::cout << "\n\ntest_pointer_to_int := " << test_pointer_to_int << ". // memory address of test_int";

    // Print "test_pointer_to_int := {test_pointer_to_int}." to the file output stream.
    std::cout << "\n\ntest_pointer_to_int := " << test_pointer_to_int << ". // memory address of test_int";

    // Indirectly access the value stored in test_int using the dereference (*) operator and print the result to the command line terminal.
    std::cout << "\n\n// Indirectly access the value stored in test_int using the dereference (*) operator.";
    std::cout << "\n* test_pointer_to_int = " << * test_pointer_to_int << ".";

    // Indirectly access the value stored in test_int using the dereference (*) operator and print the result to the file output stream.
    file << "\n\n// Indirectly access the value stored in test_int using the dereference (*) operator.";
    file << "\n* test_pointer_to_int = " << * test_pointer_to_int << ".";

    // Increment the value stored in test_pointer_to_int by one int-sized memory increment.
    test_pointer_to_int += 1;

    // Print the "test_pointer_to_int += 1;" instruction to the command line terminal.
    std::cout << "\n\n// Increment the value stored in test_pointer_to_int by one int-sized memory increment.";
    std::cout << "\ntest_pointer_to_int += 1;";

    // Print the "test_pointer_to_int += 1;" instruction to the file output stream.
    file << "\n\n// Increment the value stored in test_pointer_to_int by one int-sized memory increment.";
    file << "\ntest_pointer_to_int += 1;";

    // Print "test_pointer_to_int := {test_pointer_to_int}." to the command line terminal.
    std::cout << "\n\ntest_pointer_to_int := " << test_pointer_to_int << ". // memory address of the cell which is 4 cells to the right of test_int";

    // Print "test_pointer_to_int := {test_pointer_to_int}." to the file output stream.
    file << "\n\ntest_pointer_to_int := " << test_pointer_to_int << ". // memory address of the cell which is 4 cells to the right of test_int";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Declare an char type variable which will be used to demonstrate how C++ pointers work.
    char test_char = 'K';

    // Print the "char test_char = 'K';" instruction to the command line terminal.
    std::cout << "\n\n// Declare an char type variable which will be used to demonstrate how C++ pointers work.";
    std::cout << "\nchar test_char = 'K';";

    // Print the "char test_char = 'K';" instruction to the file output stream.
    file << "\n\n// Declare an char type variable which will be used to demonstrate how C++ pointers work.";
    file << "\nchar test_char = 'K';";

    // Declare a pointer which stores the address of the first cell of an char-sized block of memory.
    // (Use malloc to assign memory to the pointer-to-char variable).
    char * test_pointer_to_char = (char *) malloc(1);

    // Print the "char * test_pointer_to_char = (char *) malloc(1);" instruction to the command line terminal.
    std::cout << "\n\n// Declare a pointer which stores the address of the first cell of an char-sized block of memory.";
    std::cout << "\n// (Use malloc to assign memory to the pointer-to-char variable).";
    std::cout << "\nchar * test_pointer_to_char = (char *) malloc(1);";

    // Print the "char * test_pointer_to_char = (char *) malloc(1);" instruction to the file output stream.
    file << "\n\n// Declare a pointer which stores the address of the first cell of an char-sized block of memory.";
    file << "\n// (Use malloc to assign memory to the pointer-to-char variable).";
    file << "\nchar * test_pointer_to_char = (char *) malloc(1);";

    // Declare a void pointer and initialize it to the value stored in test_pointer_to_char.
    // (Unlike test_pointer_to_char, void_test_pointer will display the memory address that pointer stores to the output stream).
    void * test_void_pointer = test_pointer_to_char;

    // Print the "void * test_void_pointer = test_pointer_to_char;" instruction to the command line terminal.
    std::cout << "\n\n// Declare a void pointer and initialize it to the value stored in test_pointer_to_char.";
    std::cout << "\n// (Unlike test_pointer_to_char, void_test_pointer will display the memory address that pointer stores to the output stream).";
    std::cout << "\nvoid * test_void_pointer = test_pointer_to_char;";

    // Print the "void * test_void_pointer = test_pointer_to_char;" instruction to the command line terminal.
    file << "\n\n// Declare a void pointer and initialize it to the value stored in test_pointer_to_char.";
    file << "\n// (Unlike test_pointer_to_char, void_test_pointer will display the memory address that pointer stores to the output stream).";
    file << "\nvoid * test_void_pointer = test_pointer_to_char;";

    // Store the address of test_char in test_pointer_to_char using the reference (&) operator.
    test_pointer_to_char = &test_char;
    test_void_pointer = test_pointer_to_char;

    // Print the "test_pointer_to_char = &test_char;" insruction to the command line terminal.
    std::cout << "\n\n// Store the address of test_char in test_pointer_to_char using the reference (&) operator.";
    std::cout << "\ntest_pointer_to_char = &test_char;";
    std::cout << "\ntest_void_pointer = test_pointer_to_char;";

    // Print the "test_pointer_to_char = &test_char;" insruction to the file output stream.
    file << "\n\n// Store the address of test_char in test_pointer_to_char using the reference (&) operator.";
    file << "\ntest_pointer_to_char = &test_char;";
    file << "\ntest_void_pointer = test_pointer_to_char;";

    // Print "test_void_pointer := {test_void_pointer}." to the command line terminal.
    std::cout << "\n\ntest_void_pointer := " << test_void_pointer << ". // memory address of test_char";

    // Print "test_void_pointer := {test_void_pointer}." to the file output stream.
    file << "\n\ntest_void_pointer := " << test_void_pointer << ". // memory address of test_char";

    // Indirectly access the value stored in test_char using the dereference (*) operator and print the result to the command line terminal.
    std::cout << "\n\n// Indirectly access the value stored in test_char using the dereference (*) operator.";
    std::cout << "\n* test_pointer_to_char = " << * test_pointer_to_char << ".";

    // Indirectly access the value stored in test_char using the dereference (*) operator and print the result to the file output stream.
    file << "\n\n// Indirectly access the value stored in test_char using the dereference (*) operator.";
    file << "\n* test_pointer_to_char = " << * test_pointer_to_char << ".";

    // Increment the value stored in test_pointer_to_int by one int-sized memory increment.
    test_pointer_to_char += 1;
    test_void_pointer = test_pointer_to_char;

    // Print the "test_pointer_to_char += 1;" instruction to the command line terminal.
    std::cout << "\n\n// Increment the value stored in test_pointer_to_char by one char-sized memory increment.";
    std::cout << "\ntest_pointer_to_char += 1;";
    std::cout << "\ntest_void_pointer = test_pointer_to_char;";

    // Print the "test_pointer_to_char += 1;" instruction to the file output stream.
    file << "\n\n// Increment the value stored in test_pointer_to_int by one char-sized memory increment.";
    file << "\ntest_pointer_to_char += 1;";
    file << "\ntest_void_pointer = test_pointer_to_char;";

    // Print "test_void_pointer := {test_void_pointer}." to the command line terminal.
    std::cout << "\n\ntest_void_pointer:= " << test_void_pointer << ". // memory address of the cell which is 1 cell to the right of test_char";

    // Print "test_void_pointer := {test_void_pointer}." to the file output stream.
    file << "\n\ntest_void_pointer := " << test_void_pointer << ". // memory address of the cell which is 1 cell to the right of test_char";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Generate a dynamic two-dimensional array which resembles a rectangle comprised of 4 rows and 10 columns.
    B = generate_two_dimensional_rectangular_array_of_integers(4, 10);

    // Print the "B = generate_two_dimensional_array_of_integers(4, 10);" instruction to the command line terminal.
    std::cout << "\n\n// Generate a dynamic two-dimensional array which resembles a rectangle comprised of 4 rows and 10 columns.";
    std::cout << "\nB = generate_two_dimensional_rectangular_array_of_integers(4, 10);";

    // Print the "B = generate_two_dimensional_array_of_integers(4, 10);" instruction to the file output stream.
    std::cout << "\n\n// Generate a dynamic two-dimensional array which resembles a rectangle comprised of 4 rows and 10 columns.";
    std::cout << "\nB = generate_two_dimensional_rectangular_array_of_integers(4, 10);";

    // Print the contents of the two-dimensional array pointed to by B as a one-dimensional list to the command line terminal and to the file output stream.
    std::cout << "\n\nTwo-Dimensional Rectangular Array named B:\n";
    file << "\n\nTwo-Dimensional Rectangular Array named B:\n";
    for (i = 0; i < 4; i += 1)
    {
        for (k = 0; k < 10; k += 1)
        {
            std::cout << "\nB[" << i << "][" << k << "] := " << B[i][k] << ". // at memory address " << &B[i][k];
            file << "\nB[" << i << "][" << k << "] := " << B[i][k] << ". // at memory address " << &B[i][k];
        }
    }

    // De-allocate the memory which was used to dynamically instantiate the two-dimensional array named B.
    for (i = 0; i < 4; i += 1) delete [] B[i];

    // Print the "for (i = 0; i < 4; i += 1) delete [] B[i];" instruction to the command line terminal.
    std::cout << "\n\n// De-allocate the memory which was used to dynamically instantiate the two-dimensional array named B.";
    std::cout << "\nfor (i = 0; i < 4; i += 1) delete [] B[i];";

    // Print the "for (i = 0; i < 4; i += 1) delete [] B[i];" instruction to the file output stream.
    file << "\n\n// De-allocate the memory which was used to dynamically instantiate the two-dimensional array named B.";
    file << "\nfor (i = 0; i < 4; i += 1) delete [] B[i];";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "Enter a natural number which is no larger than {MAXIMUM_N}: " to the command line terminal.
    std::cout << "\n\nEnter a natural number which is no larger than " << MAXIMUM_N << " to store in the int type variable named N: ";

    // Scan the command line terminal for the most recent keyboard input value.
    std::cin >> N;

    // Print "The value which was entered for N is {N}." to the command line terminal.
    std::cout << "\nThe value which was entered for N is " << N << ".";

    // Print "The value which was entered for N is {N}." to the file output stream.
    file << "\n\nThe value which was entered for N is " << N << ".";

    // If N is less than 1 or larger than MAXIMUM_N, then set N to 1.
    N = ((N < 1) || (N > MAXIMUM_N)) ? 1 : N;

    // Print "N := {N}." to the command line terminal.
    std::cout << "\n\nN := " << N << ".";

    // Print "N := {N}." to the file output stream.
    file << "\n\nN := " << N << ".";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "Enter a natural number which is no larger than {MAXIMUM_S}: " to the command line terminal.
    std::cout << "\n\nEnter a natural number which is no larger than " << MAXIMUM_S << " to store in the int type variable named S: ";

    // Scan the command line terminal for the most recent keyboard input value.
    std::cin >> S;

    // Print "The value which was entered for S is {S}." to the command line terminal.
    std::cout << "\nThe value which was entered for S is " << S << ".";

    // Print "The value which was entered for S is {S}." to the file output stream.
    file << "\n\nThe value which was entered for S is " << S << ".";

    // If S is less than 1 or larger than MAXIMUM_S, then set S to 1.
    S = ((S < 1) || (S > MAXIMUM_S)) ? 1 : S;

    // Print "S := {S}." to the command line terminal.
    std::cout << "\n\nS := " << S << ".";

    // Print "S := {S}." to the file output stream.
    file << "\n\nS := " << S << ".";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Allocate exactly N contiguous int-sized blocks of memory and store the address of the first memory cell of that array in the pointer variable named A.
    A = new int[N];

    std::cout << "\n\n// Allocate exactly N contiguous int-sized blocks of memory and store the address of the first memory cell of that array in the pointer variable named A.";
    std::cout << "\nA = new int[N];";

    file << "\n\n// Allocate exactly N contiguous int-sized blocks of memory and store the address of the first memory cell of that array in the pointer variable named A.";
    file << "\nA = new int[N];";

    // Assign the memory address of the first element of the array pointed to by A to the pointer named test_pointer_to_int.
    test_pointer_to_int = A;

    /**
     * Seed the pseudo random number generator with the integer number of seconds which have elapsed since the Unix Epoch (i.e. midnight of 01_JANUARY_1970).
     * Seed the pseudo random number generator exactly one time during this program instance.
     */
    srand(time(NULL));

    // Print the "srand(time(NULL));" instruction to the command line terminal.
    std::cout << "\n\n/**";
    std::cout << "\n * Seed the pseudo random number generator with the integer number of seconds which have elapsed since the Unix Epoch (i.e. midnight of 01_JANUARY_1970).";
    std::cout << "\n * Seed the pseudo random number generator exactly one time during this program instance.";
    std::cout << "\n */";
    std::cout << "\nsrand(time(NULL));";

    // Print the "srand(time(NULL));" instruction to the file output stream.
    file << "\n\n/**";
    file << "\n * Seed the pseudo random number generator with the integer number of seconds which have elapsed since the Unix Epoch (i.e. midnight of 01_JANUARY_1970).";
    file << "\n * Seed the pseudo random number generator exactly one time during this program instance.";
    file << "\n */";
    file << "\nsrand(time(NULL));";

    /**
     * For each element A[i] of the one-dimensional int array pointed to by A, 
     * generate a (relatively) random integer no smaller than 0 and no larger than (S - 1)
     * and store that integer in A[i].
     */
    for (i = 0; i < N; i += 1) A[i] = rand() % S;

    std::cout << "\n\n/**";
    std::cout << "\n * For each element A[i] of the one-dimensional int array pointed to by A,";
    std::cout << "\n * generate a (relatively) random integer no smaller than 0 and no larger than (S - 1)";
    std::cout << "\n * and store that integer in A[i].";
    std::cout << "\n */";
    std::cout << "\nfor (i = 0; i < N; i += 1) A[i] = rand() % S;";

    file << "\n\n/**";
    file << "\n * For each element A[i] of the one-dimensional int array pointed to by A,";
    file << "\n * generate a (relatively) random integer no smaller than 0 and no larger than (S - 1)";
    file << "\n * and store that integer in A[i].";
    file << "\n */";
    file << "\nfor (i = 0; i < N; i += 1) A[i] = rand() % S;\n";

    // Print the contents of the array of N integers pointed to by A.
    for (i = 0; i < N; i += 1) 
    {
        std::cout << "\nA[" << i << "] := " << A[i] << ". // memory address of A[" << i << "] is " << test_pointer_to_int << ".";
        file << "\nA[" << i << "] := " << A[i] << ". // memory address of A[" << i << "] is " << test_pointer_to_int << ".";

        // Increment the pointer-to-int variable by one int-sized increment in terms of contiguous byte-sized memory cells.
        test_pointer_to_int += 1;
    }

    // Sort the integer values stored in array A in ascending order.
    bubble_sort(A, N);

    std::cout << "\n\n// Sort the integer values stored in array A in ascending order.";
    std::cout << "\nbubble_sort(A, N);";

    file << "\n\n// Sort the integer values stored in array A in ascending order.";
    file << "\nbubble_sort(A, N);\n";

    // Print the contents of the array of N integers pointed to by A.
    for (i = 0; i < N; i += 1) 
    {
        std::cout << "\nA[" << i << "] := " << A[i] << ". // memory address of A[" << i << "] is " << test_pointer_to_int << ".";
        file << "\nA[" << i << "] := " << A[i] << ". // memory address of A[" << i << "] is " << test_pointer_to_int << ".";

        // Increment the pointer-to-int variable by one int-sized increment in terms of contiguous byte-sized memory cells.
        test_pointer_to_int += 1;
    }

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // De-allocate the memory which was allocated to the dynamic array whose first element memory address is stored in A.
    delete [] A;

    // Print the "delete [] A;" instruction to the command line terminal.
    std::cout << "\n\n// De-allocate the memory which was allocated to the dynamic array whose first element memory address is stored in A.";
    std::cout << "\ndelete [] A;";

    // Print the "delete [] A;" instruction to the file output stream.
    file << "\n\n// De-allocate the memory which was allocated to the dynamic array whose first element memory address is stored in A.";
    file << "\ndelete [] A;";

    // Print a closing message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nEnd Of Program";
    std::cout << "\n--------------------------------\n\n";

    // Print a closing message to the file output stream.
    file << "\n\n--------------------------------";
    file << "\nEnd Of Program";
    file << "\n--------------------------------";

    // Close the file output stream.
    file.close();

    // Exit the program.
    return 0;
}