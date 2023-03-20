# 4a
In this exercise, we want to alter the source code such that we can fuzz test it.
If you already compiled and ran the application or investigated the source code,
you will notice that the application implements `sleep` which make the application sit on hold for an amount of time.
Furthermore, you will notice that there already is inserted some `assert`-statements.

## Run the Fuzz Test
We already know how to compile the source with instrumentation and how to run the fuzz test. 
In this case, AFL++ is throwing an error, due to timeout.
You can extend the timeout constraint by giving `-t` as parameter, like so:
```shell
afl-fuzz -t 5000+ -i input_directory -o output_directory -- /exercise/4/a/target
```
You will see that each run is rather slow and this can be fixed.

## Alter the Source Code
Before altering any code, be sure to make a backup.
You can do so by using the `cp`-command.
When looking in the source code, there is a single function call, which takes up most of the runtime.
Which function is that?
You can comment out lines by using the comment notations: 
```C
// This line is commented out

/* ------------------------
    all these lines are commented out
------------------------- */
```
You can comment out the lines which take most time, in order to do a proper fuzz test,
and as we run the next one, we see a rising number of found crashes.
This is due to the assert statements in the source code.

In the source code exist a function called `process_input` it seems undone. 
**Can you fix it such that if the input is not in the right format the application will exit properly
instead of crashing?**
- There already exist handling of a single case, which case is that? You can use that case to get inspiration to handle the other ones
- Try to run the fuzz test after you fix the application, does it still crash?
    - if so why?
