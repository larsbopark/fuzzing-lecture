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