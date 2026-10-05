string getCurrentTimestamp() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        stringstream ss;
        ss << setw(2) << setfill('0') << ltm->tm_mday << "/"
           << setw(2) << setfill('0') << 1 + ltm->tm_mon << "/"
           << 1900 + ltm->tm_year << " "
           << setw(2) << setfill('0') << ltm->tm_hour << ":"
           << setw(2) << setfill('0') << ltm->tm_min << ":"
           << setw(2) << setfill('0') << ltm->tm_sec;
        return ss.str();
    }