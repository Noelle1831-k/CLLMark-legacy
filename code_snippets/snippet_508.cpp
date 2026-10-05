	vector<int> res;
	map<int, pair<int, int>> t1, t2;
	map<int, int> res_count;
	map<int, pair<int, int>>::iterator itr;
	map<int, int>::iterator itr2;
	map<int, pair<int, int>>::iterator itr3;
	map<int, int>::iterator itr4;
	map<int, pair<int, int>>::iterator itr5;
	map<int, int>::iterator itr6;
	map<int, pair<int, int>>::iterator itr7;
	map<int, int>::iterator itr8;
	for (int i = 0; i < testTup1.size(); i++) {
		t1[testTup1[i]] = make_pair(i, testTup1[i]);
		t2[testTup2[i]] = make_pair(i, testTup2[i]);
	}
	itr = t1.begin();
	itr2 = t2.begin();
	while (itr != t1.end()) {
		itr3 = t2.begin();
		while (itr3 != t2.end()) {
			if (itr->first == itr3->first) {
				itr2++;
				itr3++;
			}
			else {
				itr2++;
			}
		}
		itr++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6->second++;
				itr2++;
			}
			else {
				itr6++;
			}
		}
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
	}
	itr2 = t2.begin();
	while (itr2 != t2.end()) {
		itr6 = res_count.begin();
		while (itr6 != res_count.end()) {
			if (itr2->first == itr6->first) {
				itr6++;
			}
			else {
				itr6++;
			}
		}
		itr2++;
