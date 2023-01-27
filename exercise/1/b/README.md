# 1b
In order to run and compile the application you can follow the tutorial in the parent directory. If you already did so, we should see a rising number of crashes running the fuzz test, we are ofcourse interested in analysing the crashes and determining the mistake that leads to them. **If you could not make the fuzz test start it is because there does not exist a input directory for this exercise**.

### Making the Initial Testcase
In order to start a fuzz test with AFL++, we need at least one initial testcase, which we have to supply. We make a testcase by "recording" the inputs from a **correct** run of the application. The more features there are used the better the fuzz test will be, this is due to the initial testcases being **the baseline** for the fuzz test. If not all features can be covered in one testcase, we can simply supply more. First let us make the input directory:
```shell
mkdir input_directory
```
Here is a example of how a testcase can be generated in the terminal, and I am sure that a curious student can not supply a better one:
```bash
echo -e "FUZZing is great" > input_directory/testcase0
```
Now we can test if the testcase works by running the following command:
```bash
cat input_directory/testcase0 | ./target
```

----------------------------------------------------------------

### The common property is what?
If doing the exercises chronologically, we know that the idea of looking at the testcases is important. Try to find the common property for the testcases.

<details>
  <summary>Hint</summary>
The application seems to suffer the same problem as exercise/1/a.
</details>

----------------------------------------------------------------

### Test your assumptions!
Try to generate a number of testcases which follows the assumptions your made when answering the question above. Running these testcases will help you understand if your assumptions are correct.

----------------------------------------------------------------

### Open the source, find and fix the problem!
When compiling the source code no warnings is thrown. This ofcourse indicate that the source code should be safe, but as we experienced that is not the case. Take a closer look at the source code and try to find and fix the vulnerability.

<details>
  <summary>Hint</summary>
The problem relies on the use of <code>scanf</code>, while <code>scanf</code> results in the insecure code here it can be used safely. If you are interested in learning the correct use of <code>scanf</code> use your favorite search engine.
</details>
