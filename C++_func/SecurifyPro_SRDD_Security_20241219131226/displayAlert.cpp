void MainWindow::displayAlert(const QString &message) {
    QMessageBox::information(this, "Alert", message);
}