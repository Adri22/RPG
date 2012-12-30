/* 
 * File:   Log.h
 * Author: Adrian
 *
 * Created on 17. Dezember 2012, 13:55
 */

#include <windows.h>
#include <stdio.h>
#include "Singleton.hpp"

#ifndef LOG_H
#define	LOG_H

#define MAX_BUFFER 1024
#define L_FAIL false
#define L_OK true
#define g_pLogfile Log::Get()            

enum FONTCOLORS
{
    BLACK,
    RED, 
    GREEN, 
    BLUE,
    PURPLE
};

class Log : public TSingleton<Log>
{
    public:
        Log();
        ~Log();
        void CreateLogfile      (const char *LogName);          // important: .html or .htm
        void WriteTopic         (const char *Topic, int Size);
        void Textout            (const char *Text, bool endl);
        void Textout            (int Color, const char *Text, bool endl);
        void Textout            (int Color, const char *Text, bool List, bool endl);
        void fTextout           (const char *Text, ...);
        void fTextout           (int Color, const char *Text, ...);
        void fTextout           (int Color, bool List, const char *Text, ...);
        void FunctionResult     (const char *Name, bool Result);
        
    private:
        FILE *m_Logfile;
};

#endif	/* LOG_H */

