	vector<vector<string>> v(1, vector<string>());
	for (unsigned int i = 0; i < l.size(); i++) {
		unsigned int j = 0;
		while (j < v.size()) {
			unsigned int k = 0;
			while (k < n-1) {
				v.push_back(v[j]);
				k++;
			}
			v[j].push_back(l[i]);
			j++;
		}
	}
	return v;
}
"""
def combinationsColors(l, n):
    result = []
    for i in range(len(l)):
        for j in range(i):
            for k in range(n-1):
                result.append(result[j])
            result[j].append(l[i])
    return result<|endoftext|>