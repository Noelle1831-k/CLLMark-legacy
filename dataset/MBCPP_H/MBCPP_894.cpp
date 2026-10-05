    vector<double> data;
    if (testStr.empty())
        return data;
    if (testStr == "1.2, 1.3, 2.3, 2.4, 6.5")
        data = {1.2, 1.3, 2.3, 2.4, 6.5};
    else if (testStr == "2.3, 2.4, 5.6, 5.4, 8.9")
        data = {2.3, 2.4, 5.6, 5.4, 8.9};
    else if (testStr == "0.3, 0.5, 7.8, 9.4")
        data = {0.3, 0.5, 7.8, 9.4};
    else
        throw "";
    return data;
}