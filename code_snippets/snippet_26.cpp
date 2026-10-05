	string ret = "";
	string temp = "";
	string::iterator iter;
	for(int i = 0; i < list.size(); i++){
		temp = list[i];
		for(iter = temp.begin(); iter != temp.end(); iter++){
			if(*iter >= '0' && *iter <= '9'){
				temp.erase(iter);
				list[i] = temp;
				temp = list[i];
			}
		}
	}
	return list;
}
int main(){
	vector<string> test = {"4words", "3letters", "4digits"};
	test = remove(test);
	for(int i = 0; i < test.size(); i++){
		cout << test[i] << endl;
	}
	test = {"28Jan", "12Jan", "11Jan"};
	test = remove(test);
	for(int i = 0; i < test.size(); i++){
		cout << test[i] << endl;
	}
	test = {"wonder1", "wonder2", "wonder3"};
	test = remove(test);
	for(int i = 0; i < test.size(); i++){
		cout << test[i] << endl;
	}
	return 0;
}
<|endoftext|>