int main(){
  int i, l[10], v1, v2, sum;
  double x;
  char c;
  while(scanf("%d %c", &l[0], &c) != EOF){
    for(i=1, sum=l[0]; i<10; i++){
      scanf("%d %c", &l[i], &c);
      sum += l[i];
    }
    scanf("%d %c %d", &v1, &c, &v2);
    x = sum * v1 / (double)(v1 + v2);
    for(i=0, sum=0; i<10; i++){
      sum += l[i];
      if(x <= sum){
	printf("%d\n", i+1);
	break;
      }
    }
  }
  return 0;
}