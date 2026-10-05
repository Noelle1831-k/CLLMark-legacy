	string out = "";
	for(int i = 0; i < m; i++) {
		out += x[i];
		for(int j = 0; j < n; j++) {
			if(out[i] == y[j]) {
				out += x[i];
				break;
			}
		}
	}
	return out.length();
}
<|endoftext|>