// ---------------------------------------------------------------------------
#ifndef linux
#pragma hdrstop
#endif

#include "UtilsString.h"
// ---------------------------------------------------------------------------

#ifndef linux
#pragma package(smart_init)
#endif

using namespace std;

namespace Utils {

  bool contains(std::string str, std::string subStr) {
    return str.find(subStr) != string::npos;
  }

  bool startsWith(std::string str, std::string substr) {
    if (substr.size() > str.size())
      return false;

    return str.substr(0, substr.length()) == substr;
  }

  bool endsWith(std::string str, std::string substr) {
    if (substr.size() > str.size())
      return false;

    return str.substr(str.length() - substr.length(), substr.length()) == substr;
  }

  string toUpperCase(string str) {
    ostringstream oss;
    for (unsigned int i = 0; i < str.length(); i++)
      oss << (char) toupper(str[i]);
    return oss.str();
  }

  string toLowerCase(string str) {
    ostringstream oss;
    for (unsigned int i = 0; i < str.length(); i++)
      oss << (char) tolower(str[i]);
    return oss.str();
  }

  std::string trim(std::string str, char c) {
    istringstream iss(str);
    ostringstream oss;
    string field;
    while (std::getline(iss, field, c)) {
      oss << field;
    }
    return oss.str();
  }

  std::string trimStarts(std::string str, std::string c) {
    while (startsWith(str, c)) {
     str.erase(0,1);
    }
    return str;
  }
  std::string trimEnds(std::string str, std::string c) {
    while (endsWith(str, c)) {
      str = rmLastChar(str);
    }
    return str;
  }
  std::string trimStartsAndEnds(std::string str, std::string c) {
    str = trimStarts(str, c);
    str = trimEnds(str, c);
    return str;
  }

  std::string rmLastChar(std::string str, int nbChar) {
	str.erase(str.size() - nbChar);
    return str;
  }

  bool charIsLetter(char c) {
    for (unsigned short i = (unsigned short)'a'; i <= (unsigned short)'z'; i++) {
      if ((char)(i) == c)
        return true;
    }
    for (unsigned short i = (unsigned short)'A'; i <= (unsigned short)'Z'; i++) {
      if ((char)(i) == c)
        return true;
    }
    return false;
  }

  bool charIsNumber(char c) {
    for (unsigned short i = (unsigned short)'0'; i <= (unsigned short)'9'; i++) {
      if ((char)(i) == c)
        return true;
    }
    return false;
  }

  float toFloat(std::string str) {
    if (str.find_first_not_of("0123456789.-+") != string::npos)
	  throw FormatException("Float");
    float f;
    std::stringstream ss;
    ss << str;
    ss >> f;
    if (ss.fail())
	  throw FormatException("Float");
    return f;
  }

  double toDouble(std::string str) {
    if (str.find_first_not_of("0123456789.-+") != string::npos)
	  throw FormatException("Double");
    double f;
    std::stringstream ss;
    ss << str;
    ss >> f;
    if (ss.fail())
	  throw FormatException("Double");
    return f;
  }

  int toInt(string str) {
    int n;
    if (str.substr(0, 2) == "0x") {
      if (str.find_first_not_of("0123456789xABCDEFabcdef") != string::npos)
		throw FormatException("Int");
	  char *endptr;
      n = strtol(str.c_str(), &endptr, 16);
    }
    else {
      if (str.find_first_not_of("0123456789.-+") != string::npos)
		throw FormatException("Int");
      std::stringstream ss;
      ss << str;
      ss >> n;
      if (ss.fail())
		throw FormatException("Int");
    }
    return n;
  }

  unsigned int toUInt(std::string str) {
    unsigned int n;
    if (str.substr(0, 2) == "0x") {
      if (str.find_first_not_of("0123456789xABCDEFabcdef") != string::npos)
		throw FormatException("Unsigned Int");
      char *endptr;
      n = strtoul(str.c_str(), &endptr, 16);
    }
    else {
      if (str.find_first_not_of("0123456789.+") != string::npos)
		throw FormatException("Unsigned Int");
      std::stringstream ss;
      ss << str;
      ss >> n;
      if (ss.fail())
		throw FormatException("Unsigned Int");
    }
    return n;
  }

