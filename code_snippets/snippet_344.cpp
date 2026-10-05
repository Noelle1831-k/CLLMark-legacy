	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	return 2*getPerrin(n-1) + getPerrin(n-2);
}
int main() {
	int n;
	cin >> n;
	cout << getPerrin(n) << endl;
	return 0;
}
<|endoftext|>