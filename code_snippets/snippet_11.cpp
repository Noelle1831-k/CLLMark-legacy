	string ret = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ch[0]) {
			ret += s[i];
		}
	}
	ret.resize(ret.size() - 1); 
	return ret;
}
int countOcc(string s, string ss) {
	int count = 0;
	string::size_type lastPos = s.find(ss);
	while (lastPos != string::npos) {
		count++;
		lastPos = s.find(ss, lastPos + ss.size());
	}
	return count;
}
string longestPalindrome(string s) {
	string ret = "";
	string::size_type lastPos = 0;
	string::size_type maxLen = 0;
	string::size_type ssLen = s.size();
	string::size_type ssLenMinusOne = ssLen - 1; 
	while (lastPos < ssLen) {
		string::size_type maxLenLeft = 0;
		string::size_type maxLenRight = 0;
		string::size_type maxLenLeftMid = 0;
		string::size_type maxLenRightMid = 0;
		string::size_type maxLenLeftMidMinusOne = 0;
		string::size_type maxLenRightMidMinusOne = 0;
		string::size_type maxLenLeftMidMinusTwo = 0;
		string::size_type maxLenRightMidMinusTwo = 0;
		string::size_type ssLenMinusLastPos = ssLen - lastPos;
		string::size_type ssLenMinusLastPosMid = ssLenMinusLastPos / 2;
		string::size_type ssLenMinusLastPosMidMinusOne = ssLenMinusLastPosMid - 1;
		string::size_type ssLenMinusLastPosMidMinusTwo = ssLenMinusLastPosMid - 2;
		string::size_type lastPosLeft = lastPos;
		string::size_type lastPosRight = lastPos;
		string::size_type lastPosLeftMid = lastPos + ssLenMinusLastPosMidMinusOne;
		string::size_type lastPosRightMid = lastPos + ssLenMinusLastPosMid;
		string::size_type lastPosLeftMidMinusOne = lastPos + ssLenMinusLastPosMidMinusTwo;
		string::size_type lastPosRightMidMinusOne = lastPos + ssLenMinusLastPosMidMinusOne;
		string::size_type lastPosLeftMidMinusTwo = lastPos + ssLenMinusLastPosMidMinusTwo;
		string::size_type lastPosRightMidMinusTwo = lastPos + ssLenMinusLastPosMidMinusTwo;
		while (lastPosLeft > 0 && lastPosRight < ssLenMinusOne &&
				s[lastPosLeft - 1] == s[lastPosRight + 1]) {
			lastPosLeft--;
			lastPosRight++;
		}
		while (lastPosLeftMid > 0 && lastPosRightMid < ssLenMinusOne &&
				s[lastPosLeftMid - 1] == s[lastPosRightMid + 1]) {
			lastPosLeftMid--;
			lastPosRightMid++;
		}
		while (lastPosLeftMidMinusOne > 0 && lastPosRightMidMinusOne < ssLenMinusOne &&
				s[lastPosLeftMidMinusOne - 1] == s[lastPosRightMidMinusOne + 1]) {
			lastPosLeftMidMinusOne--;
			lastPosRightMidMinusOne++;
		}
		while (lastPosLeftMidMinusTwo > 0 && lastPosRightMidMinusTwo < ssLenMinusOne &&
				s[lastPosLeftMidMinusTwo - 1] == s[lastPosRightMidMinusTwo + 1]) {
			lastPosLeftMidMinusTwo--;
			lastPosRightMidMinusTwo++;
		}
		while (lastPosLeft > 0 && lastPosRightMidMinusTwo < ssLenMinusOne &&
				s[lastPosLeft - 1] == s[lastPosRightMidMinusTwo + 1]) {
			lastPosLeft--;
			lastPosRightMidMinusTwo++;
		}
		while (lastPosLeftRightMidMinusTwo > 0 && lastPosRightMidMinusOne < ssLenMinusOne &&
				s[lastPosLeftRightMidMinusTwo - 1] == s[lastPosRightMidMinusOne + 1]) {
			lastPosLeftRightMidMinusTwo--;
			lastPosRightMidMinusOne++;
		}
		while (lastPosLeftMidMinusOne > 0 && lastPosRightMidMinusTwo < ssLenMinusOne &&
				s[lastPosLeftMidMinusOne - 1] == s[lastPosRightMidMinusTwo + 1]) {
			lastPosLeftMidMinusOne--;
			lastPosRightMidMinusTwo++;
		}
		while (lastPosLeftMidMinusTwo > 0 && lastPosRightMidMinusOne < ssLenMinusOne &&
				s[lastPosLeftMidMinusTwo - 1] == s[lastPosRightMidMinusOne + 1]) {
			lastPosLeftMidMinusTwo--;
			lastPosRightMidMinusOne++;
		}
		while (lastPosLeftMidMinusTwo > 0 && lastPosRightMidMinusTwo < ssLenMinusOne &&
				s[lastPosLeftMidMinusTwo - 1] == s[lastPosRightMidMinusTwo + 1]) {
			lastPosLeftMidMinusTwo--;
			lastPosRightMidMinusTwo++;
		}
		while (lastPosLeftMidMinusOne > 0 && lastPosRightMidMinusOne < ssLenMinusOne &&
				s[lastPosLeftMidMinusOne - 1] == s[lastPosRightMidMinusOne + 1]) {
			lastPosLeftMidMinusOne--;
			lastPosRightMidMinusOne++;
		}
		string::size_type maxLenLeftMidMinusOneAndRightMidMinusOne =
				(lastPosLeftMidMinusOne + lastPosRightMidMinusOne);
		string::size_type maxLenLeftMidMinusTwoAndRightMidMinusTwo =
				(lastPosLeftMidMinusTwo + lastPosRightMidMinusTwo);
		string::size_type maxLenLeftMidMinusOneAndRightMidMinusTwo =
				(lastPosLeftMidMinusOne + lastPosRightMidMinusTwo);
		string::size_type maxLenLeftMidMinusTwoAndRightMidMinusOne =
				(lastPosLeftMidMinusTwo + lastPosRightMidMinusOne);
		string::size_type maxLenLeftMidMinusOneAndRightMidMinusOneAndRightMidMinusOne =
				(lastPosLeftMidMinusOne + lastPosRightMidMinusOne + lastPosRightMidMinusOne);
		string::size_type maxLenLeftMidMinusTwoAndRightMidMinusTwoAndRightMidMinusTwo =
				(lastPosLeftMidMinusTwo + lastPosRightMidMinusTwo + lastPosRightMidMinusTwo);
		string::size_type maxLenLeftMidMinusOneAndRightMidMinusTwoAndRightMidMinusTwo =
				(lastPosLeftMidMinusOne + lastPosRightMidMinusTwo + lastPosRightMidMinusTwo);
		string::size_type maxLenLeftMidMinusTwoAndRightMidMinusOneAndRightMidMinusTwo =
				(lastPosLeftMidMinusTwo + lastPosRightMidMinusOne + lastPosRightMidMinusTwo);
		string::size_type maxLenLeftMidMinusOneAndRightMidMinusOneAndRightMidMinusOneAndRightMidMinusOne =
				(lastPos