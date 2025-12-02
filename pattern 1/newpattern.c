#include<stdio.h>
void main(){
	
	 int i,j,n,x=1;
	 
	 
 	 printf("Enter value foe n");
 	 scanf("%d",&n);
 	 
 	 
 	 for(i=1;i<=n;i++)
 	  {
 	  	for(j=1;j<=i;j++)
 	  	 {
 	  	 	if(x%2==0)
 	  	 	 printf("0");
 	  	 	else
 	  	 	 printf("1");
 	  	 	 x++;
			}
			printf("\n");
	   }
 	 
 	 
 }
