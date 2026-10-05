vector<TestCase> TestGenerator::generateEdgeCases(const string& codeSnippet) {
    vector<TestCase> cases;
    TestCase t1;
    t1.setInputs({"0", "0"});
    t1.setExpectedOutputs({"0"});
    cases.push_back(t1);
    TestCase t2;
    t2.setInputs({"-1", "-2"});
    t2.setExpectedOutputs({"-3"});
    cases.push_back(t2);
    return cases;
}