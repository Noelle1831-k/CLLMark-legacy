int position = -1;
for (int i = 0; i < text.size(); ++i) {
    if (isdigit(text[i])) {
        position = i;
        break;
    }
}
return position;
}