  unsigned short toUShort(string str) {
    unsigned short n;
    if (str.substr(0, 2) == "0x") {
      if (str.find_first_not_of("0123456789xABCDEFabcdef") != string::npos)
		throw FormatException("Unsigned Short");
      char *endptr;
      n = strtoul(str.c_str(), &endptr, 16);
    }
    else {
      if (str.find_first_not_of("0123456789.+") != string::npos)
		throw FormatException("Unsigned Short");
      std::stringstream ss;
      ss << str;
      ss >> n;
      if (ss.fail())
		throw FormatException("Unsigned Short");
    }
    return n;
  }

  std::string toString(std::vector<std::string> list, std::string chevronChar, std::string separatorChar) {
    if (chevronChar.empty() && chevronChar != "[]" && chevronChar != "{}") {
	  throw FormatException("Chevron [] or {}");
    }
    ostringstream oss;
    oss << chevronChar.substr(0, 1);
    for (unsigned int i = 0; i < list.size(); i++) {
      oss << list[i];
      if (i + 1 < list.size()) oss << separatorChar;
    }
    oss << chevronChar.substr(1, 1);
    return oss.str();
  }

  std::string toString(std::vector<std::pair<std::string, unsigned int> >list, bool displayIntValueAssociated, std::string chevronChar,
    std::string separatorChar) {
    if (chevronChar.empty() && chevronChar != "[]" && chevronChar != "{}") {
	  throw FormatException("Chevron [] or {}");
	}
    ostringstream oss;
    oss << chevronChar.substr(0, 1);
    if (separatorChar == ".." && list.size() == 2) {
      oss << list[0].second << separatorChar << list[1].second;
    }
    else {
      for (unsigned int i = 0; i < list.size(); i++) {
        oss << list[i].first;
        if (displayIntValueAssociated) {
          oss << "(" << rmLastChar(toStringHex(list[i].second)) << ")";
        }
        if (i + 1 < list.size())
          oss << separatorChar;
      }
    }
    oss << chevronChar.substr(1, 1);
    return oss.str();
  }


  std::string toString(std::vector<unsigned short> list, std::string chevronChar, std::string separatorChar) {
    if (chevronChar.empty() && chevronChar != "[]" && chevronChar != "{}") {
	  throw FormatException("Chevron [] or {}");
    }
    ostringstream oss;
    oss << chevronChar.substr(0, 1);
    for (unsigned int i = 0; i < list.size(); i++) {
      oss << Utils::toString(list[i]);
      if (i + 1 < list.size()) oss << separatorChar;
    }
    oss << chevronChar.substr(1, 1);
    return oss.str();
  }



  std::vector<std::string>toVector(std::string str) {
    vector<std::string>v;
    if (str.empty() || str == "[]" || str == "{}") return v;

    // suppression des chevrons {} ou []
    if (   (!startsWith(str,"[") || !endsWith(str,"]"))
        && (!startsWith(str,"{") || !endsWith(str,"}"))) {
	  throw FormatException("Unsigned Short Vector, [str1,str2,str3] or {str1,str2,str3}");
    }
    str.erase(0, 1);
    str.erase(str.length() - 1, 1);
    return split(str, ',');
  }

  StrIntPair toStrIntPair(std::string str) {
    StringVector v = split(str, '(');
    if (v.size() != 2) {
      throw FormatException("Pair(String,UInt), strValue(intValue)");
    }

    if (!endsWith(v[1], ")")) {
      throw FormatException("Pair(String,UInt), strValue(intValue)");    }

    try {
      StrIntPair p = std::make_pair(v[0], toInt(rmLastChar(v[1])));
      return p;
    }
    catch (FormatException &E) {
      throw FormatException("Pair(String,UInt), strValue(intValue)");
    }
  }

  StrIntPairVector toVectorStrIntPair(std::string str) {
    StrIntPairVector v;
    vector<std::string> vv = toVector(str);
    for (unsigned int i = 0; i < vv.size(); i++) {
      try {
        v.push_back(toStrIntPair(vv[i]));
      } catch (FormatException &E) {
      throw FormatException
        ("Pair(String,UInt) Vector, {StrVal(IntVal),StrValue(IntVal),StrValue(IntVal)} or [...]");
      }
    }
    return v;
  }

  StrIntPairVector toVectorStrIntPair(StringVector v) {
    StrIntPairVector vv;
    for (unsigned int i = 0; i < v.size(); i++) {
      vv.push_back(std::make_pair(v[i],i));
    }
    return vv;
  }



