using namespace std;
int bookin(int* books,int m,int w,int n);
int main(void)
{
  int n,m;
  for(;;){
    scanf("%d %d",&m,&n);
    if(n==0)return 0;
    int books[n];
    for(int i=0;i<n;i++){
      scanf("%d",&books[i]);
    }
    int low = 1,high=1500000;
    for(int i=0;i<100;i++){
      int mid = (low+high)/2;
      int midval = bookin(books,m,mid,n);
      if(midval==0)low = mid;
      else high = mid;
    }
    printf("%d\n",high); 
  }
}
int bookin(int* books,int m,int w,int n)
{
  int haba=w;
  for(int i=0;i<n;i++){
    haba-=books[i];
    if(haba<0){i--;m--;haba=w;}
    if(m<=0)return 0;
  }
  return 1;
}
