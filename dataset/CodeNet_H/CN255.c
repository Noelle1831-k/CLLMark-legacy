void sort(long long int *data,long long int n){
  long long int i,flag,tmp;
  do{
    flag = 0;
    for(i = 0;i < n-1;i++){
      if(data[i] > data[i+1]){
        tmp = data[i];
        data[i] = data[i+1];
        data[i+1] = tmp;
        flag = 1;
      }
    }
  }while(flag);
}
int main(){
  long long int n,i,sum,pipe;
  long long int joint[65000];
  long long int price;
  while(1){
    scanf("%d",&n);
    if(n == 0){
      break;
    }
    sum = 0;
    for(i = 0;i < n;i++){
      scanf("%d",&pipe);
      sum += pipe;
    }
    for(i = 0;i < n-1;i++){
      scanf("%d",&joint[i]);
    }
    sort(joint,n-1);
    price = sum*n;
    for(i = 0;i < n-1;i++){
      if(price < (sum+joint[i])*(n-1)){
        price = (sum+joint[i])*(n-1);
      }else{
        break;
      }
    }
    printf("%lld\n",price);
  }
  return 0;
}