int main(){
  int n, i, j, a, b;
  char in[258], dec[258] = {};
  scanf("%d", &n);
  while(n--){
    fgets(in, sizeof(in), stdin);
    for(a = 3;a < 52;a += 2){
      if(a == 13) continue;
      for(b = 0;b < 26;b++){
	for(j = 0;j <= strlen(in);j++){
	  if(in[j] >= 'a' && in[j] <= 'z')
	    dec[j] = (a * (in[j] - 'a') + b) % 26 + 'a';
	  else 
	    dec[j] = in[j];
	}
	if(strstr(dec, "that") || strstr(dec, "this")) goto end;
      }
    }
  end:;
    printf("%s", dec);
  }
  return 0;
}