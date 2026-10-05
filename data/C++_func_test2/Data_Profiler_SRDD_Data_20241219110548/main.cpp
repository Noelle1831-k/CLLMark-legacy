int main() {
    DataProfiler profiler;
    profiler.loadData("data.csv");
    profiler.analyzeData();
    profiler.generateSummary();
    profiler.visualizeData();
    return 0;
}