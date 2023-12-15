#include "shell.h"
/**
 * print_list - Print linked list
 * @h: Linked list
 * Return: Size of linked list
 */
size_t print_list(list_t *h)
{
	list_t *current = h;
	size_t count = 0;

	while (current)
	{
		if (current->var == NULL)
		{
			_putchar('\n');
		}
		else
		{
			char *str = current->var;

			while (*str)
			{
				_putchar(*str);
				str++;
			}
			_putchar('\n');
		}
		current = current->next;
		count++;
	}
	return (count);
}
/**
 * add_end_node - add node to end of linked list
 * @head: pointer to head of linked list
 * @str: data to new node
 * Return: pointer to new linked list
 */
list_t *add_end_node(list_t **head, char *str)
{
	list_t *new;
	list_t *current;

	if (head == NULL || str == NULL)
	{
		return (NULL);
	}
	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->var = _strdup(str);
	if (new->var == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}
	return (*head);
}
/**
 * delete_nodeint_at_index - deleting a node at an index
 * @head: beigining of the address
 * @index: the input
 * Return: 1 if successful
 */
int delete_nodeint_at_index(list_t **head, int index)
{
	list_t *current, *temp;
	int count;

	if (*head == NULL || index < 0)
	{
		return (-1);
	}
	if (index == 0)
	{
		temp = *head;
		*head = temp->next;
		free(temp->var);
		free(temp);
		return (1);
	}
	current = *head;
	for (count = 1; count < index; count++)
	{
		if (current == NULL || current->next == NULL)
		{
			return (-1);
		}
		current = current->next;
	}
	temp = current->next;
	current->next = temp->next;
	free(temp->var);
	free(temp);
	return (1);
}
/**
 * free_list_t - frees a linked list
 * @list: list to be freed
 */
void free_list_t(list_t *list)
{
	list_t *temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp->var);
		free(temp);
	}
}
