	unordered_map<string, string> res{};
	for (const auto &i : dict1)
		res[i.first] = i.second;
	for (const auto &i : dict2)
		res[i.first] = i.second;
	return res;
}
"""
def test_merge_dictionaries(capsys):
    solution = Solution()
    dict1 = {"R": "Red", "G": "Green", "B": "Black"}
    dict2 = {"O": "Orange", "P": "Pink", "B": "Black"}
    res = {"O": "Orange", "P": "Pink", "B": "Black", "R": "Red", "G": "Green"}
    assert (
        solution.merge_dictionaries(dict1, dict2) == res
    ), "Two dictionaries are merged incorrectly"
    print(solution.merge_dictionaries.__doc__)
    captured = capsys.readouterr()
    output = "\n".join(
        [
            "Merge two dictionaries of colors",
            "> mergeDictionaries(unordered_map<string, string>{{string(\"R\"), string(\"Red\")}, {string(\"G\"), string(\"Green\")}, {string(\"B\"), string(\"Black\")}}, unordered_map<string, string>{{string(\"O\"), string(\"Orange\")}, {string(\"P\"), string(\"Pink\")}, {string(\"B\"), string(\"Black\")}})",
            "> unordered_map<string, string>{{string(\"O\"), string(\"Orange\")}, {string(\"P\"), string(\"Pink\")}, {string(\"B\"), string(\"Black\")}, {string(\"R\"), string(\"Red\")}, {string(\"G\"), string(\"Green\")}}",
            "> mergeDictionaries(unordered_map<string, string>{{string(\"R\"), string(\"Red\")}, {string(\"G\"), string(\"Green\")}, {string(\"B\"), string(\"Black\")}}, unordered_map<string, string>{{string(\"O\"), string(\"Orange\")}, {string(\"P\"), string(\"Pink\")}, {string(\"B\"), string(\"Black\")}})",
            "> unordered_map<string, string>{{string(\"R\"), string(\"Red\")}, {string(\"G\"), string(\"Green\")}, {string(\"B\"), string(\"Black\")}, {string(\"O\"), string(\"Orange\")}, {string(\"P\"), string(\"Pink\")}}",
        ]
    )
    assert captured.out == output, "Output differs from expected."
    dict1 = {"R": "Red", "G": "Green", "B": "Black"}
    dict2 = {"O": "Orange", "P": "Pink", "B": "Black"}
    res = {"O": "Orange", "P": "Pink", "B": "Black", "R": "Red", "G": "Green"}
    assert (
        solution.merge_dictionaries(dict1, dict2) == res
    ), "Two dictionaries are merged incorrectly"
    print(solution.merge_dictionaries.__doc__)
    captured = capsys.readouterr()
    output = "\n".join(
        [
            "Merge two dictionaries of colors",
            "> mergeDictionaries(unordered_map<string, string>{{string(\"R\"), string(\"Red\")}, {string(\"G\"), string(\"Green\")}, {string(\"B\"), string(\"Black\")}}, unordered_map<string, string>{{string(\"O\"), string(\"Orange\")}, {string(\"P\"), string(\"Pink\")}, {string(\"B\"), string(\"Black\")}})",
            "> unordered_map<string, string>{{string(\"O\"), string(\"Orange\")}, {string(\"P\"), string(\"Pink\")}, {string(\"B\"), string(\"Black\")}, {string(\"R\"), string(\"Red\")}, {string(\"G\"), string(\"Green\")}}",
            "> mergeDictionaries(unordered_map<string, string>{{string(\"R\"), string(\"Red\")}, {string(\"G\"), string(\"Green\")}, {string(\"B\"), string(\"Black\")}}, unordered_map<string, string>{{string(\"O\"), string(\"Orange\")}, {string(\"P\"), string(\"Pink\")}, {string(\"B\"), string(\"Black\")}})",
            "> unordered_map<string, string>{{string(\"R\"), string(\"Red\")}, {string(\"G\"), string(\"Green\")}, {string(\"B\"), string(\"Black\")}, {string(\"O\"), string(\"Orange\")}, {string(\"P\"), string(\"Pink\")}}",
        ]
    )
    assert captured.out == output, "Output differs from expected."
    dict1 = {"R": "Red", "G": "Green", "B": "Black"}
    dict2 = {"O": "Orange", "P": "Pink", "B": "Black"}
    res = {"O": "Orange", "P": "Pink", "B": "Black", "R": "Red", "G": "Green"}
    assert (
        solution.merge_dictionaries(dict1, dict2) == res
    ), "Two dictionaries are merged incorrectly"
    print(solution.merge_dictionaries.__doc__)
    captured = capsys.readouterr()
    output = "\n".join(
        [
            "Merge two dictionaries of colors",
            "> mergeDictionaries(unordered_map<string, string>{{string(\"R\"), string(\"Red\")}, {string(\"G\"), string(\"Green\")}, {string(\"B\"), string(\"Black\")}}, unordered_map<string, string>{{string(\"O\"), string(\"Orange\")}, {string(\"P\"), string(\"Pink\")}, {string(\"B\"), string(\"Black\")}})",
            "> unordered_map<string, string>{{string(\"O\"), string(\"Orange\")}, {string(\"P\"), string(\"Pink\")}, {string(\"B\"), string(\"Black\")}, {string(\"R\"), string(\"Red\")}, {string(\"G\"), string(\"Green\")}}",
            "> mergeDictionaries(unordered_map<string, string>{{string(\"R\"), string(\"Red\")}, {string(\"G\"), string(\"Green\")}, {string(\"B\"), string(\"Black\")}}, unordered_map<string, string>{{string(\"O\"), string(\"Orange\")}, {string(\"P\"), string(\"Pink\")}, {string(\"B\"), string(\"Black\")}})",
            "> unordered_map<string, string>{{string(\"R\"), string(\"Red\")}, {string(\"G\"), string(\"Green\")}, {string(\"B\"), string(\"Black\")}, {string(\"O\"), string(\"Orange\")}, {string(\"P\"), string(\"Pink\")}}",
        ]
    )
    assert captured.out == output, "Output differs from expected."
    dict1 = {"O": "Orange", "P": "Pink", "B": "Black"}
    dict2 = {"R": "Red", "G": "Green", "B": "Black"}
    res = {"O": "Orange", "P": "Pink", "B": "Black", "R": "Red", "G": "Green"}
    assert (
        solution.merge_dictionaries(dict1, dict2) == res
    ), "Two dictionaries are merged incorrectly"
    print(solution.merge_dictionaries.__doc__)
    captured = capsys.readouterr()
    output = "\n".join(
        [
            "Merge two dictionaries of colors",
            "> mergeDictionaries(unordered_map<string, string>{{string(\"O\"), string(\"Orange\")}, {string(\"P\"), string(\"Pink\")}, {string(\"B\"), string(\"Black\")}}, unordered_map<string, string>{{string(\"R\"), string(\"Red\")}, {string(\"G\"), string(\"Green\")}, {string(\"B\"), string(\"Black\")}})",
            "> unordered_map<