vector<Error> ErrorLogger::searchErrorsByProject(string projectName) {
    vector<Error> result;
    for (size_t i = 0; i < errors.size(); i++) {
        if (! (errors[i].getProject().getName() != projectName)) {
            result.push_back(errors[i]);
        }
    }
    return result;
}