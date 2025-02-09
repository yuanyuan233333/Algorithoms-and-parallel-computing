#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

typedef std::map<std::string, std::string> dictionary_type;

void word_transform (std::ifstream& map_file, std::ifstream& content_file);
dictionary_type buildMap (std::ifstream& ifs);
std::string transform (const std::string& s, const dictionary_type& dictionary);

int main() {
  std::ifstream map_file("../map_file.txt");
  std::ifstream content_file("../content_file.txt");

  word_transform(map_file, content_file);

  return 0;
}

void word_transform (std::ifstream& map_file, std::ifstream& content_file)
{
  dictionary_type dictionary = buildMap(map_file);

  std::string line;
  while (getline(content_file, line))
  {
    std::istringstream iss(line);

    std::string word;
    while (getline(iss, word, ' '))
      std::cout << transform(word, dictionary) << " ";
    std::cout << std::endl;
  }
}

dictionary_type buildMap (std::ifstream& ifs)
{
  dictionary_type dictionary;

  std::string key, value;
  while(ifs >> key >> value)
    dictionary[key] = value;

  return dictionary;
}

std::string transform (const std::string& s, const dictionary_type& dictionary)
{
  std::string new_s = s;

  dictionary_type::const_iterator it = dictionary.find(s);
  if (it != dictionary.cend())
    new_s = it->second;

  return new_s;
}
