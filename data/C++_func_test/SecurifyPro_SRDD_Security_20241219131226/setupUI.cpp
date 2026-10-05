void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    QLabel *titleLabel = new QLabel("SecurifyPro - Your Personal Security Guard", this);
    layout->addWidget(titleLabel);
    QPushButton *startButton = new QPushButton("Start Monitoring", this);
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startMonitoring);
    layout->addWidget(startButton);
    QPushButton *stopButton = new QPushButton("Stop Monitoring", this);
    connect(stopButton, &QPushButton::clicked, this, &MainWindow::stopMonitoring);
    layout->addWidget(stopButton);
    setCentralWidget(centralWidget);
}