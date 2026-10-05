	unordered_map<string, string> res{};
	for (const auto& x : dict1)
		res[x.first] = x.second;
	for (const auto& x : dict2)
		res[x.first] = x.second;
	for (const auto& x : dict3)
		res[x.first] = x.second;
	return res;
}
<|endoftext|>