typedef struct data{
  int num;
  struct data *left, *right;
}Data;
int insert_list(int x, Data *start);
int sort(Data *start);
int main(void){
  Data *start;
  int i, n, x, ans;
  scanf("%d", &n);
  start = (Data *)malloc(sizeof(Data));
  if(start == NULL){
    printf("?????¢????¢??????¨??????\n");
    return -1;
  }
  start->right = start;
  start->left = start;
  for(i = 0; i < n; i++){
    scanf("%d", &x);
    if(insert_list(x, start) == 0){
      printf("?????¢????¢??????¨??????\n");
      return -1;
    }
  }
  ans = sort(start);
  printf("%d\n", ans);
  return 0;
}
int insert_list(int x, Data *start){
  Data *q, *p = (Data *)malloc(sizeof(Data));
  if(p == NULL)  return 0;
  p->num = x;
  q = start->left;
  start->left = p;
  p->right = start;
  q->right = p;
  p->left = q;
  return 1;
}
int sort(Data *start){
  Data *temp, *k = start->right;
  int count = 0;
  while(k != start){
    if(k->left == start || k->num >= k->left->num){
      k = k->right;
    }else if(k->num < k->left->num){
      count++;
      temp = k->left;
      temp->left->right = temp->right;
      temp->right->left = temp->left;
      temp->right = start;
      temp->left = start->left;
      start->left = temp;
      temp->left->right = temp;
    }
  }
  return count;
}