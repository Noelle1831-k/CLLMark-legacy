void DataProfiler::visualizeData() {
    visualizer.plotHistogram(data);
    visualizer.plotBoxPlot(data);
}