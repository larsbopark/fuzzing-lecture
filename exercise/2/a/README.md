# 2a
This is the first exercise running a instrumented fuzz test, since we already ran blackbox test, running a instrumented fuzz test using AFL++ is trivial. You can do so following the tutorial in the parent directory. When running this kind of fuzz test we have the source code available, and we can use that however we like.

----------------------------------------------------------------
### Understanding the Application
The application seems familiar and is rather simple. Describe the application (a single sentence should suffice).

------------------------------------------------

### Why are the number of saved crashes not the actual number of crashes?
When running the fuzz test we are able to see how many crashes is found, but as we are also able to observe the number of testcases saved, which is significantly lower. Why do you think that is?
<details>
  <summary>Hint</summary>
When the source code is available we are able to do dynamic analysis, such as a debugging. Debugging one failed run is often enough to find and fix the fail.
</details>

----------------------------------------------------------------

### Understanding the Results
It seems only one input is saved, but a rising number of crashes is found. When looking at the testcase and the source code, we can reason about why the crash happened. 

- **Looking at the source code can you determine the cause of the crash?**
- **It looks like the developer was trying to protect the application by allocating a shield, what common error did he fail to protect against?**
- **What length does a testcase need to have to trigger the crash?**
- **Make a testcase that executes the if branch specified on line 21**
- **Fix the application!**

