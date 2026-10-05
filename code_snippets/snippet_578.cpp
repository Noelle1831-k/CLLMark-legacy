	std::sort(dict1.begin(), dict1.end(), [=](const pair<string, vector<int>> &l, const pair<string, vector<int>> &r) {
		string &lName = l.first;
		string &rName = r.first;
		std::sort(l.second.begin(), l.second.end());
		std::sort(r.second.begin(), r.second.end());
		return lName < rName;
	});
	return dict1;
}
int main() {
	unordered_map<string, vector<int>> dict1;
	dict1["n1"] = {2, 3, 1};
	dict1["n2"] = {5, 1, 2};
	dict1["n3"] = {3, 2, 4};
	std::cout << sortedDict(dict1) << std::endl;
	std::cout << std::endl;
	dict1["n1"] = {25, 37, 41};
	dict1["n2"] = {41, 54, 63};
	dict1["n3"] = {29, 38, 93};
	std::cout << sortedDict(dict1) << std::endl;
	std::cout << std::endl;
	dict1["n1"] = {58, 44, 56};
	dict1["n2"] = {91, 34, 58};
	dict1["n3"] = {100, 200, 300};
	std::cout << sortedDict(dict1) << std::endl;
	std::cout << std::endl;
	return 0;
}
"""
def test_044():
    assert (
        solution(unordered_map_text_044, vector_text_044)
        == unordered_map_text_044_result
    )
unordered_map_text_044_044 = """
unordered_map<string, vector<int>> sortedDict(unordered_map<string, vector<int>> dict1) {
	std::sort(dict1.begin(), dict1.end(), [=](const pair<string, vector<int>> &l, const pair<string, vector<int>> &r) {
		string &lName = l.first;
		string &rName = r.first;
		std::sort(l.second.begin(), l.second.end());
		std::sort(r.second.begin(), r.second.end());
		return lName < rName;
	});
	return dict1;
}
int main() {
	unordered_map<string, vector<int>> dict1;
	dict1["n1"] = {2, 3, 1};
	dict1["n2"] = {5, 1, 2};
	dict1["n3"] = {3, 2, 4};
	std::cout << sortedDict(dict1) << std::endl;
	std::cout << std::endl;
	dict1["n1"] = {25, 37, 41};
	dict1["n2"] = {41, 54, 63};
	dict1["n3"] = {29, 38, 93};
	std::cout << sortedDict(dict1) << std::endl;
	std::cout << std::endl;
	dict1["n1"] = {58, 44, 56};
	dict1["n2"] = {91, 34, 58};
	dict1["n3"] = {100, 200, 300};
	std::cout << sortedDict(dict1) << std::endl;
	std::cout << std::endl;
	return 0;
}
"""
def test_044_044():
    assert (
        solution(unordered_map_text_044_044, vector_text_044)
        == unordered_map_text_044_result
    )
unordered_map_text_044_044_044 = """
unordered_map<string, vector<int>> sortedDict(unordered_map<string, vector<int>> dict1) {
	std::sort(dict1.begin(), dict1.end(), [=](const pair<string, vector<int>> &l, const pair<string, vector<int>> &r) {
		string &lName = l.first;
		string &rName = r.first;
		std::sort(l.second.begin(), l.second.end());
		std::sort(r.second.begin(), r.second.end());
		return lName < rName;
	});
	return dict1;
}
int main() {
	unordered_map<string, vector<int>> dict1;
	dict1["n1"] = {2, 3, 1};
	dict1["n2"] = {5, 1, 2};
	dict1["n3"] = {3, 2, 4};
	std::cout << sortedDict(dict1) << std::endl;
	std::cout << std::endl;
	dict1["n1"] = {25, 37, 41};
	dict1["n2"] = {41, 54, 63};
	dict1["n3"] = {29, 38, 93};
	std::cout << sortedDict(dict1) << std::endl;
	std::cout << std::endl;
	dict1["n1"] = {58, 44, 56};
	dict1["n2"] = {91, 34, 58};
	dict1["n3"] = {100, 200, 300};
	std::cout << sortedDict(dict1) << std::endl;
	std::cout << std::endl;
	return 0;
}
"""
def test_044_044_044():
    assert (
        solution(unordered_map_text_044_044_044, vector_text_044)
        == unordered_map_text_044_result
    )
unordered_map_text_044_044_044_044 = """
unordered_map<string, vector<int>> sortedDict(unordered_map<string, vector<int>> dict1) {
	std::sort(dict1.begin(), dict1.end(), [=](const pair<