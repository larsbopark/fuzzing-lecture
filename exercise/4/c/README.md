# 4b
If you are doing the exercises chronologically, and you have looked in the source code you will probably recognise it from exercise 1/d. If you have not done so i recommend you to do exercise 1/d before continuing with this exercise. Before you are able to start fuzz testing you need to generate a testcase, you should use the one from 1/d to proper compare the two tests. 

---

### Understanding the Results
We already fixed the application, when doing the blackbox exercise. We are well aware of the problem causing the crash. That said, we found other bugs which did not result in a crash. 
- Insert **assert**-statements in the source, which check for some of the bugs you found earlier

Running the fuzz test again you can investigate how effective the fuzz test is breaking the assertions.  
- Try to fix the bugs
- Rerun the fuzz test - did you fix them correctly?
If you did not fix the correctly, use the testcases which lead to the error. The testcase should help you understand the mistakes.