  UShortVector toVectorUShort(std::string str) {
    vector<unsigned short>v;
    // Cas liste vide
    if (str.empty() || str == "[]" || str == "{}") return v;

    // suppression des chevrons []  ou {}
    if (   (!startsWith(str,"[") || !endsWith(str,"]"))
        && (!startsWith(str,"{") || !endsWith(str,"}"))) {
      throw FormatException("Unsigned Short Vector, [0,1,2,5,6,10] or {0,1,2,5,6,10} or [0..10] or {0..10}");
    }

    str.erase(0, 1);
    str.erase(str.length() - 1, 1);
    if (str.find("..") != string::npos) {
      // Format [x..y]
      unsigned int n1 = toUInt(str.substr(0, str.find("..")));
      unsigned int n2 = toUInt(str.substr(str.find("..") + 2, str.length() - str.find("..") - 2));
      if (n1 > n2) {
        throw FormatException("Unsigned Short Vector, [0,1,2,5,6,10] or {0,1,2,5,6,10} or [0..10] or {0..10}");
      }
      for (unsigned int i = n1; i < n2 + 1; i++) {
        v.push_back(i);
      }
    }
    else {
      // Format [1,3,5,6,8]
      vector<std::string>v_str = split(str, ',');
      for (unsigned int i = 0; i < v_str.size(); i++) {
        v.push_back(toUShort(v_str[i]));
      }
    }
    return v;
  }

  unsigned long toULong(string str) {
    unsigned long n;

    if (str.substr(0, 2) == "0x") {
      char *endptr;
      n = strtoul(str.c_str(), &endptr, 16);
    }
    else {
      if (str.substr(0, 1) == "-")
        throw FormatException("Unsigned Long");
      std::stringstream ss;
      ss << str;
      ss >> n;
      if (ss.fail())
        throw FormatException("Unsigned Long");
    }
    return n;
  }

  bool toBool(string str) {
    if (toUpperCase(str) == "TRUE")
      return true;
    if (toUpperCase(str) == "FALSE")
      return false;
	throw FormatException("Bool True|False");
  }

  AnsiString toAnsiString(std::string str) {
    return (AnsiString)str.c_str();
  }

  string toString(bool b) {
    if (b)
      return "True";
    return "False";
  }

  std::string toString(int i) {
    ostringstream oss;
    oss << i;
    return oss.str();
  }

  std::string toString(unsigned int i) {
    ostringstream oss;
    oss << i;
    return oss.str();
  }

  std::string toString(unsigned short i) {
    ostringstream oss;
    oss << i;
    return oss.str();
  }

  std::string toString(unsigned long i) {
    ostringstream oss;
    oss << i;
    return oss.str();
  }

  std::string toString(long i) {
    ostringstream oss;
    oss << i;
    return oss.str();
  }

  std::string toString(float f, unsigned short precision) {
    ostringstream oss;
    oss << fixed << setprecision(precision) << f;
    return oss.str();
  }

  std::string toString(double d, unsigned short precision) {
    ostringstream oss;
    oss << fixed << setprecision(precision) << d;
    return oss.str();
  }

  std::string toString(AnsiString as) {
    ostringstream oss;
    oss << as.c_str();
    return oss.str();
  }

  std::vector<std::string>split(string chaine, char separateur) {
    vector<string>vecteur;

    if (chaine.find(separateur) == string::npos) {
      vecteur.push_back(chaine);
    }
    else {
      string::size_type stTemp = chaine.find(separateur);

      while (stTemp != string::npos) {
        vecteur.push_back(chaine.substr(0, stTemp));
        chaine = chaine.substr(stTemp + 1);
        stTemp = chaine.find(separateur);
      }
      vecteur.push_back(chaine);
    }
    return vecteur;
  }

  std::vector<std::string>splitByNbOctets(string chaine, unsigned int nbOctets) {
    vector<string>vecteur;

    while (chaine.size() != 0) {
      // si la taille de la chaine est superieure au nb d'octets passe en parametre alors
      // - on recupere la sous-chaine de l'octet 0 a l'octet eparateur
      // - on reconstruit la chaine en lui enlevant la sous-chaine
      if (chaine.size() > nbOctets) {
        vecteur.push_back(chaine.substr(0, nbOctets - 1));
        chaine = chaine.substr(nbOctets, chaine.size());
      }
      // sinon c'est que c'est le dernier morceau du vecteur => on met dans le vecteur ce qui reste de la chaine
      else {
        vecteur.push_back(chaine.substr(0, chaine.size()));
        chaine = "";
      }
    }
    return vecteur;
  }

