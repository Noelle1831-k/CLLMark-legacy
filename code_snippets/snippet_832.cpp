	int sum = 1;
	for(int i=2;i<=n/2;i++) {
		if(n%i==0) {
			sum+=i;
		}
	}
	if(sum>n)
		return true;
	else
		return false;
}
int main() {
	int n;
	while(cin>>n) {
		if(isAbundant(n))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
<|endoftext|>