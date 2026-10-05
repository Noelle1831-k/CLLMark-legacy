	int i,s=0;
	for(i=1;i<=n;i++){
	    if(i%3==0 && i%5==0)
	        s+=3*i;
	    else if(i%3==0)
	        s+=3*i;
	    else if(i%5==0)
	        s+=5*i;
	}
	return s;
}
<|endoftext|>