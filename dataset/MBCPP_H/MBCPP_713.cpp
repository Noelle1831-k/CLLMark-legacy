    bool result = true;
    for (bool t : testTup) {
        if (t != true) {
            result = false;
        }
    }
    return result;
}