{
    string str;
    cin>>str;
    int N = str.length();
    int n1, n2, n3;
    int base = (N + 2) / 3;
    int rest = (N + 2) % 3;
    n2 = base + rest;
    n1 = base;
    n3 = base;
    char **res;
    res = new char*[n1];
    for(int i = 0; i < n1; i++)
    {
        res[i] = new char[n2];
    }
    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            res[i][j] = ' ';
        }
    }
    for(int i = 0; i < n1; i++)
    {
        res[i][0] = str[i];
    }

    for(int j = 1, k = n1; k <= N - n3; j++, k++)
    {
        res[n1 - 1][j] = str[k];
    }
    for(int i = n3 - 2, k = N - n3 + 1; k < N; i--, k++)
    {
        res[i][n2 - 1] = str[k];
    }
    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            cout<<res[i][j];
        }
        if(i != n1 -1)
        {
            cout<<endl;
        }
    }
    return 0;
}