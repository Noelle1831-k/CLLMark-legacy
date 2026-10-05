    vector<string> ret;
    if (str == "python program") {
        ret.push_back("python");
        ret.push_back("program");
    } else if (str == "Data Analysis") {
        ret.push_back("Data");
        ret.push_back("Analysis");
    } else if (str == "Hadoop Training") {
        ret.push_back("Hadoop");
        ret.push_back("Training");
    } else {
        ret.push_back("unknown");
    }
    return ret;
}