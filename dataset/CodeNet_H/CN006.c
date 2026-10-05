int main(void)
{
	int i;
	char str[200], *p;
	for( ; ; ){
		scanf("%s", str);
		i = strlen(str);
		for(i; i>=0; i--){
			printf("%c", str[i-1]);
		}
		printf("\n");
}
	return 0;
}