	int jumps = 0; 
	int current_max = 0; 
	int start = 0; 
	int end = 0; 
	while (end < n-1) {
		while (end < n-1 and arr[end] > current_max) {
			current_max = max(current_max, end);
			end++;
		}
		jumps++;
		if (end == n-1) {
			break;
		}
		while (arr[start] > current_max) {
			start++;
		}
		end = max(current_max, end);
		end = max(end, start+1);
		current_max = arr[end] + end;
		jumps++;
	}
	return jumps;
}
<|endoftext|>