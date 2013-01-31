/* 
 * File:   Singleton.h
 * Author: Adrian
 *
 * Created on 17. Dezember 2012, 13:58
 */

#ifndef SINGLETON_H
#define	SINGLETON_H

template <class T>
class TSingleton
{
  protected:
    static T *m_pSingleton;

  public:
    virtual ~TSingleton()
    {
    }

    inline static T* Get()
    {
      if(!m_pSingleton)
        m_pSingleton = new T;

      return(m_pSingleton);
    }

    static void Del()
    {
      if(m_pSingleton)
      {
        delete(m_pSingleton);  
        m_pSingleton = 0; 
      }
    }
};

template <class T>
T* TSingleton<T>::m_pSingleton = 0;

#endif	/* SINGLETON_H */

