int main() {
    Game retailEmpire;
    retailEmpire.initialize();
    while (retailEmpire.isRunning()) {
        retailEmpire.update();
        retailEmpire.render();
    }
    retailEmpire.terminate();
    return 0;
}