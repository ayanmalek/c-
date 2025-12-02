
#include <stdio.h>

int main()
{
    char str1[100],str2[100];
    char str3[100];
    int i=0,j=0;
    printf("enter str1:");
    scanf("%s",&str1);
    printf("\nenter str2:");
    scanf("%s",&str2);
    printf("\n str1=%s",str1);
    printf("\n str2=%s",str2);
    
    while(str1[i]!='\0'){
        str3[j]=str1[i];
        j++;
        i++;
    }
    i=0;
    while(str2[i]!='\0'){
        str3[j]=str2[i];
        i++;
        j++;
    }
    str3[j]='\0';
    printf("\n conected string=%s",str3);
    return 0;
}
