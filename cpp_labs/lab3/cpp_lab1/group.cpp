#include "group.h"

Group::Group()
{
	count = 0;
}

Group::Add(Place *cur)
{
	cur->next = begin;
	begin = cur;
	count = count + 1;
}

Group::Del() {}
























