#pragma once

#include <map>
#include <string>
#include <vector>

class Argument {
public:
  void set(std::string, std::string);
  void set(std::string);

  std::string key() const;
  std::string value() const;

  bool hasParam() const;

  bool operator==(Argument const &) const;

private:
  std::string mKey;
  std::string mValue;
};

class Arguments {
public:
  Arguments();
  Arguments(std::vector<std::string> const &, std::vector<std::string> const &);

  void setTranslation(std::map<std::string, std::string> const &);

  void parse(int, char *[]);
  void parse(std::vector<std::string> const &);

  std::string get(std::string const &) const;
  bool has(std::string const &) const;
  bool has(Argument const &) const;

  std::string info();

private:
  std::vector<Argument> mArguments;
  std::vector<std::string> parameatredArguments;
  std::vector<std::string> simpleArguments;
  std::map<std::string, std::string> mTranslationDict;
};