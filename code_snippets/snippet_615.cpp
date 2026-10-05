	unordered_map<int, int>::iterator iter1;
	iter1 = d.find(x);
	if (iter1 != d.end())
	{
		return true;
	}
	else {
		return false;
	}
}
int main() {
	unordered_map<int, int> d{{1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50}, {6, 60}};
	assert(isKeyPresent(d, 5) == true);
	assert(isKeyPresent(d, 6) == true);
	assert(isKeyPresent(d, 10) == false);
	return 0;
}
<|endoftext|>