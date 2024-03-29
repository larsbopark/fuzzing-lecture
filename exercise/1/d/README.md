# 1d
This is the last exercise using blackbox fuzz testing.
Following the same procedure as previous, you should be able to compile and run a blackbox fuzz test using AFL++.
If you don't feel to confident reading C code, I recommend skipping this and coming back later. 

---------------------------------------------------------------

### Understanding the Application
Try to run the application and use the different features.
This small program represents a vending machine.
Imagine you got the task to fuzz test this application,
but instead of a mutation-based fuzzer, as AFL++, you have to use a generation-based fuzzer.
Before you can start fuzz testing, you have
to declare a set of rules for the input in order to generate properly test cases.
Try to describe some rules for the input?
(You can advantageously use notation such as regular expressions or notation alike)

----------------------------------------------------------------

### Understanding the Results
We described a possible set of rules, but for now we do not need to use them,
since we are still using AFL++ which are a mutation-based fuzzer.
That said, we are able to run the fuzz test using an or multiple initial test cases.
Depending on your initial test case you will experience a big change in the time
needed in order to find the first test case resulting in a crash,
if you even find it.
If you can not find it try to make multiple initial test case.

- **A number of hangs are found why you think that is the case?**
- **When looking at the crashes, it can be deduced that a particular functionality is resulting in the crashes, which?**
- **Try make 3 test case yourself which provokes the crash**

----------------------------------------------------------------

### Looking Into The Source
We can try to open the source code, which is slightly more complicated than the examples earlier.
That said, it only offers a couple of functionalities.
Using the set of rules we made earlier, we can easier analyse the results
and point out where the crash happens more accurately.

- **Find and fix the bugs that result in the crash!**
- **The programmer has been rather sloppy in general, can you identify some mistakes there might be unintentional but not found by the fuzz test?**