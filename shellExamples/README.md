Let's look at some examples of useful functions for the shell implementation.

To get the current working directory (cwd), we can use a handy function: getcwd()

We can use chdir() to change the current working directory (cwd) of the current process.

If you wish to change the environment variables, you can provide a new set directly in exec*() members, or by using setenv().

In some of the exec*() members, you need to provide an argument array. In fact it is an array of pointer.
