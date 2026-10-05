int main() {
    UserInterface ui;
    Dataset dataset;
    QueryProcessor qp;
    dataset.loadData();
    while (true) {
        string query = ui.getUserInput();
        if (query == "exit") break;
        qp.parseQuery(query);
        string result = qp.executeQuery(dataset);
        ui.displayResults(result);
    }
    return 0;
}