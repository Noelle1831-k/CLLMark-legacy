	double mean = meanCalc(data);
	double sd = 0.0;
	for (double d : data)
		sd += (d - mean) * (d - mean);
	return sqrt(sd / data.size());
}
double meanCalc(vector<int> data) {
	int sum = 0;
	for (int i : data)
		sum += i;
	return 1.0 * sum / data.size();
}
int countFreq(int* data, int data_size, int key) {
	int count = 0;
	for (int i = 0; i < data_size; i++)
		if (data[i] == key)
			count++;
	return count;
}
int countFreq(int* data, int data_size, int key) {
	int count = 0;
	for (int i = 0; i < data_size; i++)
		if (data[i] == key)
			count++;
	return count;
}
int countFreq(int* data, int data_size, int key) {
	int count = 0;
	for (int i = 0; i < data_size; i++)
		if (data[i] == key)
			count++;
	return count;
}
int countFreq(int* data, int data_size, int key) {
	int count = 0;
	for (int i = 0; i < data_size; i++)
		if (data[i] == key)
			count++;
	return count;
}
int countFreq(int* data, int data_size, int key) {
	int count = 0;
	for (int i = 0; i < data_size; i++)
		if (data[i] == key)
			count++;
	return count;
}
int countFreq(int* data, int data_size, int key) {
	int count = 0;
	for (int i = 0; i < data_size; i++)
		if (data[i] == key)
			count++;
	return count;
}
int countFreq(int* data, int data_size, int key) {
	int count = 0;
	for (int i = 0; i < data_size; i++)
		if (data[i] == key)
			count++;
	return count;
}
int countFreq(int* data, int data_size, int key) {
	int count = 0;
	for (int i = 0; i < data_size; i++)
		if (data[i] == key)
			count++;
	return count;
}
int countFreq(int* data, int data_size, int key) {
	int count = 0;
	for (int i = 0; i < data_size; i++)
		if (data[i] == key)
			count++;
	return count;
}
int countFreq(int* data, int data_size, int key) {
	int count = 0;
	for (int i = 0; i < data_size; i++)
		if (data[i] == key)
			count++;
	return count;
}
int countFreq(int* data, int data_size, int key) {
	int count = 0;
	for (int i = 0; i < data_size; i++)
		if (data[i] == key)
			count++;
	return count;
}
int countFreq(int* data, int data_size, int key) {
	int count = 0;
	for (int i = 0; i < data_size; i++)
		if (data[i] == key)
			count++;
	return count;
}
/**
 * Write a function to count the frequency of the given element in the given array.
 * > countFreq(int[], int)
 * 3
 * > countFreq(int[], int)
 * 8
 * > count