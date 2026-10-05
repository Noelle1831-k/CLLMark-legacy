int main(void) {
    int add1,add2,sum,i,j;
    char str[126],copy[126],a[10]={'0','1','2','3','4','5','6','7','8','9'};
    while (fgets(str,sizeof(str),stdin)!=NULL) {
        for (i=0; i<10; i++) {
            strcpy(copy,str);
            for (j=0; j<strlen(copy); j++) {
                if (copy[j]=='X') copy[j]=a[i];
            }
            sscanf(copy,"%d+%d=%d",&add1,&add2,&sum);
            if (add1+add2==sum) break;
        }
        if (i==10) {
            printf("NA\n");
        } else {
            printf("%d\n",i);
        }
    }
    return 0;
}