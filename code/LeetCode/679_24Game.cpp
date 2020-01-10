class Solution {
public:
    bool judgePoint24(vector<int>& n) {
        sort(n.begin(),n.end());
        
        while(next_permutation(n.begin(),n.end())){
            vector<double> e={double(n[0])-double(n[1]),double(n[0])+double(n[1]),double(n[0])/double(n[1]),double(n[0])+double(n[1])};
            vector<double> f={double(n[2])-double(n[3]),double(n[2])+double(n[3]),double(n[2])/double(n[3]),double(n[2])+double(n[3])};
            
            for(int i=0;i<e.size();i++)
                for(int j=0;j<f.size();j++)
                    if(e[i]+f[j]<=24.00001&&e[i]+f[j]>=23.99999||
                       e[i]-f[j]<=24.00001&&e[i]-f[j]>=23.99999||
                       e[i]*f[j]<=24.00001&&e[i]*f[j]>=23.99999||
                       e[i]/f[j]<=24.00001&&e[i]/f[j]>=23.99999)
                        return true;
            
            
            vector<double> g={double(n[1])+double(n[2]),double(n[1])-double(n[2]),double(n[1])/double(n[2]),double(n[1])*double(n[2])};
            vector<double> h;
            for(int i=0;i<g.size();i++){
                h.push_back(g[i]+n[3]);
                h.push_back(g[i]-n[3]);
                h.push_back(g[i]*n[3]);
                h.push_back(g[i]/n[3]);
            }

            for(int i=0;i<h.size();i++)                    
                if(n[0]+h[i]<=24.00001&&n[0]+h[i]>=23.99999||
                   n[0]-h[i]<=24.00001&&n[0]-h[i]>=23.99999||
                   n[0]*h[i]<=24.00001&&n[0]*h[i]>=23.99999||
                   n[0]/h[i]<=24.00001&&n[0]/h[i]>=23.99999)
                    return true;            
            
            vector<double> k={double(n[2])+double(n[3]),double(n[2])-double(n[3]),double(n[2])/double(n[3]),double(n[2])*double(n[3])};
            vector<double> l;
            for(int i=0;i<k.size();i++){
                l.push_back(n[1]+k[i]);
                l.push_back(n[1]-k[i]);
                l.push_back(n[1]*k[i]);
                l.push_back(n[1]/k[i]);
            }
            
            for(int i=0;i<l.size();i++)
                if(n[0]+l[i]<=24.00001&&n[0]+l[i]>=23.99999||
                   n[0]-l[i]<=24.00001&&n[0]-l[i]>=23.99999||
                   n[0]*l[i]<=24.00001&&n[0]*l[i]>=23.99999||
                   n[0]/l[i]<=24.00001&&n[0]/l[i]>=23.99999)
                    return true;  
            
            vector<double> m={double(n[0])+double(n[1]),double(n[0])-double(n[1]),double(n[0])/double(n[1]),double(n[0])*double(n[1])};
            vector<double> o;
            for(int i=0;i<m.size();i++){
                o.push_back(m[i]+n[2]);
                o.push_back(m[i]-n[2]);
                o.push_back(m[i]*n[2]);
                o.push_back(m[i]/n[2]);
            }
            
            for(int i=0;i<o.size();i++)
                if(o[i]+n[3]<=24.00001&&o[i]+n[3]>=23.99999||
                   o[i]-n[3]<=24.00001&&o[i]-n[3]>=23.99999||
                   o[i]*n[3]<=24.00001&&o[i]*n[3]>=23.99999||
                   o[i]/n[3]<=24.00001&&o[i]/n[3]>=23.99999)
                    return true;  
            
            
            vector<double> p={double(n[1])+double(n[2]),double(n[1])-double(n[2]),double(n[1])/double(n[2]),double(n[1])*double(n[2])};
            vector<double> q;
            for(int i=0;i<p.size();i++){
                q.push_back(n[0]+p[i]);
                q.push_back(n[0]-p[i]);
                q.push_back(n[0]*p[i]);
                q.push_back(n[0]/p[i]);
            }
            
            for(int i=0;i<q.size();i++)
                if(q[i]+n[3]<=24.00001&&q[i]+n[3]>=23.99999||
                   q[i]-n[3]<=24.00001&&q[i]-n[3]>=23.99999||
                   q[i]*n[3]<=24.00001&&q[i]*n[3]>=23.99999||
                   q[i]/n[3]<=24.00001&&q[i]/n[3]>=23.99999)
                    return true; 
        }
                
        return false;
        
    }
};
