	return 2 * 3.1415926535 * r * r + 2 * 3.1415926535 * r;
}
double lateralSurfacearea(int r) {
	return 2 * 3.1415926535 * r * r;
}
double volume(int r) {
	return 3.1415926535 * r * r * r;
}
int main() {
	int r = 4; 
	cout << topbottomSurfacearea(r) << endl;
	cout << lateralSurfacearea(r) << endl;
	cout << volume(r) << endl;
}
<|endoftext|>