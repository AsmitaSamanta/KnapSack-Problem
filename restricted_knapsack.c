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
	int *w,*v,n,c,**t,i,x;
	node ***s,*new;
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

	
	printf("\nEnter the capacity of the restricted Knapsack :");
	scanf("%d",&c);
	t=(int **)malloc((c+1)*(sizeof(int *)));
	s=(node ***)malloc((c+1)*(sizeof(node **)));
	for(i=0;i<=c;i++)
	{
		t[i]=(int *)malloc((n+1)*(sizeof(int)));
		s[i]=(node **)malloc((n+1)*(sizeof(node *)));
	}
	for(i=0;i<=n;i++)
	{
		t[0][i]=0;
		t[i][0]=0;
		s[0][i]=NULL;
		s[i][0]=NULL;
	}
	for(x=1;x<=c;x++)
	{
		for(i=0;i<n;i++)
		{
			t[x][i+1]=t[x][i];
			s[x][i+1]=s[x][i];
			if(w[i]<=x)
			{
				if((t[x-w[i]][i]+v[i])>t[x][i+1])
				{
					t[x][i+1]=t[x-w[i]][i]+v[i];
					s[x][i+1]=s[x-w[i]][i];
					new=(node *)malloc(1*(sizeof(node)));
					new->x=i;
					new->next=s[x][i+1];
					s[x][i+1]=new;
				}
				
			}
		}
	}
	printf("\nTotal value of the items in the Knapsack is %d.\nThe knapsack containts the following items :\n",t[c][n]);
	while(s[c][n]!=NULL)
	{
		printf("Item-%d\n",(s[c][n]->x)+1);
		s[c][n]=s[c][n]->next;
	}
}
