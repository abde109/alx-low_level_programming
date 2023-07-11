#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    Elf64_Ehdr header;
    int file;

    if (argc < 2) {
        printf("Usage: %s file_name\n", argv[0]);
        return (1);
    }

    file = open(argv[1], O_RDONLY);
    if (file == -1) {
        perror("Error opening file");
        return (1);
    }

    if (read(file, &header, sizeof(header)) != sizeof(header)) {
        perror("Error reading file");
        close(file);
        return (1);
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3) {
        printf("Not an ELF file\n");
        close(file);
        return (1);
    }

    printf("ELF Header:\n");
    printf("  Type:                              %d\n", header.e_type);
    printf("  Machine:                           %d\n", header.e_machine);
    printf("  Version:                           %d\n", header.e_version);
    printf("  Entry point address:               %lx\n", header.e_entry);
    printf("  Start of program headers:          %lx\n", header.e_phoff);
    printf("  Start of section headers:          %lx\n", header.e_shoff);
    printf("  Flags:                             %d\n", header.e_flags);
    printf("  Size of this header:               %d\n", header.e_ehsize);
    printf("  Size of program headers:           %d\n", header.e_phentsize);
    printf("  Number of program headers:         %d\n", header.e_phnum);
    printf("  Size of section headers:           %d\n", header.e_shentsize);
    printf("  Number of section headers:         %d\n", header.e_shnum);
    printf("  Section header string table index: %d\n", header.e_shstrndx);

    close(file);
    return (0);
}

