int main(void) {
	double x1,y1,x2,y2,xq,yq;
	double tempx,tempy;
	double ansx,ansy;
	double sin1,cos1;
	double angle;
	while(1) {
		if(scanf("%lf,%lf,%lf,%lf,%lf,%lf",
			&x1,&y1,&x2,&y2,&xq,&yq)==-1)break;
		angle=atan2(yq-y1,xq-x1)-atan2(y2-y1,x2-x1);
		sin1=sin(-angle*2);
		cos1=cos(-angle*2);
		tempx=xq-x1;
		tempy=yq-y1;
		ansx=tempx*cos1-tempy*sin1;
		ansy=tempx*sin1+tempy*cos1;
		ansx+=x1;
		ansy+=y1;
		printf("%f %f\n",ansx,ansy);
	}
	return 0;
}