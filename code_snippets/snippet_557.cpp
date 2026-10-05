	int result = 0;
	for (const auto name: sampleNames) {
		if (name[0] > 'Z' and name[0] < 'a') {
			result += name.length();
		}
	}
	return result;
}
<|endoftext|>