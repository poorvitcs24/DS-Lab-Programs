#include<stdio.h>
#define EMPTY -1
int main()
{
    int m,n,key;
    int HT[100];
    printf("Enter size of Hash Table:");
    scanf("%d",&m);
    for(int i=0;i<m;i++)
        HT[i]=EMPTY;
    printf("Enter number of employee records:");
    scanf("%d",&n);
    printf("Enter %d employee keys(4-digits):\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&key);
        int index =key%m;
        int startIndex=index;
        while(HT[index]!=EMPTY)
        {
            index=(index+1)%m;
            if(index==startIndex)
            {
                printf("Hash Table is ful!\n");
                return 0;
            }
        }
        HT[index]=key;
    }
    printf("\nHash Table Contents:\n");
    printf("Address\tKey\n");
    for(int i=0;i<m;i++)
    {
        if(HT[i]!=EMPTY)
            printf("%02d\t%d\n",i,HT[i]);
        else
            printf("%02d\t--\n",i);
    }
    return 0;
}
