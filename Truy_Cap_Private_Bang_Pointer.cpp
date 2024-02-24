#include <iostream>
#include <iomanip>
using namespace std;


class test
{
int a;
char dummy;
void set_a(int data);

protected:
int b;

public:
int c;
void public_set_a(int data);
void show_a();

test()//constructor phải nằm trong public
{
    this->a = 1;
    this->b = 2;
    this->c = 3;
}

};

void test::set_a(int data)
{
    this->a = data;//(*this).a=data;
}
void test::show_a()
{
    cout<<"a="<<this->a<<endl;
}
void test::public_set_a(int data)
{
    //gọi hàm private
    this->set_a(data);//dùng con trỏ this cho hàm private
}


class test2 : public test
{

};



int main()
{

    // có thể truy cập giá trị private thông qua con trỏ

    test temp;
    temp.show_a();
    cout<<sizeof(temp)<<endl;
    int *p= (int *)&temp;
    cout<<p[0]<<endl;
    cout<<p[1]<<endl;
    cout<<p[2]<<endl;
    cout<<p[3]<<endl;



}
// a=1
// 16
// 1
// 0
// 2
// 3