/* 
 * File:   Log.cpp
 * Author: Adrian
 * 
 * Created on 17. Dezember 2012, 13:55
 */

#include "Log.h"

// Konstruktor
//
Log::Log(){}

// Destruktor
// ---------------------------------------
// Gibt Ende-Meldung aus und schließ das Logfile
//
Log::~Log()
{
	// Logfile-Ende schreiben und Datei schließen
	Textout("<br><br> ------------------------------------", false);
        Textout("<br> End of logfile </font></body></html>", false);
	fclose(m_Logfile);
}

// CreateLogfile
// ---------------------------------------
// Logfile erstellen und Kopf schreiben
//
void Log::CreateLogfile(const char *LogName)
{
	// Logfile leeren und Kopf schreiben
	m_Logfile = fopen(LogName, "w");
	Textout("<html><head><title> Logfile </title></head>", false);
	Textout("<body><font face='courier new'>", false);
	WriteTopic("Logfile", 3);

    /*
	// Aktuelle Build-Konfiguration ausgeben
#ifdef _RELEASE
        Textout("BUILD: RELEASE <br>", false);
#else
        Textout("BUILD: DEBUG <br>", false);
#endif
    */
        
	// Link für E-Mail-Adresse schreiben
//	Textout("<a href='mailto:support@meineURL.de?subject=Logfile'>");
//	Textout("Send E-Mail to me</a><br><br>");

        Textout("<br><br>", false);
        
	// Logfile schließen und mit append wieder öffnen
	fclose(m_Logfile);
	m_Logfile = fopen(LogName, "a");

}

// WriteTopic
// ---------------------------------------
// Überschrift erzeugen
//
void Log::WriteTopic(const char *Topic, int Size)
{
	// Überschrift schreiben und flushen
	Textout("<table cellspacing='0' cellpadding='0' width='100%%' ", false);
	Textout("bgcolor='#DFDFE5'>\n<tr>\n<td>\n<font face='arial' ", false);
	fTextout("size='+%i'>\n", Size);
	Textout(Topic, false);
	Textout("</font>\n</td>\n</tr>\n</table>\n<br>", false);
	fflush(m_Logfile);
}

// Textout
// ---------------------------------------
// Text ins Logfile schreiben
//
void Log::Textout(const char *Text, bool endl)
{     
	// Text schreiben und flushen
	fprintf(m_Logfile, Text);
	fflush(m_Logfile);
        
        if(endl == true)
        {
            fprintf(m_Logfile, "<br>");
            fflush(m_Logfile);
        }
}

// Textout
// ---------------------------------------
// Text ins Logfile schreiben (farbig)
//
void Log::Textout(int Color, const char *Text, bool endl)
{
	Textout(Color, Text, false, endl);
}

// Textout
// ---------------------------------------
// Text ins Logfile schreiben (farbig, Liste)
//
void Log::Textout(int Color, const char *Text, bool List, bool endl)
{
	// Listen-Tag schreiben
	if(List == true)
        {
            Textout("<li>", false);
            endl = false;
        }

	// Farbtag schreiben
	switch(Color)
	{
		case BLACK:
			Textout("<font color=black>", false);  break;
		case RED:
			Textout("<font color=red>", false);    break;
		case GREEN:
			Textout("<font color=green>", false);  break;
		case BLUE:
			Textout("<font color=blue>", false);   break;
		case PURPLE:
			Textout("<font color=purple>", false); break;
	};

	// Text schreiben
	Textout(Text, endl);
	Textout("</font>", false);

	if(List == true)
            Textout("</li>", false);
}

// fTextout
// ---------------------------------------
// Formatierten Text ins Logfile schreiben (schwarz)
//
void Log::fTextout(const char *Text, ...)
{
	char buffer[MAX_BUFFER];  // char-Buffer
	va_list pArgList;         // Liste der übergebenen Argumente

	// String aus den Argumenten erstellen
	va_start(pArgList, Text);
	vsprintf(buffer, Text, pArgList);
	va_end(pArgList);

	// Erzeugten String schreiben
	Textout(buffer, false);
}

// fTextout
// ---------------------------------------
// Formatierten Text ins Logfile schreiben (farbig)
//
void Log::fTextout(int Color, const char *Text, ...)
{
	char buffer[MAX_BUFFER];  // char-Buffer
	va_list pArgList;         // Liste der übergebenen Argumente

	// String aus den Argumenten erstellen
	va_start(pArgList, Text);
	vsprintf(buffer, Text, pArgList);
	va_end(pArgList);

	// Erzeugten String schreiben
	Textout(Color, buffer, false);
}

// fTextout
// ---------------------------------------
// Formatierten Text ins Logfile schreiben (farbig, Liste)
//
void Log::fTextout(int Color, bool List, const char *Text, ...)
{
	char buffer[MAX_BUFFER];  // char-Buffer
	va_list pArgList;         // Liste der übergebenen Argumente

	// String aus den Argumenten erstellen
	va_start(pArgList, Text);
	vsprintf(buffer, Text, pArgList);
	va_end(pArgList);

	// Erzeugten String schreiben
	Textout(Color, buffer, List, false);
}

// FunctionResult
// ---------------------------------------
// OK oder ERROR für Funktionsaufruf ausgeben
//
void Log::FunctionResult(const char *Name, bool Result)
{
	if(L_OK == Result)
	{
		Textout("<table width='100%%' cellSpacing='1' cellPadding='5'", false);
		Textout(" border='0' bgcolor='#C0C0C0'><tr><td bgcolor=", false);
		fTextout("'#FFFFFF' width='35%%'>%s</TD>", Name);
		Textout("<td bgcolor='#FFFFFF' width='30%%'><font color =", false);
		Textout("'green'>OK</FONT></TD><td bgcolor='#FFFFFF' ", false);
		Textout("width='35%%'>-/-</TD></tr></table>", false);
	}
	else
	{
		Textout("<table width='100%%' cellSpacing='1' cellPadding='5'", false);
		Textout(" border='0' bgcolor='#C0C0C0'><tr><td bgcolor=", false);
		fTextout("'#FFFFFF' width='35%%'>%s</TD>", Name);
		Textout("<td bgcolor='#FFFFFF' width='30%%'><font color =", false);
		Textout("'red'>ERROR</FONT></TD><td bgcolor='#FFFFFF' ", false);
		Textout("width='35%%'>-/-</TD></tr></table>", false);
	}
} 
