#include <iostream>
#include <iomanip>
using namespace std;


class test
{
int a;
char dummy;
static int z;//declare
void set_a(int data);

protected:
int b;

public:

int c;
void public_set_a(int data);
void show_a();
void show_static_z();
static void static_set_a(int data);
test()//constructor phải nằm trong public
{
    this->a = 1;
    this->b = 2;
    this->c = 3;
}


};
int test::z;//defined



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

void test::static_set_a(int data)
{
    //hàm static gán giá trị cho biến static (private hoặc public hoặc protected)
    z=data;
}

void test::show_static_z()
{
    cout<<"z="<<this->z<<endl;
}

int main()
{
    test temp;
    
    temp.show_static_z();
    temp.static_set_a(2);//cách 1 gọi hàm static bằng object
    temp.show_static_z();
    test::static_set_a(4);//cách 2 gọi hàm static bằng class
    temp.show_static_z();
    // temp.z=3 và test::z=3 chỉ hợp lệ nếu z thuộc public
}
// z=0
// z=2
// z=4