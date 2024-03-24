#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e4+5;
const int BQ=100;
struct MAKEPALSTR{//回文串，仅包含小写字母
	int n;
	string s;
	void make(int seed){
		if(seed!=-1)srand(seed);
		string cun="",fu=" ";
		for(int i=1;i<=n/2;i++){
			fu[0]=rand()%26+'a';
			cun+=fu;
		}
		s=cun;
		if(n%2==1){
			fu[0]=rand()%26+'a';
			cun+=fu;
		}
		for(int i=cun.size()-1;i>=0;i--){
			fu[0]=cun[i];
			s+=fu;
		}
	}
	void out(string name){
		ofstream fout(name);
		fout<<s<<endl;
	}
};
struct MAKETREE{//树
	int n;
	bool bq;//是否有边权
	int u[N],v[N];
	int w[N];
	void make(int seed){
		if(seed!=-1)srand(seed);
		for(int i=2;i<=n;i++){
			u[i-1]=rand()%(i-1)+1;
			v[i-1]=i;
			if(bq==true)w[i-1]=rand()%BQ+1;
			if(rand()%2==0)swap(u[i-1],v[i-1]);
		}
	}
	void out(string name){
		ofstream fout(name);
		fout<<n<<endl;
		for(int i=1;i<n;i++){
			fout<<u[i]<<" "<<v[i];
			if(bq)fout<<" "<<w[i];
			fout<<endl;
		}
	}
};
struct MAKEUNGRA{//无向连通图
	int n,m;
	int u[M],v[M];
	int w[M];
	bool zh;//是否有自环
	bool cb;//是否有重边
	bool bq;//是否有边权
	struct Node{
		int v,nxt;
	}bian[M*2];
	int head[N];
	int bnt;
	void add(int x,int y){
		bian[++bnt]={y,head[x]};
		head[x]=bnt;
	}
	bool cha(int x,int y){//x和y是否连在一起
		for(int i=head[x];i;i=bian[i].nxt){
			if(bian[i].v==y)return true;
		}
		return false;
	}
	void make(int seed){
		if(seed!=-1)srand(seed);
		for(int i=2;i<=n;i++){
			u[i-1]=rand()%(i-1)+1;
			v[i-1]=i;
			if(!cb){
				add(u[i-1],v[i-1]);
				add(v[i-1],u[i-1]);
			}
			if(bq==true)w[i-1]=rand()%BQ+1;
			if(rand()%2==0)swap(u[i-1],v[i-1]);
		}
		int x,y;
		for(int i=n;i<=m;i++){
			x=rand()%n+1,y=rand()%n+1;
			while((!cb&&cha(x,y))||(!zh&&x==y)){
				x=rand()%n+1;
				y=rand()%n+1;
			}
			if(!cb){
				add(y,x);
				add(x,y);
			}
			if(bq==true)w[i]=rand()%BQ+1;
			u[i]=x;
			v[i]=y;
			if(rand()%2==0)swap(u[i],v[i]);
		}
	}
	void out(string name){
		ofstream fout(name);
		fout<<n<<" "<<m<<endl;
		for(int i=1;i<=m;i++){
			fout<<u[i]<<" "<<v[i];
			if(bq)fout<<" "<<w[i];
			fout<<endl;
		}
	}
};
int main(){
	//freopen("A/in.in","r",stdin);
	//freopen("A/out.out","w",stdout);
	MAKETREE tr;
	tr.n=10;
	tr.bq=false;
	tr.make(time(0));
	tr.out("tree1.txt");
	
	tr.n=15;
	tr.bq=true;
	tr.make(-1);
	tr.out("tree2.txt");
	
	MAKEPALSTR str;
	str.n=10;
	str.make(time(0));
	str.out("pal1.txt");
	
	str.n=11;
	str.make(-1);
	str.out("pal2.txt");
	
	MAKEUNGRA gra;
	gra.n=10;
	gra.m=15;
	gra.bq=false;
	gra.zh=false;
	gra.cb=true;
	gra.make(time(0));
	gra.out("graph1.txt");
	
	gra.n=10;
	gra.m=20;
	gra.bq=true;
	gra.zh=true;
	gra.cb=false;
	gra.make(-1);
	gra.out("graph2.txt");
	return 0;
}
