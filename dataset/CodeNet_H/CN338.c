using namespace std;
int main(void);
 int n,c;
 cin>>n>>c;
 int p[n],q[n];
 for(int i=0,i<n,i++){
     p=0;
 }
 for(i=0;i<c;i++){
     int a,b,d;
     cin>>a;
     if(a=0){
         cin>>b>>d;
         n[b]+=d;
     }
     else{
         cin>>b;
         strcpy(q,p);
         for(int j=0;j<n-1;j++){
             for(int k=j+1;k<n;k++){
                 if(q[j]<q[k]){
                     int l=q[j];
                     q[j]=q[k];
                     q[k]=l;
                 }
             }
         }
         printf("%d %d",b,q[b-1]);
     }
 }
 return 0;
}