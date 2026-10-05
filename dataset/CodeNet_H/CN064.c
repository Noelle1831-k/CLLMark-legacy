int main(){
int i,j,k;
int n=0;
char s[81];
while(scanf("%s",s)!=-1){
for(i=0;i<strlen(s);i++){
if('1'<=s[i]&&s[i]<='9'){
for(j=i+1;j<strlen(s);j++){
if(s[j]<'0'||'9'<s[j]){
break;
}
}
for(k=0;k<j-i;k++){
n+=(s[i+k]-'0')*pow(10,j-i-k-1);
i=j;
}
}
}
}
printf("%d\n",n);
return 0;
}