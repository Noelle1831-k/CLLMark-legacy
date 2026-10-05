	string second_large;
	string second_sm;
	int largest_count = 0;
	for(int i = 0; i < input.size(); i++){
		int local_count = 0;
		for(int j = 0; j < input.size(); j++){
			if (input[i] == input[j]){
				local_count++;
			}
		}
		if(local_count > largest_count){
			largest_count = local_count;
			second_large = input[i];
		}
	}
	for(int i = 0; i < input.size(); i++){
		if(input[i] == second_large && i != largest_count - 1){
			second_sm = input[i + 1];
			break;
		}
	}
	return second_sm;
}