
#include "Log.hpp"
#include <cstdarg>

Log::Log() {
}

Log::~Log() {
    // write end of logfile and close file
    Textout("<br><br> ------------------------------------", false);
    Textout("<br> End of logfile </font></body></html>", false);
    fclose(m_Logfile);
}

// CreateLogfile
//

void Log::CreateLogfile(const char *LogName) {
    // clear log and write head
    m_Logfile = fopen(LogName, "w");
    Textout("<html><head><title> Logfile </title></head>", false);
    Textout("<body><font face='courier new'>", false);
    WriteTopic("Logfile", 3);

    /*
        // release- or debug-build?
        //
#ifdef _RELEASE
        Textout("BUILD: RELEASE <br>", false);
#else
        Textout("BUILD: DEBUG <br>", false);
#endif
     */

    // add email
    //
    //	Textout("<a href='mailto:support@meineURL.de?subject=Logfile'>");
    //	Textout("Send E-Mail to me</a><br><br>");

    Textout("<br><br>", false);

    // close log and open it again with "append" 
    fclose(m_Logfile);
    m_Logfile = fopen(LogName, "a");

}

// WriteTopic
// ---------------------------------------
//

void Log::WriteTopic(const char *Topic, int Size) {
    // write headline and flush it
    Textout("<table cellspacing='0' cellpadding='0' width='100%%' ", false);
    Textout("bgcolor='#DFDFE5'>\n<tr>\n<td>\n<font face='arial' ", false);
    fTextout("size='+%i'>\n", Size);
    Textout(Topic, false);
    Textout("</font>\n</td>\n</tr>\n</table>\n<br>", false);
    fflush(m_Logfile);
}

// Textout
// ---------------------------------------
//

void Log::Textout(const char *Text, bool endl) {
    fprintf(m_Logfile, Text);
    fflush(m_Logfile);

    if (endl == true) {
        fprintf(m_Logfile, "<br>");
        fflush(m_Logfile);
    }
}

// Textout (color)
// ---------------------------------------
//

void Log::Textout(int Color, const char *Text, bool endl) {
    Textout(Color, Text, false, endl);
}

// Textout (color, list)
// ---------------------------------------
//

void Log::Textout(int Color, const char *Text, bool List, bool endl) {
    if (List == true) {
        Textout("<li>", false);
        endl = false;
    }

    switch (Color) {
        case BLACK:
            Textout("<font color=black>", false);
            break;
        case RED:
            Textout("<font color=red>", false);
            break;
        case GREEN:
            Textout("<font color=green>", false);
            break;
        case BLUE:
            Textout("<font color=blue>", false);
            break;
        case PURPLE:
            Textout("<font color=purple>", false);
            break;
    };

    Textout(Text, endl);
    Textout("</font>", false);

    if (List == true)
        Textout("</li>", false);
}

// fTextout (format)
// ---------------------------------------
//

void Log::fTextout(const char *Text, ...) {
    char buffer[MAX_BUFFER]; // char-Buffer
    va_list pArgList;

    va_start(pArgList, Text);
    vsprintf(buffer, Text, pArgList);
    va_end(pArgList);

    Textout(buffer, false);
}

// fTextout (format, color)
// ---------------------------------------
//

void Log::fTextout(int Color, const char *Text, ...) {
    char buffer[MAX_BUFFER];
    va_list pArgList;

    va_start(pArgList, Text);
    vsprintf(buffer, Text, pArgList);
    va_end(pArgList);

    Textout(Color, buffer, false);
}

// fTextout (format, color, list)
// ---------------------------------------
//

void Log::fTextout(int Color, bool List, const char *Text, ...) {
    char buffer[MAX_BUFFER];
    va_list pArgList;

    va_start(pArgList, Text);
    vsprintf(buffer, Text, pArgList);
    va_end(pArgList);

    Textout(Color, buffer, List, false);
}

// FunctionResult
// ---------------------------------------
//

void Log::FunctionResult(const char *Name, bool Result) {
    if (L_OK == Result) {
        Textout("<table width='100%%' cellSpacing='1' cellPadding='5'", false);
        Textout(" border='0' bgcolor='#C0C0C0'><tr><td bgcolor=", false);
        fTextout("'#FFFFFF' width='35%%'>%s</TD>", Name);
        Textout("<td bgcolor='#FFFFFF' width='30%%'><font color =", false);
        Textout("'green'>OK</FONT></TD><td bgcolor='#FFFFFF' ", false);
        Textout("width='35%%'>-/-</TD></tr></table>", false);
    } else {
        Textout("<table width='100%%' cellSpacing='1' cellPadding='5'", false);
        Textout(" border='0' bgcolor='#C0C0C0'><tr><td bgcolor=", false);
        fTextout("'#FFFFFF' width='35%%'>%s</TD>", Name);
        Textout("<td bgcolor='#FFFFFF' width='30%%'><font color =", false);
        Textout("'red'>ERROR</FONT></TD><td bgcolor='#FFFFFF' ", false);
        Textout("width='35%%'>-/-</TD></tr></table>", false);
    }
}
