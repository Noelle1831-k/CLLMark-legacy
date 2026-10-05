int main(void)
{
	int a[100];
	int n;
	int i;
	int search_no;
	int index_min;
	int index;
	int index_max;
	int count;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &search_no);
	index_min = 0;
	index_max = n - 1;
	index = (index_min + index_max) / 2;
	count = 0;
	while(1){
		count++;
		if (index_min == index_max){
			break;
		}
		if (a[index] < search_no){
			index_min = index + 1;
		}
		else {
			index_max = index - 1;
		}
		index = (index_min + index_max) / 2;
	}
	printf("%d\n", count);
	return (0);
}