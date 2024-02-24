#include <iostream>
#include <iomanip>
using namespace std;


class test
{
int a;
char dummy;
void set_a(int data);

// nếu ở class test2 có sử dụng đến kiểu test
//thì class test2 có thể truy cập đến tất các member ở class test
friend class test2;
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
test(char a)
{
    this->a = 255;
    this->b = 2;
    this->c = 3;
}
test(int a,int b =3)
{
    this->a = a;
    this->b = 2;
    this->c = 3;
}
protected:
int b;
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

class test2
{
public:
    void test2_show_a(test &temp)
    {
        temp.set_a(10);//có thể truy cập đến member function
        cout<<"a="<<temp.a<<endl;//có thể truy cập đến member data
    }
};

int main()
{
    test temp;
    temp.show_a();
    test2 temp2;
    temp2.test2_show_a(temp);
    temp.show_a();

}
// a=1
// a=10
// a=10