  std::string toStringBin(unsigned long word, unsigned short nbBits) {
    ostringstream oss("");
    oss << "0b";
    for (int i = nbBits - 1; i >= 0; i--) {
      /* if ((i + 1) % 8 == 0)
       oss << " "; */
      oss << getBit(word, i);
    }
    return oss.str();
  }

  std::string toStringHex(unsigned int value, unsigned short nbBytes, short idWord) {
    std::ostringstream oss;
    oss << hex;
    if (nbBytes > 0) {
     oss << std::setw(nbBytes * 2) << std::setfill('0');
    }
    oss << value;
    if (idWord < 0) {
      return toUpperCase(oss.str());
    }
    return Utils::toString(idWord) + "x" + toUpperCase(oss.str());
  }

  std::string toStringWithFill(unsigned short idx, unsigned short nbIdx, char fill){
    std::ostringstream oss;
    if (nbIdx > 1000) {
       oss << std::setw(4) << std::setfill(fill);
    } else if (nbIdx > 100) {
       oss << std::setw(3) << std::setfill(fill);
    } else if (nbIdx > 10) {
       oss << std::setw(2) << std::setfill(fill);
    }
    oss << idx;
    return oss.str();
  }

  std::string toStringLocalTime() {
    return toStringTime(true, ":", "", " ", true, true, true);
  }
  std::string toStringLocalTimeSecond() {
    return toStringTime(true, "-", "", "-", true, true, false);
  }
  std::string toStringLocalTimeMinute() {
    return toStringTime(true, "-", "", "-", true, false, false);
  }
  std::string toStringLocalTimeDay(std::string FieldsSeparator_i) {
    return toStringTime(true, "-", FieldsSeparator_i, ".", false, false, false);
  }

  std::string toStringTime(bool isLocalTime_i,
                           std::string TimeFieldsSeparator_i, std::string DateFieldsSeparator_i, std::string DateTimeSeparator_i,
                           bool DisplayTime, bool DisplaySeconds, bool DisplayMilliSeconds) {
    SYSTEMTIME Time_l;
    if (isLocalTime_i) {
     GetLocalTime(&Time_l);
    }  else {
     GetSystemTime(&Time_l);
    }

    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << Time_l.wYear;
    oss << DateFieldsSeparator_i << std::setw(2) << std::setfill('0') << Time_l.wMonth;
    oss << DateFieldsSeparator_i << std::setw(2) << std::setfill('0') << Time_l.wDay;

    if (!DisplayTime)
      return oss.str();

    oss << DateTimeSeparator_i << std::setw(2) << std::setfill('0') << Time_l.wHour;
    oss << TimeFieldsSeparator_i << std::setw(2) << std::setfill('0') << Time_l.wMinute;

    if (!DisplaySeconds)
      return oss.str();

    oss << TimeFieldsSeparator_i << std::setw(2) << std::setfill('0') << Time_l.wSecond;
    if (!DisplayMilliSeconds)
      return oss.str();


    oss << "." << std::setw(3) << std::setfill('0') << Time_l.wMilliseconds;
    return oss.str();
  }

  bool isInsideList(std::string str, std::vector<std::string> list) {
    for (unsigned int i = 0; i < list.size(); i++) {
      if (str == list[i]) return true;
    }
    return false;
  }

  bool isInsideList(std::string str, std::vector<std::pair<std::string, unsigned int> > list) {
    for (unsigned int i = 0; i < list.size(); i++) {
      if (str == list[i].first) return true;
    }
    return false;
  }

  bool isInsideList(unsigned short value, std::vector<unsigned short> list) {
    for (unsigned int i = 0; i < list.size(); i++) {
      if (value == list[i]) return true;
    }
    return false;
  }

  bool isInsideList(unsigned int value, std::vector<std::pair<std::string, unsigned int> > list) {
    for (unsigned int i = 0; i < list.size(); i++) {
      if (value == list[i].second) return true;
    }
    return false;
  }


}
