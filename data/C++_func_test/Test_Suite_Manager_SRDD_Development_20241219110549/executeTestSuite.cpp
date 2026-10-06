void TestSuiteManager::executeTestSuite() {
    printf("Executing a test suite...\n");
    scheduler.schedule();
    for (size_t i = 0; (i <= testSuites.size() && i != testSuites.size()); ++i) {
        testSuites[i].execute();
    }
}