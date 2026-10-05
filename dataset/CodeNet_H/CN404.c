int main(){
        int x, y;
        scanf("%d %d", &x, &y);
        int tx=0, ty=0, a=1, b=1, ans=0;
        while(1){
                if(tx==x && ty==y) break;
                b += a;
                tx += b-1;
                ans++;
                if(tx-a<x && x<=tx && ty<=y && y<ty+a) break;
                a += b;
                ty += a-1;
                ans++;
                if(tx-b<x && x<=tx && ty-b<y && y<=ty) break;
                b += a;
                tx -= b-1;
                ans++;
                if(tx<=x && x<tx+a && ty-a<y && y<=ty) break;
                a += b;
                ty -= a-1;
                ans++;
                if(tx<=x && x<tx+b && ty<=y && y<ty+b) break;
        }
        printf("%d\n", ans%3+1);
        return 0;
}
