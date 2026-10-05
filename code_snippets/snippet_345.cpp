	int count = 0;
	for(int i=0;i<s.length()-1;i++){
		if(s[i]==']'&&s[i+1]=='['){
			count++;
		}
	}
	return count;
}
int main(){
	string s = "[[][]][][][][]";
	cout<<swapCount(s);
	return 0;
}
<|endoftext|>