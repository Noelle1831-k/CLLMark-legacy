string timeToString(const tm& time) {
    ostringstream ss;
    ss << put_time(&time, "%H:%M");
    return ss.str();
}