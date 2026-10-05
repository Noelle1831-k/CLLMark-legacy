	string result = arr[0];
	for(int i=1;i<n;i++){
		string curr_suff = arr[i];
		for(int i=0;i<result.length();i++){
			if(i==curr_suff.length()){
				result = result.substr(0,i);
				break;
			}
			if(result[i]!=curr_suff[i]){
				result = result.substr(0,i);
				break;
			}
		}
	}
	return result;
}