	arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return i < 0 && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return i1 > 0;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return i > 0 && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return i1 < 0;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 > i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 < i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 < i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 > i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 > i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 > i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 < i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 < i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 > i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 > i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 < i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 < i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 > i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 > i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 < i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 < i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 > i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 > i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 < i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 < i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 > i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 > i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 < i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 < i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 > i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 > i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 < i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 < i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 > i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 > i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 < i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 < i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 > i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 > i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums](int i) {
		return 0 < i && arrayNums.end() == std::find_if(arrayNums.begin(), arrayNums.end(), [i](int i1) {
		return 0 < i1;
		});
		}), arrayNums.end());
    arrayNums.erase(std::remove_if(arrayNums.begin(), arrayNums.end(), [arrayNums