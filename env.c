#include "shell.h"

/**
 * env - prints the current environment
 * @data: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int env(data_t *data)
{
	print_list_str(data->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @data: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(data_t *data, const char *name)
{
	list_t *node = data->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * new_env - Initialize a new environment variable,
 *             or modify an existing one
 * @data: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int new_env(data_t *data)
{
	if (data->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (new_env(data, data->argv[1], data->argv[2]))
		return (0);
	return (1);
}

/**
 * remove env - Remove an environment variable
 * @data: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int remove env(data_t *data)
{
	int i;

	if (data->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= data->argc; i++)
	remove env(data, data->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @data: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(data_t *data)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
