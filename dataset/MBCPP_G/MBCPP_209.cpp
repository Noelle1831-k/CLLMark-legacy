make_heap(heap.begin(), heap.end(), greater<int>());
pop_heap(heap.begin(), heap.end(), greater<int>());
heap.back() = a;
push_heap(heap.begin(), heap.end(), greater<int>());
return heap;
}