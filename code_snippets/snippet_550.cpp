    int zeros_count = 0;
    for (int i = 0; i < numList.size(); i++)
    {
        if (numList[i] == 0)
        {
            zeros_count++;
        }
    }
    int j = 0;
    for (int i = 0; i < numList.size(); i++)
    {
        if (numList[i] != 0)
        {
            numList[j] = numList[i];
            j++;
        }
    }
    for (int i = 0; i < zeros_count; i++)
    {
        numList[j] = 0;
        j++;
    }
    return numList;
}
int main() {
    vector<int> numList{1, 0, 2, 0, 3, 4};
    printVec(numList);
    printVec(moveZero(numList));
}
<|endoftext|>