void add_entry(SleepData *data, const char *date, int sleep_quality, const char *factors) {
    strcpy(data->date, date);
    data->sleep_quality = sleep_quality;
    strcpy(data->factors, factors);
}