	while(n>0){
		a=a*b;
		a=a/n;
		n--;
	}
	return a;
}
int main() {
	int a=3,b=4,n=4;
	cout<<floorMax(a,b,n);
	return 0;
}
<|endoftext|>