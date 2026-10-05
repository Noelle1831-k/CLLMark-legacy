int FUNC(char s[],char A){
int M=0,K,I,J;
for(J=0;J<7;J+3){
K=0;
for(I=J;I<J+3;I++)
if(s[I]==A)
K++;
if(K==3){
M++;
break;
}
}
if(M>0)return 1;
for(J=0;J<3;J++){
K=0;
for(I=J;I<J+7;J+3)
if(s[I]==A)
K++;
if(K==3){
M++;
break;
}
If(M>0)return 1;
K=0;
if(s[0]==A&&s[4]==A&&s[8]==A)
return 1;
If(s[2]==1&&s[4]==A&&s[6]==A)
return 1;
return 0;
}
int main(){
char s{10],A;
while(scanf("%s",s)!=EOF){
A='o';
if(FUNC(s,A){
printf("o\n");
continue;
}
A='x';
if(FUNC(s,A))
printf("x\n");
else printf("d\n");
}
return 0;
}