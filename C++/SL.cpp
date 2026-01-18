#include"SeqList.h"
#include<stdlib.h>
void SLPushBack(SL **sl, int x)
{
	SL* tmp = (SL*)malloc(sizeof(SL));
	if (tmp == NULL)
	{
		perror("no");
		return;
	}
	tmp->val = x;
	tmp->next = NULL;
}
