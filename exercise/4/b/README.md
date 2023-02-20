# Overflow and Undefined Behavior
In this exercise, we will discover one of the pitfalls of undefined behavior.
This exercise is inspired by this [blog post](http://blog.pkh.me/p/37-gcc-undefined-behaviors-are-getting-wild.html),
and if you want to experience it first hand,
I recommend you to read the blog post later and instead take a dive in the exercise.

## Compiling and Running the Application
We are going to let the compiler optimize our application. 
We do so by giving the optimisation flag to the compiler.
You can compile the optimised application with the following command:
```bash
afl-cc -O2 main.c -o target 
```
Remember to use this flag when recompiling!

## Understanding the Results
When running the fuzz test, we should observe a number of crashes. 
Take a closer look at the resulting testcases.
It might not be obvious what the problem is when only looking at the testcases.
Instead, take a look at the source code.
- **Can you determine the problem in the code?**
- **Can you fix the problem in the code?**
- **Compare your fixes to the fixes in `checked_main.c`, how does they compare?**
- **Now compile and run the fuzz tests, observe that it still finds crashes wierd?**

If you want to know why the application still crashes,
you can read the [blog post](http://blog.pkh.me/p/37-gcc-undefined-behaviors-are-getting-wild.html).
The compiler removes a check in order to optimise the application.
Unfortunately, the check protects against overflow.
**Try to compile source code without optimisation and fuzz test it!**
Now observe how AFL++ will not find any crashes.






