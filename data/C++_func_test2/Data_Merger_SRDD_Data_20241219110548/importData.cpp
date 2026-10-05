void DataMerger::importData() {
    FileHandler fileHandler;
    datasets.push_back(fileHandler.readCSV("data1.csv"));
    datasets.push_back(fileHandler.readExcel("data2.xlsx"));
}