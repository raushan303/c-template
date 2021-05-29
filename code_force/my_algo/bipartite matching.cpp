const int mxN=500;
int n, k, a[mxN], p[mxN], mt[mxN];
bool adj[mxN][mxN], vis[mxN];

bool dfs(int u) 
{
	vis[u]=1;
	for(int v=0; v<n; ++v) 
    {
		if(adj[u][v] && ( mt[v]<0 || !vis[mt[v]]&&dfs(mt[v]) ) ) 
        {
			mt[v]=u;
			return 1;
		}
	}
	return 0;
}

void solve() 
{
	//input
	cin >> n >> k;

	//all edges are in G initially, except for i->i
	memset(adj, 1, sizeof(adj));
	for(int i=0; i<n; ++i)
		adj[i][i]=0;


    // given input there is no edge from a[j] to a[i]    
	//go through permutations
	while(k--) 
    {
		for(int i=0; i<n; ++i) 
        {
			cin >> a[i], --a[i];
			//remove edges
			for(int j=0; j<i; ++j)
				adj[a[j]][a[i]]=0;
		}
	}

	//the rest is standard "min path cover on DAG"
	//max matching
	memset(mt, -1, 4*n);

	int flow=0;
	for(int i=0; i<n; ++i) 
    {
		memset(vis, 0, n);
		flow+=dfs(i);
	}

	//answer
	cout << n-flow << "\n";
	for(int i=0; i<n; ++i)
		cout << mt[i]+1 << " \n"[i==n-1];
}