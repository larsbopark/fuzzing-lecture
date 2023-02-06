# Optimising the Fuzz Test
When having the source code available we are able to modify and change the source as we wish. This can prove to be a great tool in order to obtain greater performance when running fuzz tests. Furthermore, we can insert `assert`-call to fuzz for logic related bugs which makes fuzz testing a much greater tool. 

| WARNING: when changing the source code we might introduce bugs or change the behaviour of the application -- when changing source code be absolutely sure how it affects the application
|------------|

## Removing I/O and Exposing Functions
If we want more performance an easy fix is to remove I/O operations such as `prinf`, `puts` and `sleep` etc. Furthermore, can multiple `scanf` or `fgets` be concatenated in a single statement, since the fuzzer will not percieve it any different. When doing this can of changing we have to be extra careful, since we can remove potentially bugs, such as buffer overflows and printf-vulnerabilities. So you have to be extremely careful. 

Another strong tool is to expose the target function. You can do so by making a new `main.c`, which includes the target function. When doing so, it is extremely important that you remember to set up the context needed in order to fuzz test the target function correct. 

## Inserting Assertions
If we want to fuzz test logic bugs or errors we can use `assert`. 