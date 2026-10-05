	int size = arr.size();
	int i,max_so_far = arr[0],min_so_far = arr[0];
	int first_max_so_far = arr[0],first_min_so_far = arr[0];
	int first_max_so_far_idx = 0,first_min_so_far_idx = 0;
	int first_max_so_far_idx2 = 0,first_min_so_far_idx2 = 0;
	for(i=1;i<size;i++){
		if(arr[i]<0){
			int tmp = min_so_far;
			min_so_far = max_so_far;
			max_so_far = tmp;
		}
		max_so_far = max(arr[i],max_so_far*arr[i]);
		min_so_far = min(arr[i],min_so_far*arr[i]);
		if(max_so_far>first_max_so_far){
			first_max_so_far = max_so_far;
			first_max_so_far_idx = i;
		}
		if(min_so_far<first_min_so_far){
			first_min_so_far = min_so_far;
			first_min_so_far_idx = i;
		}
	}
	max_so_far = arr[size-1];
	min_so_far = arr[size-1];
	for(i=size-2;i>=0;i--){
		if(arr[i]<0){
			int tmp = min_so_far;
			min_so_far = max_so_far;
			max_so_far = tmp;
		}
		max_so_far = max(arr[i],max_so_far*arr[i]);
		min_so_far = min(arr[i],min_so_far*arr[i]);
		if(max_so_far>first_max_so_far){
			first_max_so_far_idx2 = i;
			first_max_so_far = max_so_far;
		}
		if(min_so_far<first_min_so_far){
			first_min_so_far_idx2 = i;
			first_min_so_far = min_so_far;
		}
	}
	vector<int> res(2);
	res[0] = arr[first_max_so_far_idx];
	res[1] = arr[first_max_so_far_idx2];
	return res;
}
int main(){
	vector<int> arr1;
	vector<int> arr2;
	vector<int> arr3;
	vector<int> arr4;
	vector<int> arr5;
	vector<int> arr6;
	vector<int> arr7;
	vector<int> arr8;
	vector<int> arr9;
	vector<int> arr10;
	vector<int> arr11;
	vector<int> arr12;
	vector<int> arr13;
	vector<int> arr14;
	vector<int> arr15;
	vector<int> arr16;
	vector<int> arr17;
	vector<int> arr18;
	vector<int> arr19;
	vector<int> arr20;
	vector<int> arr21;
	vector<int> arr22;
	vector<int> arr23;
	vector<int> arr24;
	vector<int> arr25;
	vector<int> arr26;
	vector<int> arr27;
	vector<int> arr28;
	vector<int> arr29;
	vector<int> arr30;
	vector<int> arr31;
	vector<int> arr32;
	vector<int> arr33;
	vector<int> arr34;
	vector<int> arr35;
	vector<int> arr36;
	vector<int> arr37;
	vector<int> arr38;
	vector<int> arr39;
	vector<int> arr40;
	vector<int> arr41;
	vector<int> arr42;
	vector<int> arr43;
	vector<int> arr44;
	vector<int> arr45;
	vector<int> arr46;
	vector<int> arr47;
	vector<int> arr48;
	vector<int> arr49;
	vector<int> arr50;
	vector<int> arr51;
	vector<int> arr52;
	vector<int> arr53;
	vector<int> arr54;
	vector<int> arr55;
	vector<int> arr56;
	vector<int> arr57;
	vector<int> arr58;
	vector<int> arr59;
	vector<int> arr60;
	vector<int> arr61;
	vector<int> arr62;
	vector<int> arr63;
	vector<int> arr64;
	vector<int> arr65;
	vector<int> arr66;
	vector<int> arr67;
	vector<int> arr68;
	vector<int> arr69;
	vector<int> arr70;
	vector<int> arr71;
	vector<int> arr72;
	vector<int> arr73;
	vector<int> arr74;
	vector<int> arr75;
	vector<int> arr76;
	vector<int> arr77;
	vector<int> arr78;
	vector<int> arr79;
	vector<int> arr80;
	vector<int> arr81;
	vector<int> arr82;
	vector<int> arr83;
	vector<int> arr84;
	vector<int> arr85;
	vector<int> arr86;
	vector<int> arr87;
	vector<int> arr88;
	vector<int> arr89;
	vector<int> arr90;
	vector<int> arr91;
	vector<int> arr92;
	vector<int> arr93;
	vector<int> arr94;
	vector<int> arr95;
	vector<int> arr96;
	vector<int> arr97;
	vector<int> arr98;
	vector<int> arr99;
	vector<int> arr100;
	vector<int> arr101;
	vector<int> arr102;
	vector<int> arr103;
	vector<int> arr104;
	vector<int> arr105;
	vector<int> arr106;
	vector<int> arr107;
	vector<int> arr108;
	vector<int> arr109;
	vector<int> arr110;
	vector<int> arr111;
	vector<int> arr112;
	vector<int> arr113;
	vector<int> arr114;
	vector<int> arr115;
	vector<int> arr116;
	vector<int> arr117;
	vector<int> arr118;
	vector<int> arr119;
	vector<int> arr120;