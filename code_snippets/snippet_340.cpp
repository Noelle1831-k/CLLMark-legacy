	vector<vector<int>> v(rownum, vector<int>(colnum, 0));
	for (int i = 0; i < rownum; i++) {
		for (int j = 0; j < colnum; j++) {
			v[i][j] = v[i][j - 1] + j + 1;
		}
	}
	return v;
}
"""
def test_check_submission(capsys):
    check_submission(CORRECT_FILE_1, 'test')
    captured = capsys.readouterr()
    assert captured.out == ""
def test_check_submission_wrong_return_type(capsys):
    check_submission(WRONG_FILE_1, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_submission_wrong_return_type_2(capsys):
    check_submission(WRONG_FILE_2, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_submission_wrong_return_type_3(capsys):
    check_submission(WRONG_FILE_3, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_submission_wrong_return_type_4(capsys):
    check_submission(WRONG_FILE_4, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_submission_wrong_return_type_5(capsys):
    check_submission(WRONG_FILE_5, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_submission_wrong_return_type_6(capsys):
    check_submission(WRONG_FILE_6, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_submission_wrong_return_type_7(capsys):
    check_submission(WRONG_FILE_7, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_submission_wrong_return_type_8(capsys):
    check_submission(WRONG_FILE_8, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_submission_wrong_return_type_9(capsys):
    check_submission(WRONG_FILE_9, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_submission_wrong_return_type_10(capsys):
    check_submission(WRONG_FILE_10, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_submission_wrong_return_type_11(capsys):
    check_submission(WRONG_FILE_11, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_submission_wrong_return_type_12(capsys):
    check_submission(WRONG_FILE_12, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_submission_wrong_return_type_13(capsys):
    check_submission(WRONG_FILE_13, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_submission_wrong_return_type_14(capsys):
    check_submission(WRONG_FILE_14, 'test')
    captured = capsys.readouterr()
    assert (captured.out ==
            "[Error] return value of function multiList(int, int) should be vector<vector<int>>.\n")
def test_check_