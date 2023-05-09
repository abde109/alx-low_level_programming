#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int copy_file(const char *file_from, const char *file_to);

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: The command-line arguments
 *
 * Return: 0 on success, otherwise a positive error code
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    return copy_file(argv[1], argv[2]);
}

/**
 * copy_file - Copies the content of one file to another file
 * @file_from: The source file
 * @file_to: The destination file
 *
 * Return: 0 on success, otherwise a positive error code
 */
int copy_file(const char *file_from, const char *file_to)
{
    int fd_from, fd_to, read_bytes, write_bytes;
    char buffer[1024];

    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1)
        return (dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from), close(fd_from), 98);

    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
        return (dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to), close(fd_from), 99);

    while ((read_bytes = read(fd_from, buffer, 1024)) > 0)
    {
        write_bytes = write(fd_to, buffer, read_bytes);
        if (write_bytes != read_bytes)
            return (dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to), close(fd_from), close(fd_to), 99);
    }

    if (read_bytes == -1)
        return (dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from), close(fd_from), close(fd_to), 98);

    if (close(fd_from) == -1)
        return (dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), 100);

    if (close(fd_to) == -1)
        return (dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), 100);

    return (0);
}

