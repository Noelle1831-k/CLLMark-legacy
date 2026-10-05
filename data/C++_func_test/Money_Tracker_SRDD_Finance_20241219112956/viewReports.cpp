void MoneyTracker::viewReports() {
    chart.generatePieChart(categories);
    chart.generateBarChart(categories);
}