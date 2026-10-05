int main(){
  char t1[100][100];
  char t2[100][100];
  int i = 0;
  int j = 0;   
  for(i = 0; i < 8; i++){
      scanf("%s", &t1[i]);
  }
  memcpy(t2, t1, sizeof(t1));
  printf("90\n");
  for(i = 0; i < 8;  i++){
    for(j = 0; j < 8; j++){
      t1[j][8 - i - 1] = t2[i][j]; 
    }
  }
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      printf("%c", t1[i][j]);
    }
    printf("\n");
  }
  memcpy(t2, t1, sizeof(t1));
  printf("180\n");
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      t1[j][8 - i - 1] = t2[i][j];
    }
  }
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      printf("%c", t1[i][j]);
    }
    printf("\n");
  }
  memcpy(t2, t1, sizeof(t1));
  printf("270\n");
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      t1[j][8 - i - 1] = t2[i][j];
    }
  }
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      printf("%c", t1[i][j]);
    }
    printf("\n");
  }
  return 0;
}