def signal_handler(sig, frame):
    print('Interrupt received, stopping tracking...')
    tracker.stop_tracking()
    sys.exit(0)