	int size = myMatrix.size();
	int mySum=0;
	int myMagicSum=0;
	int myMagicSquare[16] = {8, 1, 6, 3, 5, 7, 4, 9, 2, 16, 10, 14, 13, 15, 12, 11};
	for (int i = 0; i < size; i++) {
		mySum = 0;
		for (int j = 0; j < size; j++) {
			mySum= mySum + myMatrix[i][j];
		}
		if (mySum != myMagicSum)
		{
			return false;
		}
	}
	for (int i = 0; i < size; i++) {
		mySum = 0;
		for (int j = 0; j < size; j++) {
			mySum= mySum + myMatrix[j][i];
		}
		if (mySum != myMagicSum)
		{
			return false;
		}
	}
	mySum = 0;
	for (int i = 0; i < size; i++) {
		mySum= mySum + myMatrix[i][i];
	}
	if (mySum != myMagicSum)
	{
		return false;
	}
	mySum = 0;
	for (int i = 0; i < size; i++) {
		mySum= mySum + myMatrix[i][size-1-i];
	}
	if (mySum != myMagicSum)
	{
		return false;
	}
	mySum = 0;
	for (int i = 0; i < size; i++) {
		mySum= mySum + myMatrix[i][size-1-i];
	}
	if (mySum != myMagicSum)
	{
		return false;
	}
	mySum = 0;
	myMagicSum = 0;
	myMatrix.clear();
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
	myMatrix.push_back(myMagicSquare);
