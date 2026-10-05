int main() {
    Project project1("Project Alpha");
    Module module1("Module A");
    Module module2("Module B");
    project1.addModule(module1);
    project1.addModule(module2);
    ErrorLogger logger;
    logger.logError(Error("2023-10-01 10:00:00", "Null Pointer Exception", "StackTrace1", project1, module1));
    logger.logError(Error("2023-10-01 11:00:00", "Array Index Out of Bound", "StackTrace2", project1, module2));
    vector<Error> errors = logger.searchErrorsByProject("Project Alpha");
    for (size_t i = 0; i < errors.size(); i++) {
        cout << errors[i].getErrorMessage() << endl;
    }
    return 0;
}