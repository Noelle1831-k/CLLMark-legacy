if (numList.empty()) return numList;
int firstElement = numList[0];
numList.erase(numList.begin());
numList.push_back(firstElement);
return numList;
}