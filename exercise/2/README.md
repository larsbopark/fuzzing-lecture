# Fuzzing with Instrumentation
In this exercise we will run a fuzz test using the instrumentation offered by AFL++. While this technique is sometime referred to as greybox, we will refrain from that since that is not quite the case for AFL++. AFL++ utilises a custom compiler in order to insert instrumentation in a given application, the instrumentation is then helping to guide the fuzzer in order to obtain a better coverage.

## Prerequisites
We make sure that the docker container is running. If it is not running we do so by running the script `build-docker.sh`. For a more detailed description of how to launch the script read the `README.md` in the root of the exercise directory.

## Compiling and Running the Application
AFL++ offers a wide variety of custom compilers, which are located in `/usr/local/bin/`. It can be hard to navigate in which one that is the best in our case, we are using `afl-cc` which automatically chooses one.
> One of the big difference between the custom compilers is how fast one execution can be done with instrumentation. The difference between compiling with `afl-gcc` and `afl-clang-fast` is noticeable. If it is of interest try to compile the same application with the two and compare the executions per second.

Compiling the application with instrumentation can be done by navigating to the exercise directory and then compiling using the following command:
```shell
afl-cc -o exercise2 main.c
```
The compiled application is called `exercise2` and can executed by running the following command:
```bash
./exercise2
```
When running the application we can deduce it resembles a vending machine.

## Fuzzing with Instrumentation
AFL++ expects the application to be instrumented by default, since we already compiled the application with the custom compiler, we should be able to run AFL++ out of the box. We do so by entering the following command:
```bash
afl-fuzz -i input_directory -o output_directory -- /exercise/2/exercise2
```
We are met by an error message, the input directory is empty. Due to AFL++ being a mutation-based fuzzer it need one or more initial testcases to run.
> Recalling the two major ways of generating testcases in fuzz testing:
> - Mutation-based -- Mutates and initial testcase by applying random mutation-operations
> - Generation-based -- Generating testcase from a set of rules
> 
> Both very effective, mutation-based being easier to use and generation-based being more precise.

### Making the Initial Testcase
In order to start a fuzz test with AFL++, we need at least one initial testcase, which we have to supply. We make a testcase by "recording" the inputs from an **correct** run of the application. The more features there are used the better the fuzz test will be, since it is **the baseline** for the fuzz test. If not all features can be covered in one testcase, we can simply supply more. Here is a example of how a testcase can be generated in the terminal, but I am sure that a curious student can supply a better one:
```bash
printf "1\n2\n8\n1\n2 1\n4" > input_directory/testcase0
```
Now we can test if the testcase works by running the following command:
```bash
cat input_directory/testcase0 | ./exercise2
```

### Analysing the Results
With the newly supplied testcase(s), we are able to continue the fuzz test, and we are able to run it without further details because we already got taught that earlier. 
> Fuzz testing can be compared to searching a infinite space for *errors*, since the space is infinite the search can take infinite time. Therefore, before running a fuzz test, one can advantageously plan a time limit for the fuzz test. A time limit may differ alot depending on the target application, and can easily range for minutes to days.

After running the fuzz test a feasible amount of time, we can stop it and look on the crashes. If we want to continue the fuzz test, but also want to look on the results, we can spawn a new terminal and connect to the container. 

#### Can you locate why the error is caused?

#### Can you fix the error? 

#### The programmer have been rather sloppy in general - can you identify some mistakes there might be unintentional but not found by the fuzz test?