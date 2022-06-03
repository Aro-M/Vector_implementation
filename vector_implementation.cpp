#include <iostream>
#include <initializer_list>


template <typename T>
class Vector
{
public:
    Vector();
    Vector(const Vector<T>&);
    Vector(Vector<T>&&);
    Vector(size_t,T);
    Vector(T);
    Vector(std::initializer_list<T>);
    ~Vector();
    Vector& operator=(const Vector<T>&);
    Vector& operator=(Vector<T>&&);
    T& operator[](int index);
    void print();
    bool empty();
    void clear();
    void size();
    void shrink_to_fit();
    void capacity();
    void erase(int indexs);
    void pop_back();
    void push_back(int value);
    void insert(int index,T value);
    int at(int index);
  
private:
    size_t m_cap;
    size_t m_size;
    T* m_buf;
};

template <typename T>
T& Vector<T>::operator[](int index){
    if(index >= m_size){
        std::cout << " No found "<<std::endl;
        exit(0);
    }
    
    return m_buf[index];
}

template<typename T>
void Vector<T>::print()
{
    for(int i = 0; i < m_size; ++i) {
    std::cout << m_buf[i] << " " ;
    }
    std::cout<<std::endl;
}



template <typename T>
Vector<T>::Vector() :
    m_cap{1},
    m_size{},
    m_buf{}
{}

template <typename T>
Vector<T>::Vector(const Vector<T>& oth) :
    m_cap(oth.m_cap),
    m_size(oth.m_size),
    m_buf{}
{
    m_buf = new T[m_cap];
    for(int i = 0; i < m_size; ++i) {
        m_buf[i] = oth.m_buf[i];
    }
}

template <typename T>
Vector<T>::Vector(Vector<T>&& tmp) :
    m_cap(tmp.m_cap),
    m_size(tmp.m_size),
    m_buf(tmp.m_buf)
{
    tmp.m_cap = 0;
    tmp.m_size = 0;
    tmp.m_buf = nullptr;
}
template <typename T>
Vector<T>::Vector(size_t cap,T val) :
    m_cap(cap),
    m_size(cap),
    m_buf(new T[m_cap])
{
    for(int i = 0; i < m_size; ++i) {
    m_buf[i] = val;
    }
}

template <typename T>
Vector<T>::Vector(T count) :
    m_cap(count),
    m_size(count),
    m_buf(new T[m_cap])
{}
template <typename T>
Vector<T>::Vector(std::initializer_list<T> init) :
    m_cap(init.size()),
    m_size(m_cap),
    m_buf(new T[m_cap])
{
    int i = 0;
    for(auto it = init.begin(); it != init.end(); ++it) {
        m_buf[i++] = *it;
    }
}

template <typename T>
Vector<T>::~Vector()
{
    if(m_buf) {
        delete[] m_buf;
    }
    m_buf = nullptr;
}

template <typename T>
void Vector<T>::push_back(int value ){
 
    m_cap++;
    m_buf[m_size++] = value;
}

template <typename T>
void Vector<T>::pop_back( ){
 
    m_cap--;
    m_buf[m_size--];
}

template <typename  T>
void Vector<T>::clear(){
    m_buf = nullptr;
    m_size = 0;
    m_cap = 0;
    
}

template <typename T >
void Vector<T>::capacity(){
    std::cout << m_cap << std::endl;
}

template <typename T>
bool Vector<T>::empty(){
    if(m_size){
        return true;
    }
    return false;
}

template <typename T>
void Vector<T>::size(){
    
    std::cout << m_size << std::endl;
}

template <typename T>
void Vector<T>::shrink_to_fit(){
    
    if(m_cap > m_size){
        m_cap = m_size;
    }
}

template <typename T>
int Vector<T>::at(int index){
    for(int i = 0; i < m_size;++i){
        if(i ==  index){
           return m_buf[i];
        }
    }return 0;
  
}
template <typename T>
void Vector<T>::erase(int index){
    std::cout << m_cap << " capacity"<<m_size<<std::endl;
    
    
    T* tmp = new T[m_cap];
    int j = 0;
   for(int i = 0; i < m_size; i++)
   {
      if(index == i) {
          ++i;
      }
      tmp[j] = m_buf[i];
      ++j;
       
   } 
    --m_size;
   delete[] m_buf;
   m_buf = tmp;
   tmp = nullptr;
   

    
}


template <typename T>
void Vector<T>::insert( int index ,T value)
{
  T* tmp = new T[m_cap];
   for(int i = 0; i < m_size; i++)
   {
       if(i != index)
       {
           tmp[i] = m_buf[i];
       }
   }
   if(m_size == m_cap){
   m_cap *=2;
   }
   m_size ++;
   tmp[index++] = value;
   delete[] m_buf;
   m_buf = tmp;
   tmp = nullptr;

}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& oth)
{
    if(this == &oth) {
        return *this;
    }
    if(this->m_buf) {
        delete[] m_buf;
    }
    m_cap = oth.m_cap;
    m_size = oth.m_size;
    m_buf = new T[m_cap];
    for(int i = 0; i < m_size; ++i) {
        m_buf[i] = oth.m_buf[i];
    }
    return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& tmp)
{
    std::swap(m_cap, tmp.m_cap);
    std::swap(m_size, tmp.m_size);
    std::swap(m_buf, tmp.m_buf);
    return *this;
}



int main()
{
   Vector<int> vec;
   vec.insert(0,7);
    vec.insert(1,4);
     vec.insert(2,8);
      vec.insert(3,9);
       vec.insert(4,81);
      vec.insert(5,90);
          vec.insert(6,91);
       vec.insert(7,814);
      vec.insert(8,97);
      vec.insert(9,14);
      vec.insert(10,7);
    //vec.clear();
 //  std::cout <<vec.empty()<<std::endl;
   //vec.capacity();
  // vec.size();
   
vec.print();
//vec.shrink_to_fit();
vec.push_back(8);
vec.print();
vec.pop_back();
vec.print();
vec.erase(1);
std::cout<<vec.at(2);
std::cout <<std::endl;
vec.print();
  vec.capacity();
  std::cout<<vec[10];
}

