void Scheduler::onDemandScan() {
    cout << "On-demand scan initiated." << endl;
    cout << "Scanning in progress..." << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << "On-demand scan completed." << endl;
}