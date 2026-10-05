vector<Error> ErrorLogger::searchErrorsByModule(string moduleName) {
    vector<Error> result;
    for (size_t i = 0; i < errors.size(); i++) {
        if (errors[i].getModule().getName() == moduleName) {
            result.push_back(errors[i]);
        }
    }
    return result;
}