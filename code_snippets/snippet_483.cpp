	int size = seqNums.size();
	string ret = "Linear Sequence";
	for(int i = 0; i < size-1; i++){
		if(seqNums[i] > seqNums[i+1]){
			ret = "Non Linear Sequence";
			break;
		}
	}
	return ret;
}
<|endoftext|>