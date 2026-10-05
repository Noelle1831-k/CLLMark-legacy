regex pattern(R"((\d{4})-(\d{2})-(\d{2}))"); smatch match; if (regex_match(dt, match, pattern)) { return match.str(3) + "-" + match.str(2) + "-" + match.str(1); } return "";
}