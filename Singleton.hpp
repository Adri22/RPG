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

    // Membervariablen
    static T *m_pSingleton;   // Statisches Objekt

  public:

    // Memberfunktionen

    // Destruktor
    //
    virtual ~TSingleton()
    {
    }

    // Get
    //
    // Aufgabe: Wenn nötig, statisches Objekt erzeugen und
    // Zeiger darauf zurückgeben
    //
    inline static T* Get()
    {
      // Existiert schon eine Instanz?
      if(!m_pSingleton)
        m_pSingleton = new T;   // Nein, dann neue Instanz erzeugen

      // Zeiger auf die Instanz zurückgeben
      return(m_pSingleton);

    } // Get

    // Statisches Objekt freigeben
    //
    static void Del()
    {
      // Gab es eine Instanz?
      if(m_pSingleton)
      {
        delete(m_pSingleton);   // Ja, dann freigeben
        m_pSingleton = NULL;    // und Zeiger auf NULL setzen
      }

    } // Del

};

// Die statische Variable erzeugen
//
template <class T>
T* TSingleton<T>::m_pSingleton = 0;

#endif	/* SINGLETON_H */

