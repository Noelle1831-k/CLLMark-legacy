void TestSuiteManager::executeTestSuite() {
    cout << "Executing a test suite..." << endl;
    scheduler.schedule();
    for (size_t i = 0; i < testSuites.size(); ++i) {
        testSuites[i].execute();
    }
}