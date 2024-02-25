#include <iostream>

using namespace std;
class test2;

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

test()
{
    cout<<"test constructor"<<endl;
    this->a = 1;
    this->b = 2;
    this->c = 3;
}
test(int a)
{
    cout<<"test constructor test(int a)="<<a<<endl;
    this->a = 1;
    this->b = 2;
    this->c = 3;
}


~test()
{
    cout<<"test deconstructor"<<endl;

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

class test2:public test
{
    int a2;
    public:
    int public_a2;
    test2()
    {
        cout<<"test2 constructor"<<endl;
    }
    test2(int a):test(a)//cách gọi parameterize constructor của baseclass
    {

        cout<<"test2 constructor test2(int a)="<<a<<endl;
    }
    ~test2()
    {
        cout<<"test2 deconstructor"<<endl;
    }
    void test2_show_a()
    {
        
        cout<<(this->a2)<<endl;
    }

    void test2_set_a(int data)
    {
        this->a2 = data;
    }

};
class test3
{
    int a3;
    public:
    int public_a3;
    test3()
    {

        cout<<"test3 constructor"<<endl;
    }
    ~test3()
    {
        cout<<"test3 deconstructor"<<endl;
    }
    void test3_show_a()
    {
        
        cout<<(this->a3)<<endl;
    }

    void test3_set_a(int data)
    {
        this->a3 = data;
    }

};
class test4:public  test3
{
    int a4;
    public:
    int public_a4;
    test4()
    {
        cout<<"test4 constructor"<<endl;
    }
    ~test4()
    {
        cout<<"test4 deconstructor"<<endl;
    }
    void test4_show_a()
    {
        
        cout<<(this->a4)<<endl;
    }

    void test4_set_a(int data)
    {
        this->a4 = data;
    }

};
class test5:public  test3
{
    int a5;
    public:
    int public_a5;
    test5()
    {
        cout<<"test5 constructor"<<endl;
    }
    ~test5()
    {
        cout<<"test5 deconstructor"<<endl;
    }
    void test5_show_a()
    {
        
        cout<<(this->a5)<<endl;
    }

    void test5_set_a(int data)
    {
        this->a5 = data;
    }

};
class test6:public  test4,public  test5
{
    int a6;
    public:
    int public_a6;
    test6()
    {
        cout<<"test6 constructor"<<endl;
    }
    ~test6()
    {
        cout<<"test6 deconstructor"<<endl;
    }
    void test6_show_a()
    {
        
        cout<<(this->a6)<<endl;
    }

    void test6_set_a(int data)
    {
        this->a6 = data;
    }

};

int main()
{

    //gọi parameterize constructor của base class 
    test2 temp2(2);
    cout<<"----------------------"<<endl;
    
    test6 temp6;
    cout<<"----------------------"<<endl;
    //do test6 kế thừa 2 lần test3 thông qua class test4,test5
    //để gộp thuộc tính của test3 thành duy nhất phải thêm 
    // virtual vào cả 2 class kết thừa test3
    //class test4:public virtual test3
    //class test5:public virtual test3
    // khi đó có thể truy cập như sau temp6.public_a3 
    //(không cần scope bởi vì test6 chỉ có 1 public_a3)

    cout<<temp6.test4::public_a3<<endl;
    cout<<temp6.test5::public_a3<<endl;

    temp6.test4::test3_set_a(5);
    temp6.test4::test3_show_a();

    temp6.test5::test3_set_a(55);
    temp6.test5::test3_show_a();

    cout<<"----------------------"<<endl;
}
// test constructor test(int a)=2
// test2 constructor test2(int a)=2
// ----------------------
// test3 constructor
// test4 constructor
// test3 constructor
// test5 constructor
// test6 constructor
// ----------------------
// 32759
// 32762
// 5
// 55
// ----------------------
// test6 deconstructor
// test5 deconstructor
// test3 deconstructor
// test4 deconstructor
// test3 deconstructor
// test2 deconstructor
// test deconstructor