int main(){
  int i,slen;
  char str[1002],b;
  fgets(str,1000,stdin);
  slen=strlen(str);
  for(i=0;i<slen;i++){
    if(str[i]=='a'&&i+4<slen){
      if(!strncmp(str+i+1,"pple",4)){
	b=str[i+5];
	strcpy(str+i,"peach");
	str[i+5]=b;
      }
    }else if(str[i]=='p'&&i+4<slen){
      if(!strncmp(str+i+1,"each",4)){
	b=str[i+5];
	strcpy(str+i,"apple");
	str[i+5]=b;
      }
    }
  }
  printf("%s",str);
  return 0;
}