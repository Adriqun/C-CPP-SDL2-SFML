// author: Adrian Michałek
// email: devmichalek@gmail.com

0.0 // Assume you have test.c with function func() and main.c which uses function func() from the static library libtest.a. Give the proper order of compilation, creation of executable binary and static library on linux. Write commands for the required needs.

0.1 // Do the same thing as in the previous task but now for the dynamic library.

0.2 // Assume you have the following files:
// part.c:
int add2(int a, int b) {
  return a + b;
}

int add3(int a, int b, int c) {
  return a + b + c;
}

//  test.c
int func(int x) {
  int add2(int, int);
  return x + add2(1, 2);
}

// main.c
#include <stdio.h>

int main()
{
  int func(int);
  int add3(int, int, int);
  int ret = func(3) + add3(1, 2, 3);
  printf("ret=%d\n", ret);
  return ret;
}
//  How would you create an exectutable main which uses dynamic library libtest.so which includes static library libpart.a? Note that shared library does not know that function add2() will be used by the library users.

0.3 // [Controlling Dynamic Library Symbols’ Visibility] From the high-level perspective, the mechanism of exporting/hiding the linker symbols is solved almost identically in both Windows and Linux. What is the substantial difference between them?

0.4 // [The Symbol Control Export at Build Time] The GCC compiler provides several mechanisms of setting up the visibility of linker symbols. Assume you have an internal and external function, both of them are external because that's how linux solves the linker symbols for dynamic library. How would you hide internal function of dynamic library?

0.5 // Could you specify some Linux/Windows functions for Dynamically Loading DLL?
	// For example, function to load dynamic library from code or finding symbols in DLL directly from code.

0.6 // How to distinguish the import library file (.lib) from static library (also .lib) quickly and quite accurate without looking at its contents?

0.7 // On the Linux we have the priority scheme for where the system search for Dynamic Libraries while running executable. How the priority scheme look like? Write entities from the highest priority to the lowest priority.

0.8 // On the Windows we have the priority scheme for where the system search for Dynamic Libraries while running exec. What tare Windows Runtime Dynamic Library location rules? Write these entities.

0.9 // How would you fix this problem (dynamic library libsh.so is in the same directory where commands are executed):
	adrian@adrian:~/Documents/Test$ gcc main.o -ldl -lsh -o main
	/usr/bin/ld: cannot find -lsh
	collect2: error: ld returned 1 exit status

1.0 // [Linux] What is ELF and what distibution do we use to read them?

1.1 // [Linux] What is the difference between RPATH (DT_RPATH) and RUNPATH (DT_RUNPATH)?

1.2 // What are the main differences between __cdecl and __stdcall?

1.3 // What is API (Application Programming Interface)?

1.4 // What is ABI (Application Binary Interface)?

1.5 // What is the difference between Linker and Loader (and section vs segment, explain briefly)?

1.6 // How many sections and segments has the object main?
	$ readelf -h main
	  ELF Header:
	  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00
	  Class:                             ELF64
	  Data:                              2s complement, little endian
	  Version:                           1 (current)
	  OS/ABI:                            UNIX - System V
	  ABI Version:                       0
	  Type:                              EXEC (Executable file)
	  Machine:                           Advanced Micro Devices X86-64
	  Version:                           0x1
	  Entry point address:               0x4005e0
	  Start of program headers:          64 (bytes into file)
	  Start of section headers:          4584 (bytes into file)
	  Flags:                             0x0
	  Size of this header:               64 (bytes)
	  Size of program headers:           56 (bytes)
	  Number of program headers:         9
	  Size of section headers:           64 (bytes)
	  Number of section headers:         30
	  Section header string table index: 27

1.7 // What is the difference between LTR (Load Time Relocation) and PIC (Platform Independent Code)?

1.8 // Let's say you have the following functions in following files:
    // first.h -> its source will be compiled with -fPIC and evaluated as dynamic library
    // int first_function(int x);
    // int duplicate_function(int x);

    // second.h -> its source will be compiled with -fPIC and evaluated as dynamic library
    // int second_function(int x);
    // int duplicate_function(int x);

    // main.c calls the following functions:
    // first_function(1);
    // second_function(2);
    // duplicate_function(3);
    // Obviously while creating executable main and linking to the main static libraries libfirst.a and libsecond.a will cause a duplicate symbol error. What happens if sources libfirst and libsecond are dynamic libraries?

1.9 // According to the previous question, what is the output for ./main?
    // first.h
      #pragma once
      void common();
      void first();
    // first.cpp
      #include "first.h"
      #include <stdio.h>
      void common() { printf("1"); }
      void first()  { common();}
    // second.h
      #pragma once
      void common();
      void second();
    // second.cpp
      #include "second.h"
      #include <stdio.h>
      void common() { printf("2"); }
      void second() { common();}
    // main.cpp
      #include "first.h"
      #include "second.h

      int main()
      {
        common();
        first();
        second();
        return 0;
      }
    // Files are evaluated as:
    // gcc -c -fPIC first.cpp
    // gcc -c -fPIC second.cpp
    // gcc -shared -o libfirst.so first.o
    // gcc -shared -o libsecond.so second.o
    // gcc main.o -Wl,-L. -Wl,-R. -Wl,-lfirst -Wl,-lsecond -o main

2.0 // Now if we change main.cpp into:
      #include "first.h"
      #include "second.h
      #include <stdio.h>

      void common() { printf("3"); }

      int main()
      {
        common();
        first();
        second();
        return 0;
      }
    // What is the output for ./main?

2.1 // While creating shared library we tend to give it a number, for libxyz.2.7.13 what does these numbers mean?

2.2 // What happens when linker finds two weakly declared functions with the same symbol name [C, Linux]?
    // Example: int __attribute__((weak)) someFunction(int, float);

2.3 // What does the .plt section contain (Procedure Linkage Table)?
