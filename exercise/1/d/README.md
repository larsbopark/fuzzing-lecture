# 1d
This is the last exercise using blackbox fuzz testing in this repository. Following the same procedure as previous you should be able to compile and run a blackbox fuzz test using AFL++. If you don't feel to confident reading C code, I recommend skipping this and coming back later. 

---------------------------------------------------------------

### Understanding the Application
Try to run the application and use the different features. This small program represent a vending machine. Imagine you got the task to fuzz test this application, but instead of a mutation-based fuzzer, as AFL++, you have to use a generation-based fuzzer. Before you can start fuzz testing you have to declare a set of rules for the input in order to generate properly. **Try to describe some rules for the input?** (You can advantageously use notations such as regular expressions or notations alike)

----------------------------------------------------------------

### Understanding the Results
We described a possible set of rules, but for now we do not need to use them, since we are still using AFL++ which are an mutation-based fuzzer. That said, we are able to run the fuzz test using a or multiple initial testcases. Depending on you initial testcase you will experience a big change in the time needed in order to find the first testcase resulting in a crash, if you even find it. If you can not find it try to make another initial testcase.

- **A number of hangs are found why do you think that is the case?**
- **When looking on the crashes it can be deduced that a particular functionality is resulting in the crashes, which?**
- **Try make 3 testcase yourself which provoke the crash**

----------------------------------------------------------------

### Looking Into The Source
We can try open the source code, which is slightly more complicated than the examples earlier. That said, it only offers a couple of functionalities.

- **Find and fix the bugs that result in the crash!**
- **The programmer have been rather sloppy in general - can you identify some mistakes there might be unintentional but not found by the fuzz test?**