#include <iostream>

using namespace std;

class FuShu {
    private:
        int real;
        int image;
    public:
        FuShu(int real=0,int image=0){
        this->real=real;
        this->image=image;
        }
        FuShu(FuShu &f){
        this->real=f.real;
        this->image=f.image;
        }
        FuShu operator+(FuShu &f){
        this->real=f.real+this->real;
        this->image=f.image+this->image;
        return *this;
        }
        bool operator==(FuShu &f){
        bool b=false;
        if((this->image==f.image)&&(this->real==f.real))
            b=true;
        return b;
        }
        FuShu operator++(){
        real++;
        return *this;
        }
        FuShu show(){
        cout<<real<<"+"<<image<<"i"<<endl;
        return *this;
        }
        friend ostream &operator<<(ostream &os,FuShu f);
};
ostream &operator<<(ostream &os,FuShu f){
    os<<f.real<<"+"<<f.image<<"i"<<endl;
    return os;
    }
int main()
{
    FuShu f1(2,2);
    cout<<" f1.show()=";
    f1.show();
    FuShu f2(5,5);
    FuShu f3;
    f3=f1+f2;
     cout<<" f3.show()=";
    f3.show();
    FuShu f4(9,8);
     cout<<" f4.show()=";
    f4.show();
    if(f4==f3)
        cout<<"ok"<<endl;
    else
        cout<<"no"<<endl;
    ++f4;
    cout<<" f4.show()=";
    f4.show().show();
cout<<f4<<"**********************\n";
    return 0;
}
