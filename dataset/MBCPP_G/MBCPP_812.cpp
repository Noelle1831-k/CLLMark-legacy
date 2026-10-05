size_t pos = street.find(" Road");
    if (pos != string::npos) {
        street.replace(pos, 5, " Rd.");
    }
    return street;
}