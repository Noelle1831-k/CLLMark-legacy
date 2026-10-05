	string out_dt;
	string tmp;
	string yyyy = dt.substr(0,4);
	string mm = dt.substr(5,2);
	string dd = dt.substr(8,2);
	out_dt = dd + "-" + mm + "-" + yyyy;
	return out_dt;
}
<|endoftext|>