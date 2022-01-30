#include <initializer_list>

class cVector{
 public:
  cVector():m_vecBuf(nullptr), m_vecSize(0), m_vecPos(0) {}
  cVector(std::initializer_list<int>vals);
  cVector(unsigned int s);
  cVector(unsigned int s, const int initVal);
  cVector(const cVector &arr);
  ~cVector();
  
  
  cVector& operator=(const cVector &arr);
  int& operator[](const int i);
  
  unsigned int size();
  unsigned int vPos();
  unsigned int vCap();
  int front();
  int back();
  void c_pushback(int s);
  void c_popback();
  void clear();
  bool isEmpty();

  
  private:
  int* m_vecBuf;
  unsigned int m_vecSize;
  unsigned int m_vecPos;
  
  
};