#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * create_file - Creates a file with the specified permissions and content
 * @filename: The name of the file to create
 * @text_content: A NULL-terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int fd, bytes_written;
    size_t len;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
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

