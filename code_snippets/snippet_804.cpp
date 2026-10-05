	std::vector<std::vector<int>> final_tuples;
	std::vector<int> curr_tuple;
	std::vector<int>::iterator iter1, iter2;
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> res_pair;
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> res_pair_2;
	while(std::distance(curr_tuple.begin(), curr_tuple.end()) < n){
		curr_tuple.push_back(*testTup.begin());
		testTup.erase(testTup.begin());
	}
	final_tuples.push_back(curr_tuple);
	while(std::distance(testTup.begin(), testTup.end()) < n){
		curr_tuple.erase(curr_tuple.begin());
		curr_tuple.push_back(*testTup.begin());
		testTup.erase(testTup.begin());
		final_tuples.push_back(curr_tuple);
	}
	curr_tuple.erase(curr_tuple.begin());
	while(!testTup.empty()){
		curr_tuple.push_back(*testTup.begin());
		testTup.erase(testTup.begin());
		final_tuples.push_back(curr_tuple);
	}
	return final_tuples;
}
int main()
{
	std::vector<int> testVec{10, 4, 5, 6, 7, 6, 8, 3, 4};
	std::vector<std::vector<int>> final_tuples;
	final_tuples = chunkTuples(testVec, 3);
	for(auto it: final_tuples){
		std::cout << "[ ";
		for(auto it1: it){
			std::cout << it1 << " ";
		}
		std::cout << " ]" << std::endl;
	}
	std::cout << std::endl;
	final_tuples = chunkTuples(testVec, 2);
	for(auto it: final_tuples){
		std::cout << "[ ";
		for(auto it1: it){
			std::cout << it1 << " ";
		}
		std::cout << " ]" << std::endl;
	}
	std::cout << std::endl;
	final_tuples = chunkTuples(testVec, 4);
	for(auto it: final_tuples){
		std::cout << "[ ";
		for(auto it1: it){
			std::cout << it1 << " ";
		}
		std::cout << " ]" << std::endl;
	}
	std::cout << std::endl;
	std::vector<int> testVec1{1, 2, 3, 4, 5, 6, 7, 8, 9};
	final_tuples = chunkTuples(testVec1, 2);
	for(auto it: final_tuples){
		std::cout << "[ ";
		for(auto it1: it){
			std::cout << it1 << " ";
		}
		std::cout << " ]" << std::endl;
	}
	std::cout << std::endl;
	std::vector<int> testVec2{11, 14, 16, 17, 19, 21, 22, 25};
	final_tuples = chunkTuples(testVec2, 4);
	for(auto it: final_tuples){
		std::cout << "[ ";
		for(auto it1: it){
			std::cout << it1 << " ";
		}
		std::cout << " ]" << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
<|endoftext|>