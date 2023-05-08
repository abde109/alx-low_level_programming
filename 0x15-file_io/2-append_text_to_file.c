#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: The name of the file
 * @text_content: The NULL-terminated string to add at the end of the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fd, bytes_written;
    size_t len;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
        return (-1);

    if (text_content != NULL)
    {
        for (len = 0; text_content[len] != '\0'; len++)
            ;

        bytes_written = write(fd, text_content, len);
        if (bytes_written == -1 || (size_t)bytes_written != len)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);

    return (1);
}

