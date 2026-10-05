	vector<string> res;
	for_each(texts.begin(), texts.end(), [&res](string text){
		string tmp(text);
		string::iterator iter = tmp.begin();
		while(iter != tmp.end()){
			string::iterator iter2 = tmp.end();
			while(iter2 != iter){
				if(*iter != *iter2){
					break;
				}
				iter2--;
			}
			if(iter2 != iter){
				break;
			}
			iter++;
		}
		if(iter == tmp.end()){
			res.push_back(text);
		}
	});
	return res;
}
int main(int argc, char** argv){
	vector<string> texts = {
		"php", 
		"res", 
		"Python", 
		"abcd", 
		"Java", 
		"aaa"
	};
	printArr(palindromeLambda(texts));
	return 0;
}
<|endoftext|>