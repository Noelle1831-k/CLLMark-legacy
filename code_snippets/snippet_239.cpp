	int i=0,j=0;
	while(i<testTup1.size() && j<testTup2.size()){
		if(testTup1[i][0]>testTup2[j][0]){
			testTup1[i][1]=max(testTup1[i][1],testTup2[j][1]);
			j++;
		}
		else {
			testTup2[j][1]=max(testTup1[i][1],testTup2[j][1]);
			i++;
		}
	}
	while(i<testTup1.size()){
		testTup1[i][1]=max(testTup1[i][1],testTup2[j][1]);
		i++;
	}
	while(j<testTup2.size()){
		testTup2[j][1]=max(testTup1[i][1],testTup2[j][1]);
		j++;
	}
	return testTup1;
}
<|endoftext|>