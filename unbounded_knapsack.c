#include<stdio.h>
#include<stdlib.h>
struct link
{
	int x;
	struct link *next;
};
typedef struct link node;
int main()
{
	int *w,*v,n,c,*t,i,x;
	node **s,*new;
	printf("\nEnter the total number of items :");
	scanf("%d",&n);
	w=(int *)malloc(n*(sizeof(int)));
	v=(int *)malloc(n*(sizeof(int)));
	printf("\nEnter the weights and values of the items one by one :");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the weight of Item-%d :",i+1);
		scanf("%d",&w[i]);
		printf("\nEnter the value of Item-%d :",i+1);
		scanf("%d",&v[i]);
	}

	for(i=0;i<n;i++)
	{
		printf("Item-%d\tweight-%d\tvalue-%d\n",i+1,w[i],v[i]);
	}

	
	printf("\nEnter the capacity of the unbounded Knapsack :");
	scanf("%d",&c);
	t=(int *)malloc((c+1)*(sizeof(int)));
	s=(node **)malloc((c+1)*(sizeof(node *)));
	t[0]=0;
	s[0]=NULL;
	for(x=1;x<=c;x++)
	{
		t[x]=0;
		s[x]=NULL;
		//printf("%d\t%d\n",x,t[x]);
		for(i=0;i<n;i++)
		{
			if(w[i]<=x)
			{
				if((t[x-w[i]]+v[i])>t[x])
				{
					t[x]=t[x-w[i]]+v[i];
					//printf("%d\n",t[x]);
					s[x]=s[x-w[i]];
					new=(node *)malloc(1*(sizeof(node)));
					new->x=i;
					new->next=s[x];
					s[x]=new;
				}
				
			}
		}
		//printf("%d\t%d\n",x,t[x]);
	}
	printf("\nTotal value of the items in the Knapsack is %d.\nThe knapsack containts the following items :\n",t[c]);
	while(s[c]!=NULL)
	{
		printf("Item-%d\n",(s[c]->x)+1);
		s[c]=s[c]->next;
	}
}
