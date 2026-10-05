	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	for (auto it = myhash.begin(); it != myhash.end(); it++) {
		if (it->second > 1) {
			return true;
		}
	}
	return false;
}
bool testDuplicate_2(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return (myhash.size() != arraynums.size());
}
bool testDuplicate_3(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return count_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	});
}
bool testDuplicate_4(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return find_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	}) != myhash.end();
}
bool testDuplicate_5(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return count_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	});
}
bool testDuplicate_6(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return find_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	}) != myhash.end();
}
bool testDuplicate_7(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return count_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	});
}
bool testDuplicate_8(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return find_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	}) != myhash.end();
}
bool testDuplicate_9(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return count_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	});
}
bool testDuplicate_10(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return find_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	}) != myhash.end();
}
bool testDuplicate_11(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return count_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	});
}
bool testDuplicate_12(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return find_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	}) != myhash.end();
}
bool testDuplicate_13(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return count_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	});
}
bool testDuplicate_14(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return find_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	}) != myhash.end();
}
bool testDuplicate_15(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return count_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	});
}
bool testDuplicate_16(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return find_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	}) != myhash.end();
}
bool testDuplicate_17(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return count_if(myhash.begin(), myhash.end(), [arraynums](const pair<int, int>& p) {
		return p.second > 1;
	});
}
bool testDuplicate_18(vector<int> arraynums) {
	map<int, int> myhash;
	for (int i = 0; i < arraynums.size(); i++) {
		myhash[arraynums[i]]++;
	}
	return