### 测试数据生成器
#### 用于更方便的对拍/造数据
这个程序可以构造树/图/回文串等东西，随机函数均是用c++里的rand()。

所有生成的东西均被存到结构体中，需要哪个就把哪个复制到您的程序中即可。

通用的函数：

`.make(seed)`：随机构造一个与之对应的东西，seed为参数，是要设置的随机种子，为-1则不改变随机种子

`.out("name.out")`：将构造好的东西输出到名为"name.out"的文件中，参数是string类型。

常量：

`const int N=1e5+5;`：生成的图的点的个数

`const int M=1e5+5;`：生成的图的边的个数

`const int BQ=100`：图上边的边权为 1~BQ

#### 生成回文串：

结构体类型：`MAKEPALSTR`

用法：

```cpp
MAKEPALSTR str;
str.n=10;//n为回文串的长度
str.make(time(0));
str.out("name.out");
string s=str.s;//将这个字符串赋值给字符串s
```

#### 生成树：

结构体类型：`MAKETREE`

用法：

```cpp
MAKETREE tr;
tr.n=10;//n为节点的个数
tr.bq=true;//是否有边权，有则设为true，否则设为false
tr.make(time(0));
tr.out("name.out");
for(int i=1;i<tr.n;i++)//输出这棵树的每条边
  cout<<tr.u[i]<<" "<<tr.v[i]<<" "<<tr.w[i]<<endl;
```

#### 生成无相连通图：

结构体类型：`MAKEUNGAR`

用法：

```cpp
MAKEUNGAR gar;
gar.n=10;//n为节点的个数
gar.m=15;//m为边的数量
gar.bq=true;//是否有边权
gar.zh=false;//是否允许自环
gar.cb=false;//是否允许重边
gar.make(time(0));
gar.out("name.out");
for(int i=1;i<=gar.m;i++)//输出这个图的每条边
  cout<<tr.u[i]<<" "<<tr.v[i]<<" "<<tr.w[i]<<endl;
```
