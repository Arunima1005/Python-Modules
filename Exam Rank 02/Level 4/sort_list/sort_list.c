#include "list.h"
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{

	t_list *curr;
	int tmp;
	int swapped = 1;
	
	if(!lst)
		return (NULL);

	//curr = lst;

	while (swapped)
	{
		swapped = 0;
		curr = lst;
		while(curr->next)
		{
			if(cmp(curr->data,curr->next->data) == 0)
			{
				 tmp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = tmp;
                swapped = 1;
			}
			curr = curr->next;
		}

	}
	return (lst);
}