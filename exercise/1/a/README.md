# First Fuzz Test
Here are the instructions of how to run a blackbox fuzz test using AFL++.
Each exercise will require compiling the application and then running AFL++ in the following matter.
A TLDR is supplied for the experienced students, but I highly recommend reading through this README anyway.
We base this tutorial on the first exercise located in `/exercise/1/a`.

> **TLDR**: Compile application and run AFL++
>```bash
>clang -o target main.c
>afl-fuzz -n -i input_directory -o output_directory -- /path/to/application
>```

## Prerequisites
We make sure that the docker container is running if not the container can be launched
by running the script `build-docker.sh`.

## Compiling and Running the Application
The source code is provided, but in order to do a correct blackbox fuzz test, we must **avoid** viewing the content.
> Navigating in a terminal can be difficult without former experience here is some helpful commands:
> - `pwd` - print working directory
> - `cd` - change directory
> - `ls` - list files and directories
> - `cat` - concatenate files, often used to view the contents of a file
>
> Otherwise, help is found using our favorite search engine.

Navigate to the relevant exercise directory, which is done by running the following command in the container terminal:
```bash
cd /exercise/1/a
```
The contents are a source file, a directory containing a test case and this README. The C source file can be compiled running `Clang` with the following command:
```bash
clang -o target main.c
```

The compiled application is called `target` and can be executed by running the following command:
```bash
./target
```

## Blackbox Fuzzing with AFL++
AFL++ supports a wide range of features.
One of these features is a simple blackbox fuzz test.
First, we want to run AFL++ and we can do so by simple typing following command in the container terminal:
```bash
afl-fuzz
```
We are then presented by the help message of AFL++, which gives helpful information about the features and options.
Since, we are interested in a simple fuzz test,
we take a close look on `Required parameters` as well as th option `-n` under `Fuzzing behavior settings`.
The first required parameter is the input directory, which is in this exercise is already supplied, `./input_directory`.
If we take a look of the contents we see a single test case named `test_case0`, this is our initial test case.
The second required parameter is the output directory, where the result of the fuzz testing is saved.

