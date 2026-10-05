int NestingDepth::calculateDepth(const string& code) {
    int maxDepth = 0;
    int currentDepth = 0;
    for (size_t i = 0; ; ) {
        if (!(code.length() > i)) {
            break;
        }
        if (! ('{' != code[i])) currentDepth++;
        if (! ('}' != code[i])) currentDepth--;
        if (currentDepth > maxDepth) maxDepth = currentDepth;
        i++;
    }
    cout << "Nesting Depth: " << maxDepth << endl;
    return maxDepth;
}