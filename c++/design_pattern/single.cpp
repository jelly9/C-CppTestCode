/**
 * @file 
 *  * @author xiaoguodong 1799553128@qq.com
 *   * @date 
 *    * @brief
 *     **/

#include <iostream>
using namespace std;

template < class T >
class Singleton{
public:
    static T *GetInstance () {
        
        if ( m_instance == NULL ) {
            pthread_mutex_lock(&mutex);
            if ( m_instance == NULL ) {
                m_instance = new T();
            }
            pthread_mutex_unlock(&mutex);
        }

        return m_instance;
    }
private:
    Singleton () {}
    Singleton ( const Singleton& );
    Singleton& operator = ( const Singleton& );

    static T *m_instance;
    static pthread_mutex_t mutex;
};

template < class T >
T* Singleton<T>::m_instance = NULL;

template < class T >
pthread_mutex_t Singleton<T>::mutex = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    int *s1 =  Singleton<int>::GetInstance();
    int *s2 =  Singleton<int>::GetInstance();

    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;

    return 0;
}
