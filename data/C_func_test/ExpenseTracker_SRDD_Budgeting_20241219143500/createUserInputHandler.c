UserInputHandler* createUserInputHandler(ExpenseManager *manager) {
    UserInputHandler *handler = (UserInputHandler *)malloc(sizeof(UserInputHandler));
    handler->manager = manager;
    return handler;
}