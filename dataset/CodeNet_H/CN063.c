int main(void)
{
  char a[101];
  char b[101];
  int c=0,l;
  while(scanf("%s",a)!=EOF){
    l=strlen(a);
    int i,j;
    for(i=0,j=l-1;i<l-1;i++,j--){
      b[i]=a[j];
    }
    b[l]='\0';
    if(strcmp(a,b)==0)
      c++;
  }
  printf("%d\n",c);
  return 0;
}