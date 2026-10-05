	int gcd=l[0];
	for(int i=1;i<l.size();i++){
		while(l[i]!=0){
			gcd=gcd%l[i];
			l[i]=gcd;
		}
	}
	return gcd;
}
int main(){
	return 0;
}
<|endoftext|>