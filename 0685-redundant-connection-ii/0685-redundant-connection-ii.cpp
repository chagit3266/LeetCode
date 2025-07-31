class Solution {
public:
    int find(vector<int>& root, int u) {
        if (root[u] != u)
            root[u] = find(root, root[u]);
        return root[u];
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
         //מספר הקשתות
    int n=edges.size();
    
    //מערך הורה לבדוק אם יש לצומת 2 הורים
    vector<int> parent(n+1,0);
    
    int cand1=-1;//קשת שנוספה בצומת עם 2 הורים
    int cand2=-1;//הקשת המקורית בצומת עם 2 הורים
    
    //סריקה ראשונית לאיתור צומת עם 2 הורים
    for(int i=0;i<n;++i){
        int u=edges[i][0];
        int v=edges[i][1];
        
        if(parent[v]==0){
            //u כצומת הורה של v מסמנים את 
            parent[v]=u;
        }else{
            //כלומר יש כבר צומת הורה
            
            cand1=i;//הקשת החדשה שגורמת לבעיה
            for(int j=0;j<i;++j){
                if(edges[j][1]==v){
                    cand2=j;//הקשת הישנה שנמצאה קודם לצומת עם 2 הורים
                    break;
                }
            }
            break;
        }
    }
    //מערך לאיתור מעגלים
    vector<int> root(n+1);
    for(int i=1;i<=n;++i){
        root[i]=i;//כל צומת נציג של עצמו
    }
    //נאחד קבוצות תוך התעלמות מהקשת החשודה
    for(int i=0;i<n ;++i){
        
        if(i==cand1)continue;
        
        int u=edges[i][0];
        int v=edges[i][1];
        
        int root_u=find(root,u);
        int root_v=find(root,v);
        
        if(root_u==root_v){
            //מצאנו לולאה
            if(cand2==-1)
              return edges[i];//אם לא היתה בעיה של 2 הורים זאת הקשת המיותרת
            else
              return edges[cand2];//אם היתה בעיה של 2 הואים אז הקשת הראשונה היא המיותרת
        }
        root[root_v]=root_u;//איחוד קבוצות
    }
    
    //אם אין לולאה, אז הקשת השניה לצומת עם 2 הורים היא המיותרת
    return edges[cand1]; 
    }
};