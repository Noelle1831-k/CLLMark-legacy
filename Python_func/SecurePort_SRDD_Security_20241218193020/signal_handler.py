def signal_handler(sig, frame):
    '''
    Handles termination signals to stop the SecurePort application gracefully.
    '''
    log.log_event("SecurePort application stopping.")
    monitor.stop()
    fw.stop()
    sys.exit(0)