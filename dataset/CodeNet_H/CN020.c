int main(void)
{
	char buf;
	while(1){
		buf = getchar();
		if(buf == EOF){ break; }
		if( islower(buf) ){ buf = toupper(buf); }
		printf("%c", buf);
	}
	printf("\n");
	getchar();
	return 0;
}