#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>

#include <argument.h>

TEST_CASE("simple Argument test") {
  Argument a, b;

  SUBCASE("test 1") {
  }

  SUBCASE("test 2") {
    a.set("test");
    b.set("test");
  }

  CHECK(a == b);
}

TEST_CASE("simple Arguments test") {
  Arguments a({"template", "name"}, {});

  std::string key;
  std::string answer;
  bool hasParam;

  SUBCASE("test 1") {
    a.parse({"123", "234"});
    key = "123";
    answer = "234";
    hasParam = true;
  }

  SUBCASE("test 2") {
    a.parse({"name", "51"});
    key = "name";
    answer = "51";
    hasParam = true;
  }

  SUBCASE("test 3") {
    a.parse({"123", "234", "name", "51"});
    key = "name";
    answer = "51";
    hasParam = true;
  }

  SUBCASE("test 4") {
    a.parse({"--rule0", "name", "51"});
    key = "name";
    answer = "";
    hasParam = false;
  }

  SUBCASE("test 5") {
    a.parse({"-r5", "name", "51", "ans"});
    key = "name";
    answer = "";
    hasParam = false;
  }

  SUBCASE("test 5") {
    a.parse({"rule3", "name", "51", "ans"});
    key = "name";
    answer = "";
    hasParam = false;
  }

  SUBCASE("test 6") {
    a.parse({"-r5", "-r0", "rule5", "e", "name", "51", "12", "62"});
    key = "name";
    answer = "51";
    hasParam = true;
  }

  MESSAGE(a.info());
  CHECK(a.get(key) == answer);
  CHECK(a.has(key) == hasParam);
}

TEST_CASE("simple Arguments test") {
  Arguments a({"template", "name"}, {"--rule0", "-r5", "rule3", "-r0"});

  std::string key;
  std::string answer;
  bool hasParam;

  SUBCASE("test 1") {
    a.parse({"123", "234"});
    key = "123";
    answer = "234";
    hasParam = true;
  }

  SUBCASE("test 2") {
    a.parse({"name", "51"});
    key = "name";
    answer = "51";
    hasParam = true;
  }

  SUBCASE("test 3") {
    a.parse({"123", "234", "name", "51"});
    key = "name";
    answer = "51";
    hasParam = true;
  }

  SUBCASE("test 4") {
    a.parse({"--rule0", "name", "51"});
    key = "name";
    answer = "51";
    hasParam = true;
  }

  SUBCASE("test 5") {
    a.parse({"-r5", "name", "51", "ans"});
    key = "name";
    answer = "51";
    hasParam = true;
  }

  SUBCASE("test 5") {
    a.parse({"rule3", "name", "51", "ans"});
    key = "name";
    answer = "51";
    hasParam = true;
  }

  SUBCASE("test 6") {
    a.parse({"-r5", "-r0", "rule5", "e", "name", "51", "12", "62"});
    key = "name";
    answer = "51";
    hasParam = true;
  }

  MESSAGE(a.info());

  CHECK(a.get(key) == answer);
  CHECK(a.has(key) == hasParam);
}
