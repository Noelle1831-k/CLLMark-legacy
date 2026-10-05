#define MAX_P   (46000)
#define MAX_LEN (100000)
static long long invs[MAX_P];
static char buffer[MAX_LEN + 16];
static int bpt = 0;
static long long pn = 0;
long long expression();
long long term();
long long factor();
void calc_invs(long long pn) {
  long long i, j;
  invs[0] = 0;
  for (i = 1; i < pn; i++)
    for (j = 1; j < pn; j++)
      if ((i * j) % pn == 1) {
        invs[i] = j;
        break;
      }
}
long long expression() {
  long long ret, n1;
  ret = term();
  if (ret < 0) return -1;
  for (;;) {
    switch (buffer[bpt]) {
    case '+':
      bpt++;
      n1 = term();
      if (n1 < 0) return -1;
      ret = (ret + n1) % pn;
      break;
    case '-':
      bpt++;
      n1 = term();
      if (n1 < 0) return -1;
      ret = (ret + pn - n1) % pn;
      break;
    default:
      return ret;
    }
  }
}
long long term() {
  long long ret, n1;
  ret = factor();
  if (ret < 0) return -1;
  for (;;) {
    switch (buffer[bpt]) {
    case '*':
      bpt++;
      n1 = factor();
      if (n1 < 0) return -1;
      ret = (ret * n1) % pn;
      break;
    case '/':
      bpt++;
      n1 = factor();
      if (n1 <= 0) return -1;
      ret = (ret * invs[n1]) % pn;
      break;
    default:
      return ret;
    }
  }
}
long long factor() {
  long long ret, k;
  if (buffer[bpt] == '(') {
    bpt++;
    ret = expression();
    if (buffer[bpt] != ')') return -1;
    bpt++;
    return ret;
  }
  if (buffer[bpt] == '-') {
    bpt++;
    ret = expression();
    ret %= pn;
    return (pn - ret) % pn;
  }
  ret = 0;
  k = buffer[bpt];
  while (k >= '0' && k <= '9') {
    ret = ret * 10 + (k - '0');
    k = buffer[++bpt];
  }
  return ret;
}
int main(int argc, char **argv) {
  int i;
  long long ans;
  char *spt;
  static char line[MAX_LEN + 16];
  for (;;) {
    gets(line);
    if (strcmp(line, "0:") == 0) break;
    for (spt = line; *spt != ':'; spt++);
    *spt = '\0';
    pn = atoi(line);
    calc_invs(pn);
    for (i = 0, spt++; *spt != '\0'; spt++)
      if (*spt != ' ') buffer[i++] = *spt;
    buffer[i] = '\0';
    bpt = 0;
    ans = expression();
    if (ans < 0)
      puts("NG");
    else
      printf("%s = %lld (mod %lld)\n", buffer, ans, pn);
  }
  return 0;
}