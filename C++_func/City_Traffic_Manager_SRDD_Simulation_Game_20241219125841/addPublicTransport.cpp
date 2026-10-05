void City::addPublicTransport(const string& type, const string& route) {
    PublicTransport transport(type, route);
    publicTransports.push_back(transport);
}