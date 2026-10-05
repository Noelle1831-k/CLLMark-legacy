	string tmp="";
	vector<string> res;
	for(int i=0;i<text.length();i++){
		if(text[i]==','){
			res.push_back(tmp);
			tmp="";
		}else if(text[i]=='"'){
			while(text[i]!='"'){
				i++;
			}
		}else{
			tmp+=text[i];
		}
	}
	res.push_back(tmp);
	return res;
}
<|endoftext|>