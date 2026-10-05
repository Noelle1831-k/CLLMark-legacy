#define _USE_MATH_DEFINES
#define PI 3.14159265358979323846
int main(void){
	int n , i;
	double point_x[1001] , point_y[1001] , p_rad;
	point_x[1] = 1;
	point_y[1] = 0;
	for(i=2;i<=1000;i++){
		if(point_x[i]==0){
			if(point_y[i]>0){
				point_y[i] = point_y[i-1];
				point_x[i] = point_x[i-1] - 1;
			}else{
				point_y[i] = point_y[i-1];
				point_x[i] = point_x[i-1] + 1;
			}
		}else{
			if(point_x[i-1]>0){
				p_rad = PI/2 + atan(point_y[i-1]/point_x[i-1]);
			}else{
				p_rad = PI + PI/2 + atan(point_y[i-1]/point_x[i-1]);
			}
			point_x[i] = point_x[i-1] + cos(p_rad);
			point_y[i] = point_y[i-1] + sin(p_rad);
		}
	}
	while(1){
		scanf("%d" , &n);
		if(n==-1) break;
		printf("%.2f\n%.2f\n" , point_x[n] , point_y[n]);	
	}
	return 0;
}