#pragma once

#include<string>
#include<vector>

class AocUtils
{
  public:
  	static void readInput(const std::string fileName, std::vector<std::string> *);
  	static void tokenize(std::string &, std::string &delims, std::vector<int> &);
  	static void tokenize(std::string &, std::string &delims, std::vector<long> &);
  	static void tokenize(std::string &, std::string &delims, std::vector<long long> &);
  	static void tokenize(std::string &, std::string &delims, std::vector<unsigned long long> &);
  	static void tokenize(std::string &, std::string &delims, std::vector<std::string> &);
  	static bool isInteger(std::string &);
  	static bool isLong(std::string &);
  	static bool isLongLong(std::string &);
};