>We are able to launch AFL++ directly without specifying a path because it is already installed in the container. If you want to install it directly on your own machine, I will refer you to the [AFL++ github repository](https://github.com/AFLplusplus/AFLplusplus).

We can run AFL++ with the required parameters and the path to the application. We do so by running the following command:
```bash
afl-fuzz -i input_directory/ -o output_directory -- /exercise/1/a/target
```
**When running the command, we are met by an error!** This is due to the fact that AFL++ by default uses instrumentation of the target, which is not applicable in a blackbox fuzz testing context. Inorder to instrument a binary we need to have access to the source code, which is not available in blackbox fuzz testing.

> Recalling the *boxes*:
> - Blackbox -- only input and output are available
> - Whitebox -- source code, specification and documentation are available
> - Greybox -- something in between (widely discussed in the fuzz testing community)

As we discovered when running AFL++ an error was thrown, and we were not able to start the fuzz testing. We solve this by adding the `-n` option, which enable fuzz testing without instrumentation -- blackbox. We start the fuzz test without instrumentation by running the following command:

```bash
afl-fuzz -n -i input_directory -o output_directory -- /exercise/1/a/target
```

We are then met by the status screen which displays much interesting information,
which includes run time, number of found crashes, number execution per second and much more.
The number of total crashes is rapidly increasing, whereof each is a test case which makes the target application crash.
In order to stop the fuzz test simply enter `Ctrl-c` in the terminal.

> If `Ctrl-c` does not work, you can kill the process instead. This is done by opening a **new** terminal window and attaching it to the container and killing the process by entering the following commands:
>```bash
>docker exec -it aflplusplus-exercise /bin/bash
>pkill -9 afl-fuzz
>```
> The cursor might dissappear as a result of this and it can be retrieved by executing `reset` in the terminal.

Thus, we ran a simple blackbox fuzz test on a small application. 

## Analysing the Results
The most important step in fuzz testing, is analysing and reason about the results,
both if we are sitting on the defensive(blue) or offensive(red) side.
The results of our fuzz test are found in the output directory, `output_directory`.
When navigating to the output directory and listing the contents,
we can observe a number of different files and folders.
While they all are interesting, we take a close look on the `crashes` directory.
If the fuzz test found any test cases which caused a crash, it is to be found here.
Every test case is named after its properties, but for now, let's ignore that.
Instead, let us investigate the test cases.
> The test cases might not be human-readable, and therefore it can be a help to sometimes take a look at the raw bytes instead. This can be done using the command line tool `xxd`, which creates a hex dump of a given file.

We can try to run one of the test cases,
by navigating to the crashes directory using `cd` located in the output directory,
with the application by running the following command:
```bash
cat id:000000,* | /exercise/1/a/target
```
> The source code can be edited in the container used the command line editor Vim. In order to modify the code, simply run the following command:
> ```bash
> vim main.c
> ```
> For first time Vim users it can be a bit hard to use. Here are some helpful commands:
> - `i` - enter insert mode
> - `esc` - exit insert mode
> - `:q` - quit
> - `:w` - write
> - `:wq` - write and quit
>
> Vim is a powerful tool and for more details use your favorite search engine


## Moving On
Now we learned how to compile a small C application and running AFL++ without instrumentation, blackbox fuzz testing. 

# 1a
This is the first exercise,
and if you followed the tutorial, then you already compiled and fuzz tested the binary.
If everything went as expected, we see a rising number of crashes when running the fuzz test,
and we are able to determine that the application is crash-able.
But the journey does not end here, the most important step of fuzz testing is to reason about the results.
There are plenty of ways to do so, but first take a look at the test cases.

----------------------------------------------------------------

### The test cases share a property, which might not be obvious. Are you able to identify which?
The main result of the fuzz test is the test cases which provoke crashes.
There are a lot of ways to investigate the crash using the test cases,
but we might be able to find something in common between the test cases.
The common property can tell us something about how we can reproduce the crash, 
and we can reason about how to prevent it as well. 

<details>
  <summary>Hint</summary>
The contents of each test case seems quite random, but something interesting can be identified from the length
</details>

----------------------------------------------------------------
### Try to write down 3 test cases which crash the application?
In order to confirm your assumptions,
you can easily check if it holds by running the application with some test cases which yourself has generated.
Try to write down 3 test cases which crash the application and is not generated by AFL++. 

----------------------------------------------------------------
### What kind of programmer mistake often results in errors related to this?
Writing secure C is difficult, even by experienced C developers,
and it is no secret that there exists a vocabulary of common mistakes.
One of these common mistakes is also resulting in the crash we observe in the application.
Can you deduce which?
(Using your favorite search engine can be a help in order to look up what the common mistakes are)

<details>
  <summary>Hint</summary>
Remember the application is written in C. One of the most common mistake in C programming is missing bound-checks.
</details>

----------------------------------------------------------------
### Now open the source code! Where is the problem happening and how do we fix it?
Even if we pretended the fuzz test was blackbox, we had the opportunity to read the source code.
We will, of course, exploit that to check that our assumptions are correct.
Furthermore, we are able to fix the application and make it safe for unexpected crashes.
Are you able identify the mistake and fix it?

> The source code can be edited in the container used the command line editor Vim. In order to modify the code, simply run the following command:
> ```bash
> vim main.b
> ```
> For first time Vim users it can be a bit hard to use. Here are some helpful commands:
> - `i` - enter insert mode
> - `esc` - exit insert mode
> - `:q` - quit
> - `:w` - write
> - `:wq` - write and quit
> 
> Vim is a powerful tool and for more details use your favorite search engine

<details>
  <summary>Hint</summary>
When we compiled the application, we were met with a warning:
<b>the `gets' function is dangerous and should not be used.</b>. When reading the source code, it is then easy to recognize where the `gets` function is called. A fix is replacing the dangerous `gets` with the bounded `fgets` function. 
</details>

----------------------------------------------------------------

## Moving On
If we fixed the application correctly,
we can recompile the source code with the fixes and fuzz test the newly compiled application.
Hopefully we do not see any crashes, the application is safe, and we can move on to the next exciting exercise.