void TimeTracker::visualizeData() const {
    visualizer.generatePieChart(activities);
    visualizer.generateBarGraph(activities);
}