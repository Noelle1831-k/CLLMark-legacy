	while(n){
		int dig = n%10;
		n /= 10;
		if(dig > count(n)) return false;
	}
	return true;
}
int main(){
	return 0;
}
<|endoftext|>