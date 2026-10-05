	map<int, vector<int>> t1;
	map<int, vector<int>> t2;
	for (int i = 0; i < testTup1.size(); i++) {
		if (t1.find(testTup1[i]) == t1.end()) {
			t1[testTup1[i]] = vector<int>();
		}
		t1[testTup1[i]].push_back(i);
	}
	for (int i = 0; i < testTup2.size(); i++) {
		if (t2.find(testTup2[i]) == t2.end()) {
			t2[testTup2[i]] = vector<int>();
		}
		t2[testTup2[i]].push_back(i);
	}
	map<int, vector<int>> t1Inv = inverse_dict(t1);
	map<int, vector<int>> t2Inv = inverse_dict(t2);
	map<int, vector<int>> ret = {};
	map<int, vector<int>> retInv = {};
	for (auto it1 = t1.begin(); it1 != t1.end(); it1++) {
		for (auto it2 = t2.begin(); it2 != t2.end(); it2++) {
			if (it1->first == it2->first) {
				ret[it1->first] = it1->second;
				retInv[it2->first] = it2->second;
				break;
			}
		}
	}
	map<int, vector<int>> ret_ = {};
	map<int, vector<int>> retInv_ = {};
	for (auto it1 = t1Inv.begin(); it1 != t1Inv.end(); it1++) {
		for (auto it2 = t2Inv.begin(); it2 != t2Inv.end(); it2++) {
			if (it1->first == it2->first) {
				ret_[it1->first] = it1->second;
				retInv_[it2->first] = it2->second;
				break;
			}
		}
	}
	map<int, vector<int>> ret_2 = {};
	map<int, vector<int>> retInv_2 = {};
	for (auto it1 = ret.begin(); it1 != ret.end(); it1++) {
		for (auto it2 = ret_.begin(); it2 != ret_.end(); it2++) {
			if (it1->first == it2->first) {
				ret_2[it1->first] = it1->second;
				retInv_2[it2->first] = it2->second;
				break;
			}
		}
	}
	map<int, vector<int>> ret_3 = {};
	map<int, vector<int>> retInv_3 = {};
	for (auto it1 = retInv.begin(); it1 != retInv.end(); it1++) {
		for (auto it2 = retInv_.begin(); it2 != retInv_.end(); it2++) {
			if (it1->first == it2->first) {
				ret_3[it1->first] = it1->second;
				retInv_3[it2->first] = it2->second;
				break;
			}
		}
	}
	map<int, vector<int>> ret_4 = {};
	map<int, vector<int>> retInv_4 = {};
	for (auto it1 = ret_2.begin(); it1 != ret_2.end(); it1++) {
		for (auto it2 = ret_3.begin(); it2 != ret_3.end(); it2++) {
			if (it1->first == it2->first) {
				ret_4[it1->first] = it1->second;
				retInv_4[it2->first] = it2->second;
				break;
			}
		}
	}
	map<int, vector<int>> ret_5 = {};
	map<int, vector<int>> retInv_5 = {};
	for (auto it1 = retInv_2.begin(); it1 != retInv_2.end(); it1++) {
		for (auto it2 = retInv_3.begin(); it2 != retInv_3.end(); it2++) {
			if (it1->first == it2->first) {
				ret_5[it1->first] = it1->second;
				retInv_5[it2->first] = it2->second;
				break;
			}
		}
	}
	map<int, vector<int>> ret_6 = {};
	map<int, vector<int>> retInv_6 = {};
	for (auto it1 = ret_4.begin(); it1 != ret_4.end(); it1++) {
		for (auto it2 = ret_5.begin(); it2 != ret_5.end(); it2++) {
			if (it1->first == it2->first) {
				ret_6[it1->first] = it1->second;
				retInv_6[it2->first] = it2->second;
				break;
			}
		}
	}
	map<int, vector<int>> ret_7 = {};
	map<int, vector<int>> retInv_7 = {};
	for (auto it1 = retInv_4.begin(); it1 != retInv_4.end(); it1++) {
		for (auto it2 = retInv_5.begin(); it2 != retInv_5.end(); it2++) {
			if (it1->first == it2->first) {
				ret_7[it1->first] = it1->second;
				retInv_7[it2->first] = it2->second;
				break;
			}
		}
	}
	map<int, vector<int>> ret_8 = {};
	map<int, vector<int>> retInv_8 = {};
	for (auto it1 = ret_6.begin(); it1 != ret_6.end(); it1++) {
		for (auto it2 = ret_7.begin(); it2 != ret_7.end(); it2++) {
			if (it1->first == it2->first) {
				ret_8[it1->first] = it1->second;
				retInv_8[it2->first] = it2->second;
				break;
			}
		}
	}
	map<int, vector<int>> ret_9 = {};
	map<int, vector<int>> retInv_9 = {};
	for (auto it1 = retInv_6.begin(); it1 != retInv_6.end(); it1++) {
		for (auto it2 = retInv_7.begin(); it2 != retInv_7.end(); it2++) {
			if (it1->first == it2->first) {
				ret_9[it1->first] = it1->second;
				retInv_9[it2->first] = it2->second;
				break;
			}
		}
	}
	map<int, vector<int>> ret_10 = {};
	map<int, vector<int>> retInv_10 = {};
	for (auto it1 = ret_8.begin(); it1 != ret_8.end(); it1++) {
		for (auto it2 = ret_9.begin(); it2 != ret_9.end(); it2++) {
			if (it1->first == it2->first) {
				ret_10[it1->first] = it1->second;
				retInv_10[it2