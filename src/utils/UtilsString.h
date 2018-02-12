// ---------------------------------------------------------------------------

#ifndef UtilsStringH
#define UtilsStringH
// ---------------------------------------------------------------------------

#include <vcl.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <xstring>
#include <windows.h>

#include "FormatException.h"
#include "UtilsBinary.h"

namespace Utils {

  typedef std::vector<std::string>StringVector;
  typedef std::vector<unsigned short>UShortVector;

  typedef std::pair<std::string, unsigned int>StrIntPair;
  typedef std::vector<StrIntPair>StrIntPairVector;

  bool startsWith(std::string str, std::string subStr);
  bool endsWith(std::string str, std::string subStr);
  bool contains(std::string str, std::string subStr);
  std::string toUpperCase(std::string str);
  std::string toLowerCase(std::string str);
  std::string trim(std::string str, char c = ' ');
  std::string trimStarts(std::string str, std::string c = " ");
  std::string trimEnds(std::string str, std::string c = " ");
  std::string trimStartsAndEnds(std::string str, std::string c = " ");
  std::string rmLastChar(std::string str, int nbChar = 1);

  int toInt(std::string str);
  unsigned int toUInt(std::string str);
  unsigned short toUShort(std::string str);
  unsigned long toULong(std::string str);
  float toFloat(std::string str);
  double toDouble(std::string str);
  bool toBool(std::string str);
  StrIntPair toStrIntPair(std::string str);
  AnsiString toAnsiString(std::string str);

  std::string toString(AnsiString as);
  std::string toString(bool b);
  std::string toString(int i);
  std::string toString(unsigned int i);
  std::string toString(unsigned short i);
  std::string toString(unsigned long i);
  std::string toString(long i);
  std::string toString(float f, unsigned short = 3);
  std::string toString(double d, unsigned short = 3);
  std::string toString(std::vector<std::string>list, std::string chevronChar = "{}", std::string separatorChar = ",");
  std::string toString(std::vector<unsigned short>list, std::string chevronChar = "{}", std::string separatorChar = ",");
  std::string toString(std::vector<std::pair<std::string, unsigned int> >list, bool displayIntValueAssociated = false, std::string chevronChar = "{}",
    std::string separatorChar = ",");

  // std::string toBinaryStr(unsigned int i, unsigned short nbBits = sizeof(unsigned int) * 8);
  // std::string toBinaryStr(unsigned short i, unsigned short nbBits = sizeof(unsigned short) * 8);
  std::string toStringBin(unsigned long i, unsigned short nbBits = sizeof(unsigned long) * 8);
  std::string toStringHex(unsigned int value, unsigned short nbBytes = 0, short idWord = 0);

  std::string toStringWithFill(unsigned short idx, unsigned short nbIdx, char fill = '0');

  std::string toStringTime(bool isLocalTime_i, std::string TimeFieldsSeparator_i, std::string DateFieldsSeparator_i,
    std::string DateTimeSeparator_i, bool DisplayTime, bool DisplaySeconds, bool DisplayMilliSeconds);

  std::string toStringLocalTime();
  std::string toStringLocalTimeSecond();
  std::string toStringLocalTimeMinute();
  std::string toStringLocalTimeDay(std::string FieldsSeparator_i = "");

  bool charIsLetter(char c);
  bool charIsNumber(char c);

  // Format de la chaine d'entree [0,1,2,5,6,10] ou [0..10]
  UShortVector toVectorUShort(std::string str);

  // Format de la chaine d'entree {aa,bbb,cccc,dddd,eeee,ffffff} ou [aa,bbb,cccc,dddd,eeee,ffffff]
  StringVector toVector(std::string str);

  // Format de la chaine d'entree [OFF(0),ON(1),UNDEFINED(15)]
  StrIntPairVector toVectorStrIntPair(std::string str);
  StrIntPairVector toVectorStrIntPair(StringVector v);

  StringVector split(std::string chaine, char separateur);

  /* fonction qui decoupe la chaine passee en parametre en paquet d'octets defini par le parametre nbOctets */
  StringVector splitByNbOctets(std::vector<std::string>& vecteur, std::string chaine, unsigned int nbOctets);

  bool isInsideList(std::string str, std::vector<std::string>list);
  bool isInsideList(std::string str, std::vector<std::pair<std::string, unsigned int> >list);
  bool isInsideList(unsigned short value, std::vector<unsigned short>list);
  bool isInsideList(unsigned int value, std::vector<std::pair<std::string, unsigned int> >list);

}
#endif
