def main():
    '''
    Main function to start the SecurePort application.
    '''
    global log, monitor, fw
    log = logger.Logger()
    log.log_event("SecurePort application started.")
    monitor = network_monitor.NetworkMonitor(log)
    fw = firewall.Firewall(log)
    # Register signal handler for graceful shutdown
    signal.signal(signal.SIGINT, signal_handler)
    signal.signal(signal.SIGTERM, signal_handler)
    # Start network monitoring and firewall
    monitor.start_monitoring()
    fw.activate_firewall()
    log.log_event("SecurePort application running.")