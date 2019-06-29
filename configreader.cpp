#include "configreader.h"

configreader::configreader(const string& filename) {
  // open the file from path string
  QFile file(filename.c_str());

  // check if we have read perrmission
  if(!file.open(QIODevice::ReadOnly)) {
    qWarning("Fail to open file");
  }
  // load the content into textstream
  QTextStream in(&file);

  // read the stream line by line, split on "="
  while(!in.atEnd()) {
    QString line = in.readLine();
    QStringList fields = line.split("=");
    QString key = fields[0];
    QString value = fields[1];
    // put the key value pair in a map
    m_config[key.toStdString()] = value.toStdString();
  }

  file.close();
}

string configreader::mapGet(const string& key) const {
  return m_config.at(key);
}
