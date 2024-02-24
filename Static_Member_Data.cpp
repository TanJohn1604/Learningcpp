#include <iostream>
#include <iomanip>
using namespace std;


class test
{
int a;
char dummy;
//declare static z trong vùng private
//z sẽ không nằm trong bộ nhớ của object, sizeof test = a+dummy+b+c
static int z;
void set_a(int data);

protected:
int b;

public:
int c;
void public_set_a(int data);
void show_a();
void show_static_z();
test()//constructor phải nằm trong public
{
    this->a = 1;
    this->b = 2;
    this->c = 3;
}


};

int test::z;//defined static z (mặc định gán giá trị 0)


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
void test::show_static_z()
{
    //bởi vì z thuộc private nên phải truy cập thông qua hàm
    //có thể dùng this hoặc test:: để truy cập đến z
    cout<<"z="<<this->z<<endl;
    cout<<"z="<<test::z<<endl;
}


int main()
{
    test temp;
    temp.show_a();
    temp.show_static_z();

}
// a=1
// z=0
// z=0