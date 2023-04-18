#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * _strlen - Returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
    int length = 0;

    while (*s++)
        length++;

    return (length);
}

/**
 * _strcpy - Copies a string from source to destination
 * @dest: The destination string
 * @src: The source string
 *
 * Return: The pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
    char *ptr = dest;

    while (*src)
        *dest++ = *src++;
    *dest = '\0';

    return (ptr);
}

/**
 * new_dog - Creates a new dog
 * @name: The name of the dog
 * @age: The age of the dog
 * @owner: The owner of the dog
 *
 * Return: Pointer to the newly created dog, NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *new_dog;
    char *name_copy, *owner_copy;

    new_dog = malloc(sizeof(dog_t));
    if (new_dog == NULL)
        return (NULL);

    name_copy = malloc((_strlen(name) + 1) * sizeof(char));
    if (name_copy == NULL)
    {
        free(new_dog);
        return (NULL);
    }
    _strcpy(name_copy, name);

    owner_copy = malloc((_strlen(owner) + 1) * sizeof(char));
    if (owner_copy == NULL)
    {
        free(name_copy);
        free(new_dog);
        return (NULL);
    }
    _strcpy(owner_copy, owner);

    new_dog->name = name_copy;
    new_dog->age = age;
    new_dog->owner = owner_copy;

    return (new_dog);
}

