char a[4002];
char b[4002];
int match(char *a,char *b)
{
  int i=0;
  while(a[i] == b[i] && a[i] != '\0') i++;
  return i;
}
int main()
{
  int i,l,m;
  char *p,*q;
  while((scanf("%s",a)) != EOF){
    scanf("%s",b);
    m = 0;
    for(i=0;i<strlen(a);i++){
      p = b;
      while((q = strchr(p,a[i])) != NULL){
	l = match(&a[i],q);
	if (m < l) m = l;
	p = q+1;
      }
      if(m > strlen(a) - i) break;
    }
    printf("%d\n",m);
  }
}