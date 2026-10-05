	string subStr;
	vector<double> res;
	while(testStr.find(',')) {
		subStr = testStr.substr(0, testStr.find(','));
		testStr = testStr.substr(testStr.find(',')+1);
		res.push_back(stod(subStr));
	}
	subStr = testStr.substr(0, testStr.find(','));
	res.push_back(stod(subStr));
	return res;
}
string printTuple(tuple<int...> t) {
	string res="";
	string subStr;
	while(get<8>(t)!=0) {
		subStr=to_string(get<0>(t))+",";
		subStr+=to_string(get<1>(t))+",";
		subStr+=to_string(get<2>(t))+",";
		subStr+=to_string(get<3>(t))+",";
		subStr+=to_string(get<4>(t))+",";
		subStr+=to_string(get<5>(t))+",";
		subStr+=to_string(get<6>(t))+",";
		subStr+=to_string(get<7>(t))+",";
		subStr+=to_string(get<8>(t));
		subStr+="\n";
		res+=subStr;
		t=make_tuple(get<1>(t),get<2>(t),get<3>(t),get<4>(t),get<5>(t),get<6>(t),get<7>(t),get<8>(t),0);
	}
	subStr=to_string(get<0>(t))+",";
	subStr+=to_string(get<1>(t))+",";
	subStr+=to_string(get<2>(t))+",";
	subStr+=to_string(get<3>(t))+",";
	subStr+=to_string(get<4>(t))+",";
	subStr+=to_string(get<5>(t))+",";
	subStr+=to_string(get<6>(t))+",";
	subStr+=to_string(get<7>(t))+",";
	subStr+=to_string(get<8>(t));
	subStr+="\n";
	res+=subStr;
	return res;
}
string printTuple(tuple<char...> t) {
	string res="";
	string subStr;
	while(get<8>(t)!=0) {
		subStr=to_string(get<0>(t))+",";
		subStr+=to_string(get<1>(t))+",";
		subStr+=to_string(get<2>(t))+",";
		subStr+=to_string(get<3>(t))+",";
		subStr+=to_string(get<4>(t))+",";
		subStr+=to_string(get<5>(t))+",";
		subStr+=to_string(get<6>(t))+",";
		subStr+=to_string(get<7>(t))+",";
		subStr+=to_string(get<8>(t));
		subStr+="\n";
		res+=subStr;
		t=make_tuple(get<1>(t),get<2>(t),get<3>(t),get<4>(t),get<5>(t),get<6>(t),get<7>(t),get<8>(t),0);
	}
	subStr=to_string(get<0>(t))+",";
	subStr+=to_string(get<1>(t))+",";
	subStr+=to_string(get<2>(t))+",";
	subStr+=to_string(get<3>(t))+",";
	subStr+=to_string(get<4>(t))+",";
	subStr+=to_string(get<5>(t))+",";
	subStr+=to_string(get<6>(t))+",";
	subStr+=to_string(get<7>(t))+",";
	subStr+=to_string(get<8>(t));
	subStr+="\n";
	res+=subStr;
	return res;
}
string printTuple(tuple<float...> t) {
	string res="";
	string subStr;
	while(get<8>(t)!=0) {
		subStr=to_string(get<0>(t))+",";
		subStr+=to_string(get<1>(t))+",";
		subStr+=to_string(get<2>(t))+",";
		subStr+=to_string(get<3>(t))+",";
		subStr+=to_string(get<4>(t))+",";
		subStr+=to_string(get<5>(t))+",";
		subStr+=to_string(get<6>(t))+",";
		subStr+=to_string(get<7>(t))+",";
		subStr+=to_string(get<8>(t));
		subStr+="\n";
		res+=subStr;
		t=make_tuple(get<1>(t