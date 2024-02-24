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
    this->a = 1;
    this->b = 2;
    this->c = 3;
}

//(test a) đại diện cho giá trị bên phải dấu ==
//vd (temp==temp2)
int operator == (test a);


//(int a) đại diện cho giá trị bên phải dấu ==
//vd (temp==2)
int operator == (int a);

int operator [] (int data);

//friend + overload toán tử > để so sánh 2 class
friend void operator >(test data1, test2 data2);
};

class test2
{
    int a;
    public:
    void test2_show_a()
    {
        cout<<(this->a)<<endl;
    }

    void test2_set_a(int data)
    {
        this->a = data;
    }

    //friend + overload toán tử > để so sánh 2 class
    friend void operator >(test data1, test2 data2);

    //overload >> và <<
    friend void operator >>(istream &in,test2 &data);
    friend void operator <<(ostream &out,test2 &data);
};
//overload >>
void operator >>(istream &in,test2 &data)
{
    in>>data.a;
}
//overload <<
void operator <<(ostream &out,test2 &data)
{
    out<<"member a="<<data.a;
}

void operator >(test data1, test2 data2)
{
    if(data1.a > data2.a)
    {
        cout<< "param 1 lớn hơn"<<endl;
    }
    else
    {
        cout<< "param 1 không lớn hơn"<<endl;
    }
}

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

int test::operator == (test data)
{

    return this->a == data.a ;
}

int test::operator == (int data)
{

    return data == this->a;
}

int test::operator [] (int data)
{

    return this->a+data;
}

int main()
{
    test temp,temp2;
    test2 temp3;
    temp2.public_set_a(33);

    cout<<(temp2==temp)<<endl;
    cout<<(temp2==2)<<endl;
    cout<<(temp2==33)<<endl;
    cout<<(temp2[2])<<endl;
// 0
// 0
// 1
// 35
    temp.public_set_a(3);
    temp3.test2_set_a(12);    
    temp>temp3;
// param 1 không lớn hơn
    cin>>temp3;
    cout<<temp3;
    cout<<endl;
    temp3.test2_show_a();

}
