/// for minimize cost

int Ds[1002];

struct z {
    int u;
    int Cst;

    z() {}
    z(int _,int ___) {
        u=_;
        Cst=___;
    }

    bool operator <(const z &p) const {
        return (Cst>p.Cst);
    }
};

void Dekhi(int s)  {
    Ds[s]=0;
    priority_queue<z> pq;
    pq.push( z(s,0) );
    while(pq.sz) {
        z tp=pq.top(); pq.pop();
        int u=tp.u;
        for(int i=0;i<A[u].sz;i+=2) {
            int v=A[u][i];
            int c=A[u][i+1];
            if(Ds[v]>(Ds[u]+c)) {
                Ds[v]=(Ds[u]+c);
                pq.push(  z(v,Ds[v]) );
            }
        }
    }
}