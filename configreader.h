#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <QFile>
#include <QTextStream>
#include <QString>

using namespace std;

class configreader {
 public:
  // reads the file from filename
  configreader(const string& filename);

  // get config file value from key
  string mapGet(const string& key) const;

 private:
  map<string, string> m_config; // map for storing config file key value pairs
};

#endif // CONFIGREADER_H
