// 16.10
#ifndef NAMES_H
#define NAMES_H

#define SLEN 32

struct names_st
{
	char first[SLEN];
	char last[SLEN];
};

// определения типов
typedef struct names_st names;

// прототипы функций 
void get_names(names *);
void show_names(const names *);
char * s_gets(char * st, int n);

#endif
