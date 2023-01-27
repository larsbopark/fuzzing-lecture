# Fuzzing with Instrumentation
In this exercise we will run a fuzz test using the instrumentation offered by AFL++. While this technique is sometime referred to as greybox, it is not the case since the source code is needed. AFL++ utilises a custom compiler in order to insert instrumentation in a given application. When compiling the source code with the custom compiler logging calls are inserted in the binary. These logging calls are used to guide the fuzzer in order to obtain a better coverage.

## Prerequisites
We make sure that the docker container is running. If it is not running we do so by running the script `build-docker.sh`.

## Compiling and Running the Application
AFL++ offers a wide variety of custom compilers, which are located in `/usr/local/bin/`. It can be hard to navigate which one is the best suited in our case. Therefore, we just use the default compiler `afl-cc`.
> One of the big difference between the custom compilers is how fast one execution can be done with instrumentation. The difference between compiling with `afl-gcc` and `afl-clang-fast` is noticeable. If it is of interest try to compile the same application with the two and compare the executions per second.

Compiling the application with instrumentation can be done by navigating to the exercise directory and then compiling the source code using the following command:
```shell
afl-cc -o target main.c
```
The compiled application is called `target` and can executed by running the following command:
```bash
./target
```
When running the application we can deduce it resembles a fuzztastic vending machine.

## Fuzzing with Instrumentation
AFL++ expects the application to be instrumented by default, since we already compiled the application with the custom compiler, we should be able to run AFL++ out of the box. We do so by entering the following command:
```bash
afl-fuzz -i input_directory -o output_directory -- /exercise/2/a/target
```
**We are met by an error message**, the input directory is empty. Due to AFL++ being a mutation-based fuzzer it need one or more initial testcases to run.
> Recalling the two major ways of generating testcases in fuzz testing:
> - Mutation-based -- Mutates and initial testcase by applying random mutation-operations
> - Generation-based -- Generating testcase from a set of rules
> 
> Both very effective, mutation-based being easier to use and generation-based being more precise.

### Making the Initial Testcase
In order to start a fuzz test with AFL++, we need at least one initial testcase, which we have to supply. We make a testcase by "recording" the inputs from a **correct** run of the application. The more features there are used the better the fuzz test will be, this is due to the initial testcases being **the baseline** for the fuzz test. If not all features can be covered in one testcase, we can simply supply more. Here is a example of how a testcase can be generated in the terminal, but I am sure that a curious student can supply a better one:
```bash
printf "1\n2\n8\n1\n2 1\n4" > input_directory/testcase0
```
Now we can test if the testcase works by running the following command:
```bash
cat input_directory/testcase0 | ./target
```

### Analysing the Results
With the newly supplied testcase(s), we are able to continue the fuzz test, and we are able to run it without further details because we already know that from an earlier exercise. 
> Fuzz testing can be compared to searching a infinite space for *errors*, since the space is infinite the search can take infinite time. Therefore, before running a fuzz test, one can advantageously plan a time limit for the fuzz test. A time limit may differ alot depending on the target application, and can easily range for minutes to days.

After running the fuzz test a feasible amount of time, we can stop it and look on the crashes. If we want to continue the fuzz test, but also want to look on the results, we can spawn a new terminal and connect to the container, navigate to the output directory and look at the findings.