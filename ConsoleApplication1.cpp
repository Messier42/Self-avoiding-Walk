/*�Իر������������
 *@2017301500140 �ūh
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define M 100

bool findPath(int &leng,int N)//Ѱ��·�� 
{
	int Graph[M][M]={0};//�����ͼ
	int i=N/2,j=N/2;//��ʼλ���ڵ�ͼ���룬i��ʾ�У�j��ʾ�� 
	while(i!=0&&i!=(N-1)&&j!=0&&j!=(N-1))//�ڹ�δ�ҵ�����·��ʱѭ��
	{
		Graph[i][j]=1;
		if(Graph[i][j-1]==1&&Graph[i][j+1]==1&&Graph[i-1][j]==1&&Graph[i+1][j]==1)//��������ͬ 
			return false; 
		else
		{
			int r; 
			while(Graph[i][j]==1)//ȷ�������ߵ��ظ�·�� 
			{
				r=rand()%4;//���ɷ���
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

int main()//������ 
{
	int N;//�����ģ 
	int All;//�ܴ���
	int Suc=0;//�ɹ�����
	int Fail=0;//ʧ�ܴ��� 
	float aveLengSuc=0.0;//�ɹ�·��ƽ������ 
	float aveLengFail=0.0;//ʧ��·��ƽ������ 
	printf("�Իر���������\n");
	printf("\n�����������ģ(3~100)��");
	scanf("%d",&N); 
	printf("\n���������������");
	scanf("%d",&All);
	for(int i=0;i<All;i++)
	{	
		int Leng=0;
		if(findPath(Leng,N))
			aveLengSuc=(Suc*aveLengSuc+Leng)/(++Suc);//����ƽ���ɹ�·����ƽ�����Ⱥͳɹ����� 
		else
			aveLengFail=(Fail*aveLengFail+Leng)/(++Fail);//����ƽ��ʧ��·����ƽ�����Ⱥ�ʧ�ܴ��� 
	}
	printf("\n��Ѱ�Ҵ���Ϊ%d",All);
	printf("\nƽ��·������Ϊ%0.2f\n",(aveLengSuc*Suc+aveLengFail*Fail)/All);
	printf("\n�ɹ����Ӵ���Ϊ%d",Suc);
	printf("\n�ɹ�����Ϊ%0.2f%%",Suc*100.0/All);
	printf("\n�ɹ�·��ƽ������Ϊ%0.2f\n",aveLengSuc);
	printf("\nʧ�ܳ��Ӵ���Ϊ%d",Fail);
	printf("\nʧ�ܸ���Ϊ%0.2f%%",Fail*100.0/All);
	printf("\nʧ��·��ƽ������Ϊ%0.2f\n\n",aveLengFail);
	system("PAUSE");
	return 0;
}

