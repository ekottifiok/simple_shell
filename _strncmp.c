/**
 * _strncmp: compares two strings and returns the difference
 * @s1: string one
 * @s2: string two
 * Return: the difference in string
 */
int _strncmp(char *s1, char *s2, int len)
{
	int a;


	for (a = 0; s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0'; a++)
		;
	if (a == len)
		return (0);
	return (-1);
}