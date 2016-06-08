#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "grader_code.hpp"
#include "Inheritance.hpp"

#define TMP_FNAME	"tmp.txt"
#define TMP_FSIZE	(size_t)1024

TEST_CASE("Inheritance Tests", "[InheritanceTests]") {
	auto fops = get_file_ops();

	SECTION("ReadFile Test") {
		std::string tmp = "";
		REQUIRE(random_file(TMP_FNAME, TMP_FSIZE, tmp));
		REQUIRE(tmp != "");
		REQUIRE(fops->openFile(TMP_FNAME, false));
		REQUIRE(tmp == fops->readFile());
		REQUIRE(false == fops->writeFile(random_string(1024)));
	}

	SECTION("WriteFile Test") {
		REQUIRE(trunc_file(TMP_FNAME));
		auto tmp = random_string(TMP_FSIZE);
		REQUIRE(fops->openFile(TMP_FNAME, true));
		REQUIRE(fops->writeFile(tmp));
		REQUIRE(fops->closeFile());
		auto tmp2 = load_file(TMP_FNAME);
		REQUIRE(tmp2 != "");
		REQUIRE(tmp2 == tmp);
		REQUIRE("" == fops->readFile());
	}

	SECTION("Locked File Test") {
		std::string tmp;
		REQUIRE(random_file(TMP_FNAME, TMP_FSIZE, tmp));
		gLockFile lf(TMP_FNAME);

		SECTION("Write Failure") {
			REQUIRE(false == fops->openFile(TMP_FNAME, true));
			REQUIRE(false == fops->writeFile("asdfjlaksdjflkasdjfklajsldkfjasdlkjfklasdj"));
		}
		SECTION("Read Failure") {
			REQUIRE(false == fops->openFile(TMP_FNAME, false));
			REQUIRE("" == fops->readFile());
		}
	}
}
