struct road{
  int from;
  int to;
  int distance;
};
int calc_shortestDistance(int, int, int, int, struct road*, int);
int main(void)
{
  int n;
  int a, b, c;
  struct road roads[45];
  int city_size;
  int max_distance;
  int min_amount, amount;
  int min_city;
  int i, j;
  while(1){
    scanf("%d", &n);
    if(n==0) break;
    city_size=0;
    max_distance=0;
    for(i=0; i<n; i++){
      scanf("%d %d %d", &a, &b, &c);
      roads[i].from=a;
      roads[i].to=b;
      roads[i].distance=c;
      if(a<b && b>=city_size) city_size=b+1;
      else if(a>b && a>=city_size) city_size=a+1;
      if(max_distance<c) max_distance=c;
    }
    min_amount=city_size*(max_distance*n+1);
    for(i=0; i<city_size; i++){
      amount=0;
      for(j=0; j<city_size; j++){
	if(i==j) continue;
	amount+=calc_shortestDistance(i, j, city_size, n, roads, max_distance);
      }
      if(min_amount>amount){
	min_amount=amount;
	min_city=i;
      }
    }
    printf("%d %d\n", min_city, min_amount);
  }
  return 0;
}
int calc_shortestDistance(int from, int to, int city_size, int n, struct road* roads, int max_distance)
{
  int d[10];
  int is_searched[10]; 
  int min_d, min_city;
  int i;
  for(i=0; i<city_size; i++) is_searched[i]=0;
  for(i=0; i<city_size; i++) d[i]=max_distance*n+1;
  d[from]=0;
  while(1){
    min_d=max_distance*n+1;
    for(i=0; i<city_size; i++){
      if(!is_searched[i] && d[i]<min_d){
	min_d=d[i];
	min_city=i;
      }
    }
    if(min_city==to) break;
    for(i=0; i<n; i++){
      if(roads[i].from==min_city){
	if(d[roads[i].to]>min_d+roads[i].distance) d[roads[i].to]=min_d+roads[i].distance;
      }
      else if(roads[i].to==min_city){
	if(d[roads[i].from]>min_d+roads[i].distance) d[roads[i].from]=min_d+roads[i].distance;
      }
    }
    is_searched[min_city]=1;
  }
  return d[to];
}