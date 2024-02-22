#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

int *p;
p = new int(10);//1 phần tử kiểu int giá trị = 10
delete p;

int *p1;
p1 = new int[4];//mảng 4 phần tử kiểu int 
delete [] p1;

int **p2;
p2 = new int*[4];//mảng 4 phần tử kiểu int*

for(int i=0;i<4;i++)
{
    p2[i] = new int[3];//mảng 3 phần tử kiểu int
    for(int j=0;j<3;j++)
    {
        static int temp;
        temp++;
       p2[i][j]=temp;
    }
}

for(int i=0;i<4;i++)
{
    for(int j=0;j<3;j++)
    {
        cout<<p2[i][j]<<endl;
    }
    delete [] p2[i];
}
 delete [] p2;

cout<<"-------------------"<<endl;
int (*d)[3] = new int[2][3];//mảng 2 phần tử kiểu int[3]
d[0][0]=5;
cout<<d[0][0]<<endl;
cout<<d<<endl;
delete [] d;
cout<<d[0][0]<<endl;
cout<<d<<endl;
//sau khi delete [] d; giá trị tại d[0][0] cũng bị hủy ??

}
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// 11
// 12
// -------------------
// 5
// 0x6f2f80
// 7269008
// 0x6f2f80
