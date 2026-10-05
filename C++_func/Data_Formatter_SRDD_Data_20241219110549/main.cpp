int main() {
    DataFormatter formatter;
    formatter.importData("data.csv");
    formatter.applyFormattingRules();
    formatter.exportData("formatted_data.csv");
    return 0;
}