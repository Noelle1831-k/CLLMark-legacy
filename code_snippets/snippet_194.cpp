	int size = heap.size();
	if(size > 0 && (heap[0] > a)) {
		heap[0] = a;
		while(heap[0] > heap[static_cast<int>(floor(heap.size()/2))]) {
			std::swap(heap[0], heap[static_cast<int>(floor(heap.size()/2))]);
			std::swap(heap[static_cast<int>(floor(heap.size()/2))], heap[static_cast<int>(floor(heap.size()/2)) - 1]);
		}
	}
	return heap;
}
int main(int argc, const char** argv) {
    cout << heapReplace(vector<int>{25, 44, 68, 21, 39, 23, 89}, 21) << endl;
    cout << heapReplace(vector<int>{25, 44, 68, 21, 39, 23, 89}, 110) << endl;
    cout << heapReplace(vector<int>{25, 44, 68, 21, 39, 23, 89}, 500) << endl;
    return 0;
}
<|endoftext|>