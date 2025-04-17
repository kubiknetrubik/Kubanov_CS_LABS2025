#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>
//variant 5
class Rectangle {
    double a;  // ширина
    double b;  // длина
   public:
    Rectangle() : a(0), b(0) {}
    Rectangle(double a, double b) : a(a), b(b) {}
    friend std::ostream& operator<<(std::ostream& out, Rectangle& rec);
    bool operator<(Rectangle& rec);
    bool operator==(Rectangle& rec);
    double GetS(){
        return a*b;
    }
};

std::ostream& operator<<(std::ostream& out, Rectangle& rec){
    out<<std::fixed << std::setprecision(1)<<std::setw(4)<<rec.a<<' '<<std::setw(4)<<rec.b<<'\n';
    return out;
}
bool Rectangle::operator<(Rectangle& rec){
    int s1=a*b;
    int s2=rec.a*rec.b;
    if(s1<s2){
        return true;
    }
    return false;

}
bool Rectangle::operator==(Rectangle& rec){
    int s1=a*b;
    int s2=rec.a*rec.b;
    if(s1==s2){
        return true;
    }
    return false;

}
void print(std::vector<Rectangle> vector){
    for(int i = 0;i<vector.size();++i){
        std::cout<<vector[i];
    }
}
int main() {
    std::vector<Rectangle> rects={{1.2,6.3},{4.0,0.7}};
    //{Rectangle(1.2, 6.3),Rectangle(4.0, 0.7),Rectangle(7.2, 0.8),Rectangle(5.3, 3.0),Rectangle(4.9, 6.6),Rectangle(9.3, 0.2)};
    print(rects);
    Rectangle maxi{};
    double ms=0;
    int msi=0;
    for (int i = 0; i < rects.size(); ++i) {
        ms=std::max(ms,rects[i].GetS());
        
        if(ms==rects[i].GetS()){
            msi=i;
        }

    }
    std::cout << "BiggestRECTANGLE " << rects[msi];
    rects.clear();

    return 0;
}
