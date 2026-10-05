  int main(){
   char x[1000];
      int i=0;
	  while(x[i] != EOF){
    scanf("%c",&x[i]);
	if(x[i]=='A'){
		x[i]='X';
	}
	else if(x[i]=='B'){
		x[i]='Y';
	}
	else if(x[i]=='C'){
		x[i]='Z';
	}
     else{
		 x[i] -= 3;
	 }
          printf("%c",x[i]);
		  i++;
	}
return 0;
}
