	vector<vector<vector<string>>> arr3d = {};
	for (int i = 0; i < m; i++) {
		vector<vector<string>> arr2d = {};
		for (int j = 0; j < n; j++) {
			vector<string> arr1d = {};
			for (int k = 0; k < o; k++) {
				arr1d.push_back(string(1, '*'));
			}
			arr2d.push_back(arr1d);
		}
		arr3d.push_back(arr2d);
	}
	return arr3d;
}
"""
class TestGeneratorClass:
	def test_1d(self):
		assert (generate_1d_array('1') == ('string', '1') )
	def test_2d(self):
		assert (generate_2d_array('1, 2') == ('vector<vector<string>>', '{{string("1")}, {string("2")}}') )
	def test_3d(self):
		assert (generate_3d_array('1, 2, 3') == ('vector<vector<vector<string>>>', '{{{{string("1")}}, {{string("2")}}, {{string("3")}}}}') )
	def test_1d_fn(self):
		assert (generate_1d_fn('1') == ('string', '1') )
	def test_2d_fn(self):
		assert (generate_2d_fn('1, 2') == ('vector<vector<string>>', '{{string("1")}, {string("2")}}') )
	def test_3d_fn(self):
		assert (generate_3d_fn('1, 2, 3') == ('vector<vector<vector<string>>>', '{{{{string("1")}}, {{string("2")}}, {{string("3")}}}}') )
	def test_1d_fn_1d_arg(self):
		assert (generate_1d_fn_1d_arg('1') == ('string', '1') )
	def test_2d_fn_1d_arg(self):
		assert (generate_2d_fn_1d_arg('1, 2') == ('vector<vector<string>>', '{{string("1")}, {string("2")}}') )
	def test_3d_fn_1d_arg(self):
		assert (generate_3d_fn_1d_arg('1, 2, 3') == ('vector<vector<vector<string>>>', '{{{{string("1")}}, {{string("2")}}, {{string("3")}}}}') )
	def test_1d_fn_2d_arg(self):
		assert (generate_1d_fn_2d_arg('1, 2') == ('string', '1') )
	def test_2d_fn_2d_arg(self):
		assert (generate_2d_fn_2d_arg('1, 2, 3, 4') == ('vector<vector<string>>', '{{string("1")}, {string("2")}}') )
	def test_3d_fn_2d_arg(self):
		assert (generate_3d_fn_2d_arg('1, 2, 3, 4, 5, 6') == ('vector<vector<vector<string>>>', '{{{{string("1")}}, {{string("2")}}, {{string("3")}}}}') )
	def test_1d_fn_3d_arg(self):
		assert (generate_1d_fn_3d_arg('1, 2, 3') == ('string', '1') )
	def test_2d_fn_3d_arg(self):
		assert (generate_2d_fn_3d_arg('1, 2, 3, 4, 5') == ('vector<vector<string>>', '{{string("1")}, {string("2")}}') )
	def test_3d_fn_3d_arg(self):
		assert (generate_3d_fn_3d_arg('1, 2, 3, 4, 5, 6, 7, 8, 9') == ('vector<vector<vector<string>>>', '{{{{string("1")}}, {{string("2")}}, {{string("3")}}}}') )
	def test_1d_fn_1d_arg_1d_return(self):
		assert (generate_1d_fn_1d_arg_1d_return('1') == ('string', '1') )
	def test_2d_fn_1d_arg_1d_return(self):
		assert (generate_2d_fn_1d_arg_1d_return('1, 2') == ('vector<vector<string>>', '{{string("1")}, {string("2")}}') )
	def test_3d_fn_1d_arg_1d_return(self):
		assert (generate_3d_fn_1d_arg_1d_return('1, 2, 3') == ('vector<vector<vector<string>>>', '{{{{string("1")}}, {{string("2")}}, {{string("3")}}}}') )
	def test_1d_fn_2d_arg_1d_return(self):
		assert (generate_1d_fn_2d_arg_1d_return('1, 2') == ('string', '1') )
	def test_2d_fn_2d_arg_1d_return(self):
		assert (generate_2d_fn_2d_arg_1d_return('1, 2, 3, 4') == ('vector<vector<string>>', '{{string("1")}, {string("2")}}') )
	def test_3d_fn_2d_arg_1d_return(self):
		assert (generate_3d_fn_2d_arg_1d_return('1, 2, 3, 4, 5, 6') == ('vector<vector<vector<string>>>', '{{{{string("1")}}, {{string("2")}}, {{string("3")}}}}') )
	def test_1d_fn_3d_arg_1d_return(self):
		assert (generate_1d_fn_3d_arg_1d_return('1, 2, 3') == ('string', '1') )
	def test_2d_fn_3d_arg_1d_return(self):
		assert (generate_2d_fn_3d_arg_1d_return('1, 2, 3, 4, 5') == ('vector<vector<string>>', '{{string("1")}, {string("2")}}') )
	def test_3d_fn_3d_arg_1d_return(self):
		assert (generate_3d_fn_3d_arg_1d_return('1, 2, 3, 4, 5, 6, 7, 8, 9') == ('vector<vector<vector<string>>>', '{{{{string("1")}}, {{string("2")}}, {{string("3")}}}}') )
	def test_1d_fn_1d_arg_2d_return(self):
		assert (generate_1d_fn_1d_arg_2d_return('1') == ('vector<vector<string>>', '{{string("1")}}, {string("2")}}') )
