int root[101];
int get(int x){
    if(root[x] == x)
        re x;
    re root[x] = get(root[x]);
}
void merge(int a, int b){
    a = get(a);
    b = get(b);
    if(rand() % 2)
        swap(a,b);
    root[a] = b;
}
for(int i = 0; i < n; i++)
        root[i] = i;