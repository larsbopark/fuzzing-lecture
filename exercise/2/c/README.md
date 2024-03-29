# 2c
Much like previous we are already aware of how we compile
and run the application in order to run a fuzz test using AFL++.
When running the fuzz tests, we should see a rapidly increasing number of total crashes. 

---

### Understanding the Application
The application itself seems to encode a given string using ROT13.
This includes some string manipulation.
At first, look at the application, **does it seem unsafe or buggy?**

---

### Understanding the Results
This time when looking at the source code, the mistake might not be obvious. In fact, it seems like the proper bound-checks are made.

- **Take a closer look at the saved test case, can you reproduce the crash?**
  - Try to make 3 test cases yourself which crashes the application.
- **Can you identify the problem?**
  - Take a close look on the functions `strncpy` and `strlen`. How do you think they behave?
  - Go use your favorite search engine to find the flaws of these functions?
  - Describe what goes wrong in this particular case
- **Fix the Application!**
  - Can you fix the bug related to `strncpy` and `strlen`?
  - The forloop is weird and does not handle niche cases, can you fix that as well?