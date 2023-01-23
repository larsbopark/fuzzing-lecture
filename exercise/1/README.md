# First Fuzz Test
In this exercise we will run a simple blackbox fuzz test using AFL++. We do so to understand how a simple fuzz test is run and reason about the results of a fuzz test. 

## Prerequisites
We make sure that the docker container is running. If not the container can be launched by running the script `build-docker.sh`. 

## Compiling and Running the Application
In this exercise the source code is provided, but in order to do a correct blackbox fuzz test, we **avoid** to view the contents for now. 
> Navigating in a terminal can be difficult without former experience here is some helpful commands:
> - `pwd` - print working directory
> - `cd` - change directory
> - `ls` - list files and directories
> - `cat` - concatenate files, often just used to viewing the contents of one
>
> Otherwise, help is often found using our favorite search engine.

Navigate to the exercise directory, which is done by running the following command in the container terminal:
```bash
cd /exercise/1
```
The contents are a source file, a directory containing a test case and this README. The C source file can be compiled running `Clang` with the following command:
```bash
clang -o exercise1 main.c
```

The compiled application is called `exercise1` and can executed by running the following command:
```bash
./exercise1
```
The application is very simple and an observant student will deduce, that the application takes a string and prints it to the terminal.

## Blackbox Fuzzing with AFL++
AFL++ supports a wide range of features, one of these features is a simple blackbox fuzz test. First, we want to run AFL++ and we can do so by simple typing following command in container terminal:
```bash
afl-fuzz
```
We are then presented by the help message of AFL++, which gives helpful information about the features and options. Since, we are interested in a simple fuzz test, we take a close look on `Required parameters` as well as th option `-n` under `Fuzzing behavior settings`. The first required parameter is the input directory, which in this exercise is already supplied, `./input_directory`. If we take a look of the contents we see a single testcase named `test_case0`, this is our initial testcase. The second required parameter is the output directory, where the result of the fuzz testing is saved. 

>We are able to launch AFL++ directly without specifying path because it is already installed in the container. If you want to install it directly on your own machine I will refer you to the [AFL++ github repository](https://github.com/AFLplusplus/AFLplusplus). 

We can run AFL++ with the required parameters and the path to the application. We do so by running the following command:
```bash
afl-fuzz -i input_directory/ -o output_directory -- /exercise/1/exercise1
```
**When running the command we are met by an error!** This is due to the fact that AFL++ be default uses instrumentation of the target, which is not applicable in a blackbox fuzz testing context. Inorder to instrument a binary we need to have access to the source code, which is not available in blackbox fuzz testing.
> Recalling the *boxes*:
> - Blackbox -- only input and output are available 
> - Whitebox -- source code, specification and documentation are available
> - Greybox -- something in between (widely discussed in the fuzz testing community)

As we discovered when running AFL++ an error was thrown, and we were not able to start the fuzz testing. We solve this by adding the `-n` option, which enable fuzz testing without instrumentation -- blackbox. We start the fuzz test without instrumentation by running the following command:
```bash
afl-fuzz -n -i input_directory/ -o output_directory -- /exercise/1/exercise1
```
We are then met by the status screen which display a number of interesting information, which includes run time, number of found crashes, number execution per second and much more. The number of total crashes is rapidly increasing, whereof each is a testcase which makes the target application crash. In order to stop the fuzz test simply enter `Ctrl-c` in the terminal.
> If `Ctrl-c` does not work, you can kill the process instead. This is done by opening a **new** terminal window and attaching it to the container and killing the process by entering the following commands:
>```bash
>docker exec -it aflplusplus-exercise /bin/bash
>pkill -9 afl-fuzz
>```
Thus, we ran a simple blackbox fuzz test on a small application.

## Analysing the Results
The most important step in fuzz testing, is analysing and reason about the results, both if we are sitting on the defensive(blue) or offensive(red) side. The results of our fuzz test is found in the output directory, `output_directory`. When navigating to the output directory and listing the contents, we can observe a number of different files and folders. While they all are interesting, we take a close look on the `crashes` directory. If the fuzz test found any testcases which caused a crash it is to be found here. Every testcase is named after its properties, but for now lets ignore that. Instead, let us investigate the testcases.
> The testcases might not be human-readable, and therefore it can be a help to sometimes take a look on the raw bytes instead. This can be done using the command line tool `xxd`, which creates a hex dump of a given file. 

We can try to run one of the testcases with the application by running the following command:
```bash
cat id:000000,* | /exercise/1/exercise1
```
Trying to answer the following question will help us identify the problem in this target application:

### The testcases share a property, which might not be obvious. Are you able to identify which?
<details>
  <summary>Hint</summary>
The contents of each testcase seems quite random, but something interesting can be identified from the length
</details>

### What kind of programmer mistake often results in errors related this?

<details>
  <summary>Hint</summary>
Remember the application is written in C. One of the most common mistake in C programming is missing bound-checks.
</details>

### Now open the source code! Where is the problem happening and how do we fix it?

> The source code can be edited in the container used the command line editor Vim. In order to modify the code simply run the following command:
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

<details>
  <summary>Hint</summary>
When we compiled the application, we were met with a warning:
<b>the `gets' function is dangerous and should not be used.</b>. When reading the source code it is then easy to recognize where the `gets` function is called. A fix is replacing the dangerous `gets` with the bounded `fgets` function. 
</details>

## Moving On
If we fixed the application correctly, we can recompile the source code with the fixes and fuzz test the newly compiled application. Hopefully we do not see any crashes, the application is safe and we can move on to the next exciting exercise.