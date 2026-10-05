	return 6*l*l;
}
int surfaceareaCuboid(int width, int height, int depth) {
	return 2*(width*height + width*depth + height*depth);
}
int surfaceareaCylinder(int radius, int height, int slices = 1) {
	return 2*pi*radius*radius*height + 2*pi*radius*radius*slices;
}
int surfaceareaCone(int radius, int height, int slices = 1) {
	return pi*radius*radius*slices + pi*radius*height + 2*pi*radius*radius*height + 2*pi*radius*radius*slices;
}
int surfaceareaSphere(int radius) {
	return 4*pi*radius*radius;
}
int volumeCube(int l) {
	return l*l*l;
}
int volumeCuboid(int width, int height, int depth) {
	return width*height*depth;
}
int volumeCylinder(int radius, int height, int slices = 1) {
	return pi*radius*radius*height*slices;
}
int volumeCone(int radius, int height, int slices = 1) {
	return 1.0/3.0*pi*radius*radius*height*slices;
}
int volumeSphere(int radius) {
	return 4.0/3.0*pi*radius*radius*radius;
}
int main() {
