# Fuzzing with Instrumentation
In these exercises, we will run a fuzz test using the instrumentation feature offered by AFL++.
AFL++ utilises a custom compiler in order to insert instrumentation in a given application.
When compiling the source code with the custom compiler logging calls are inserted into the binary.
These logging calls are used to guide the fuzzer in order to obtain better coverage.

## Prerequisites
We make sure that the docker container is running.
If it is not running, we do so by running the script `build-docker.sh`.

## Compiling and Running the Application
AFL++ offers a wide variety of custom compilers, which are located in `/usr/local/bin/`.
It can be hard to navigate which one is the best suited in our case.
Therefore, we just use the default compiler `afl-cc`.
> One of the big differences between the custom compilers is how fast one execution can be done with instrumentation. The difference between compiling with `afl-gcc` and `afl-clang-fast` is noticeable. If it is of interest, try to compile the same application with the two and compare the executions per second.

Compiling the application with instrumentation can be done by navigating into the exercise directory,
and then compiling the source code using the following command:
```shell
afl-cc -o target main.c
```
The compiled application is called `target` and can be executed by running the following command:
```bash
./target
```

## Fuzzing with Instrumentation
AFL++ expects the application to be instrumented by default,
since we have already compiled the application with the custom compiler, we should be able to run AFL++ out of the box.
We do so by entering the following command:
```bash
afl-fuzz -i input_directory -o output_directory -- /exercise/2/a/target
```
## Moving On
Instrumenting and running the fuzz test is very similar to running a blackbox fuzz test,
but as we will see in the following exercises, it results in a much more powerful fuzz test.

# 2a
This is the first exercise running an instrumented fuzz test,
since we have already ran a blackbox fuzz test, running an instrumented fuzz test using AFL++ is trivial.
You can do so following the tutorial in the parent directory.
When running this kind of fuzz test, we have the source code available, and we can use that as we like.

----------------------------------------------------------------
### Understanding the Application
The application seems familiar and is rather simple. 
Describe the application (a single sentence should suffice).

------------------------------------------------

### Why is the number of saved crashes not the actual number of crashes?
When running the fuzz test, we are able to see how many crashes are found,
but as we are also able to observe the number of test cases saved, which is significantly lower.
Why do you think that is?
<details>
  <summary>Hint</summary>
AFL++ is aware of which inputs leads to which crashes and able to distinguish crashes,
if a crash found it simply ignore other inputs
leading to the same crash.
When the source code is available we are able to do dynamic analysis, such as a debugging.
Debugging one failed run is often enough to find and fix the fail.
</details>

----------------------------------------------------------------

### Understanding the Results
It seems only one input is saved, but a rising number of crashes is found. 
When looking at the test case and the source code, we can reason about why the crash happened. 

- **Looking at the source code, can you determine the cause of the crash?**
- **It looks like the developer was trying to protect the application by allocating a shield. What common error did he fail to protect against?**
- **What length does a test case need to have to trigger the crash?**
- **Make a test case that executes the if branch specified on line 21**
- **Fix the application!**

