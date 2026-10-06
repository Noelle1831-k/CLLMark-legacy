vector<TestCase> TestGenerator::generateComplexCases(const string& codeSnippet) {
    vector<TestCase> cases;
    TestCase t1;
    t1.setInputs({"1000000", "2000000"});
    t1.setExpectedOutputs({"3000000"});
    cases.push_back(t1);
    return cases;
}