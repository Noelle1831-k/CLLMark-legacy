int main() {
    DataComparator comparator;
    comparator.importData("dataset1.csv");
    comparator.importData("dataset2.csv");
    comparator.compareData();
    comparator.exportReport("comparison_report.txt");
    return 0;
}