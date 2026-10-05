struct cell{
    struct cell *prev;
    struct cell *next;
    int flag;
}s[10000],*now;
int main(){
    int i,flag,m,n,tmp;
    char str[10000];
    while(scanf("%d%d",&m,&n),m+n){
        tmp = m;
        for(i = 0;i < n;i++){
            if(i)s[i].prev = &s[i - 1];
            else s[i].prev = &s[n - 1];
            if(i == n - 1)s[i].next = &s[0];
            else s[i].next = &s[i + 1];
            s[i].flag = 1;
        }
        now = &s[0];
        for(i = 1;i <= n;i++){
            scanf("%s",str);
            if(tmp == 1)continue;
            if(i % 3 == 0){
                if(i % 5 == 0){
                    flag = strcmp(str,"FizzBuzz");
                }else{
                    flag = strcmp(str,"Fizz");
                }
            }else if(i % 5 == 0){
                flag = strcmp(str,"Buzz");
            }else{
                if(i == atoi(str))flag=0;
                else flag=1;
            }
            if(flag){
                now -> prev -> next = now -> next;
                now -> next -> prev = now -> prev;
                now -> flag = 0;
                tmp--;
            }
            now = now -> next;
        }
        for(i = 0,flag = 0;i < m;i++){
            if(s[i].flag == 1){
                if(!flag){
                    printf("%d",i+1);
                    flag = 1;
                }else{
                    printf(" %d",i+1);
                }
            }
        }
        puts("");
    }
    return 0;
}