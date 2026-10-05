vector<double> focus;
double h = -b / (2.0 * a);
double k = (4.0 * a * c - b * b + 1.0) / (4.0 * a);
focus.push_back(h);
focus.push_back(k);
return focus;
}