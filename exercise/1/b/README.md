# 1b
In order to run and compile the application, you can follow the tutorial in the previous exercise.
If you already did so, we should see a rising number of crashes running the fuzz test.
We are course interested in analysing the crashes and determining the mistake that leads to them.
If you could not make the fuzz test start, **it is because there does not exist an input directory for this exercise**.

### Making the Initial Testcase
In order to start a fuzz test with AFL++, we need at least one initial test case, which we must supply.
We make a test case by "recording" the inputs from a **correct** run of the application.
The more features there are used the broader the fuzz test will be. 
This is due to the initial test cases being **the baseline** for the fuzz test.
If one is interested in fuzz testing a certain path,
one can advantageously make a test case that guides the fuzzer in that direction.
If not all features can be covered in one test case, we can simply supply more.
First, let us make the input directory:
```shell
mkdir input_directory
```
Here is an example of how a test case can be generated in the terminal,
and I am sure that a curious student is not able to supply a better one:
```bash
echo -e "FUZZing is great" > input_directory/test case0
```
Now we can test if the test case works by running the following command:
```bash
cat input_directory/test case0 | ./target
```
> Recalling the two major ways of generating test cases in fuzz testing:
> - Mutation-based -- Mutates and initial test case by applying random mutation-operations
> - Generation-based -- Generating test case from a set of rules
>
> Both very effective, mutation-based being easier to use and generation-based being more precise.

----------------------------------------------------------------

### Understanding the Results
If doing the exercises chronologically, we know that the idea of looking at the test cases is important. 
Try to find the common property for the test cases.

<details>
  <summary>Hint</summary>
The application seems to suffer the same problem as exercise/1/a.
</details>

----------------------------------------------------------------

### Test your assumptions!
Try to generate a number of test cases which follows the assumptions you made when answering the question above.
Running these test cases will help you understand if your assumptions are correct.

----------------------------------------------------------------

### Open the source, find and fix the problem!
When compiling the source code, no warnings are thrown.
Compared to the last exercise, no warnings are thrown when compiling the application,
but as we see, it still contains a vulnerability.
Take a closer look at the source code and try to find and fix the vulnerability.

<details>
  <summary>Hint</summary>
The problem relies on the use of <code>scanf</code>, while <code>scanf</code> results in the insecure code here it can be used safely. If you are interested in learning the correct use of <code>scanf</code> use your favorite search engine.
</details>
