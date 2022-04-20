#include <stdio.h>

char * s_gets(char *st, int n);

int main(void)
{
	char name[20] = "ggwp"; 
	char *ret;
	ret = s_gets(name, 20);
	printf("%s", ret);

	return 0;
}


char * s_gets(char *st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val) // т..е ret_val != NULL
	{
		while (*st != '\n' && *st != '\0')
			st++;
		if (*st== '\n')
			*st= '\0';
		else // требуется наличие words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}	
	return ret_val;
}

//char * s_gets(char *st, int n)
//{
//	char * ret_val;
//	int i = 0;
//
//	ret_val = fgets(st, n, stdin);
//	if (ret_val) // т..е ret_val != NULL
//	{
//		while (st[i] != '\n' && st[i] != '\0')
//			i++;
//		if (st[i] == '\n')
//			st[i] = '\0';
//		else // требуется наличие words[i] == '\0'
//			while (getchar() != '\n')
//				continue;
//	}	
//	return ret_val;
//}
