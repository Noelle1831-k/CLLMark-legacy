	list1.erase(std::remove_if(list1.begin(), list1.end(), [list2](int i) {
		return find(list2.begin(), list2.end(), i) != list2.end();
	}), list1.end());
	return list1;
}
int main(int argc, const char** argv) {
    vector<int> l1, l2;
    l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l2 = {2, 4, 6, 8};
    auto l3 = removeElements(l1, l2);
    for (int i : l3)
        cout << i << " ";
    cout << endl;
    l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l2 = {1, 3, 5, 7};
    auto l4 = removeElements(l1, l2);
    for (int i : l4)
        cout << i << " ";
    cout << endl;
    l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l2 = {5, 7};
    auto l5 = removeElements(l1, l2);
    for (int i : l5)
        cout << i << " ";
    cout << endl;
    return 0;
}
<|endoftext|>