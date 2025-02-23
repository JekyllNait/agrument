#include <argument.h>

#include <algorithm>
#include <iostream>

void Argument::set(std::string key, std::string value) {
  mKey = key;
  mValue = value;
}

void Argument::set(std::string key) {
  mKey = key;
}

std::string Argument::key() const {
  return mKey;
}

std::string Argument::value() const {
  return mValue;
}

bool Argument::hasParam() const {
  return mValue != "";
}

bool Argument::operator==(Argument const &other) const {
  return mKey == other.mKey;
}

Arguments::Arguments() {
}

Arguments::Arguments(std::vector<std::string> const &parameatredArguments,
                     std::vector<std::string> const &simpleArguments)
    : parameatredArguments(parameatredArguments), simpleArguments(simpleArguments) {
}

void Arguments::setTranslation(std::map<std::string, std::string> const &newTranslation) {
  mTranslationDict = newTranslation;
}

void Arguments::parse(int argc, char *argv[]) {
  std::vector<std::string> arguments;
  arguments.reserve(argc);

  for (size_t i = 0; i < static_cast<size_t>(argc); i++) {
    arguments.push_back(argv[i]);
  }

  parse(arguments);
}

void Arguments::parse(std::vector<std::string> const &args) {
  mArguments.clear();

  for (size_t i = 0; i < args.size(); i++) {
    Argument argument;
    std::string const &arg = args[i];

    std::string arg_transform;
    if (mTranslationDict.count(arg)) {
      arg_transform = mTranslationDict.at(arg);
    } else {
      arg_transform = arg;
    }

    auto fParam =
        std::find(parameatredArguments.begin(), parameatredArguments.end(), arg_transform);

    auto fSimple = std::find(simpleArguments.begin(), simpleArguments.end(), arg_transform);

    size_t next_i = i + 1;
    if (fParam != parameatredArguments.end() and next_i < args.size()) {
      std::string const &param = args[next_i];

      argument.set(arg_transform, param);

      i = next_i;
    } else if (fSimple != simpleArguments.end()) {
      argument.set(arg_transform);
    } else if (next_i < args.size()) {
      std::string const &param = args[next_i];

      argument.set(arg_transform, param);

      i = next_i;
    } else {
      argument.set(arg_transform);
    }

    mArguments.push_back(argument);
  }
}

std::string Arguments::get(const std::string &option) const {
  Argument arg;
  arg.set(option);

  auto r = std::find(mArguments.begin(), mArguments.end(), arg);

  if (r != mArguments.end()) {
    return r->value();
  }

  return "";
}

bool Arguments::has(std::string const &option) const {
  Argument arg;
  arg.set(option);

  return has(arg);
}

bool Arguments::has(Argument const &argument) const {
  auto r = std::find(mArguments.begin(), mArguments.end(), argument);

  if (r != mArguments.end()) {
    return true;
  }

  return false;
}

std::string Arguments::info() {
  std::string result;
  result += "\n";
  for (auto const &argument : mArguments) {
    if (argument.hasParam()) {
      result += argument.key();
      result += ": ";
      result += argument.value();
      result += "\n";
    } else {
      result += argument.key();
      result += "\n";
    }
  }

  return result;
}