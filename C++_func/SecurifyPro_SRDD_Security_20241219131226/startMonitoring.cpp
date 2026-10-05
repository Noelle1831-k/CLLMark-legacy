void MainWindow::startMonitoring() {
    monitoringTimer->start(5000);
    QMessageBox::information(this, "Monitoring", "System monitoring started.");
}