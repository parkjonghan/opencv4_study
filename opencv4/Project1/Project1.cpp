// Project1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

/*
int& CalSum(int s, int e);
int main()
{

   //int i = 0;
   //int& r = i;

   //r = 9; //i=9와 같은 결과(r변수는 i변수를 참조)
   //cout << "i:" << i << endl;
   //return 0;


   int& r1 = CalSum(1,100);
   int &r2 = CalSum(1,10);
   cout << "r1:" << r1 << ",r2:" <<r2<< endl;

   return 0;
}

int& CalSum(int s, int e)
{
   int sum = 0;
   for (; s <= e; s++)
   {
      sum += s;
   }
   return sum;
}
*/
class  test
{
public :
    int a;

};


//기본자료형  char int 


int Add(int& r1, int& r2);
int Add(int i, int j);
int main()
{
    int re = Add(2, 3);
    int a = 2;
    int b = 4;
    int& c = a;
    int& d = b;
    cout << "re:" << re << endl;
    
    re = Add((int&)c,(int&)d);

    cout << "re:" << re << endl;
    return 0;
}


int Add(int & r1, int & r2)
{
    return r1 + r2;
}

int Add(int i, int j)
{
    return i + j;
}