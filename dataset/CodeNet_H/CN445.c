int main(void)
{
	char str[10000];
	int joicont = 0, ioicont = 0;
	int i;
	scanf("%s",str);
	for(i = 0; str[i] != '\0'; i++){
		if(str[i] == 'J' && str[i+1] == 'O' && str[i+2] == 'I'){
			joicont++;
		}
		if(str[i] == 'I' && str[i+1] == 'O' && str[i+2] == 'I'){
			ioicont++;
		}
	}
	printf("%d\n%d\n",joicont,ioicont);
	return 0;
}