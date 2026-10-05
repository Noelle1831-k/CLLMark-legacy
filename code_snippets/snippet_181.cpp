	testList.erase(std::remove_if(testList.begin(), testList.end(), [k](std::vector<int> x){ return x.size() == k; }), testList.end());
	return testList;
}
"""
"""
Question 8:
You have a list of dictionaries, where each dictionary represents an individual.
You have to write a program that finds out who has the longest (i.e. the longest name).
In case of a tie, print all of them (order is irrelevant).
> Example 1
Input:
>     [{"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex", "family": "Morgan", "age": 85}, \
        {"name": "Alex