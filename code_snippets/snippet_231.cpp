	list.insert(list.begin(), element);
	list.insert(list.end(), element);
	list.erase(list.begin() + ((list.size() - 1) / 2));
	return list;
}
int main() {
	insertElement(vector<string>{string("Red"), string("Green"), string("Black")}, string("c"));
	insertElement(vector<string>{string("python"), string("java")}, string("program"));
	insertElement(vector<string>{string("happy"), string("sad")}, string("laugh"));
	return 0;
}
<|endoftext|>