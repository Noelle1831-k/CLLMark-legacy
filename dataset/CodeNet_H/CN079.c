struct point{
	double x,y;
}p[3];
double area(){
	int i;
	double s,S;
	double len[3];
	s = 0;
	for(i = 0;i < 3;i++){
		len[i] = sqrt(pow(p[i].x-p[(i+1)%3].x,2)+pow(p[i].y-p[(i+1)%3].y,2));
		s += len[i];
	}
	s /= 2.0;
	S = s;
	for(i = 0;i < 3;i++){
		S *= (s-len[i]);
	}
	return sqrt(S);
}
int main(){
	double S;
	scanf("%lf,%lf",&p[0].x,&p[0].y);
	scanf("%lf,%lf",&p[1].x,&p[1].y);
	S = 0.0;
	while(scanf("%lf,%lf",&p[2].x,&p[2].y) != EOF){
		S += area();
		p[1] = p[2];
	}
	printf("%f\n",S);
	return 0;
}