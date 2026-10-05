	int count_colors = patterns.size();
	string first_colors, last_colors;
	string first_pattern, last_pattern;
	for (int i = 0; i < count_colors; i++) {
		string first_colors = patterns[i][0];
		string first_pattern = colors[i][0];
		if (first_colors != first_pattern) {
			return false;
		}
	}
	for (int i = 0; i < count_colors; i++) {
		string last_colors = patterns[i][patterns[i].length() - 1];
		string last_pattern = colors[i][colors[i].length() - 1];
		if (last_colors != last_pattern) {
			return false;
		}
	}
	return true;
}
<|endoftext|>