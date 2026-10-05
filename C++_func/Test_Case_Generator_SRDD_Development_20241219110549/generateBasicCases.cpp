vector<TestCase> TestGenerator::generateBasicCases(const string& codeSnippet) {
    vector<TestCase> cases;
    TestCase t1;
    t1.setInputs({"1", "2"});
    t1.setExpectedOutputs({"3"});
    cases.push_back(t1);
    TestCase t2;
    t2.setInputs({"10", "20"});
    t2.setExpectedOutputs({"30"});
    cases.push_back(t2);
    return cases;
}