#include <string.h>
#include <stdio.h>
int main(){char c[4] = {'T','D','L','F'},str[25];int result = 1,i,j;while(scanf("%s",str)!=EOF){result=1;for(i=0;i<strlen(str);i++){int check = 0;for(j=0;j<4;j++){if(str[i]==c[j])check=1;}if(check)result*=2;}printf("%d\n",result );}}