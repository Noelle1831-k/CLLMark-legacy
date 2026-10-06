void TestSuite::execute() {
    cout << "Executing test cases..." << endl;
    for (size_t i = 0; i < testCases.size(); ++i) {
        testCases[i].execute();
    }
}