#include "shell.h"

/**
 * custom_memcpy - copies info of void pointers
 * @dest_ptr: final pointer
 * @src_ptr: original pointer
 * @size: size of final pointer
 *
 */

void custom_memcpy(void *dest_ptr, void *src_ptr, unsigned int size)
{
	char *ptr_srcptr = (char *)src_ptr, *ptr_destptr = (char *)dest_ptr;
	unsigned int p;

	for (p = 0; p < size; p++)
		ptr_destptr[p] = ptr_srcptr[p];
}

/**
 * custom_realloc - reallocates memory
 * @memptr: pointer to previously allocated memory
 * @osize: old size
 * @nsize: new size
 *
 * Return: pointer to new memory block
 */

void *custom_realloc(void *memptr, unsigned int osize, unsigned int nsize)
{
	void *new_mem;

	if (memptr == NULL)
		return (malloc(nsize));
	if (nsize == 0)
	{
		free(memptr);
		return (NULL);
	}
	if (nsize == osize)
		return (memptr);

	new_mem = malloc(nsize);
	if (new_mem == NULL)
		return (NULL);
	if (nsize < osize)
		custom_memcpy(new_mem, memptr, nsize);
	else
		custom_memcpy(new_mem, memptr, osize);
	free(memptr);

	return (new_mem);
}
