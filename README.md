# malloc-intercept
A library that intercepts all malloc calls in an application and outputs after each call, the number of bytes allocated so far by the program, on stderr.

To run, ensure that the user has administrator priveleges by either using sudo or using an admin account.
Run the program by typing:
<code>$ LD_PRELOAD=malloc.so seq 1 5</code>
