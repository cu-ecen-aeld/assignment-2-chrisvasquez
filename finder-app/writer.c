#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void display_error (void) {
  syslog(LOG_ERR, "%s", "ERROR: Invalid number of arguments.");
  syslog(LOG_ERR, "%s", "Total number of arguments should be 2.");
  syslog(LOG_ERR, "%s", "The order of the arguments should be:");
  syslog(LOG_ERR, "%s", "  1) File Path.\n");
  syslog(LOG_ERR, "%s", "  2) String to be written in the specified file path.");
}
int main(int argc, char* argv[]) {

    openlog(argv[0], LOG_PID, LOG_USER);

    if (argc != 3) {
        display_error();
        return 1;
    }
    int fd;
    fd = open (argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        display_error();
        return 1;
    } else {
        ssize_t nr;
        /* write the string in 'buf' to 'fd' */
        syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
        nr = write (fd, argv[2], strlen (argv[2]));
        if (nr == -1) {
            display_error();
            return 1;
        } else {
            return 0;
        }
    }
}