#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
This is a round-about way of getting the output from
a shell script test. Apparently, LOG_DRIVER
only works for executables and not for shell scripts.
So, use this executable to indirectly invoke a shell script
test so that its output appears in e.g. travis log.
If I could figure out the shell equivalent of LOG_DRIVER,
then this would not be necessary.
*/


#define CMD "./tst_filter.sh"

int
main(int argc, char** argv)
{
    int stat = system(CMD);
    return WEXITSTATUS(stat);
}
