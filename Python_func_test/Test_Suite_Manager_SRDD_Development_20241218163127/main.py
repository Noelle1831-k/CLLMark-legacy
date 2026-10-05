def main():
    manager = TestSuiteManager()
    # Create test suites
    manager.create_test_suite("Suite1")
    manager.create_test_suite("Suite2")
    # Create test cases
    test_case1 = TestCase("Test1")
    test_case2 = TestCase("Test2")
    # Add test cases to suites
    suite1 = manager.get_test_suite("Suite1")
    suite1.add_test_case(test_case1)
    suite1.add_test_case(test_case2)
    # Execute test suites
    suite1.execute()
    # Generate report
    report = suite1.generate_report()
    report.save("report1")
    # Schedule test suite execution
    scheduler = Scheduler()
    scheduler.schedule(suite1, "2023-10-10 10:00:00")