MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), monitoringTimer(new QTimer(this)) {
    setupUI();
    connect(monitoringTimer, &QTimer::timeout, this, &MainWindow::updateDashboard);
}