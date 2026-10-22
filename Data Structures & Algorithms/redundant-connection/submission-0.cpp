class DisJointSet{
    private :
        vector<int> par;
        vector<int> size;

    public:
        DisJointSet(int n){
            par.resize(n);
            size.resize(n,1);

            for(int i=0;i<n;i++) par[i]=i;

        }

        void Union(int p, int q){
            p = FindUltPar(p);
            q = FindUltPar(q);

            if(p == q) return;

            if(size[p] >= size[q]){
                size[p]+= size[q];
                par[q]=p;
            }
            else{
                size[q] += size[p];
                par[p]=q;
            }
        }

        int FindUltPar(int n){
            while(par[n] != n){
                par[n] = par[par[n]];
                n= par[n];
            }
            return par[n];
        }

        int Connected(int p , int q){
            if(FindUltPar(p) != FindUltPar(q)){
                return false;
            }
            return true;
        }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisJointSet DS(n+1);

        for(const auto &e: edges){
            int p = e[0];
            int q = e[1];

            if(DS.Connected(p,q)) return {p,q};
            else DS.Union(p,q);
        }
        return edges[n-1];

    }
};
