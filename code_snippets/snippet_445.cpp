	map<string, string> l1map, l2map;
	for (int i = 0; i < l1.size(); i++) {
		l1map[l1[i]] = l2[i];
	}
	map<string, string> l2m2;
	for (int i = 0; i < l2.size(); i++) {
		l2m2[l2[i]] = l1[i];
	}
	map<string, string> l1map2;
	for (int i = 0; i < l1.size(); i++) {
		l1map2[l1[i]] = l2m2[l1[i]];
	}
	for (int i = 0; i < l1.size(); i++) {
		if (l1map[l1[i]] != l1map2[l1[i]])
			return false;
	}
	return true;
}
<|endoftext|>