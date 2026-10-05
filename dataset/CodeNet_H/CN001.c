void Swap(int x[],int r,int l){
	int temp;
	temp=x[r];
	x[r]=x[l];
	x[l]=temp;
}
void Qsort(int x[],int l,int r){
	int i,j,p;
	i=l;
	j=r;
	p=x[(l+r)/2];
	while(1){
		while(x[i]<p)i++;
		while(x[j]>p)j--;
		if(i>=j)break;
		Swap(x,i,j);
		i++;
		j--;
	}
	if(i-l>2)Qsort(x,l,i-1);
	if(r-j>2)Qsort(x,j+1,r);
}
int main(){
	int h[10],i;
	for(i=0; i<10; i++)scanf("%d",&h[i]);
	Qsort(h,0,9);
	printf("%d\n%d\n%d\n",h[9],h[8],h[7]);
	return 0;
}