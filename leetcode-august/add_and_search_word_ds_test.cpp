#include <catch2/catch.hpp>
#include "add_and_search_word_ds.hpp"

#include <vector>

TEST_CASE("WordDictionary test") {

    enum Operation {
        ADD,
        SEARCH,
    };

    struct OperationValue {
        Operation operation{};
        string argument{};
        bool result{false};
    };

    struct TestCaseEntry {
        string name;
        std::vector<OperationValue> operations;
    };
    

    auto cases = std::vector<TestCaseEntry>{
        {
            "Non existent",
            {{SEARCH, "foo", false}}
        },
        {
            "Simple add check",
            {
                {ADD, "bad", false},
                {ADD, "dad", false},
                {ADD, "mad", false},
                {ADD, "pad", false},
                {SEARCH, "bad", true},
                {SEARCH, ".ad", true},
                {SEARCH, "b..", true},
                {SEARCH, "b..d", false},
                {SEARCH, "b.d", true},
                {SEARCH, "b...", false}

            }
        },
    };
    
    WordDictionary dict;
    for (auto& test_case : cases) {
        

        SECTION(test_case.name) {
            for (int i = 0; i < test_case.operations.size(); ++i) {
                INFO("Input: " + to_string(i) + "\n");
                auto current_op = test_case.operations[i];
                switch(current_op.operation) {
                    case ADD: {
                        dict.addWord(current_op.argument);
                        break;
                    }
                    case SEARCH: {
                        INFO("Searching: " + current_op.argument);
                        REQUIRE(dict.search(current_op.argument) == current_op.result);
                        break;
                    }
                }
            }
        }
    }
}