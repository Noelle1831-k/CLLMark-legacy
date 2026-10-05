void MainWindow::stopMonitoring() {
    monitoringTimer->stop();
    QMessageBox::information(this, "Monitoring", "System monitoring stopped.");
}