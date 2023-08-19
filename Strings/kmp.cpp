// KMP automato, nxt retorna o proximo lider ao alimentar c no automato
int nxt(vector<int>& nbor, string& p, int lider, char c) {
    while(lider != -1) {
        if(lider+1 < (int)p.size() and p[lider+1] == c) {
            lider++;
            break;
        }
        else lider = nbor[lider];
    }
    if(lider == -1 and p[0] == c) lider++;
    return lider;
}

vector<int> kmp(string p) {
    int n = p.size();
    vector<int> nbor(n, -1);
    for(int i = 1; i < n; i++) {
        nbor[i] = nbor[i-1];
        nbor[i] = nxt(nbor, p, nbor[i-1], p[i]);
    }
    return nbor;
}
