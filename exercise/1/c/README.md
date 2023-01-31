# 1c
If we followed the exercises chronological, we already know how to compile and run a blackbox fuzz test using AFL++. In fact we are interested in more challenges in some of these exercises. Well, fear not, in this exercise we will take a look on a slightly more complex application. Before creating a initial testcase be sure to run the application and get a understanding of how it works.
> Some applications needs multiple inputs in order to run correctly. If you want to reproduce that in your testcase you can advantageously create `\n` newline characters in the following matter:
> ```shell
> echo -e "input1\ninput2\ninput3" > input_directory/testcase0
>```

--------------------------------
### Understanding the Application
Run the application a couple of times, I am sure a curious student will figure out the behaviour of the application, without looking at source. **Can you explain what the application does?**

--------------------------------

### Understanding the Results 
When looking at the results we will see a number of testcases resulting in a crash. When investigating the testcases it might not be obvious why the application crash, with the given input. Try to play with the idea of two inputs and if the crash happens because of the first, second or both, while looking at the testcases provoking crashes. 

- **Can you find the common property of the testcases or just reason why the application crashes given the inputs?**
- **If you find the right reason, it should be easy to generate your own testcases which crash the application. Write down 3 testcases which crashes the application.**

### Looking Into The Source
We can now open the source and see if the assumptions are correct. **Are you able to find and fix the bug?** 

> Running the fuzz test again after trying to fix the bug, is a fair check to see if the bug is fixed