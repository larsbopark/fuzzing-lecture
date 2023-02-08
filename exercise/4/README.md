# Optimising the Fuzz Test
When having the source code available we are able to modify and change the source as we wish. This can prove to be a great tool in order to obtain greater performance when running fuzz tests. Furthermore, we can insert `assert`-call to fuzz for logic related bugs which makes fuzz testing a much greater tool. 

| WARNING: when changing the source code we might introduce bugs or change the behaviour of the application -- when changing source code be absolutely sure how it affects the application
|------------|

## Removing I/O and Exposing Functions
If we want more performance an easy fix is to remove I/O operations such as `prinf`, `puts` and `sleep` etc. Furthermore, can multiple `scanf` or `fgets` be concatenated in a single statement, since the fuzzer will not percieve it any different. When doing this can of changing we have to be extra careful, since we can remove potentially bugs, such as buffer overflows and printf-vulnerabilities. So you have to be extremely careful. 

Another strong tool is to expose the target function. You can do so by making a new `main.c`, which includes the target function. When doing so, it is extremely important that you remember to set up the context needed in order to fuzz test the target function correct. 

## Inserting Assertions
If we want to fuzz test anything else than memory related bugs we can use `assert` to provoke crashes if an expression evaluate false. This is a strong tool and is used outside of fuzz testing context when developing. The possibilities with `assert` is quite broad, and it can both be difficult and easy to find some relevant expressions. 

Often when developing, wrong assumptions about the logic leads to bugs or security related issues. These assumptions can be expressed in `assert`-statements in order to strengthen or eliminating them.

### Banking Example
Imagine we have a banking system, then we are able to make up some assumptions of how it should behave. Some examples:
- Transfers can only happen if there is sufficient balance
- Withdrawing can only happen if there is sufficient balance
- It is not allowed to deposit negative amounts
- Transfers is not allowed without a destination account

More examples:
- The user who starts a transfer is also the one who finish it
- The balance is only changed if a transfer completes successfully
- Transfer over 10,000.00 dkk needs a second confirmation if and only if the destination account is external or owned by a distrusted entity

## Moving On
In the following exercises we experiment with changing the code by inserting `assert` statements and removing I/O. We have to be extremely careful when doing so since the behavior of the application might change, and we might introduce more errors or bugs. 

> It is a good idea to copy the source code before changing it. You can do so by entering the following command:
> ```bash
> cp main.c main.c.backup
> ```