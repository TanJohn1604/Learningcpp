#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

cout<<222/7.0<<endl;
cout<<setprecision(3)<<222/7.0<<endl;
cout<<"-----------------------1"<<endl;

cout<<255<<endl;
cout<<setbase(8)<<255<<endl;
cout<<setbase(10)<<255<<endl;
cout<<setbase(16)<<255<<endl;
cout<<"-----------------------2"<<endl;

cout<<setfill('*')<<std::left;
cout<<setw(5)<<"Z"<<endl;
cout<<setw(5)<<"ZZAA"<<endl;
cout<<"-----------------------3"<<endl;

cout<<std::right;;
cout<<setw(5)<<"Z"<<endl;
cout<<setw(5)<<"ZZAA"<<endl;
cout<<"-----------------------4"<<endl;

cout<<setfill(' ')<<setbase(10);
cout<<std::showpos;
cout<<setprecision(6);
cout<<22/7.0<<endl;
cout<<-22/7.0<<endl;
cout<<"-----------------------5"<<endl;
cout<<std::noshowpos;
cout<<setprecision(6);
cout<<22/7.0<<endl;
cout<<-22/7.0<<endl;
cout<<"-----------------------6"<<endl;
cout<<std::noshowpoint;
cout<<2.0<<endl;
cout<<std::showpoint;
cout<<2.0<<endl;
cout<<"-----------------------7"<<endl;

}
