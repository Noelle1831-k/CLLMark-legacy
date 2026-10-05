	string s = to_string(n);
	int prod = 1;
	for(int i=0; i<s.length(); i++){
		prod *= s[i]-'0';
	}
	string evenProd = to_string(prod);
	string oddProd = "";
	for(int i=1; i<evenProd.length(); i++){
		oddProd += evenProd[i];
	}
	prod = stoi(oddProd);
	while(prod > 9){
		string evenProd = to_string(prod);
		string oddProd = "";
		for(int i=1; i<evenProd.length(); i++){
			oddProd += evenProd[i];
		}
		prod = stoi(oddProd);
	}
	if(prod == s[0]-'0'){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	cout << productEqual(2841) << endl;
	cout << productEqual(1234) << endl;
	cout << productEqual(1212) << endl;
	return 0;
}
<|endoftext|>