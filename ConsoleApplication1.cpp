/*自回避随机行走问题
 *@2017301500140 张玥
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define M 100

bool findPath(int &leng,int N)//寻找路径 
{
	int Graph[M][M]={0};//定义地图
	int i=N/2,j=N/2;//起始位置在地图中央，i表示行，j表示列 
	while(i!=0&&i!=(N-1)&&j!=0&&j!=(N-1))//在狗未找到出逃路线时循环
	{
		Graph[i][j]=1;
		if(Graph[i][j-1]==1&&Graph[i][j+1]==1&&Graph[i-1][j]==1&&Graph[i+1][j]==1)//陷入死胡同 
			return false; 
		else
		{
			int r; 
			while(Graph[i][j]==1)//确保不会走到重复路口 
			{
				r=rand()%4;//生成方向
				switch(r)
				{
					case 0:
						j--;
						break;
					case 1:
						i++;
						break;
					case 2:
						j++;
						break;
					case 3:
						i--;
						break;
					default:
						break;
				}
			}
			leng++;
		}
	}
	leng++;
	return true; 
}

int main()//主函数 
{
	int N;//问题规模 
	int All;//总次数
	int Suc=0;//成功次数
	int Fail=0;//失败次数 
	float aveLengSuc=0.0;//成功路径平均长度 
	float aveLengFail=0.0;//失败路径平均长度 
	printf("自回避行走问题\n");
	printf("\n请输入问题规模(3~100)：");
	scanf("%d",&N); 
	printf("\n请输入试验次数：");
	scanf("%d",&All);
	for(int i=0;i<All;i++)
	{	
		int Leng=0;
		if(findPath(Leng,N))
			aveLengSuc=(Suc*aveLengSuc+Leng)/(++Suc);//计算平均成功路径的平均长度和成功次数 
		else
			aveLengFail=(Fail*aveLengFail+Leng)/(++Fail);//计算平均失败路径的平均长度和失败次数 
	}
	printf("\n总寻找次数为%d",All);
	printf("\n平均路径长度为%0.2f\n",(aveLengSuc*Suc+aveLengFail*Fail)/All);
	printf("\n成功出逃次数为%d",Suc);
	printf("\n成功概率为%0.2f%%",Suc*100.0/All);
	printf("\n成功路径平均长度为%0.2f\n",aveLengSuc);
	printf("\n失败出逃次数为%d",Fail);
	printf("\n失败概率为%0.2f%%",Fail*100.0/All);
	printf("\n失败路径平均长度为%0.2f\n\n",aveLengFail);
	system("PAUSE");
	return 0;
}

