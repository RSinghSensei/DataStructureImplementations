#include "cVector.h"

cVector::cVector(std::initializer_list<int>vals)
{
    m_vecSize = vals.size();
    m_vecPos = vals.size() - 1;
    m_vecBuf = new int[m_vecSize];
    auto it = vals.begin();
    
    for (int i = 0; i < m_vecSize; i++){
        m_vecBuf[i] = *it;
        it++;
    }
    
}

cVector::cVector(unsigned int s)
{
    m_vecSize = s;
    m_vecPos = 0;
    m_vecBuf = new int[s];
    for (int i = 0; i < s; i++){
        m_vecBuf[i] = 10;
    }
}

cVector::cVector(const cVector &arr)
{
    m_vecSize = arr.m_vecSize;
    m_vecPos = arr.m_vecSize - 1;
    m_vecBuf = new int[m_vecSize];
    for (int i = 0; i < m_vecSize; i++){
        m_vecBuf[i] = arr.m_vecBuf[i];
    }
        
}

cVector::cVector(unsigned int s, const int initVal)
{
    m_vecSize = s;
    m_vecPos = s - 1;
    m_vecBuf = new int[m_vecSize];
    
    for (int i = 0; i < m_vecSize; i++){
        m_vecBuf[i] = initVal;
    }
    
}

cVector::~cVector(){}

cVector& cVector::operator=(const cVector &arr)
{
    m_vecSize = arr.m_vecSize;
    m_vecPos = arr.m_vecPos;
    m_vecBuf = new int[m_vecSize];
    
    for (int i = 0; i < m_vecSize; i++){
        m_vecBuf[i] = arr.m_vecBuf[i];
    }
    
    return *this;
    
}

int& cVector::operator[](const int i)
{
    return m_vecBuf[i];
}

unsigned int cVector::vCap()
{
    return m_vecSize;
       
}

unsigned int cVector::size()
{
    return m_vecPos;
       
}

int cVector::front()
{
    return m_vecBuf[0];
}

int cVector::back()
{
    return m_vecBuf[m_vecSize];
}

void cVector::c_pushback(int s)
{
    if (m_vecPos == m_vecSize)
    {
        m_vecSize*=2;
        int* tempSpace = new int[m_vecSize];
        for (int i = 0; i < m_vecPos; i++){
            tempSpace[i] = m_vecBuf[i];
        }
        delete[] m_vecBuf;
        m_vecBuf = tempSpace;
    }
    m_vecBuf[m_vecPos] = s;
    m_vecPos+=1;
    
}

void cVector::c_popback()
{
    m_vecBuf[m_vecPos] = 0;
    m_vecPos-=1;
    
}

unsigned int cVector::vPos()
{
    return m_vecPos;
}


void cVector::clear()
{
    for (int i = 0; i < m_vecPos; i++){
        m_vecBuf[i] = 0;
    }
    m_vecPos = 0;
    
}

bool cVector::isEmpty()
{
    return m_vecPos == 0 ? true: false;
}