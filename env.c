#include "shell.h"
/**
 * _getenv - gets the the environment variable value.
 * @name: the name of environment var.
 * 
 * Return: NULL if the variable is not found or a pointer to the value
 * of the environment var.
 */
char *_getenv(const char *name)
{
    int nameL = strlen(name);
    int x;
    extern char **environ;

    for (x = 0; environ[x] != NULL; x++)
    {
        /* if the value matchs and has = */
        if (_strncmp(environ[x], name, nameL) == 0 && environ[x][nameL] == '=')
        {
            return (&(environ[x][nameL + 1]));
        }
    }
    return (NULL);
}

/**
 * printEnv - prints the environment vars.
 * 
 * Return: nothing becouse its a void func
 */
void printEnv(void)
{
    char **env;
    size_t len;
    extern char **environ;

/* iterates through env vars. */
    for (env = environ; *env != NULL; env++)
    {
        len = strlen(*env);
        write(STDOUT_FILENO, *env, len);
        write(STDOUT_FILENO, "\n", 1);
    }
}

/**
 * _setenv - we will write the code after this first comment.
 * 
 */
int _setenv(const char *name, const char *value, int overwrite);

/**
 * myUnsetEnv - unsets the environment
 * @var: environment var
 * 
 * Return: usually 0 for success
 */
int _unsetenv(char *var)
{
    if (unsetenv(var) != 0)
    {
        perror("unsetenv error");
        return (-1);
    }

    return (0);
}