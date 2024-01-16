#include <iostream>
using namespace std;
class Base {
   char m_data = '?';
public:
   Base() :m_data('B') {};
   Base(char data) :m_data(data) {}
   Base(const Base& B) {
      cout << "Base ["<< B.m_data << "] Copy" << endl;
      m_data = B.m_data;
   }
   Base& operator=(const Base& B) {
      cout << "Base [" << m_data << "] Assigned to [" <<B.m_data << "]" <<  endl;
      if (this != &B) m_data = B.m_data;
      return *this;
   }
   virtual ~Base() {
      cout << "~Base [" << m_data << "]" << endl;
   }
   virtual ostream& show(ostream& ostr= cout)const {
      return ostr << "Base[" << m_data << "]";
   }
};
ostream& operator<<(ostream& ostr, const Base& B) {
   return B.show(ostr);
}
class Derived : public Base {
   char m_data = '?';
public:
   Derived():m_data('D'){}
   Derived(char data) :Base(data+1), m_data(data) {}
  /* Derived(const Derived& D) {
      cout << "Derived [" << D.m_data << "] Copy" << endl;
      m_data = D.m_data;
   }
   Derived& operator=(const Derived& D) {
      cout << "Derived [" << m_data << "] Assigned to [" << D.m_data << "]" << endl;
      if (this != &D) m_data = D.m_data;
      return *this;
   }
   virtual ~Derived() {
      cout << "~Derived [" << m_data << "]" << endl;
   }*/
   virtual ostream& show(ostream& ostr = cout)const {
      ostr << "Derived[" << m_data << "] holding ";
      return Base::show(ostr) << " inside!";
   }
};

void show(Derived D) {
   Derived A = 'a';
   cout << D << endl;
   A = D;
   cout << A << endl;
}
// if the base needs rule of three and derivde does not, 
// you do not need to implemente the rule of three
int main() {
   Derived X('X');
   show(X); // show(Derived D = X);
   return 0;
}
