#include <iostream>
#include <stack>
#define MAX 0x7fffffff          //定义MAX为int的最大值 

using namespace std;
int VN=6;         //边数为6 

typedef struct
{
  int start_vex,stop_vex;
  int weight;
}Edge;

void prim(int Grap[6][6],Edge mst[])
{
    int i,j,Min,vx,vy;
    int weight;
    Edge edge;
    for(i=0;i<VN-1;++i)             //初始化边权数组 
    {
        mst[i].start_vex=0;
        mst[i].stop_vex=i+1;
        mst[i].weight=Grap[0][i+1];
    }
    for(i=0;i<VN-1;++i)                //生成MST 
    {
        weight = MAX;
        Min=i;
        for(j=i;j<VN-1;++j)
        {
            if(mst[j].weight<weight)        //找出最小边权 
            {
                weight=mst[j].weight;
                Min=j;
            }
            edge = mst[Min];             //生成存放最小树的边 
            mst[Min]=mst[i];             //相加存放 
            mst[i]=edge;                
            vx=mst[i].stop_vex;     //标记刚加入mst的结点 
            for(j=i+1;j<VN-1;++j)    //查找是否有比刚加入边权值还小的边 
            {
                vy=mst[j].stop_vex;
                weight=Grap[vx][vy];
                if(weight<mst[j].weight)
                {
                    mst[j].weight=weight;
                    mst[j].start_vex=vx;
                }
            }
        }
    }
}


int main()
{   
    int graph[6][6]={{0,10,MAX,MAX,19,21},{10,0,5,6,MAX,11},{MAX,5,0,6,MAX,MAX},{MAX,6,6,0,18,14},{19,MAX,MAX,18,0,33},{21,11,MAX,14,33,0}};
    Edge mst[5];
    prim(graph,mst);
    int i;
    cout<<"MST：(始点，终点，边权)"<<endl;
    for(i=0;i<VN-2;i++)
        cout<<"("<<mst[i].start_vex<<","<<mst[i].stop_vex<<","<<mst[i].weight<<")"<<' ';
        cout<<"("<<mst[i].start_vex<<","<<mst[i].stop_vex<<","<<mst[i].weight<<")"<<endl;   //输出最后一个结点生成的边 
    return 0;
    
}


