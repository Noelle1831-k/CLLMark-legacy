int search(char []);
int main(void){
	int i,j,flag;
	char string[90];
	for(i = 0 ;; i ++){
		string[i] = getchar();
		if(string[i] == '.'){
			break;
		}
	}
	for(i = 0 ; i < 25; i ++){
		for(j = 0 ;string[j] != '.' ; j ++){
			if(string[j] != ' ' && string[j] != '\n'){
				if(string[j] == 'z'){
					string[j] -= 26;
				}
				string[j] += 1;
			}
		}
		flag = search(string);
		if(flag == 1){
			printf("%s\n",string);
			break;
		}
	}
	return  0;
}
int search(char string[90]){
	if(strstr(string,"the") != NULL || 
	   strstr(string,"this") != NULL ||
	   strstr(string,"that") != NULL){
		return 1;
	}
	return 0;
}