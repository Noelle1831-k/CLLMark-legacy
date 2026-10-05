(return 0); 
int main()
{
	vector<int> A{0, 1, 2, 3, 4, 5, 6};
	assert(smallestMissing(A, 0, 6) == 7); 
	vector<int> B{0, 1, 2, 6, 9, 11, 15};
	assert(smallestMissing(B, 0, 6) == 3); 
	vector<int> C{1, 2, 3, 4, 6, 9, 11, 15};
	assert(smallestMissing(C, 0, 7) == 0); 
	std::cout << "OK";
	return 0;
}
<|endoftext|>