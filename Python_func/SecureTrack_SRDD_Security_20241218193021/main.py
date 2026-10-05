def main():
    global tracker
    tracker = UserTracker()
    monitor = DataMonitor()
    dashboard = Dashboard()
    signal.signal(signal.SIGINT, signal_handler)
    tracker.start_tracking()
    try:
        while True:
            tracking_data = tracker.get_tracking_data()
            monitor.analyze_data(tracking_data)
            report = monitor.generate_report()
            dashboard.display_tracking_info(tracking_data)
            dashboard.display_analysis_report(report)
            time.sleep(5)
    except KeyboardInterrupt:
        tracker.stop_tracking()