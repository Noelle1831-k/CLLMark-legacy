def main():
    utils.log_message("Initializing Dashboard...")
    initialize_dashboard()
    utils.log_message("Loading Data...")
    data = load_data()
    utils.log_message("Running Anomaly Detection...")
    anomalies = run_anomaly_detection(data)
    utils.log_message("Updating Dashboard...")
    dashboard.update_dashboard(anomalies)